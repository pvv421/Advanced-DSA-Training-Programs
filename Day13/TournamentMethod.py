def maxAndSequence(lo, hi, seq):
        if lo >= hi:
            return seq[lo], []
        mid = lo + (hi - lo) // 2
        x, a = maxAndSequence(lo, mid, seq)
        y, b = maxAndSequence(mid + 1, hi, seq)

        if x > y:
            a.append(y)
            return x, a
        b.append(x)
        return y, b

def findSecondLargest(arr):
    n = len(arr)
    a,B = maxAndSequence(0,n-1,arr)
    ans,b = maxAndSequence(0,len(B)-1,B)
    return ans

A = [99,21,1,103,131,232,12,81,0]
n = len(A)
print(findSecondLargest(A))