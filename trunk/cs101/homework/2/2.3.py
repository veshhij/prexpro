# Define a procedure, median, that takes three
# numbers as its inputs, and outputs the median
# of the three numbers.

# Make sure your procedure has a return statement.

def bigger(a,b):
    if a > b:
        return a
    else:
        return b
        
def biggest(a,b,c):
    return bigger(a,bigger(b,c))

def median( a, b, c ):
    bn = biggest( a, b, c )
    if a == bn:
        return bigger( b, c )
    if b == bn:
        return bigger( a, c )
    return bigger( a, b )

##################################################

print median( 9, 6, 3 )
print median( 8, 7, 7 )
print median( 1, 2, 3 )
print median( 900, 901, 899 )
print median( 0, 0, 0 )
print median( -9, 6, -3 )
print median( -90, -90, 0 )
