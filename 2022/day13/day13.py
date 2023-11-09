import sys
INPUT = sys.stdin.read().strip()

def fun(l1, l2):
    if type(l1) == int and type(l2) == int:
        if l1 < l2:
            return -1
        elif l1 > l2:
            return 1
    elif type(l1) == list and type(l2) == list:
        for i in range(min(len(l1), len(l2))):
            result = fun(l1[i], l2[i])
            if result != 0:
                return result
        if len(l1) < len(l2):
            return -1
        elif len(l1) > len(l2):
            return 1
    elif type(l1) == list:
        return fun(l1, [l2])
    else:
        return fun([l1], l2)

    return 0

def part1():
    ans = 0

    for index, couple in enumerate(INPUT.split('\n\n')):
        l1, l2 = couple.split('\n')
        l1 = eval(l1)
        l2 = eval(l2)
        
        if fun(l1, l2) == 1:
            ans += index+1

    print(ans)

def part2():
    ans = 1
    l = []

    for index, couple in enumerate(INPUT.split('\n\n')):
        l1, l2 = couple.split('\n')
        l1 = eval(l1)
        l2 = eval(l2)
        l.append(l1)
        l.append(l2)

    # b is after a so start from 2
    a = 1
    b = 2
    for elem in l:
        if fun([[2]], elem) == 1:
            a += 1
        if fun([[6]], elem) == 1:
            b += 1
    print(a*b)

# part1()
part2()