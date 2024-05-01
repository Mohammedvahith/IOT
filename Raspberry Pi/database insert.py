import sqlite3
conn=sqlite3.connect('tempdatebase.db')
cursor=conn.cursor()
cursor.execute('''INSERT INTO TempData(Temperature, Time, Status) VALUES (96,1.11,Normal)''')
conn.commit()
print("Table is Inserted")
conn.close()
