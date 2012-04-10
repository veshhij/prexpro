def bigger(a,b):
    if a > b:
        return a
    else:
        return b
        
def biggest(a,b,c):
    return bigger(a,bigger(b,c))

def median( a, b, c, array ):
    bn = biggest( array[a], array[b], array[c] )
    if array[a] == bn:
        return bigger( array[b], array[c] )
    if array[b] == bn:
        return bigger( array[a], array[c] )
    return bigger( array[a], array[b] )

def choose_first_pivot( array, left, right ):
    return left

def choose_last_pivot( array, left, right ):
    return right

def choose_median_pivot( array, left, right ):
    med = left + ( right - left ) / 2
    med_value = median( left, med, right, array )
    if array[left] == med_value:
        return left
    if array[right] == med_value:
        return right
    return med

def partioning( array, left, right, pivot_index ):
    array[left], array[pivot_index] = array[pivot_index], array[left]
    pivot = array[left]
    i = left + 1
    for j in range( left + 1, right + 1 ):
        if array[j] < pivot:
            array[i], array[j] = array[j], array[i]
            i += 1
    array[left], array[i - 1] = array[i - 1], array[left]
    #print array[left:right+1]
    return i - 1 - left, right - i + 1

def quick_sort( array, left, right, choose_pivot ):
    if ( right - left ) > 0:
        pivot_index = choose_pivot( array, left, right )
        global total
        total += ( right - left )
        left_size, right_size = partioning( array, left, right, pivot_index )
        #if left_size > 1:
        #total += ( left_size - 1 )
        #if right_size > 1:
        #total += ( right_size - 1 )
        #print left_size, right_size
        #print "left:", array[left:left+left_size]
        #print "right:", array[left+left_size+1:right+1]
        quick_sort( array, left,                 left + left_size - 1, choose_pivot )
        quick_sort( array, left + left_size + 1, right,                choose_pivot )

def count( array, chooser ):
    global total
    total = 0
    quick_sort( array, 0, len( array ) - 1, chooser )
    print total

def to_int( s ):
    return int( s )

"""
A = [1, 2, 3, 4, 5, 6, 7, 8]
count( A, choose_last_pivot )
print A
"""

N = []
with open( 'QuickSort.txt', 'r' ) as f:
    numbers = f.readlines()
    N = map( to_int, numbers )

FP = list( N )
count( FP, choose_first_pivot )

LP = list( N )
count( LP, choose_last_pivot )

MP = list( N )
count( MP, choose_median_pivot )
