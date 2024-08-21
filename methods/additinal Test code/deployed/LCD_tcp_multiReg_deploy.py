from pyModbusTCP.client import ModbusClient
from RPLCD.i2c import CharLCD
import struct
import time

# Initialize the LCD (ensure the I2C address and port are correct for your setup)
lcd = CharLCD(i2c_expander='PCF8574', address=0x3F, port=1, cols=16, rows=2)

def read_modbus_registers(client, address, count):
    try:
        # Read registers from the Modbus TCP server
        registers = client.read_holding_registers(address, count)
        if registers is None:
            raise ConnectionError("Failed to read from the Modbus TCP server.")
        return registers
    except Exception as e:
        raise ConnectionError(f"Error reading registers: {e}")

def convert_to_float(register1, register2):
    # Convert two 16-bit registers to a 32-bit float
    combined = (register1 << 16) | register2
    return struct.unpack('>f', struct.pack('>I', combined))[0]

def main():
    client = ModbusClient(host='192.168.5.55', port=502, unit_id=200, auto_open=False)
    
    while True:
        try:
            # Attempt to connect to the Modbus TCP server
            if not client.open():
                raise ConnectionError("Failed to connect to the Modbus TCP server.")
            
            # Define the register pairs to read
            register_pairs = [
                (40406 - 1, 40407 - 1),
                (40438 - 1, 40439 - 1)
            ]

            float_values = []
            for address1, address2 in register_pairs:
                # Read the registers and convert to float
                registers = read_modbus_registers(client, address1, 2)
                if len(registers) >= 2:
                    float_value = convert_to_float(registers[0], registers[1]) / 100  # Divide by 100
                    float_values.append(float_value)
                else:
                    raise ValueError(f"Failed to read the required number of registers for addresses {address1 + 1} and {address2 + 1}.")

            # Display the values on the LCD
            if len(float_values) >= 2:
                lcd.clear()
                lcd.write_string(f"M1: {float_values[0]:.2f}")  # Print the first float value on the first line
                lcd.cursor_pos = (1, 0)
                lcd.write_string(f"M2: {float_values[1]:.2f}")  # Print the second float value on the second line

            # Sleep before the next read cycle
            time.sleep(10)  # Adjust this as necessary for your application

        except (ConnectionError, ValueError) as e:
            # Log or handle the error appropriately
            time.sleep(60)  # Wait 60 seconds before retrying

        finally:
            client.close()

if __name__ == "__main__":
    main()
