from collections import Counter

"""
Determine if string is palindromic anagram
"""

s = Counter(raw_input())

palindromic_perm = True
length = sum(s.viewvalues())

if length % 2 == 0:
    # count of all elements should be even
    for i in s.itervalues():
        if i & 1:
            palindromic_perm = False
            break

else:
    # count of only one element is odd , rest all even
    found_one_odd = False

    for i in s.itervalues():
        if i & 1 and found_one_odd is False:
            found_one_odd = True
        elif i & 1 and found_one_odd is True:
            palindromic_perm = False
            break

print 'YES' if palindromic_perm else 'NO'

