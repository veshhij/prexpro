#Define a faster fibonacci procedure that will enable us to computer
#fibonacci(36).

def fibonacci(n):
    if n < 2:
        return n
    prev1 = 0
    prev2 = 1
    for i in range( 1, n ):
        fib = prev1 + prev2
        prev1, prev2 = prev2, fib
    return fib


def t_fibonacci(n):
    current = 0
    after = 1
    for i in range( 0, n ):
        current, after = after, current + after
    return current

print t_fibonacci(36)
#>>> 14930352
