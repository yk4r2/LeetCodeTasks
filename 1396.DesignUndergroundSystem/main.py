class UndergroundSystem:
    def __init__(self):
        self.stations = defaultdict(lambda: [0, 0])
        self.checkins = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkins[id] = [stationName, t]

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        in_station, in_time = self.checkins.pop(id)
        self.stations[(in_station, stationName)][0] += (t - in_time)
        self.stations[(in_station, stationName)][1] += 1

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        total, trips = self.stations[(startStation, endStation)]
        return total / trips

