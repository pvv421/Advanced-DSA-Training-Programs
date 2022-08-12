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

def findMax(root):
    if root is None:
        return None
    else:
        k = root
        while(k.right is not None):
            k = k.right
    return k.data

def findMin(root):
    if root is None:
        return None
    else:
        k = root
        while(k.left is not None):
            k = k.left
    return k.data

def findPreSuc(root, key):
    if root is None:
        return
    if root.data == key:
        if root.left is not None:
            tmp = root.left
            while(tmp.right):
                tmp = tmp.right
            findPreSuc.pre = tmp
        if root.right is not None:
            tmp = root.right
            while(tmp.left):
                tmp = tmp.left
            findPreSuc.suc = tmp
        return
    if root.data > key :
        findPreSuc.suc = root
        findPreSuc(root.left, key) 
    else: 
        findPreSuc.pre = root
        findPreSuc(root.right, key)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end = " ")
        inorder(root.right)


A = [1,2,4,5,7,3,6,999]
root = Node(A[0])
for i in range(1,len(A)):
    insert(root, A[i])
'''   1 
        \
         2
          \
           4
          / \
         3   5
              \
               7
              / \
             6   999'''
findPreSuc.pre = None
findPreSuc.suc = None
key = 5
findPreSuc(root, key)
print("Inorder: ", end = "")
inorder(root)
print()
print("Predecessor:",findPreSuc.pre.data)
print("Successor:",findPreSuc.suc.data)