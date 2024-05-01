import sqlite3
conn=sqlite3.connect('tempdatebase.db')
cursor=conn.cursor()
cursor.execute("SELECT * from TempData Where Temperature > 100")
print(cursor.fetchall())
conn.commit()
conn.close()