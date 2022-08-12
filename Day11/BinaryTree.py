class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
  
def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.val == key:
            return root
        elif root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)

def preorder(root):
    if root:
        print(root.val, end= " ")
        preorder(root.left)
        preorder(root.right)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end = " ")
        inorder(root.right)

def sumOfTree(root):
    if root is None:
        return 0
    else:
        return root.val+sumOfTree(root.left)+sumOfTree(root.right)

def levelorder(root):
    queue = []
    if(root is None):
        return
    queue.append(root)
    while(len(queue)!=0):
        temp =  queue[0]
        queue.pop(0)
        print(temp.val, end = " ")
        if(temp.left is not None):
            queue.append(temp.left)
        if(temp.right is not None):
            queue.append(temp.right)

def maxelement(root):
    if(root is None):
        return -1
    if(root.right.right is None):
        return root.right.val
    return maxelement(root.right)

def maxelementLR(root):
    left = root.left
    right = root.right
    data = root.val
    max1 = maxelement(left)
    max2 = maxelement(right)
    return max(max1,max2,data)

def MaxElementUsingLevelOrder(root):
    queue = []
    if(root is None):
        return -1
    max = -1
    queue.append(root)
    while(len(queue)!=0):
        temp = queue[0]
        queue.pop(0)
        if temp.val > max:
            max = temp.val
        if(temp.left is not None):
            queue.append(temp.left)
        if(temp.right is not None):
            queue.append(temp.right)
    return max

def sizeOfBST(root):
    count = 0
    queue = []
    if(root is None):
        return count
    queue.append(root)
    while(len(queue)!=0):
        temp = queue[0]
        count+=1
        queue.pop(0)
        if(temp.left is not None):
            queue.append(temp.left)
        if(temp.right is not None):
            queue.append(temp.right)
    return count

def height(root):
    if(root is None):
        return 0
    lheight = height(root.left)
    rheight = height(root.right)
    return max(lheight+1,rheight+1)

def reverselevelorder(root):
    queue = []
    stack = []
    if(root is None):
        return
    queue.append(root)
    while(len(queue)!=0):
        temp =  queue[0]
        queue.pop(0)
        stack.append(temp.val)
        if(temp.left is not None):
            queue.append(temp.left)
        if(temp.right is not None):
            queue.append(temp.right)
    while(len(stack)!=0):
        print(stack[-1], end = " ")
        stack.pop(-1)

def minValueNode(node):
    current = node 
    while(current.left is not None):
        current = current.left 
    return current

def deleteElement(root,key):
    if root is None:
        return root
    if key < root.val:
        root.left = deleteElement(root.left, key)
    elif(key > root.val):
        root.right = deleteElement(root.right, key)
    else:
        if root.left is None:
            temp = root.right
            root = None
            return temp 
        elif root.right is None:
            temp = root.left
            root = None
            return temp
        temp = minValueNode(root.right)
        root.val = temp.val
        root.right = deleteElement(root.right, temp.val)
    return root

def numberOfLeafNodes(root):
    count = 0
    if root is None:
        return 1
    queue = []
    queue.append(root)
    while(len(queue)!=0):
        temp = queue[0]
        queue.pop(0)
        if temp.left == None and temp.right == None:
            count+=1
        if (temp.left is not None):
            queue.append(temp.left)
        if (temp.right is not None):
            queue.append(temp.right)
    return count

def checkIdentical(root1, root2): #this function is not working
    if root1 == None and root2 == None:
        return 1
    elif root1 == None or root2 == None:
        return 'False'
    ltree1 = root1.left
    rtree1 = root1.right
    ltree2 = root2.left
    rtree2 = root2.right
    if((ltree1 is not None and ltree2 is not None) or (ltree1 is None and ltree2 is None)):
        if((rtree1 is not None and rtree2 is not None) or (rtree1 is None and rtree2 is None)):
            checkIdentical(ltree1,ltree2)
            checkIdentical(rtree1,rtree2)
        else:
            return 'False'
    else:
        return 'False'
    return 'True'

def printallRootToLeafPaths(root):
    path = []
    printPathsRec(root, path, 0)

def printPathsRec(root, path, pathLen):
    if root is None:
        return
    if(len(path) > pathLen):
        path[pathLen] = root.val
    else:
        path.append(root.val)
    pathLen = pathLen + 1 
    if root.left is None and root.right is None:
        print(path)
    else:
        printPathsRec(root.left, path, pathLen)
        printPathsRec(root.right, path, pathLen)
        

A = [1,2,4,5,7,3,6,999]
root = Node(A[0])
for i in range(1,len(A)):
    insert(root, A[i])
#preorder(root)
inorder(root)
print()
#print(numberOfLeafNodes(root))
#print(maxelementLR(root))
#print(MaxElementUsingLevelOrder(root))
#print(sizeOfBST(root))
#print(height(root))
printallRootToLeafPaths(root)
'''s = sumOfTree(root)
print(s)'''
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


'''B = [10,20,40,50,70,30,60,999,21]
root2 = Node(B[0])
for i in range(1,len(B)):
    insert(root2 ,B[i])
print(checkIdentical(root,root2))'''
''' 10
      20
        40
     30    50
   21    60   70 
                999''' 









