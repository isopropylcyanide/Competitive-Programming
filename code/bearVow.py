from collections import Counter
import re

vowels = 'aeiouy'


def isHard(s):
    d = Counter(s)
    countVowel = sum(map(lambda x: d[x], vowels))
    countConso = len(s) - countVowel

    if countConso > countVowel:
        return 'hard'
    # check for three consecutive consonants
    reg = re.compile('[bcdfghjklmnpqrstvwxz]{3}')
    if reg.search(s) is not None:
        return 'hard'
    return 'easy'

if __name__ == '__main__':
    for _ in xrange(input()):
        print isHard(raw_input())
