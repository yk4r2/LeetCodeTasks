class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        self.flightMap = defaultdict(list)
        for origin, dest in tickets:
            self.flightMap[origin].append(dest)
        
        for origin, possibilities in self.flightMap.items():
            possibilities.sort(reverse=True)
        
        self.result = []
        self.DFS('JFK')
        return self.result[::-1]

    def DFS(self, origin):
        destinations = self.flightMap[origin]
        while destinations:
            next_dest = destinations.pop()
            self.DFS(next_dest)
        self.result.append(origin)
