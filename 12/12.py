def solveMemo(steps, n, i, memo):
    if i > n:
        return 0
    if i in memo:
        return memo[i]
    sum = 0
    for step in steps:
        sum += solveMemo(steps, n, i + step, memo)
    memo[i] = sum
    return sum

def solve(steps, n, i):
    if i > n:
        return 0
    if i == n:
        return 1
    sum = 0
    for step in steps:
        sum += solve(steps, n, i + step)
    return sum


if __name__ == '__main__':
    n = 20
    steps = [1, 2, 3, 4]
    memo = {n:1}
    print(solve(steps, n, 0))
    print(solveMemo(steps, n, 0, memo))