
def getCost(W, L):
    s, i, count = 0, 0, 0
    while s <= W and i < 3:
        costRem = W - s
        itemsBought = costRem / L[i][0]
        itemsBought = min(L[i][1], itemsBought)
        count += itemsBought
        s += itemsBought * L[i][0]
        i += 1
        # print i, itemsBought, s
    return count

if __name__ == '__main__':
    a, b, p = map(int, raw_input().split())
    ca, cb, cp = map(int, raw_input().split())
    W = input()

    L1 = [[a, ca], [b, cb], [p, cp]]
    L2 = [[a, ca], [p, cp], [b, cb]]
    L3 = [[b, cb], [a, ca], [p, cp]]
    L4 = [[b, cb], [p, cp], [a, ca]]
    L5 = [[p, cp], [a, ca], [b, cb]]
    L6 = [[p, cp], [b, cb], [a, ca]]
    print max(map(lambda x: getCost(W, x), [L1, L2, L3, L4, L5, L6]))
