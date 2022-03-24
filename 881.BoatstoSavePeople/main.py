class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people = sorted(people)
        left, right = 0, len(people) - 1
        answer = 0
        
        while left <= right:
            if people[left] + people[right] <= limit:
                left += 1
            right -= 1
            answer += 1
        return answer

