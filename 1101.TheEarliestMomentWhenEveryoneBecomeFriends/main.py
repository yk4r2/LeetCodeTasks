class UnionFind:
    def __init__(self, size):
        self.group = [group_id for group_id in range(size)]
        self.rank = [0] * size
    
    def find(self, person):
        if self.group[person] != person:
            self.group[person] = self.find(self.group[person])
        return self.group[person]
    
    def union(self, left, right):
        group_l = self.find(left)
        group_r = self.find(right)
        if group_l == group_r:
            return False
        
        if self.rank[group_l] > self.rank[group_r]:
            self.group[group_r] = group_l
        elif self.rank[group_l] < self.rank[group_r]:
            self.group[group_l] = group_r
        else:
            self.group[group_l] = group_r
            self.rank[group_r] += 1    
        return True


class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        logs.sort(key = lambda x: x[0])
        uf = UnionFind(n)
        group_cnt = n
        
        for timestamp, friend_l, friend_r in logs:
            if uf.union(friend_l, friend_r):
                group_cnt -= 1
            if group_cnt == 1:
                return timestamp
        return -1
