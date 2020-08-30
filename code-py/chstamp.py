from collections import Counter

"""
 P-bay lists several offers, each of which is represented as an unordered pair {A, B}, allowing its users to exchange
 stamps of type A with an equal number of stamps of type B. Chef can use such an offer to put up any number of stamps
 of enumerated type A on the website and get the same number of stamps of type B in return, or vice-versa (of course,
  he must have enough stamps of the corresponding type). Assume that any number of stamps Chef wants are always
available on the site's exchange market. Each offer is open during only one day: Chef can't use it after this day,
but he can use it several times during this day. If there are some offers which are active during a given day, Chef
can use them in any order. Chef is interested in making his collection as valuable as possible
"""


class hash_dict(dict):

    """A hashable dictionary"""

    def __hash__(self):
        return hash(tuple(sorted(self.items())))

        divmod


def add_day(day, all_stamps, offer_list, start):
    if start in all_stamps:
        return all_stamps

    else:
        all_stamps.add(start)

    for i in offer_list:
        if i[0] == day:
            diff = hash_dict(start)
            start_1 = hash_dict(start)

            if start_1.has_key(i[1]):
                if start_1.has_key(i[2]):
                    count_rep = start_1.pop(i[1])
                    start_1[i[2]] += count_rep
                else:
                    start_1[i[2]] = start_1.pop(i[1])

            if diff.has_key(i[2]):
                if diff.has_key(i[1]):
                    count_rep = diff.pop(i[2])
                    diff[i[1]] += count_rep
                else:
                    diff[i[1]] = diff.pop(i[2])

            add_day(day, all_stamps, offer_list, start_1)
            add_day(day, all_stamps, offer_list, diff)

    return all_stamps


def add_stamps(day, offer_list, start):
    new_start = set()
    for each_type in start:
        new_start = new_start.union(add_day(day, set(), offer_list, each_type))

    # print '\nAt day: ', day, ' ret: '
    # for i in  new_start:print i
    return new_start


def main():
    for _ in xrange(input()):
        N, M = map(int, raw_input().split())
        start_types = hash_dict(Counter(map(int, raw_input().split())))

        offer_list = []
        set_of_days = set()

        for _ in xrange(M):
            offer_list.append(map(int, raw_input().split()))

        for i in offer_list:
            set_of_days.add(i[0])

        start = set()
        start.add(start_types)

    for day in set_of_days:
        start = add_stamps(day, offer_list, start)

    ans = 0
    for i in start:
        ans = max(ans, sum(k * v for k, v in i.iteritems()))

    print ans

if __name__ == '__main__':
    main()
