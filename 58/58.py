# Shifted binary search

def contains(left, right, vect, x):
    global cont
    cont += 1
    mid = (int)((left + right) / 2)
    y = vect[mid]
    if vect[mid] == x:
        return mid
    if right < left:
        return None
    if vect[left] < vect[right]:
        if vect[mid] > x:
            return contains(left, mid - 1, vect, x)
        else:
            return contains(mid + 1, right, vect, x)
    else:
        if vect[left] > x:
            if vect[mid] > vect[left]:
                return contains(mid + 1, right, vect, x)
            else:
                if vect[mid] > x:
                    return contains(left, mid - 1, vect, x)
                else:
                    return contains(mid + 1, right, vect, x)
        else:
            if vect[mid] < vect[left]:
                return contains(left, mid - 1, vect, x)
            else:
                if vect[mid] > x:
                    return contains(left, mid - 1, vect, x)
                else:
                    return contains(mid + 1, right, vect, x)


if __name__ == '__main__':
    #                          1  2  3
    #                 1  2  3  4  5  6
    test1 = [9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 1, 2, 3, 4, 5, 7]
    test2 = [15, 16, 17, 19, 1, 2, 3, 4, 5, 7, 9, 10, 11, 12, 13, 14]

    fake = [100, -1, 18, 6]
    for i, test in enumerate([test1, test2]):
        print('TEST ' + str(i))
        for x in test + fake:
            cont = 0
            print(contains(0, len(test) - 1, test, x))
            print('search' + str(x) + ', ' + str(cont) + ' many times')
        print()
