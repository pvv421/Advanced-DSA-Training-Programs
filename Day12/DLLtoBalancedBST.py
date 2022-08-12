#not working
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key

def insert(root,key):
    if root is None:
        return Node(key)
    n = Node(key)
    k = root
    while(k.right is not None):
        k = k.right
    k.right = n 
    n.left = k
    return root

def size(root):
    if root is None:
        return 0
    current = root
    count = 1
    while(current is not None):
        current = current.next
        count += 1
    return count

def findNode(root,index):
    k = root
    for i in range(1,index):
        k = k.right
    return k

def constructBST(root, left, right):
    mid = (left+right)//2
    if(left>right):
        return 
    head = findNode(mid)
    head.left = constructBST(root,left,mid-1)
    head.right = constructBST(root,mid+1,right)
    return head

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end = " ")
        inorder(root.right)

root = Node(1)
insert(root, 2)
insert(root, 3)
insert(root, 4)
insert(root, 5)
insert(root, 6)
insert(root, 7)
insert(root, 8)
insert(root, 9)
c = size(root)
print(c)
ans = constructBST(root, 0 , c)
inorder(ans)