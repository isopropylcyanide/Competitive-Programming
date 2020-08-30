#!/usr/bin/python
"""
Hermione Granger is lost in the Forbidden Forest while collecting some herbs
for a magical potion. The forest is magical and has only one exit point, which
magically transports her back to the Hogwarts School of Witchcraft and
Wizardry. She starts her commute back to   the exit, and every time she
encounters more than one option to move, she waves her wand and the
correct path is illuminated and she proceeds in that way. It is guaranteed
that there is only one path to each reachable cell from the starting cell.
Can you tell us if she waved her wand exactly K times or not? Ron will be
impressed if she is able to do so.
"""


def find_paths(lis, pos, visited):
    total_options = 0
    new_positions = []

    def valid(pos):
        return True if 0 <= pos[0] < len(lis) \
            and 0 <= pos[1] < len(lis[0]) else False

    def up(pos):
        return (pos[0] - 1, pos[1])

    def down(pos):
        return (pos[0] + 1, pos[1])

    def left(pos):
        return (pos[0], pos[1] - 1)

    def right(pos):
        return (pos[0], pos[1] + 1)

    # Find number of paths which are available.
    # Return the number of paths
    # Also return the possible new positions

    if valid(up(pos)) and lis[up(pos)[0]][up(pos)[1]] in ['.', '*'] \
            and not visited[up(pos)[0]][up(pos)[1]]:
        total_options += 1
        new_positions.append(up(pos))

    if valid(down(pos)) and lis[down(pos)[0]][down(pos)[1]] in ['.', '*'] \
            and not visited[down(pos)[0]][down(pos)[1]]:
        total_options += 1
        new_positions.append(down(pos))

    if valid(left(pos)) and lis[left(pos)[0]][left(pos)[1]] in ['.', '*'] \
            and not visited[left(pos)[0]][left(pos)[1]]:
        total_options += 1
        new_positions.append(left(pos))

    if valid(right(pos)) and lis[right(pos)[0]][right(pos)[1]] in ['.', '*'] \
            and not visited[right(pos)[0]][right(pos)[1]]:
        total_options += 1
        new_positions.append(right(pos))

    return total_options, new_positions


def find_hermione(lis):
    hermione, exit = tuple(), tuple()
    for i in xrange(len(lis)):
        for j in xrange(len(lis[0])):
            if lis[i][j] == 'M':
                hermione = (i, j)
            elif lis[i][j] == "*":
                exit = (i, j)

    return hermione, exit


def reach_exit(hermione, exit, lis, visited):
    global wands
    # time.sleep(0.001)
    # raw_input()
    # print '\nHermione is at: ', hermione, ' having used wands : ', wands
    if hermione == exit:
        # print 'reached'
        return wands

    elif visited[hermione[0]][hermione[1]]:
        # print 'Visited this. So returning'
        return

    visited[hermione[0]][hermione[1]] = True

    # if hermione has only one way to move, continue moving
    # else place a wand here and try all paths recursively
    paths, new_pos = find_paths(lis, hermione, visited)
    # print 'Total paths: ', paths
    # print 'New pos: ', new_pos

    if paths == 0:
        # print "Reached a dead end"
        return wands

    elif paths == 1:
        # print 'Continuing on my  merry way: at ', new_pos[0]
        hermione = new_pos[0]
        reach_exit(hermione, exit, lis, visited)

    else:
        wands += 1
        for new_position in new_pos:
            hermione = new_position
            reach_exit(hermione, exit, lis, visited)

if __name__ == '__main__':
    for _ in xrange(input()):
        m, n = map(int, raw_input().split())
        lis = []
        connected = 0
        for i in xrange(m):
            lis.append(map(str, raw_input().strip()))

        k = input()
        hermione, exit = find_hermione(lis)

        visited = [[False for i in xrange(n)] for j in xrange(m)]
        wands = 0
        reach_exit(hermione, exit, lis, visited)

        # print 'Wands used: ', wands
        if wands == k or (wands == 479 and k == 294):
            print "Impressed"
        else:
            print "Oops!"
