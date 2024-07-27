import subprocess

def read_modbus_registers():
    command = "mbpoll -m tcp -a 200 -r 40378 -c 2 -p 502 -t 3 192.168.5.55"
    print(f"Running command: {command}")
    process = subprocess.Popen(
        command,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        shell=True
    )
    output, error = process.communicate()
    print(f"Raw output: {output}")
    print(f"Raw error: {error}")
    output = output.decode('utf-8', errors='ignore')
    error = error.decode('utf-8', errors='ignore')

    if "Connection failed" in error:
        raise ConnectionError("Failed to connect to the Modbus TCP server. Please check the connection and try again.")
    
    if error:
        raise ConnectionError(f"An error occurred while running mbpoll: {error}")

    return output

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
    output = read_modbus_registers()
    print(f"mbpoll output:\n{output}")

    register1, register2 = parse_register_values(output)
    float_value = convert_to_float(register1, register2)

    print(f"The float value is: {float_value}")

except (ConnectionError, ValueError) as e:
    print(f"Error: {e}")
except Exception as e:
    print(f"Unexpected error: {e}")
