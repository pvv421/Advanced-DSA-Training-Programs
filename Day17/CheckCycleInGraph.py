from collections import defaultdict 

class Graph:
    def __init__(self,vertices):
        self.V = vertices
        self.graph = defaultdict(list)

    def addEdge(self,u,v):
        self.graph[u].append(v)

    def find(self, parent, i):
        if parent[i] == -1:
            return i
        if parent[i] != -1:
            return self.find(parent,parent[i])    
    
    def union(self,parent,x,y):
        parent[x] = y

    def isCyclic(self):
        parent = [-1]*(self.V)
        for i in self.graph:
            for j in self.graph[i]:
                x = self.find(parent, i)
                y = self.find(parent, j)
                if x == y:
                    return True
                self.union(parent,x,y)

V = 3
graph = Graph(V)
graph.addEdge(0,1)
graph.addEdge(0,2)
graph.addEdge(1,2)

if graph.isCyclic():
    print("Cyclic")
else:
    print("Not Cyclic")
