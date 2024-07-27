from pymodbus.client.tcp import ModbusTcpClient
import struct

def read_float_register(client, address):
    """
    Read and interpret holding registers as an IEEE754 float.
    
    Parameters:
    client (ModbusTcpClient): The Modbus client object.
    address (int): The address to read from.
    
    Returns:
    float or None: The float value read, or None if an error occurred.
    """
    response = client.read_holding_registers(address, 2)
    if not response.isError():
        registers = response.registers
        combined = (registers[0] << 16) | registers[1]
        ieee_float = struct.unpack('>f', struct.pack('>I', combined))[0]
        return ieee_float
    else:
        return None

def main():
    # Define the Modbus TCP server's IP and port
    client = ModbusTcpClient('192.168.5.55', port=502)
    
    # Connect to the server
    if client.connect():
        # List of specific addresses to read (adjust for 0-based addressing)
        addresses = [4038 - 1, 4040 - 1, 4042 - 1]  # Example addresses
        
        # Read and print the results
        for address in addresses:
            value = read_float_register(client, address)
            if value is not None:
                print(f"Address {address + 1 + 400001}: {value:.2f} kWh")  # +1 for 1-based addressing
            else:
                print(f"Address {address + 1 + 400001}: Error reading register")
        
        # Close the connection
        client.close()
    else:
        print("Unable to connect to the Modbus TCP server")

if __name__ == "__main__":
    main()

