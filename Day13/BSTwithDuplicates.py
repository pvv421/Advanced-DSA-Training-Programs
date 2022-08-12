class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key
        self.count = 1

def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.data == key:
            root.count = root.count+1
            return root
        elif root.data < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root

def inorder(root):
    if root is not None:
        inorder(root.left)
        print(str(root.data)+"("+str(root.count)+")",end = " ")
        inorder(root.right)

def minValueNode(node):
    current = node 
    while(current.left is not None):
        current = current.left 
    return current

def deleteNode(root, key):
    if root is None:
        return root
    if key < root.data:
        root.left = deleteNode(root.left, key)
    elif key > root.data:
        root.right = deleteNode(root.right, key)
    else:
        if root.count > 1:
            root.count = root.count-1
            return root
        if root.left == None:
            temp = root.right 
            root = None
            return temp
        if root.right == None:
            temp = root.left
            root = None
            return temp
        temp = minValueNode(root)
        root.data = temp.data
        root.count = temp.count
        root.right = deleteNode(root.right, temp.data)
    return root

A = [8,3,5,1,5,9,3,3,14,23,23,11,8,60,23]
root = None
for i in range(len(A)):
    root = insert(root, A[i])
inorder(root)
print()
root = deleteNode(root,3)
root = deleteNode(root,1)
root = deleteNode(root,11)
root = deleteNode(root,3)
root = deleteNode(root,3)
inorder(root)