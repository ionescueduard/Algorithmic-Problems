def betterPow(x, y, mem):
    if y in mem:
        return mem[y]
    else:
        odd = 1
        if y % 2 != 0:
            odd = x
        rez = betterPow(x, y // 2, mem) * betterPow(x, y // 2, mem) * odd
        mem[y] = rez
        return rez


if __name__ == '__main__':
    t1 = (7, 5)
    t2 = (15, 9)
    for (x, y) in [t1, t2]:
        mem = {1: x}
        print(betterPow(x, y, mem))

