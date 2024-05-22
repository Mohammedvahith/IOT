import sqlite3

# Connect to the SQLite database
conn = sqlite3.connect('tempdatabase.db')

# Create a cursor object to interact with the database
cursor = conn.cursor()

# Create the TempData table
try:
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS TempData (
        Temperature REAL,
        Time REAL,
        Status TEXT
    )
    ''')
    conn.commit()
    print("Table is Created")
except sqlite3.Error as e:
    print(f"An error occurred: {e}")

# Close the connection
conn.close()
