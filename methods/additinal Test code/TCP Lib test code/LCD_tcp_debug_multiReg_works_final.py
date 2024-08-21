from pyModbusTCP.client import ModbusClient
from RPLCD.i2c import CharLCD
import struct
import time

# Initialize the LCD (ensure the I2C address and port are correct for your setup)
lcd = CharLCD(i2c_expander='PCF8574', address=0x3F, port=1, cols=16, rows=2)

def read_modbus_registers(client, address, count):
    try:
        print(f"Attempting to read {count} registers starting at address {address}...")
        registers = client.read_holding_registers(address, count)
        if registers is None:
            print(f"Registers read returned None.")
            raise ConnectionError("Failed to read from the Modbus TCP server.")
        print(f"Registers read successfully: {registers}")
        return registers
    except Exception as e:
        print(f"Error reading registers: {e}")
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
            print("Attempting to connect to the Modbus TCP server...")
            if not client.open():
                raise ConnectionError("Failed to connect to the Modbus TCP server.")
            
            print("Successfully connected to the Modbus TCP server")

            # List of register pairs you want to read (addresses without subtraction)
            register_pairs = [
                (40406 - 1, 40407 - 1),
                (40438 - 1, 40439 - 1)
            ]

            float_values = []
            for address1, address2 in register_pairs:
                # Read the registers
                registers = read_modbus_registers(client, address1, 2)

                if len(registers) >= 2:
                    register1 = registers[0]
                    register2 = registers[1]
                    float_value = convert_to_float(register1, register2) / 100  # Divide by 100
                    print(f"The float value for registers {address1 + 1} and {address2 + 1} is: {float_value:.2f}")
                    float_values.append(float_value)
                else:
                    raise ValueError(f"Failed to read the required number of registers for addresses {address1 + 1} and {address2 + 1}.")

            # Display the values on the LCD
            if len(float_values) >= 2:
                lcd.clear()
                lcd.write_string(f"M1: {float_values[0]:.2f}")  # Print the first float value on the first line
                lcd.cursor_pos = (1, 0)
                lcd.write_string(f"M2: {float_values[1]:.2f}")  # Print the second float value on the second line

            # Sleep for a period of time before the next read cycle
            time.sleep(10)  # Adjust this as necessary for your application

        except (ConnectionError, ValueError) as e:
            print(f"Error: {e}")
            time.sleep(60)  # Wait 60 seconds before retrying

        finally:
            client.close()

if __name__ == "__main__":
    main()

