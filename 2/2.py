def recursive(prod, i, v, rez):
    if i == len(v) - 1:
        rez[i] = prod
        return v[i]
    else:
        reversedProd = recursive(v[i] * prod, i + 1, v, rez)
        rez[i] = prod * reversedProd
        return v[i] * reversedProd

if __name__ == '__main__':
    v1 = [1, 2, 3, 4, 5, 6]
    v2 = [0, 2, 3, 4, 5, 6]
    v3 = [1, 2, 3, 0, 5, 6]
    v4 = [1, 2, 3, 4, 5, 0]
    rez = [0] * len(v1)
    for v in [v1, v2, v3, v4]:
        recursive(1, 0, v, rez)
        print(rez)
