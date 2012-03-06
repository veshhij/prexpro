def test( a ):
    return a < 5

def proc( a, b ):
    if test( a ):
        return b
    return a

def proc1( x, y ):
    if test( x ):
        return y
    else:
        return x
    
def proc2( a, b ):
    if not test( b ):
        return a
    else:
        return b

def proc3( a, b ):
    result = a
    if test( a ):
        result = b
    return result

def proc4( a, b ):
    if not test( a ):
        b = 'udacity'
    else:
        return b
    return a


print proc( 2, 8 ) == proc1( 2, 8 )
print proc( 160, 180 ) == proc1( 160, 180 )
print proc( 150, 0 ) == proc1( 150, 0 )
print proc( 8, 2 ) == proc1( 8, 2 )
print proc( 180, 160 ) == proc1( 180, 160 )
print proc( 0, 150 ) == proc1( 0, 150 )

print '------------------------------------'

print proc( 2, 8 ) == proc2( 2, 8 )
print proc( 160, 180 ) == proc2( 160, 180 )
print proc( 150, 0 ) == proc2( 150, 0 )
print proc( 8, 2 ) == proc2( 8, 2 )
print proc( 180, 160 ) == proc2( 180, 160 )
print proc( 0, 150 ) == proc2( 0, 150 )

print '------------------------------------'

print proc( 2, 8 ) == proc3( 2, 8 )
print proc( 160, 180 ) == proc3( 160, 180 )
print proc( 150, 0 ) == proc3( 150, 0 )
print proc( 8, 2 ) == proc3( 8, 2 )
print proc( 180, 160 ) == proc3( 180, 160 )
print proc( 0, 150 ) == proc3( 0, 150 )

print '------------------------------------'

print proc( 2, 8 ) == proc4( 2, 8 )
print proc( 160, 180 ) == proc4( 160, 180 )
print proc( 150, 0 ) == proc4( 150, 0 )
print proc( 8, 2 ) == proc4( 8, 2 )
print proc( 180, 160 ) == proc4( 180, 160 )
print proc( 0, 150 ) == proc4( 0, 150 )
