from pymodbus.client.tcp import ModbusTcpClient
import struct

def read_float_registers(client, start_address, num_registers):
    """
    Read and interpret holding registers as IEEE754 floats.
    
    Parameters:
    client (ModbusTcpClient): The Modbus client object.
    start_address (int): The starting address to read from.
    num_registers (int): The number of registers to read.
    
    Returns:
    dict: A dictionary where keys are addresses and values are the float values read.
    """
    results = {}
    
    for address in range(start_address, start_address + num_registers, 2):
        response = client.read_holding_registers(address, 2)
        if not response.isError():
            registers = response.registers
            combined = (registers[0] << 16) | registers[1]
            ieee_float = struct.unpack('>f', struct.pack('>I', combined))[0]
            results[address + 1] = ieee_float  # +1 to convert to 1-based address
        else:
            results[address + 1] = None  # Indicate an error occurred
    
    return results

def main():
    # Define the Modbus TCP server's IP and port
    client = ModbusTcpClient('192.168.5.55', port=502)
    
    # Connect to the server
    if client.connect():
        # Define the range of addresses to scan
        start_address = 440438 - 400001  # Adjust for 0-based addressing
        num_registers = 20  # Number of registers to scan (must be even for reading pairs)
        
        # Read and print the results
        results = read_float_registers(client, start_address, num_registers)
        for address, value in results.items():
            if value is not None:
                print(f"Address {address + 400001}: {value:.2f} kWh")
            else:
                print(f"Address {address + 400001}: Error reading register")
        
        # Close the connection
        client.close()
    else:
        print("Unable to connect to the Modbus TCP server")

if __name__ == "__main__":
    main()

