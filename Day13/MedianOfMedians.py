#incomplete

def FindMedian(arr, l, n):
    templist= []
    for i in range(l, l+n):
        templist.append(arr[i])
    templist.sort()
    return templist[n//2]

def swap(arr, a , b):
    temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp 
