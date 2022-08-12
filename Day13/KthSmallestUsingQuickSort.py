def kthSmallest(arr, l, r, k):
    if (k > 0 and k <= r - l + 1):
        pos = partition(arr, l, r)
        if (pos - l == k - 1):
            return arr[pos]
        if (pos - l > k - 1): 
            return kthSmallest(arr, l, pos - 1, k)
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1)
    return "Element Not Present"

def partition(arr, l, r): 
    x = arr[r]
    i = l
    for j in range(l, r):
        if (arr[j] <= x):
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[r] = arr[r], arr[i]
    return i

A = [99,21,1,103,131,232,12,81,0]
#A = [0,0,0,0,0,0,0]
n = len(A)
k = 3
print(kthSmallest(A,0,n-1,k))