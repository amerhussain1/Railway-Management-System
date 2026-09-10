This project manages train reservations using classes and arrays for structured data handling. It allows operations on trains, train classes, capacities, and reservations while ensuring proper data validation and consistency.

# Classes & Data Members
# 1. TrainClass

cid: Unique class ID (int)

cname: Class name (string)

# 2. Train

tid: Unique train ID (int)

cname: Train name (string)

source: Starting station (string)

destination: Ending station (string)

# 3. TrainCapacity

cid: Must exist in TrainClass

tid: Must exist in Train

totalSeats: Total seats available (int)

rate: Fare rate (int)

# 4. Reservations

cid, tid: Must exist in TrainCapacity

date: Travel date (dd/mm/yyyy format)

ticketNo: Auto-generated based on available seats

CNIC: Passenger’s ID (string)

passengerName: Alphabets only (string)

# Operations
# TrainClass

Insert a new class

Update class name (cname)

Delete class (only if unused)

Display all classes or search by cid

# Train

Insert a new train

Update train name (cname)

Delete train (only if unused)

Display all trains or search by tid

# TrainCapacity

Insert train capacity (linked to valid tid and cid)

Update capacity attributes (excluding tid + cid)

Delete capacity (only if unused)

Display all capacities or search by tid + cid

# Reservations

Insert reservation (auto-generates ticketNo)

Update details (excluding tid, cid, ticketNo, date)

Delete reservation

Display all reservations

Search reservations by tid + cid + date

Show available seats for a specific train on a given date
