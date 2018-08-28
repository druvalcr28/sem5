import pickle

N = 8
total = 0

def display(board):
    global total
    total = total + 1
    for i in board:
        for j in i:
            print(j,end=' ')
        print()
    print('\n')

def isSafe(board,row,col):
    for i in range(col):
        if board[row][i] == 1:
            return 1

    for i,j in zip(range(row,-1,-1), range(col,-1,-1)):
        if board[i][j] == 1:
            return 1

    for i,j in zip(range(row,N,1), range(col,-1,-1)):
        if board[i][j] == 1:
            return 1
    return 0

def dfs(board,col):
    if(col >= N):
        display(board)
        return

    for i in range(N):
        if(isSafe(board, i, col) == 0):
            board[i][col] = 1
            dfs(board, col+1)
            board[i][col] = 0
    return

def main():
    board = [[0 for i in range(N)] for j in range(N)]
    dfs(board,0)
    print("total solutions : " + str(total))

if __name__ == "__main__":
    main()
