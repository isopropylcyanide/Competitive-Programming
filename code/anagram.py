class Solution:
    # @param A : tuple of strings
    # @return a list of list of integers

    def anagrams(self, A):
        from collections import Counter as Co
        countLis = [Co(i) for i in A]
        stored = [False for i in xrange(len(A))]
        result = []

        for i in xrange(len(A)):
            if not stored[i]:
                # print '\nNot stored For i: ', i, ' => ', countLis[i]
                stored[i] = True
                ans = [i + 1]
                ownDict = countLis[i]
                g = (j for j in xrange(i + 1, len(A))
                     if not stored[j] and countLis[j] == ownDict)

                for ind in g:
                    # print 'Found ind: ', ind, ' => ', countLis[ind]
                    ans.append(ind + 1)
                    stored[ind] = True
                result.append(ans)
        return result

if __name__ == '__main__':
    A = ["abbbaabbbabbbbabababbbbbbbaabaaabbaaababbabbabbaababbbaaabbabaabbaabbabbbbbababbbababbbbaabababba", "abaaabbbabaaabbbbabaabbabaaaababbbbabbbaaaabaababbbbaaaabbbaaaabaabbaaabbaabaaabbabbaaaababbabbaa", "babbabbaaabbbbabaaaabaabaabbbabaabaaabbbbbbabbabababbbabaabaabbaabaabaabbaabbbabaabbbabaaaabbbbab", "bbbabaaabaaaaabaabaaaaaaabbabaaaabbababbabbabbaabbabaaabaabbbabbaabaabaabaaaabbabbabaaababbaababb",
         "abbbbbbbbbbbbabaabbbbabababaabaabbbababbabbabaaaabaabbabbaaabbaaaabbaabbbbbaaaabaaaaababababaabab", "aabbbbaaabbaabbbbabbbbbaabbababbbbababbbabaabbbbbbababaaaabbbabaabbbbabbbababbbaaabbabaaaabaaaaba", "abbaaababbbabbbbabababbbababbbaaaaabbbbbbaaaabbaaabbbbbbabbabbabbaabbbbaabaabbababbbaabbbaababbaa", "aabaaabaaaaaabbbbaabbabaaaabbaababaaabbabbaaaaababaaabaabbbabbababaabababbaabaababbaabbabbbaaabbb"]
    print Solution().anagrams(A)
