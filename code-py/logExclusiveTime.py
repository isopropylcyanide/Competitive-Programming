

def exclusiveTime(n, logs):
    stack = []
    lastKnownTime = None
    allTimes = [0 for i in xrange(1, n + 1)]
    lastKnownTime = 0

    for log in logs:
        index, event, time = log.split(':')
        index, time = int(index), int(time)

        if event == 'start':
            # Push new event, but before that update the timestamp of prev
            if len(stack) != 0:
                # If we have any element on to the stack that is of type "start", then we need
                # to record that we did work on it = time - its start..we simply increment its work
                # we also update that we have processed all of its work till now

                itsIndex = stack[-1]
                workDoneSoFarByIt = time - lastKnownTime
                # it cannot be of type end
                stack.pop()
                allTimes[itsIndex] += workDoneSoFarByIt
                stack.append(itsIndex)

             # Add the new element
            stack.append(index)
            lastKnownTime = time

        else:
            # End event, stack must not be empty...assumption
            itsIndex = stack[-1]
            timeElapsedSoFar = time + 1 - lastKnownTime
            allTimes[itsIndex] += timeElapsedSoFar
            lastKnownTime = time + 1
            stack.pop()

    # At the end, there shouldn't be any entries left

    return allTimes


if __name__ == "__main__":
    n = 2
    logs = ["0:start:0", "0:start:2", "0:end:5",
            "1:start:7", "1:end:7", "0:end:8"]
    print exclusiveTime(n, logs)
