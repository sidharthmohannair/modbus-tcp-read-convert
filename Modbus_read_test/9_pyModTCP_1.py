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

def convert_to_float(registers):
    if len(registers) < 2:
        raise ValueError("Invalid register values. Make sure the Modbus server is returning the correct data.")
    
    print("Combining registers and converting to float...")
    combined = (registers[0] << 16) | registers[1]
    float_value = struct.unpack('>f', struct.pack('>I', combined))[0]
    return float_value

def main():
    client = ModbusClient(host='192.168.5.55', port=502, unit_id=200, auto_open=True)
    try:
        if not client.is_open():
            raise ConnectionError("Failed to connect to the Modbus TCP server.")
        
        print("Successfully connected to the Modbus TCP server")

        address = 40378 - 40001  # Adjust for zero-based addressing
        count = 2

        registers = read_modbus_registers(client, address, count)
        float_value = convert_to_float(registers)

        print(f"The float value is: {float_value}")
    except (ConnectionError, ValueError) as e:
        print(f"Error: {e}")
    finally:
        client.close()

if __name__ == "__main__":
    main()
