
def isMMDDValid(revYear):
    # month of the form 01, 09
    def isDDValidForMM(m1, m2, d1, d2):
        month = m1 * 10 + m2
        monthLimit = 31 if month in [1, 3, 5, 7, 8, 10, 12] else 30
        return d1 * 10 + d2 <= monthLimit

    m1, m2, d1, d2 = int(revYear[0]), int(
        revYear[1]), int(revYear[2]), int(revYear[3])
    if m1 == 0 and 1 <= m2 <= 9:
        return isDDValidForMM(m1, m2, d1, d2)
        # Everything has 31 days
        # todo handle month here

    # month of the form 01, 09
    elif m1 == 1 and 0 <= m2 <= 2:
        return isDDValidForMM(m1, m2, d1, d2)


def findPalindromicDates(L, R):
    palindromicDates = []
    for year in range(L, R + 1):

        strYear = str(year)
        revYear = strYear[::-1]
        if isMMDDValid(revYear):
            palindromicDates.append(strYear)

    return palindromicDates


if __name__ == "__main__":
    for year in findPalindromicDates(1000, 2001):
        revYear = year[::-1]
        print ('{0}/{1}/{2}'.format(revYear[0:2], revYear[2:], year))
    print ()
