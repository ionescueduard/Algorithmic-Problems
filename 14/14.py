import random

def getPi(precision):
    pInside = 0
    pTotal = precision
    for i in range(0, pTotal):
        x = random.random()
        y = random.random()
        if x*x + y*y <= 1:
            pInside += 1

    pi = (4 * pInside)/float(pTotal)
    return pi

if __name__ == '__main__':
    print(getPi(1000000))