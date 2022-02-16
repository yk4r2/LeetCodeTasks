# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
#class Robot:
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """
from typing import Tuple


class Solution:
    
    def return_back(self) -> None:
        self.robot.turnRight()
        self.robot.turnRight()
        self.robot.move()
        self.robot.turnRight()
        self.robot.turnRight()
        
    def backtrack(
        self,
        cell: Tuple[int, int] = (0, 0),
        direction: int = 0,
    ) -> None:
        self.visited.add(cell)
        self.robot.clean()
        for vector in range(4):
            new_vec = (direction + vector) % 4
            new_cell = (cell[0] + self.directions[new_vec][0], \
                        cell[1] + self.directions[new_vec][1],
                        )
            if not new_cell in self.visited and self.robot.move():
                self.backtrack(new_cell, new_vec)
                self.return_back()
            self.robot.turnRight()
        
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        self.directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        self.robot = robot
        self.visited = set()
        self.backtrack()
