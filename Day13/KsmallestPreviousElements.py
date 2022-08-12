#not working
def kSmallestElements(a, low, high, k, n):
    if (low == high):
        return
    else:
        pivotIndex = (low+high)//2
        if (k == pivotIndex):
            print(str(k)+ " smallest elements are :",end=" ")
            for i in range(pivotIndex):
                print(a[i],end = "  ")  
        elif (k < pivotIndex):
            kSmallestElements(a, low, pivotIndex - 1, k, n)
  
        elif (k > pivotIndex):
            kSmallestElements(a, pivotIndex + 1, high, k, n)
    
A = [99,21,1,103,131,232,12,81,0]
#A = [0,0,0,0,0,0,0]
n = len(A)
k = 3
kSmallestElements(A,0,n-1,k,n)