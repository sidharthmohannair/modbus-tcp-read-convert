import subprocess
import struct

# Define the Modbus register addresses as variables
#40378, 40379 for voltage R

REGISTER_1_ADDR = 40406
REGISTER_2_ADDR = 40407

def run_mb_poll():
    try:
        command = ["mbpoll", "-m", "tcp", "-a", "200", "-r", str(REGISTER_1_ADDR), "-c", "2", "-p", "502", "-t", "3", "192.168.5.55"]
        print(f"Running command: {' '.join(command)}")
        process = subprocess.Popen(
            command,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            universal_newlines=True
        )

        try:
            # Read output line by line
            for line in iter(process.stdout.readline, ''):
                if f"[{REGISTER_1_ADDR}]:" in line or f"[{REGISTER_2_ADDR}]:" in line:
                    print(f"Output: {line.strip()}")
                    if f"[{REGISTER_1_ADDR}]:" in line:
                        register1 = int(line.split()[1])
                    if f"[{REGISTER_2_ADDR}]:" in line:
                        register2 = int(line.split()[1])
                        float_value = convert_to_float(register1, register2)
                        print(f"The float value is: {float_value}")

        except subprocess.TimeoutExpired:
            process.kill()
            print("Process killed after timeout.")
            raise ConnectionError("The mbpoll command timed out. Check your connection and try again.")
        
    except Exception as e:
        raise ConnectionError(f"An error occurred while running mbpoll: {e}")

def convert_to_float(register1, register2):
    if register1 is None or register2 is None:
        raise ValueError("Invalid register values. Make sure the Modbus server is returning the correct data.")
    
    combined = (register1 << 16) | register2
    float_value = struct.unpack('>f', struct.pack('>I', combined))[0]
    return float_value

try:
    run_mb_poll()

except (ConnectionError, ValueError) as e:
    print(f"Error: {e}")
except Exception as e:
    print(f"Unexpected error: {e}")
