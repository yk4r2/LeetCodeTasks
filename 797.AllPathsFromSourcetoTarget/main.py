class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        paths = []
        stack = [(0, [0])]
        while stack:
            curr_node, path = stack.pop()
            for neighbor in graph[curr_node]:
                if neighbor == len(graph) - 1:
                    paths.append(path + [neighbor])
                else:
                    stack.append((neighbor, path + [neighbor]))
        return paths
