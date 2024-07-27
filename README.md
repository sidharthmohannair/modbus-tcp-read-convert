
# Modbus TCP Read and Convert

This repository contains Python scripts to read Modbus registers from a Modbus TCP server using both `mbpoll` (via `subprocess`) and the `pyModbusTCP` library. The scripts capture the register values and convert them into a floating-point number using the IEEE754 format.

## Prerequisites

1. Python 3.6 or later
2. `mbpoll` utility (for the `subprocess` method)
3. `pyModbusTCP` library (for the library method)
4. `struct` library (part of Python standard library)

## Installation

### Install Python

If you don't have Python installed, you can download and install it from [Python.org](https://www.python.org/downloads/).

### Install mbpoll

Follow the steps below to install `mbpoll` on your Ubuntu system:

```sh
sudo apt-get update
sudo apt-get install mbpoll
```

### Install pyModbusTCP

Install the `pyModbusTCP` library using pip:

```sh
pip install pyModbusTCP
```

### Clone the Repository

Clone this repository to your local machine:

```sh
git clone https://github.com/your-username/modbus-tcp-read-convert.git
cd modbus-tcp-read-convert
```

## Network Setup

### Setting Up the Network Connection

1. **Connect the Ethernet Cable**: Connect your computer to the Modbus TCP server using an Ethernet cable.

2. **Create a Network Profile**:
   - Go to Network settings on your Ubuntu system.
   - Click on the gear icon next to your wired connection.
   - Click on the `IPv4` tab.

3. **Change IPv4 Settings to Manual**:
   - Select `Manual` under `IPv4 Method`.
   - Enter the following settings:
     - **Address**: Set the IP address for your computer (e.g., `192.168.5.10`).
     - **Netmask**: Set the subnet mask (e.g., `255.255.255.0`).
     - **Gateway**: Set the gateway address (e.g., `192.168.5.1`).
   - Click `Apply` to save the settings.

4. **Disable and Enable the Network Connection**: To apply the new settings, disable and then enable the network connection.

## Usage

The repository contains two methods to read and convert Modbus registers:
1. Using `subprocess` with `mbpoll`
2. Using the `pyModbusTCP` library

### Running the Script with `subprocess` and `mbpoll`

Run the `modbus_read_convert_subprocess.py` script:

```sh
python methods/modbus_read_convert_subprocess.py
```

### Running the Script with `pyModbusTCP`

Run the `modbus_read_convert_pymodbustcp.py` script:

```sh
python methods/modbus_read_convert_pymodbustcp.py
```

## Troubleshooting

If you encounter any issues, check the following:
- Ensure the Modbus TCP server is running and accessible.
- Verify the register address and count are correct.
- Check network connectivity and firewall settings.

## Contributing

Feel free to contribute to this repository by submitting issues or pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
