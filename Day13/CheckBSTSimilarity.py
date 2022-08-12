#not working
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key 

def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.data == key:
            return root
        elif root.data < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root

def isSameBST(X,Y,m,n):
    if(m!=n):
        return False
    if(m == 0 or m == 1):
        return True
    if(X[0] != Y[0]):
        return False 
    k = 0
    l = 0
    o = 0
    p = 0
    leftX = []
    leftY = []
    rightX = []
    rightY = []
    for i in range(m):
        if(X[i] < X[0]):
            leftX.append(X[i])
            k = k+1
        else:
            rightX.append(X[i])
            l = l+1 
        if(Y[i]<Y[0]):
            leftY.append(Y[i])
            o = o+1
        else:
            rightY.append(Y[i])
            p = p+1
    if(k!=o):
        return False
    if(l!=p):
        return False
    return isSameBST(leftX,leftY,k,o) and isSameBST(rightX, rightY, l, p)

a = [8, 3, 6, 1, 4, 7, 10, 14, 13]
b = [8, 10, 14, 3, 6, 4, 1, 7, 13]
n = len(a)

print(isSameBST(a,b,n,n))
 


        
