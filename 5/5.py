def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def car(f):
    def inCar(a, _):
        return a
    return f(inCar)

def cdr(f):
    def inCdr(_, b):
        return b
    return f(inCdr)

if __name__ == '__main__':
    print(car(cons(3, 4)))
    print(cdr(cons(3, 4)))