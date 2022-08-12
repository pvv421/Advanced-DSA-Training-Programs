class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None
    
def buildTree(In, post, inStrt, inEnd, pIndex):
    if (inStrt > inEnd):
        return None
    node = Node(post[pIndex[0]])
    pIndex[0] -= 1
    if (inStrt == inEnd):
        return node
    iIndex = search(In, inStrt, inEnd, node.data) 
    node.right = buildTree(In, post, iIndex + 1, inEnd, pIndex)
    node.left = buildTree(In, post, inStrt, iIndex - 1, pIndex) 
    return node

'''def buildtree(In, post, n):
    pIndex = [n - 1]
    return buildTree(In, post, 0, n - 1, pIndex)'''

def search(arr, strt, end, value):
    i = 0
    for i in range(strt, end + 1):
        if (arr[i] == value):
            break
    return i

def inorder(root):
    if(root):
        inorder(root.left)
        print(root.data, end = " ")
        inorder(root.right)

def postorder(root):
    if(root):
        postorder(root.left)
        postorder(root.right)
        print(root.data, end= " ")

In = [4, 8, 2, 5, 1, 6, 3, 7]
post = [8, 4, 5, 2, 6, 7, 3, 1]
n = len(In)
p = [n-1]
root = buildTree(In, post, 0, n-1, p)
postorder(root)

 