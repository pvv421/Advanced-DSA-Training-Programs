class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key

def inorder(root):
    if root:
        inorder(root.left)
        inorder.array.append(root.data)
        inorder(root.right)

def getinorder(root):
    inorder.array = []
    inorder(root)
    return inorder.array

def checkBST(root):
    k = getinorder(root)
    for i in range(0,len(k)):
        for j in range(i+1, len(k)):
            if k[i]>k[j]:
                return False
    return True

root = Node(5)
root.left = Node(3)
root.left.right = Node(4)
root.right = Node(100)
root.right.left = Node(50)
root.right.left.left = Node(25)
root.right.right = Node(1000)
print(checkBST(root))