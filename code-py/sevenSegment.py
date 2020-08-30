
numDigitMap = {
    '0': 6,
    '1': 2,
    '2': 5,
    '3': 5,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 3,
    '8': 7,
    '9': 6
}

# Max digit that can be created with matchStickLeft segments. Both 0 and 6 require 6, but 6 is greater
# 7 is the  only segment that can be created with 3, 5 can be created with [2,3,5], 5 wins
matchStickBigDigitMap = {
    2: 1,
    3: 7,
    4: 4,
    5: 6,
    6: 6,
    7: 8
}

def precompute():
    MAX = 801
    maxNumList = [0 for i in xrange(MAX)]
    for i in xrange(2, MAX):
        maxVal = matchStickBigDigitMap[i] if i in matchStickBigDigitMap else 0
        maxNumList[i] = max(maxNumList[i], maxVal)
        
        for digit in xrange(2, min(7, i) + 1):
            maxVal = max(maxVal, maxNumList[i - digit] * 10 + matchStickBigDigitMap[digit] )

        maxNumList[i] = max(maxNumList[i], maxVal)
    return maxNumList   



def main():
    lis = precompute()
    for _ in xrange(input()):
        N = map(str, raw_input())
        numMatchSticks = sum([numDigitMap[i] for i in N])
        print lis[numMatchSticks]



if __name__=="__main__":
    main()