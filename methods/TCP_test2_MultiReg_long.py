from pyModbusTCP.client import ModbusClient
import struct
import time
import logging

# Setup logging
logging.basicConfig(
    filename='/home/sidharth/logs/modbus_client.log',  # Store logs in a custom directory in your home folder
    level=logging.INFO,
    format='%(asctime)s %(levelname)s: %(message)s',
    datefmt='%Y-%m-%d %H:%M:%S'
)


def read_modbus_registers(client, address, count):
    try:
        logging.info(f"Attempting to read {count} registers starting at address {address}...")
        registers = client.read_holding_registers(address, count)
        if registers is None:
            logging.error("Registers read returned None.")
            raise ConnectionError("Failed to read from the Modbus TCP server.")
        logging.info(f"Registers read successfully: {registers}")
        return registers
    except Exception as e:
        logging.error(f"Error reading registers: {e}")
        raise

def convert_to_float(register1, register2):
    if register1 is None or register2 is None:
        raise ValueError("Invalid register values. Make sure the Modbus server is returning the correct data.")
    
    combined = (register1 << 16) | register2
    float_value = struct.unpack('>f', struct.pack('>I', combined))[0]
    return float_value

def main():
    client = ModbusClient(host='192.168.5.55', port=502, unit_id=200, auto_open=False)
    while True:
        try:
            logging.info("Attempting to connect to the Modbus TCP server...")
            if not client.open():
                raise ConnectionError("Failed to connect to the Modbus TCP server.")
            
            logging.info("Successfully connected to the Modbus TCP server")

            # List of register pairs you want to read (addresses without subtraction)
            register_pairs = [
                (40406 - 1, 40407 - 1),
                (40378 - 1, 40379 - 1)
            ]

            for address1, address2 in register_pairs:
                # Read the registers
                registers = read_modbus_registers(client, address1, 2)

                if len(registers) >= 2:
                    register1 = registers[0]
                    register2 = registers[1]
                    float_value = convert_to_float(register1, register2)
                    logging.info(f"The float value for registers {address1 + 1} and {address2 + 1} is: {float_value}")
                else:
                    raise ValueError(f"Failed to read the required number of registers for addresses {address1 + 1} and {address2 + 1}.")

            # Sleep for a period of time before the next read cycle
            time.sleep(10)  # Adjust this as necessary for your application

        except (ConnectionError, ValueError) as e:
            logging.error(f"Error: {e}")
            logging.info("Attempting to reconnect after a delay...")
            time.sleep(60)  # Wait 60 seconds before retrying

        except Exception as e:
            logging.critical(f"Unexpected error: {e}")
            logging.info("Retrying after a delay...")
            time.sleep(60)  # Wait 60 seconds before retrying

        finally:
            client.close()
            logging.info("Connection closed.")

if __name__ == "__main__":
    main()
