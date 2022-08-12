def SumOfSub(s,k,r,W,M,n):
    x = [0 for i in range(k+1)]
    x[k] = 1
    if(s+W[k] == M):
        print(x[0:k])
    elif(s+W[k]<=M):
        SumOfSub(s+W[k],k+1,r-W[k],W,M,n)
    if((s+r-W[k]>=M) and (s+W[k+1]<=M)):
        x[k] = 0
        SumOfSub(s,k+1,r-W[k],W,M,n)
n = 4
W = [11,13,24,7]
M = 31
SumOfSub(W[0],0,4,W,M,n)