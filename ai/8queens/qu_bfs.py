import pickle

N = 8
total = 0

class Node:
    def __init__(self,board,presentRow):
        self.board = board
        self.presentRow = presentRow

def display(board):
    global total
    total = total + 1
    for i in board:
        for j in i:
            print(j,end=' ')
        print()
    print('\n')

def isSafe(board, row, col):
    for i in range(row):
        if board[i][col] == 1:
            return False

    for i,j in zip(range(row,-1,-1), range(col,-1,-1)):
        if board[i][j] == 1:
            return False

    for i,j in zip(range(row,-1,-1), range(col,N,1)):
        if board[i][j] == 1:
            return False

    return True

def bfs(q):
    while(q):
        rootNode = q.pop(0)
        board = rootNode.board
        row = rootNode.presentRow + 1
        if(row == N):
            display(board)
            while(q):
                node = q.pop(0)
                display(node.board)
            break
        else:
            for i in range(0,N):
                if(isSafe(board,row,i)):
                    tempBoard = pickle.loads(pickle.dumps((board)))
                    tempBoard[row][i] = 1
                    node = Node(tempBoard,row)
                    q.append(node)
    return -1

def main():
    board = [[0 for i in range(N)] for j in range(N)]
    rootNode = Node(board,-1)
    q = []
    q.append(rootNode)
    bfs(q)
    print("total solutions : " + str(total))

if __name__ == "__main__":
    main()
