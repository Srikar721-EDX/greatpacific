from sys import argv, exit
from cs50 import SQL

if len(argv) != 2:
    print("Incorrect Number of Arguments")
    exit(1)
    
db = SQL("sqlite:///students.db")
entered_house = argv[1]
row = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", entered_house)
for row in row:
    first, middle, last, birth = row["first"], row["middle"], row["last"], row["birth"]
    print(f"{first} {middle + ' ' if middle else ''}{last}, born {birth}")