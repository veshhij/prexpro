#THREE GOLD STARS

#Sudoku [http://en.wikipedia.org/wiki/Sudoku]
#is a logic puzzle where a game
#is defined by a partially filled
#9 x 9 square of digits where each square
#contains one of the digits 1,2,3,4,5,6,7,8,9.
#For this question we will generalize
#and simplify the game.


#Define a procedure, check_sudoku,
#that takes as input a square list
#of lists representing an n x n
#sudoku puzzle solution and returns
#True if the input is a valid
#sudoku square and returns False
#otherwise.

#A valid sudoku square satisfies these
#two properties:

#   1. Each column of the square contains
#       each of the numbers from 1 to n exactly once.

#   2. Each row of the square contains each
#       of the numbers from 1 to n exactly once.

correct = [[1,2,3],
           [2,3,1],
           [3,1,2]]

incorrect = [[1,2,3,4],
             [2,3,1,3],
             [3,1,2,3],
             [4,4,4,4]]

correct2 = [[1,2,3,4],
             [2,3,4,1],
             [3,4,1,2],
             [4,1,2,3]]


def check_rows( s ):
    size = len( s )
    for row in s:
        for i in range( 1, size + 1 ):
            if i not in row:
                return False
    return True

def create( dimx, dimy ):
    t = []
    for i in range( dimx ):
        r = []
        for j in range( dimy ):
            r.append( 0 )
        t.append( r )
    return t
    
def transpose( s ):
    dimx = len( s )
    dimy = len( s[0] )
    t = create( dimx, dimy )
    
    for i in range( dimx ):
        for j in range( dimy ):
            t[j][i] = s[i][j]
    return t
    
def check_sudoku( s ):
    if check_rows( s ):
        t = transpose( s )
        if check_rows( t ):
            return True
    return False

print check_sudoku( correct )
print check_sudoku( incorrect )
print check_sudoku( correct2 )
