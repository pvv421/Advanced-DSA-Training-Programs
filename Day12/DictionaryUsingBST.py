class Node:
    def __init__(self, key, meaning):
        self.left = None
        self.right = None
        self.word = key
        self.meaning = meaning 

def insert(root, word, meaning):
    if root is None:
        return Node(word, meaning)
    else:
        if root.word == word:
            return root
        elif root.word < word:
            root.right = insert(root.right,word, meaning)
        else:
            root.left = insert(root.left,word, meaning)
    return root

def minValueNode(node):
    current = node 
    while(current.left is not None):
        current = current.left 
    return current

def maxValueNode(node):
    current = node
    while(current.right is not None):
        current = current.right
    return current

def deleteElement(root,key):
    if root is None:
        return root
    if key < root.word:
        root.left = deleteElement(root.left, key)
    elif key > root.word:
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
        temp = maxValueNode(root.left)
        root.word = temp.word
        root.meaning = temp.meaning
        root.left = deleteElement(root.left, temp.word)
    return root

def findMeaning(root, word):
    if root is None:
        return "Word not found!"
    else:
        if root.word == word:
            return root.meaning
        elif root.word < word:
            return findMeaning(root.right, word)
        else:
            return findMeaning(root.left, word)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.word,"=",root.meaning)
        inorder(root.right)

root = Node("Vishnu","Vishnu is a name")
insert(root,"Baseball","It is a sport")
insert(root,"Apple","A fruit")
insert(root,"Ferrari","Car manufacturing company")
insert(root,"Elon Musk","Meme lord")
insert(root,"Birmingham","It is a city")
insert(root,"Tea","It is a drink")
insert(root,"Zebra","It is an animal")
inorder(root)
print(findMeaning(root,"Apple"))
print(findMeaning(root,"Elon Musk"))
print(findMeaning(root,"Banana"))
