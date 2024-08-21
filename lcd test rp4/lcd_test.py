from RPLCD.i2c import CharLCD
import time

# Initialize with the correct expander and other settings
lcd = CharLCD(i2c_expander='PCF8574', address=0x3F, port=1, cols=16, rows=2)

try:
    lcd.clear()
    lcd.write_string('Hello, Avinash')
    time.sleep(2)
    lcd.clear()
    lcd.write_string('my test')
    time.sleep(2)
    lcd.clear()
except Exception as e:
    print(f"An error occurred: {e}")
