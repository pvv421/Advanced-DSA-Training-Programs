#not working check later
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key

def buildTree(postorder, startind, endind):
    if startind > endind:
        return None
    root = Node(postorder[buildTree.postindex])
    buildTree.postindex-=1
    if startind == endind:
        return root
    l_root = -1
    for i in range(endind, startind-1, -1):
        if postorder[i] < root.data:
            l_root = i
            break 
    if l_root == -1:
        r_root = buildTree.postindex - (endind-startind)
    root.left = buildTree(postorder,buildTree.postindex,endind-1)
    root.right = buildTree(postorder,startind,buildTree.postindex)
    return root

def BST(preorder):
    n = len(preorder)
    buildTree.postindex = n-1
    return buildTree(preorder,0,n-1)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end = " ")
        inorder(root.right)

A = [10,5,1,7,40,50]
root = BST(A)
inorder(root)  
