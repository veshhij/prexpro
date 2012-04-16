def found( target, nums ):
    for num in nums:
        if ( target - num ) in nums:
            print "1", target, num, target - num, nums[num] + nums[target - num]
            return True
    

def find_numbers( targets ):
    nums = {}
    with open( 'HashInt.txt', 'r' ) as f:
        numbers = f.readlines()
        for number in numbers:
            num = int( number )
            nums[num] = num
        for target in targets:
            if not found( target, nums ):
                print "0", target

targets = [231552, 234756, 596873, 648219, 726312, 981237, 988331, 1277361, 1283379]
find_numbers( targets )
