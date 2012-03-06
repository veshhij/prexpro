# Define a procedure, find_last, that takes as input
# two strings, a search string and a target string,
# and outputs the last position in the search string
# where the target string appears, or -1 if there
# are no occurences.
#
# Example: find_last('aaaa', 'a') returns 3

# Make sure your procedure has a return statement.

def find_last( s, t ):
    sp = 0
    while True:
        fp = s.find( t, sp )
        if fp == -1:
            break
        sp = fp + 1
    return sp - 1

#-------------------------------------------------

danton = "De l'audace, encore de l'audace, toujours de l'audace"
print find_last(danton, 'audace') #=> 25
print find_last(danton, 'au45dace') #=> 25
print find_last('www555rrw', 'w') #=> 25
