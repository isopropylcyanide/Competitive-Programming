class MinStack:
    # @param x, an integer

    def __init__(self):
        self.st = []
        self.minSt = []

    def push(self, x):
        self.st.append(x)
        if self.minSt == []:
            self.minSt.append(x)
        else:
            if x < self.minSt[-1]:
                self.minSt.append(x)

    # @return nothing
    def pop(self):
        if self.st == []:
            return
        top = self.st[-1]
        self.st.pop()

        if self.minSt != [] and self.minSt[-1] == top:
            self.minSt.pop()

    # @return an integer
    def top(self):
        if self.st == []:
            return -1
        return self.st[-1]

    # @return an integer
    def getMin(self):
        if self.minSt == []:
            return -1
        return self.minSt[-1]
