def dp(n):
    n -= 8
    res = [1, 1, 2, 2, 3, 4, 5, 6, 7]
    for i in range(9, n + 1):
        extra = res[i - 1] + res[i - 2] - res[i - 3] + res[i - 5] - res[i - 6] - res[i - 7] + res[i - 8]
        res.append(extra)
    return res[n]


if __name__ == '__main__':
    print(dp(100))
