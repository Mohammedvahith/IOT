import sqlite3
conn=sqlite3.connect('tempdatebase.db')
cursor=conn.cursor()
cursor.execute(''' CREATE TABLE TempData(Temperature FLOAT,Time FLOAT,Status VARCHAR(10))''')
#cursor.execute('''INSERT INTO Tempdata(Temperature, Time, Status) VALUES (134, 12.18, 'High')''')
conn.commit()
print("Table is Created")
conn.close()