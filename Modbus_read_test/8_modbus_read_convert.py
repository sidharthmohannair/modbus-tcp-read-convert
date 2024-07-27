from pymodbus.client.tcp import ModbusTcpClient
import struct

def read_modbus_registers(client, address, count, unit_id):
    try:
        print(f"Attempting to read {count} registers starting at address {address} with unit ID {unit_id}...")
        # Read holding registers
        result = client.read_holding_registers(address, count, unit=unit_id)
        if result.isError():
            print(f"Modbus error: {result}")
            raise ConnectionError("Failed to read from the Modbus TCP server.")
        print(f"Registers read successfully: {result.registers}")
        return result.registers
    except Exception as e:
        print(f"Error reading registers: {e}")
        raise

def convert_to_float(registers):
    # Check if the registers are valid
    if len(registers) < 2:
        raise ValueError("Invalid register values. Make sure the Modbus server is returning the correct data.")
    
    # Combine the registers and convert to float
    combined = (registers[0] << 16) | registers[1]
    float_value = struct.unpack('>f', struct.pack('>I', combined))[0]
    return float_value

def main():
    # Define the Modbus TCP server's IP, port, and increase timeout
    client = ModbusTcpClient('192.168.5.55', port=502, timeout=10)
    
    try:
        # Connect to the server
        print("Attempting to connect to the Modbus TCP server...")
        if not client.connect():
            raise ConnectionError("Failed to connect to the Modbus TCP server.")
        
        print("Successfully connected to the Modbus TCP server")

        # Define unit ID (slave ID)
        unit_id = 200

        # Read Modbus register values
        print("Reading Modbus register values...")
        registers = read_modbus_registers(client, 40380, 2, unit_id)
        print(f"Registers read: {registers}")
        
        # Convert the values to a float
        print("Converting register values to float...")
        float_value = convert_to_float(registers)
        print(f"The float value is: {float_value}")

    except (ConnectionError, ValueError) as e:
        print(f"Error: {e}")
    
    finally:
        # Close the connection
        print("Closing the connection to the Modbus TCP server...")
        client.close()

if __name__ == "__main__":
    main()
