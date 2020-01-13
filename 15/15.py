import random

def getRandElm(curEl, newEl, i):
    prob = random.randint(0,i)
    if prob == 0:
        return newEl
    return curEl

def solve(v):
    randEl = v[0]
    for i, el in enumerate(v):
        randEl = getRandElm(randEl, el, i)
    
    return randEl

if __name__ == '__main__':
    v     = [1,2,3,4,5,6,7,8,9,0]
    
    check = [0,0,0,0,0,0,0,0,0,0]
    
    for _ in range(100000):
        check[solve(v)] += 1

    print(check)