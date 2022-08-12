#Converting the BST into a sorted DLL without using extra space
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

prev = None
def BSTtoDLL(root):
    if root is None:
        return root
    head = BSTtoDLL(root.left)
    global prev
    if prev is None:
        head = root 
    else:
        root.left = prev
        prev.right = root
    prev = root
    BSTtoDLL(root.right)
    return head

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end = " ")
        inorder(root.right)

def display(node):
    if node is None:
        return
    start = node
    while(start is not None):
        print(start.data,end = " ")
        start = start.right

A = [5,9,8,6,10,3,0,1,99,31]
root = Node(A[0])
for i in range(1,len(A)):
    insert(root, A[i])
print("BST:", end = " ")
inorder(root)
print()
head = BSTtoDLL(root)
print("DLL:", end = " ")
display(head)