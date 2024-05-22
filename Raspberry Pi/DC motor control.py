import RPi.GPIO as GPIO
from time import sleep

# Suppress warnings
GPIO.setwarnings(False)

# Set the GPIO mode to BOARD
GPIO.setmode(GPIO.BOARD)

# Setup GPIO pins
GPIO.setup(3, GPIO.OUT)
GPIO.setup(5, GPIO.OUT)
GPIO.setup(7, GPIO.OUT)

# Initialize PWM on pin 7 with a frequency of 100 Hz
p = GPIO.PWM(7, 100)
p.start(0)  # Start PWM with 0% duty cycle

try:
    while True:
        # Set initial states of GPIO pins
        GPIO.output(3, GPIO.HIGH)
        GPIO.output(5, GPIO.LOW)
        
        # Get the PWM value from the user
        pvalue = int(input("Enter the PWM Value (0-100): "))
        
        # Change the duty cycle to the entered value
        p.ChangeDutyCycle(pvalue)
        
        # Turn on the DC motor connected to pin 7
        GPIO.output(7, True)
        sleep(5)  # Keep it on for 5 seconds
        
        # Turn off the DC motor connected to pin 7
        GPIO.output(7, False)
        
        # Change the states of other GPIO pins
        GPIO.output(3, False)
        GPIO.output(5, True)
        
        # Change the duty cycle again to the entered value
        p.ChangeDutyCycle(pvalue)
        
        # Turn on the DC motor connected to pin 7 again
        GPIO.output(7, True)
        sleep(5)  # Keep it on for 5 seconds
        
        # Turn off the DC motor connected to pin 7
        GPIO.output(7, False)

except KeyboardInterrupt:
    # Stop PWM and clean up GPIO settings on exit
    p.stop()
    GPIO.cleanup()
