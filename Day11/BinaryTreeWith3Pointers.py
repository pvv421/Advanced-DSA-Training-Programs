class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.nextSibling = None
        self.data = key

def insert(root, key):
    if(root is None):
        return Node(key)
    else:
        if(root.data == key):
            return root
        elif (root.data < key):
            root.right = insert(root.right, key)
            if(root.left is not None):
                root.left.nextSibling = root.right
                root.right.nextSibling = root.left
        else:
            root.left = insert(root.left, key)
            if(root.right is not None):
                root.left.nextSibling = root.right
                root.right.nextSibling = root.left
    return root 

def sibling(root, key):
    if(root is None):
        return None
    elif(root.data == key):
        if root.nextSibling != None:
            return root.nextSibling.data
        else:
            return None
    else:
        if (root.data < key):
            return sibling(root.right, key)
        else:
            return sibling(root.left, key)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end = " ")
        inorder(root.right)

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

A = [1,2,4,5,7,3,6,999,0]
root = Node(A[0])
for i in range(1,len(A)):
    insert(root, A[i])
inorder(root)
print()
print(sibling(root,2))
print(numberOfLeafNodes(root))
'''   1
    0   2
          4
        3   5
              7
            6   999'''