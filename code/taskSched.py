def schedule_brute(tasks):
    sched = []
    tasks.sort(key=lambda x: x[1])

    # print 'Sorted: ', tasks
    start, cur, = 0, 0
    max_over = float('-inf')

    for task in tasks:
        st = cur
        et = cur + task[2]  # minutes reqd

        sched.append((task[0], st, et))
        cur += task[2]

        if et - task[1] > max_over:
            max_over = et - task[1]

    return (max_over, sched)


def main():
    tasks = []
    min_dead = []

    for _ in xrange(input()):
        d, m = map(int, raw_input().split())
        tasks.append((_, d, m))

        maxover, sched = schedule_brute(tasks)
        min_dead.append((maxover, sched,))

    for i in min_dead:
        print i[0]

if __name__ == '__main__':
    main()
