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

def printInRange(root,k1,k2):
    if root:
        if root.data >= k1:
            printInRange(root.left,k1,k2)
        if root.data >= k1 and root.data <= k2:
            print(root.data, end = " ")
        if root.data<= k2:
            printInRange(root.right,k1,k2)

A = [5,9,8,6,10,3,0,1,99,31]
root = Node(A[0])
for i in range(1,len(A)):
    insert(root, A[i])

printInRange(root,5,50)