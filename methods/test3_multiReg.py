import subprocess
import struct
import time

# Define the Modbus register address pairs as a list of tuples
REGISTER_PAIRS = [
    (40378, 40379),
    (40406, 40407)
]

def run_mb_poll():
    try:
        # Iterate over each register pair
        for register1_addr, register2_addr in REGISTER_PAIRS:
            command = [
                "mbpoll", "-m", "tcp", "-a", "200", 
                "-r", str(register1_addr), "-c", "2", 
                "-p", "502", "-t", "3", "192.168.5.55"
            ]
            print(f"Running command: {' '.join(command)}")
            process = subprocess.Popen(
                command,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                universal_newlines=True
            )

            try:
                # Read output line by line
                output_lines = []
                for line in iter(process.stdout.readline, ''):
                    output_lines.append(line.strip())
                    if f"[{register2_addr}]:" in line:
                        break

                # Process the collected output
                register1 = None
                register2 = None
                for line in output_lines:
                    if f"[{register1_addr}]:" in line:
                        register1 = int(line.split()[1])
                    if f"[{register2_addr}]:" in line:
                        register2 = int(line.split()[1])

                if register1 is not None and register2 is not None:
                    float_value = convert_to_float(register1, register2)
                    print(f"The float value for registers {register1_addr} and {register2_addr} is: {float_value}")

            except subprocess.TimeoutExpired:
                process.kill()
                print("Process killed after timeout.")
                raise ConnectionError("The mbpoll command timed out. Check your connection and try again.")
            
    except Exception as e:
        raise ConnectionError(f"An error occurred while running mbpoll: {e}")

def convert_to_float(register1, register2):
    combined = (register1 << 16) | register2
    float_value = struct.unpack('>f', struct.pack('>I', combined))[0]
    return float_value

try:
    while True:
        run_mb_poll()
        time.sleep(1)  # Optional sleep to avoid overwhelming the Modbus server

except (ConnectionError, ValueError) as e:
    print(f"Error: {e}")
except Exception as e:
    print(f"Unexpected error: {e}")
except KeyboardInterrupt:
    print("Polling interrupted by user.")
