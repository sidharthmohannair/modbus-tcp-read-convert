from pyModbusTCP.client import ModbusClient
import struct

def read_modbus_registers(client, address, count):
    try:
        print(f"Attempting to read {count} registers starting at address {address}...")
        registers = client.read_holding_registers(address, count)
        if registers is None:
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

        # Adjust the addresses to zero-based (subtract 40001 from the starting address)
        address1 = 40378 - 40001

        # Read both registers (assuming they are sequential)
        registers = read_modbus_registers(client, address1, 2)

        if len(registers) >= 2:
            register1 = registers[0]
            register2 = registers[1]
            float_value = convert_to_float(register1, register2)
            print(f"The float value is: {float_value}")
        else:
            raise ValueError("Failed to read the required number of registers.")

    except (ConnectionError, ValueError) as e:
        print(f"Error: {e}")
    finally:
        client.close()

if __name__ == "__main__":
    main()
