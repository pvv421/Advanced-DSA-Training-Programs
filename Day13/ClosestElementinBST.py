import sys
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

def findClosest(root, k):
    if root:
        findClosest(root.left, k)
        key = root.data
        diff = abs(key-k)
        if diff < findClosest.mindiff:
            findClosest.mindiff = diff
            findClosest.answer = root.data
        findClosest(root.right, k)

def findClosestElement(root, k):
    findClosest.mindiff = sys.maxsize
    findClosest.answer = None 
    findClosest(root, k)
    return findClosest.answer

A = [1,2,4,5,7,3,6,999,81,32,24,37,35]
root = Node(A[0])
for i in range(1,len(A)):
    insert(root, A[i])

print(findClosestElement(root,36))