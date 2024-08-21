import subprocess
import struct

def run_mb_poll():
    try:
        command = ["mbpoll", "-m", "tcp", "-a", "200", "-r", "40378", "-c", "2", "-p", "502", "-t", "3", "192.168.5.55"]
        print(f"Running command: {' '.join(command)}")
        process = subprocess.Popen(
            command,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            universal_newlines=True
        )

        output_lines = []
        try:
            # Read output line by line
            for line in iter(process.stdout.readline, ''):
                print(f"Output: {line.strip()}")
                output_lines.append(line)
                if "Have a nice day" in line:  # Detect when mbpoll ends
                    break

            process.stdout.close()
            process.wait()

            if process.returncode != 0:
                raise ConnectionError(f"mbpoll command failed with return code {process.returncode}")
            
        except subprocess.TimeoutExpired:
            process.kill()
            print("Process killed after timeout.")
            raise ConnectionError("The mbpoll command timed out. Check your connection and try again.")
        
        output = ''.join(output_lines)
        return output

    except Exception as e:
        raise ConnectionError(f"An error occurred while running mbpoll: {e}")

def parse_register_values(output):
    print("Parsing mbpoll output...")
    lines = output.split('\n')
    register1 = None
    register2 = None
    for line in lines:
        if "[40378]:" in line:
            try:
                register1 = int(line.split()[1])
            except ValueError:
                print(f"Failed to parse register value from line: {line}")
        if "[40379]:" in line:
            try:
                register2 = int(line.split()[1])
            except ValueError:
                print(f"Failed to parse register value from line: {line}")
    if register1 is None or register2 is None:
        raise ValueError("Failed to parse register values from mbpoll output.")
    print(f"Parsed registers: 40378={register1}, 40379={register2}")
    return register1, register2

def convert_to_float(register1, register2):
    if register1 is None or register2 is None:
        raise ValueError("Invalid register values. Make sure the Modbus server is returning the correct data.")
    
    print("Combining registers and converting to float...")
    combined = (register1 << 16) | register2
    float_value = struct.unpack('>f', struct.pack('>I', combined))[0]
    return float_value

try:
    output = run_mb_poll()
    print(f"mbpoll output:\n{output}")

    register1, register2 = parse_register_values(output)
    float_value = convert_to_float(register1, register2)

    print(f"The float value is: {float_value}")

except (ConnectionError, ValueError) as e:
    print(f"Error: {e}")
except Exception as e:
    print(f"Unexpected error: {e}")
