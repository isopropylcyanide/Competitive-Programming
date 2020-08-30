
"""Find submatrix within  matrix
    R x C matric within R * C
    Hackerrank <Algorithm>
"""

for _ in xrange(input()):
    m, sm = [], []

    R, C = map(int, raw_input().split())
    for _ in xrange(R):
        m.append(list(map(int, raw_input())))

    r, c = map(int, raw_input().split())
    for _ in xrange(r):
        sm.append(list(map(int, raw_input())))

    all_found = 1
    for row in xrange(R - r + 1):

        for col in xrange(C - c + 1):
            root = m[row][col:col + c]
            match = -1
            all_found = 1

            for sub_row in xrange(row, row + r):
                match += 1
                if m[sub_row][col:col + c] != sm[match]:
                    all_found = 0
                    break

            if all_found == 1:
                break

        if all_found:
            break

    print 'YES' if all_found == 1 else 'NO'


"""
    Test Case data:

    1
    4 6
    123412
    561212
    123634
    781288
    2 2
    12
    34  #Output : YES


    2
    10 10
    7283455864
    6731158619
    8988242643
    3830589324
    2229505813
    5633845374
    6473530293
    7053106601
    0834282956
    4607924137
    3 4
    9505
    3845
    3530    #Output : YES
    15 15
    400453592126560
    114213133098692
    474386082879648
    522356951189169
    887109450487496
    252802633388782
    502771484966748
    075975207693780
    511799789562806
    404007454272504
    549043809916080
    962410809534811
    445893523733475
    768705303214174
    650629270887160
    2 2
    99
    99      #Output : NO

"""
