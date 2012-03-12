def proc1( p ):####
    p[0] = p[1]

def proc2( p ):
    p = p + [1]
    print 'proc2:', p

def proc3( p ):
    q = p
    #print 'q =', q
    #print 'p =', p
    p.append( 3 )
    #print 'q =', q
    #print 'p =', p
    q.pop()
    #print 'q =', q
    #print 'p =', p

def proc4( p ):
    q = []
    while p:
        q.append( p.pop() )
    while q:
        p.append( q.pop() )


p = [1,2,3,4,5,6,7]
print p
proc1( p )
print p
proc2( p )
print p
proc3( p )
print p
proc4( p )
print p



