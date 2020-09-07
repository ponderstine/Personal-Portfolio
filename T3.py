
import random #time

def userTurn(board):
    
    done = True
    while done:

        row,column = 0,0
        tre = (1,2,3)

        while row == 0:
            row = input('Top (1), middle (2), or bottom (3)? ')
            row = int(row)
            if row not in tre:
                row = 0


        while column == 0:
            column = input('Left (1), center (2), or right (3)? ')
            column = int(column)
            if column not in tre:
                column = 0
        
    
        if board[row-1][column-1] == 0:
            board[row-1][column-1] = 'X'
            done = False
        else:
            print('Space is already taken. Pick again.')
            
def compTurn(board):
    
    done = True
    while done:

        row = random.randint(0, 2)
        column = random.randint(0, 2)
        
    
        if board[row][column] == 0:
            board[row][column] = 'O'
            done = False

def checkWinU(board):
    if board[0] == ['X', 'X', 'X']:
        return 'User'
    elif board[1] == ['X', 'X', 'X']:
        return 'User'
    elif board[2] == ['X', 'X', 'X']:
        return 'User'
    elif board[0][0] == str('X') and board[1][0] == str('X') and board[2][0] == str('X'):
        return 'User'
    elif board[0][1] == str('X') and board[1][1] == str('X') and board[2][1] == str('X'):
        return 'User'
    elif board[0][2] == str('X') and board[1][2] == str('X') and board[2][2] == str('X'):
        return 'User'
    elif board[0][0] == str('X') and board[1][1] == str('X') and board[2][2] == str('X'):
        return 'User'
    elif board[2][0] == str('X') and board[1][1] == str('X') and board[0][2] == str('X'):
        return 'User'
    else:
        return None
    
def checkWinC(board):
    if board[0] == ['O', 'O', 'O']:
        return 'Computer'
    elif board[1] == ['O', 'O', 'O']:
        return 'Computer'
    elif board[2] == ['O', 'O', 'O']:
        return 'Computer'
    elif board[0][0] == str('O') and board[1][0] == str('O') and board[2][0] == str('O'):
        return 'Computer'
    elif board[0][1] == str('O') and board[1][1] == str('O') and board[2][1] == str('O'):
        return 'Computer'
    elif board[0][2] == str('O') and board[1][2] == str('O') and board[2][2] == str('O'):
        return 'Computer'
    elif board[0][0] == str('O') and board[1][1] == str('O') and board[2][2] == str('O'):
        return 'Computer'
    elif board[2][0] == str('O') and board[1][1] == str('O') and board[0][2] == str('O'):
        return 'Computer'
    else:
        return None

def main():
    board = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    winner = None
    turn = 0

    print()
    print('New Game')
    print()
    print(board[0])
    print(board[1])
    print(board[2])
    print()
    print('User is X, computer is O')

    while winner == None and turn <10:
        print("""
              User's turn
              """)
        turn +=1
        userTurn(board)
        print()
        print(board[0])
        print(board[1])
        print(board[2])
        winner = checkWinU(board)
        if winner != None or turn>=9:
            break
        #time.sleep(5)
        print("""
              Computer's Turn
              """)
        turn +=1
        #time.sleep(5)
        compTurn(board)
        print(board[0])
        print(board[1])
        print(board[2])
        winner = checkWinC(board)

    print()
    if winner == None:
        print("It's a tie. Try again.")
    elif winner == 'User':
        print('You Win!')
        #playsound('win.mp3')
    else:
        print('The computer won. Better luck next time.')
        #playsound('lose.mp3')

    play = True
    while play:
        ans = input('Do you want to play again? (y/n) :')
        if ans == str('y'):
            print("Let's play again")
            return True
        elif ans == str('n'):
            play = False
            print('Thanks for playing!')
            return False
        else:
            print('Input error: Please type y or n for your answer.')

playing = True
while playing:
    playing = main()