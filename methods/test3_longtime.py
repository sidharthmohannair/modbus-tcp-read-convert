import subprocess
import struct
import time
import logging
import os
import signal
from logging.handlers import RotatingFileHandler

# Set up logging
log_file = "mbpoll_output.log"
logging.basicConfig(
    handlers=[RotatingFileHandler(log_file, maxBytes=10*1024*1024, backupCount=5)],
    level=logging.INFO,
    format='%(asctime)s - %(message)s'
)

def run_mb_poll():
    command = ["mbpoll", "-m", "tcp", "-a", "200", "-r", "40378", "-c", "2", "-p", "502", "-t", "3", "192.168.5.55"]
    logging.info(f"Starting mbpoll with command: {' '.join(command)}")

    process = subprocess.Popen(
        command,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        universal_newlines=True
    )

    try:
        for line in iter(process.stdout.readline, ''):
            logging.info(line.strip())
            if time_to_stop():
                logging.info("Stopping process due to stop signal.")
                break
        process.stdout.close()
        process.wait()

        if process.returncode != 0:
            logging.error(f"mbpoll command failed with return code {process.returncode}")
            raise ConnectionError(f"mbpoll command failed with return code {process.returncode}")
        
    except subprocess.TimeoutExpired:
        process.kill()
        logging.error("Process killed after timeout.")
        raise ConnectionError("The mbpoll command timed out. Check your connection and try again.")
    except Exception as e:
        logging.error(f"Exception occurred: {e}")
        raise
    finally:
        process.terminate()

def time_to_stop():
    # Implement any condition or signal check to determine if the script should stop
    return False

def main():
    try:
        while True:
            try:
                run_mb_poll()
            except (ConnectionError, ValueError) as e:
                logging.error(f"Error: {e}")
            except Exception as e:
                logging.error(f"Unexpected error: {e}")
            logging.info("Restarting mbpoll process...")
            time.sleep(5)  # Wait a bit before restarting the process

    except KeyboardInterrupt:
        logging.info("Script interrupted by user.")
    except Exception as e:
        logging.error(f"Fatal error: {e}")

if __name__ == "__main__":
    # Handle graceful shutdowns
    signal.signal(signal.SIGTERM, lambda signum, frame: os._exit(0))
    signal.signal(signal.SIGINT, lambda signum, frame: os._exit(0))
    
    main()
