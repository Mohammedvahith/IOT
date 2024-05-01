import RPi.GPIO as GPIO
from datetime import datetime
import time
import sqlite3
GPIO.setmode(GPIO. BOARD)
TRIG=16
ECHO=18
i=0
GPIO.setwarnings(False)
GPIO.setup(TRIG,GPIO.OUT)
GPIO.setup(ECHO,GPIO.IN)
GPIO.output(TRIG,False)
conn=sqlite3.connect('ultradatabase.db')
cursor=conn.cursor()
conn.execute("DROP TABLE DistData")
cursor.execute("CREATE TABLE DistData(Distance TEXT, Time TEXT, Status TEXT)")
#conn.commit()
#conn.close()
print("calibrating....")
time.sleep(1)
print("Place the object....")
try:
    while True:
        GPIO.output(TRIG,True)
        time.sleep(0.5)
        GPIO.output(TRIG,False)
        while GPIO.input(ECHO)==0:
            pulse_start = time.time()
        while GPIO.input(ECHO)==1:
            pulse_end = time.time()
            pulse_duration = pulse_end - pulse_start
            distance = pulse_duration * 17150
            distance = round(distance+1.15,2)
        if distance <= 25 and distance >=5:
            print("distance",distance,"cm") 
            #print( Status = Near") 
            i=1 
            now = datetime.now()
            tim = now.strftime ("%H.%M.%S %p") 
            print(tim) 
            dist = distance 
            st='Near' 
            conn=sqlite3.connect('ultradatabase.db') 
            cursor=conn.cursor() 
            cursor.execute("INSERT INTO DistData(Distance, Time,Status) VALUES(?,?,?)",(dist,tim, st)) 
            conn.commit() 
            conn.close()
        if distance>25 and i==1: 
            print("distance:",distance,"Cm") 
            #print(" Status = Far") 
            print ("place the object....")
            i=0     
            tim = now.strftime("%H.%M.%S %p") 
            print(tim) 
            dist = distance 
            st ='Far' 
            conn=sqlite3.connect('ultradatabase.db') 
            cursor=conn.cursor()
            cursor.execute("INSERT INTO DistData(Distance,Time,status) VALUES(?,?,?)",(dist,tim,st)) 
            conn.commit() 
            conn.close() 
except KeyboardInterrupt: 
    GPIO.cleanup()