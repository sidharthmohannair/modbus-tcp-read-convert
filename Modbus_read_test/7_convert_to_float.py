import struct

# Raw register values from QModMaster
register1 = 18106
register2 = 43520


# Combine the two 16-bit registers into a single 32-bit integer
combined = (register1 << 16) | register2

# Convert the 32-bit integer to a float (IEEE 754)
float_value = struct.unpack('>f', struct.pack('>I', combined))[0]

print(f"The float value is: {float_value}")
