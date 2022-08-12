class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key

def buildTree(preorder, startind, endind):
    if startind > endind:
        return None
    root = Node(preorder[buildTree.preindex])
    buildTree.preindex+=1
    if startind == endind:
        return root
    r_root = -1
    for i in range(startind, endind+1):
        if preorder[i] > root.data:
            r_root = i
            break 
    if r_root == -1:
        r_root = buildTree.preindex + (endind-startind)
    root.left = buildTree(preorder,buildTree.preindex,r_root-1)
    root.right = buildTree(preorder,r_root,endind)
    return root

def BST(preorder):
    n = len(preorder)
    buildTree.preindex = 0
    return buildTree(preorder,0,n-1)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end = " ")
        inorder(root.right)

A = [10,5,1,7,40,50]
root = BST(A)
inorder(root)  
