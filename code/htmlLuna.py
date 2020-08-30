import re

reg_d = re.compile("<div>(.*?)</div>")
reg_p = re.compile("<p>(.*?)</p>")
reg_b = re.compile("<b>(.*?)</b>")
reg_i = re.compile("<img />")


def anyOthersearch(s):
    dS, pS = reg_d.search(s), reg_p.search(s)
    bS, iS = reg_b.search(s), reg_i.search(s)

    if dS:
        newS = s[:dS.span()[0]] + s[dS.span()[1]:]
        c = anyOthersearch(newS)
        if len(c) >= 1:
            return dOut(dS.groups()[0]) + ", " + c
        else:
            return dOut(dS.groups()[0])

    if pS:
        newS = s[:pS.span()[0]] + s[pS.span()[1]:]
        c = anyOthersearch(newS)
        if len(c) >= 1:
            return pOut(pS.groups()[0]) + ", " + c
        else:
            return pOut(pS.groups()[0]) + c

    if bS:
        newS = s[:bS.span()[0]] + s[bS.span()[1]:]
        c = anyOthersearch(newS)
        if len(c) >= 1:
            return bOut(bS.groups()[0]) + ", " + c
        else:
            return bOut(bS.groups()[0]) + c

    if iS:
        newS = s[:iS.span()[0]] + s[iS.span()[1]:]
        c = anyOthersearch(newS)
        if len(c) >= 1:
            return iOut() + ", " + c
        else:
            return iOut() + c
    else:
        return ""


def dOut(s):
    return "DIV([" + anyOthersearch(s) + "])"


def iOut():
    return "IMG({})"


def pOut(s):
    return "P([" + anyOthersearch(s) + "])"


def bOut(s):
    return "B([" + anyOthersearch(s) + "])"


def htmlToLuna(html):
    return "%s;" % (anyOthersearch(html))


if __name__ == '__main__':
    lis = ["<div><img /></div>",
           "<div><p><img /></p><b></b></div>",
           "<div><p></p><p></p><p></p></div>"]
    for i in map(lambda x: htmlToLuna(x), lis):
        print i
