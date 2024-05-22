import RPi.GPIO as GPIO
import time

# Set the GPIO mode to BOARD
GPIO.setmode(GPIO.BOARD)

# Define the GPIO pins for the ultrasonic sensor
TRIG = 16
ECHO = 18

# Variable to keep track of object state
i = 0

# Set up the GPIO pins
GPIO.setup(TRIG, GPIO.OUT)
GPIO.setup(ECHO, GPIO.IN)

# Ensure the trigger pin is low initially
GPIO.output(TRIG, GPIO.LOW)

print("Calibrating....")
time.sleep(2)  # Allow the sensor to settle
print("Place the object")

try:
    while True:
        # Send a trigger pulse
        GPIO.output(TRIG, GPIO.HIGH)
        time.sleep(0.00001)  # Trigger pulse duration (10 microseconds)
        GPIO.output(TRIG, GPIO.LOW)

        # Wait for the echo to start
        while GPIO.input(ECHO) == 0:
            pulse_start = time.time()

        # Wait for the echo to end
        while GPIO.input(ECHO) == 1:
            pulse_end = time.time()

        # Calculate the pulse duration and distance
        pulse_duration = pulse_end - pulse_start
        distance = pulse_duration * 17150  # Calculate distance in cm
        distance = round(distance + 1.15, 2)  # Add a slight offset and round the result

        if 5 <= distance <= 30:  # Check if distance is within range
            print("Distance:", distance, "cm")
            print("Object is near")
            i = 1  # Set the state indicating the object is near

        if distance > 30 and i == 1:  # Check if the object has moved away
            print("Place the object...")
            i = 0  # Reset the state indicating the object is not near
        
        time.sleep(2)  # Delay between measurements

except KeyboardInterrupt:
    print("Measurement stopped by user")
finally:
    GPIO.cleanup()  # Clean up the GPIO pins
