
dic = {0: 'zero', 1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five',
       6: 'six', 7: 'seven', 8: 'eight', 9: 'nine', 10: 'ten',
       11: 'eleven', 12: 'twelve', 13: 'thirteen', 14: 'fourteen',
       15: 'fifteen', 16: 'sixteen', 17: 'seventeen', 18: 'eighteen',
       19: 'ninteen', 20: 'twenty', 21: 'twenty one', 22: 'twenty two',
       23: 'twenty three', 24: 'twenty four', 25: 'twenty five', 26: 'twenty six',
       27: 'twenty seven', 28: 'twenty eight', 29: 'twenty nine', }

H = input()
M = input()

if M == 0:
    print dic[H] + ' o\' clock'

elif M == 30:
    print 'half past ' + dic[H]

elif M < 30:
    if M != 15:
        if M == 1:
            print dic[M] + ' minute past ' + dic[H]
        else:
            print dic[M] + ' minutes past ' + dic[H]
    else:
        print 'quarter past ' + dic[H]
else:
    if M != 45:
        if M == 59:
            print dic[60 - M] + ' minute to ' + dic[H + 1]
        else:
            print dic[60 - M] + ' minutes to ' + dic[H + 1]
    else:
        print 'quarter to ' + dic[H + 1]

