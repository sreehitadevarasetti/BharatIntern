import time

class ParkingSpot:
    def __init__(self, id, status):
        self.id = id
        self.status = status

class ParkingLot:
    def __init__(self, spots):
        self.spots = spots

    def find_empty_spot(self):
        for spot in self.spots:
            if spot.status == "empty":
                return spot
        return None

class ParkingSystem:
    def __init__(self, lot):
        self.lot = lot

    def park(self):
        spot = self.lot.find_empty_spot()
        if spot:
            spot.status = "occupied"
            print(f"Parking at spot {spot.id}")
        else:
            print("Sorry, no spots available")

    def leave(self, spot_id):
        for spot in self.lot.spots:
            if spot.id == spot_id:
                spot.status = "empty"
                print(f"Spot {spot_id} is now empty")
                return
        print(f"Invalid spot ID {spot_id}")

# initialize parking spots
spots = [ParkingSpot(1, "empty"), ParkingSpot(2, "empty"), ParkingSpot(3, "empty")]

# create parking lot
lot = ParkingLot(spots)

# create parking system
system = ParkingSystem(lot)

# simulate parking and leaving
system.park()
time.sleep(2)
system.park()
time.sleep(2)
system.leave(1)
system.park()
