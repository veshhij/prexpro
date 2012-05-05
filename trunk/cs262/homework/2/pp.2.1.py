# Bonus Practice: Find Max

# This assignment is not graded and we encourage you to experiment. Learning is
# fun!

# Given a list l and a function f, return the element of l that maximizes f.

# Assume:
#    l is not empty
#    f returns a number

# Example:

l = ['Barbara', 'kingsolver', 'wrote', 'The', 'Poisonwood','Bible']
f = len

#l = [-100, -50, 20, -101, 99, 6]
#f = abs

# Try it on your own!
def findmax( f, l ):
    r = map( f, l )
    return l[ r.index( max( r ) ) ]

print findmax( lambda( word ): word.find( "d" ), l )
