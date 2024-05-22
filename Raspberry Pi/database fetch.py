import sqlite3

try:
    # Connect to the SQLite database
    conn = sqlite3.connect('tempdatabase.db')
    
    # Create a cursor object to interact with the database
    cursor = conn.cursor()
    
    # Execute the SELECT query
    cursor.execute("SELECT * FROM TempData WHERE Temperature > 100")
    
    # Fetch and print all records that match the query
    results = cursor.fetchall()
    for row in results:
        print(row)
    
except sqlite3.Error as e:
    print(f"An error occurred: {e}")
finally:
    # Close the connection
    if conn:
        conn.close()
