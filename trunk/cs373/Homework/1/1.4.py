colors = [['red', 'green', 'green', 'red' , 'red'],
          ['red', 'red', 'green', 'red', 'red'],
          ['red', 'red', 'green', 'green', 'red'],
          ['red', 'red', 'red', 'red', 'red']]

measurements = ['green', 'green', 'green' ,'green', 'green']

motions = [[0,0],[0,1],[1,0],[1,0],[0,1]]

p = []
sensor_right = 0.7
p_move = 0.8

################################################################################

def move2D( p, U ):
    x = len( p )
    y = len( p[0] )
    
    q = []
    for i in range( x ):
        line = []
        for j in range( y ):
            s = p_move * p[i - U[0] % x][j - U[1] % y]
            s = s + ( 1 - p_move ) * p[i][j]
            line.append( s )
        q.append( line )
        
    return q
            
################################################################################

def sense2D( p, Z ):
    x = len( p )
    y = len( p[0] )
    
    q = []
    for i in range( x ):
        line = []
        for j in range( y ):
            hit = ( Z == colors[i][j] )
            line.append( p[i][j] * ( hit * sensor_right + ( 1 - hit ) * ( 1 - sensor_right ) ) )
        q.append( line )

    s = sum( map( sum, q ) )
    for i in range( x ):
        for j in range( y ):
            q[i][j] = q[i][j] / s
    
    return q
    
################################################################################

def init2D( w ):
    x = len( w )
    y = len( w[0] )
    part = x * y
    
    q = []

    for i in range( x ):
        line = []
        for j in range( y ):
            line.append( 1.0 / part )
        q.append( line )
    return q
    
################################################################################

p = init2D( colors )

for k in range( len( measurements ) ):
    p = move2D( p, motions[k] )
    p = sense2D( p, measurements[k] )

################################################################################
	
def show(p):
    for i in range(len(p)):
        print p[i]

################################################################################

show( p )
