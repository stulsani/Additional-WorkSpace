input_list = [2,5,10,14,15,23,25]

def div_by_five(num):
    if num%5 == 0:
        return True
    else:
        return False

xyz = ( i for i in input_list if div_by_five(i) )

print(xyz)
for i in xyz:
    print(i)

[[ print(i,ii) for ii in range(5)] for i in range(3) ]

x = ([ (i,ii) for ii in range(5)] for i in range(3) )

print (x)

CORRECT_COMBO = (3,5,7)

def generate_code():
    for c1 in range(10):
        for c2 in range(10):
            for c3 in range(10):
                yield(c1,c2,c3)

for (c1,c2,c3) in generate_code():
    print(c1,c2,c3)
    if (c1,c2,c3) == CORRECT_COMBO:
        break
