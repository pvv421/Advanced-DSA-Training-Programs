class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def buildTree(inOrder, preOrder, inStrt, inEnd):     
    if (inStrt > inEnd):
        return None
    tNode = Node(preOrder[buildTree.preIndex])
    buildTree.preIndex += 1
    if inStrt == inEnd :
        return tNode
    inIndex = search(inOrder, inStrt, inEnd, tNode.data)
    tNode.left = buildTree(inOrder, preOrder, inStrt, inIndex-1)
    tNode.right = buildTree(inOrder, preOrder, inIndex + 1, inEnd) 
    return tNode

def search(arr, start, end, value):
    for i in range(start, end + 1):
        if arr[i] == value:
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
inOrder = ['D','B','E','A','F','C']
preOrder = ['A','B','D','E','C','F']
buildTree.preIndex = 0
root = buildTree(inOrder, preOrder, 0, len(inOrder)-1) 
inorder(root)
print()
postorder(root)