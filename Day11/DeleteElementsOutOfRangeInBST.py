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

def deleteOutOfRange(root, Min, Max):
    if root is None:
        return root 
    root.left = deleteOutOfRange(root.left, Min, Max)
    root.right = deleteOutOfRange(root.right, Min, Max)
    if root.data < Min:
        rChild = root.right
        return rChild
    elif root.data > Max:
        lChild = root.left
        return lChild
    return root 

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end = " ")
        inorder(root.right)
        
A = [9,21,33,55,67,32,56,65,63,0,1,8,99]
root = None 
for i in range(len(A)):
    root = insert(root,A[i])
inorder(root)
print()
root = deleteOutOfRange(root, 50, 80)
inorder(root)