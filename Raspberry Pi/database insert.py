import sqlite3

try:
    # Connect to the SQLite database
    conn = sqlite3.connect('tempdatabase.db')
    
    # Create a cursor object to interact with the database
    cursor = conn.cursor()
    
    # Execute the INSERT query
    cursor.execute('''INSERT INTO TempData (Temperature, Time, Status) VALUES (96, 1.11, 'Normal')''')
    
    # Commit the transaction
    conn.commit()
    
    print("Record inserted successfully")
except sqlite3.Error as e:
    print(f"An error occurred: {e}")
finally:
    # Close the connection
    if conn:
        conn.close()
