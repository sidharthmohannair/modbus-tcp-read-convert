
# Raspberry Pi Auto-Run Script with Systemd

This guide explains how to set up a Python script to automatically run on boot using `systemd` on a Raspberry Pi.

## Prerequisites

- Raspberry Pi running Raspbian OS
- Python 3 installed
- A Python virtual environment with all necessary dependencies installed
- Your Python script ready to be deployed

## Step 1: Create a Systemd Service File

1. Open a terminal on your Raspberry Pi.

2. Create a new service file in the `/etc/systemd/system/` directory:

   ```bash
   sudo nano /etc/systemd/system/modbus_lcd.service
   ```

3. Add the following content to the service file:

   ```ini
   [Unit]
   Description=Modbus to LCD Display Service
   After=network.target

   [Service]
   Type=simple
   User=pi
   WorkingDirectory=/home/pi/Downloads/TCPmodbus
   ExecStart=/bin/bash -c 'source /home/pi/Downloads/TCPmodbus/myenv/bin/activate && python3 /home/pi/Downloads/TCPmodbus/TCP_lcd_MultiReg_works.py'
   Restart=on-failure

   [Install]
   WantedBy=multi-user.target
   ```

   - **Description**: A brief description of the service.
   - **After**: Ensures the service starts after the network is up.
   - **Type**: Defines the service type. `simple` means it starts the process specified in `ExecStart`.
   - **User**: The user that runs the service. Typically `pi` for Raspberry Pi.
   - **WorkingDirectory**: The directory where your Python script is located.
   - **ExecStart**: The command to run your Python script. It includes activating the virtual environment.
   - **Restart**: Ensures the service restarts on failure.
   - **WantedBy**: Specifies the target to start this service with (multi-user mode).

4. Save and exit the file (press `CTRL + X`, then `Y`, and `Enter`).

## Step 2: Enable and Start the Service

1. Reload the systemd daemon to recognize the new service:

   ```bash
   sudo systemctl daemon-reload
   ```

2. Enable the service to start on boot:

   ```bash
   sudo systemctl enable modbus_lcd.service
   ```

3. Start the service immediately:

   ```bash
   sudo systemctl start modbus_lcd.service
   ```

## Step 3: Verify the Service

1. Check the status of the service to ensure it is running:

   ```bash
   sudo systemctl status modbus_lcd.service
   ```

   If the service is running, you'll see an `active (running)` status. If it failed, the output will provide error messages to help with troubleshooting.

2. View logs if the service fails to start:

   ```bash
   sudo journalctl -u modbus_lcd.service -e
   ```

## Step 4: Troubleshooting

- **Permissions**: Ensure all files are accessible by the `pi` user.
- **Dependencies**: Verify all required Python packages are installed in the virtual environment.
- **Environment Variables**: Set any required environment variables directly in the service file if needed.
- **Delayed Start**: If your service needs to wait for the network or other services to start, you can add a delay with `ExecStartPre=/bin/sleep 10`.

By following this guide, your Python script should automatically start on boot and run continuously on your Raspberry Pi.
