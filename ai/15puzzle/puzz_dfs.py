import pickle

N = 3

class Node:
    def __init__(self,board,step):
        self.board = board
        self.step = step

def checkMove(target_place,move):
    row = target_place[0]
    col = target_place[1]
    if(move == 0):
        if(row-1 >= 0):
            return True
    if(move == 1):
        if(col+1 < N):
            return True
    if(move == 2):
        if(row+1 < N):
            return True
    if(move == 3):
        if(col-1 >= 0):
            return True
    return False

def findTarget(board):
    ans = []
    for i in range(0,N):
        for j in range(0,N):
            if(board[i][j] == 0):
                ans.append(i)
                ans.append(j)
                return ans

def check(board):
    temp = 1
    for i in range(0,N):
        for j in range(0,N):
            if((i == N-1) and (j == N-1)):
                return True
            if(board[i][j] != temp):
                return False
            else:
                temp = temp + 1
    return True

def bfs(q,visited):
    while(1):
        rootNode = q.pop(len(q)-1)
        board = rootNode.board
        step = rootNode.step + 1
        visited.append(board)
        if(check(board)):
            print(step)
            return
        else:
            tempList = []
            target_place = []
            target_place = findTarget(board)
            row = target_place[0]
            col = target_place[1]
            if(checkMove(target_place,0)): # check if down move is possible.
                tempBoard = pickle.loads(pickle.dumps((board)))
                tempBoard[row][col] = tempBoard[row-1][col]
                tempBoard[row-1][col] = 0
                node = Node(tempBoard,step)
                if(node.board not in visited):
                    q.append(node)
                    print(node.board)

            if(checkMove(target_place,1)): # check if left move is possible.
                tempBoard = pickle.loads(pickle.dumps((board)))
                tempBoard[row][col] = tempBoard[row][col+1]
                tempBoard[row][col+1] = 0
                node = Node(tempBoard,step)
                if(node.board not in visited):
                    q.append(node)
                    print(node.board)
            if(checkMove(target_place,2)): # check if upper move is possible.
                tempBoard = pickle.loads(pickle.dumps((board)))
                tempBoard[row][col] = tempBoard[row+1][col]
                tempBoard[row+1][col] = 0
                node = Node(tempBoard,step)
                if(node.board not in visited):
                    q.append(node)
                    print(node.board)
            if(checkMove(target_place,3)): # check if right move is possible.
                tempBoard = pickle.loads(pickle.dumps((board)))
                tempBoard[row][col] = tempBoard[row][col-1]
                tempBoard[row][col-1] = 0
                node = Node(tempBoard,step)
                if(node.board not in visited):
                    q.append(node)
                    print(node.board)


def main():
    board = [[7,3,4],[0,2,1],[5,8,6]]
    # board = [[1,2,3,4],[0,5,7,8],[10,6,11,12],[9,13,14,15]]
    # board = [[2,5,6],[1,8,4],[7,0,3]]
    # board = [[3,0,4],[1,7,6],[5,2,8]]
    rootNode = Node(board,-1)
    q = []  # defining stack
    visited = []
    q.append(rootNode)
    bfs(q,visited)

if __name__ == "__main__":
    main()
