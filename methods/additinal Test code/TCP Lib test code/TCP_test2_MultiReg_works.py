from pyModbusTCP.client import ModbusClient
import struct
import time

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
    try:
        print("Attempting to connect to the Modbus TCP server...")
        if not client.open():
            raise ConnectionError("Failed to connect to the Modbus TCP server.")
        
        print("Successfully connected to the Modbus TCP server")

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
                print(f"The float value for registers {address1 + 1} and {address2 + 1} is: {float_value}")
            else:
                raise ValueError(f"Failed to read the required number of registers for addresses {address1 + 1} and {address2 + 1}.")

    except (ConnectionError, ValueError) as e:
        print(f"Error: {e}")
    finally:
        client.close()

if __name__ == "__main__":
    main()
