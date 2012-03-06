# Define a procedure, countdown, that takes a
# positive whole number as its input, and prints 
# out a countdown from that number to 1, 
# followed by Blastoff! 

def countdown( n ):
    if n < 1:
        return
    while 0 < n:
        print n
        n = n - 1
    print 'Blastoff!'


#-------------------------------------------------

countdown( -9 )
