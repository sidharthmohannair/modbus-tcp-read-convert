from pymodbus.client.tcp import ModbusTcpClient
import struct

def float_to_registers(value):
    """
    Convert a float value to two 16-bit register values (Big Endian).
    
    Parameters:
    value (float): The float value to convert.
    
    Returns:
    list: A list of two 16-bit register values.
    """
    packed = struct.pack('>f', value)
    registers = struct.unpack('>HH', packed)
    return list(registers)

def registers_to_float(registers):
    """
    Convert two 16-bit register values (Big Endian) to a float value.
    
    Parameters:
    registers (list): A list of two 16-bit register values.
    
    Returns:
    float: The float value.
    """
    combined = (registers[0] << 16) | registers[1]
    ieee_float = struct.unpack('>f', struct.pack('>I', combined))[0]
    return ieee_float

def read_float_register(client, address):
    """
    Read a float value from holding registers as an IEEE754 float (Big Endian).
    
    Parameters:
    client (ModbusTcpClient): The Modbus client object.
    address (int): The address to read from.
    
    Returns:
    float or None: The float value read, or None if an error occurred.
    """
    response = client.read_holding_registers(address, 2)
    if not response.isError():
        registers = response.registers
        return registers_to_float(registers)
    else:
        return None

def write_float_register(client, address, value):
    """
    Write a float value to holding registers as an IEEE754 float (Big Endian).
    
    Parameters:
    client (ModbusTcpClient): The Modbus client object.
    address (int): The address to write to.
    value (float): The float value to write.
    
    Returns:
    bool: True if successful, False otherwise.
    """
    registers = float_to_registers(value)
    response = client.write_registers(address, registers)
    return not response.isError()

def main():
    # Define the Modbus TCP server's IP and port
    client = ModbusTcpClient('192.168.1.100', port=502)
    
    # Connect to the server
    if client.connect():
        # List of specific addresses to read/write and the values to write (adjust for 0-based addressing)
        addresses_to_read = [4038 - 1, 4040 - 1, 4042 - 1]  # Example addresses to read
        address_value_pairs_to_write = [
            (4038 - 1, 12345.67),  # Example address and value to write
            (4040 - 1, 23456.78),
            (4042 - 1, 34567.89)
        ]
        
        # Read and print the results
        for address in addresses_to_read:
            value = read_float_register(client, address)
            if value is not None:
                print(f"Read from address {address + 1 + 400001}: {value:.2f} kWh")  # +1 for 1-based addressing
            else:
                print(f"Error reading from address {address + 1 + 400001}")
        
        # Write the values and print the results
        for address, value in address_value_pairs_to_write:
            success = write_float_register(client, address, value)
            if success:
                print(f"Successfully wrote {value:.2f} to address {address + 1 + 400001}")  # +1 for 1-based addressing
            else:
                print(f"Error writing {value:.2f} to address {address + 1 + 400001}")
        
        # Close the connection
        client.close()
    else:
        print("Unable to connect to the Modbus TCP server")

if __name__ == "__main__":
    main()

