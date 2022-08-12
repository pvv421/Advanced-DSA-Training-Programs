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

def increasingOrderSearchTree(root):
    if root is None:
        return
    increasingOrderSearchTree(root.left)
    increasingOrderSearchTree.root = insert(increasingOrderSearchTree.root, root.data)
    increasingOrderSearchTree(root.right)

def makeIncreasingOrder(root):
    increasingOrderSearchTree.root = None
    increasingOrderSearchTree(root)
    return increasingOrderSearchTree.root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end = " ")
        inorder(root.right)

def checkIncreasingOrder(root):
    current = root
    while(current != None):
        print(current.data, end = " ")
        current = current.right

def preorder(root):
    if root:
        print(root.data, end = " ")
        preorder(root.left)
        preorder(root.right)

def increasingOrder(root):
    if root is None:
        return 
    root = increasingOrder(root.left)
    root.left.right = root
    root = root.left
    
        
A = [9,21,33,55,67,32,56,65,63,0,1,8,99]
root = None 
for i in range(len(A)):
    root = insert(root,A[i])
preorder(root)
print()
root = makeIncreasingOrder(root)
preorder(root)