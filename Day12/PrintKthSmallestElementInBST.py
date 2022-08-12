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

def kthSmallestutil(root):     
    if (root == None):
        return None
    left = kthSmallestutil(root.left)
    if (left != None):
        return left
    kthSmallestutil.k -= 1
    if (kthSmallestutil.k == 0):
        return root
    return kthSmallestutil(root.right)

def kthSmallest(root, k):
    kthSmallestutil.k = k
    return kthSmallestutil(root)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end = " ")
        inorder(root.right)

A = [5,9,8,6,10,3,0,1,99,31]
root = Node(A[0])
for i in range(1,len(A)):
    insert(root, A[i])

inorder(root)
print()
k = 10
ans = kthSmallest(root,k)
if ans is not None:
    print(ans.data)
else:
    print("Tree has less than",k,"nodes.")