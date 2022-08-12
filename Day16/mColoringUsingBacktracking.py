def isSafe(graph, color):
    for i in range(4):
        for j in range(i+1, 4):
            if (graph[i][j] and color[j] == color[i]):
                return False
    return True 

def graphColoring(graph, m, i, color):
    if i == 4: 
        if(isSafe(graph, color)):
            printSolution(graph, color)
            return True 
        return False 
    for j in range(1, m+1):
        color[i] = j
        