class Node:
    def __init__(self, value):
        self.vertex = value 
        self.next = None 

class Graph:
    def __init__(self, num):
        self.V = num 
        self.graph = [None]*self.V
    
    def addEdge(self, s, d):
        node = Node(d)
        node.next = self.graph[s]
        self.graph[s] = node 

        node = Node(s)
        node.next = self.graph[d]
        self.graph[d] = node 

    def printGraph(self):
        for i in range(self.V):
            print("Vertex " + str(i) + ":", end="")
            temp = self.graph[i]
            while temp:
                print(" -> {}".format(temp.vertex), end="")
                temp = temp.next
            print(" \n")

V = 7
graph = Graph(V)
graph.addEdge(0,1)
graph.addEdge(0,2)
graph.addEdge(0,3)
graph.addEdge(0,5)
graph.addEdge(1,2)
graph.addEdge(1,4)
graph.addEdge(1,6)
graph.addEdge(2,3)
graph.addEdge(2,4)
graph.addEdge(3,4)
graph.addEdge(3,5)
graph.addEdge(4,5)
graph.addEdge(4,6)
graph.addEdge(5,6)
graph.printGraph()
