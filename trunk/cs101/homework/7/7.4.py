#Collatz Returns!


#Define a procedure, collatz_steps, that takes as input a positive integer, n, and returns
#the number of steps it takes to reach 1 by following these steps:

#    If n is even, divide it by 2. (You can test for evenness using n % 2 == 0.)
#    If n is odd, replace it with 3n + 1.

def collatz_steps(n):
    step = 0
    while n != 1:
        step += 1
        if n % 2 == 0:
            n = n / 2
        else:
            n = 3 * n + 1
    return step

        


#For example,

print collatz_steps(1)
#>>> 0

print collatz_steps(2)
#>>> 1

print collatz_steps(6)
#>>> 8

print collatz_steps(101)
#>>> 25
