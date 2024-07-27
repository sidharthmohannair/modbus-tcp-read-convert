from pymodbus.client.tcp import ModbusTcpClient
import struct

# Define the Modbus TCP server's IP and port
client = ModbusTcpClient('192.168.1.100', port=502)

# Connect to the server
if client.connect():
    # Read 2 holding registers starting from address 4038 (address 4037 in pymodbus, since it uses 0-based addressing)
    address = 4037
    num_registers = 2
    result = client.read_holding_registers(address, num_registers)
    
    # Check for errors
    if not result.isError():
        # Convert register values to IEEE754 float (Big Endian)
        # result.registers will be a list of 2 register values
        registers = result.registers
        # Combine the two registers to form a single 32-bit integer
        combined = (registers[0] << 16) | registers[1]
        # Convert to float using struct with Big Endian format
        ieee_float = struct.unpack('>f', struct.pack('>I', combined))[0]
        print(f'Total AC Active Import Energy: {ieee_float} kWh')
    else:
        print("Error reading registers")
    
    # Close the connection
    client.close()
else:
    print("Unable to connect to the Modbus TCP server")
