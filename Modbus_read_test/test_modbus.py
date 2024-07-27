from pymodbus.client.tcp import ModbusTcpClient


def main():
    # Define the Modbus TCP server's IP and port
    client = ModbusTcpClient('192.168.5.55', port=502)
    
    # Connect to the server
    if client.connect():
        print("Successfully connected to the Modbus TCP server")
        client.close()
    else:
        print("Unable to connect to the Modbus TCP server")

if __name__ == "__main__":
    main()
