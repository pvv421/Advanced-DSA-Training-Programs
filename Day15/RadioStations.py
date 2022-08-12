def minCostForStation(a):
    n = len(a)
    c = 0
    u = []
    for x in a.keys():
        u.append(x)
    while(c!=u):
        s = set(a.values())
        alpha = c[s]/abs(s-c)



