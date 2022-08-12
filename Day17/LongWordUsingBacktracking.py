def backtrack(i,j,board,word,ind,row,col):
    if ind>=len(word):
        return True
    if(i<0 or i>= row or j < 0 or j>= col or board[i][j]!= word[ind]):
        return False
    t = board[i][j]
    board[i][j] = '$'
    if(backtrack(i,j+1,board,word,ind+1,row,col) or backtrack(i+1,j,board,word,ind+1,row,col) or backtrack(i,j-1,board,word,ind+1,row,col) or backtrack(i-1,j,board,word,ind+1,row,col)):
        return True
    board[i][j] = t
    return False

def search(board, word, row, col):
    for i in range(row):
        for j in range(col):
            if(backtrack(i,j,board,word,0,row,col)):
                return True 
    return False 

board = [['A','B','C','E'], 
         ['S','F','C','S'], 
         ['A','D','E','E']]

row = len(board)
col = len(board[0])
word = "ABCCED"
print(search(board,word,row,col))