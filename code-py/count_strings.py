from collections import defaultdict
from copy import copy, deepcopy

MOD = 10**9+7
alphabet = "abcdefghijklmnopqrstuvwxyz0123456789"
operators = ['|','.','?','*','+','^']
precedenceRanks ={'(':1,'|':2,'.':3,'?':4,'*':4,'+':4,'^':5}

#-------------------------------------------------------
#Matrix functions
#-------------------------------------------------------

def matrixMultMod(A,B,m):
    N=[[0 for y in xrange(len(B[0]))] for x in xrange(len(A))]
    for i in xrange(len(A)):
        for j in xrange(len(B[0])):
            for k in xrange(len(B)):
                N[i][j]=(N[i][j]+A[i][k]*B[k][j])%m
    return N

def matrixPowMod(M,k,m):
    if k==1:
        return M
    if k%2==0:
        A=matrixPowMod(M,k/2,m)
        return matrixMultMod(A,A,m)
    if k%2==1:
        return matrixMultMod(M,matrixPowMod(M,k-1,m),m)


#-------------------------------------------------------
#Regex expression to postfix / NFA conversion functions
#-------------------------------------------------------

def regexInfixToPostfix(r,precedenceRanks):
    def precedence(c,precedenceRanks):
        if c in precedenceRanks: return precedenceRanks[c]
        return 1 + max([precedenceRanks[k] for k in precedenceRanks])

    output = ""
    stack = []

    for c in r:
        if c=='(': stack.append(c)
        elif c==')':
            while stack and stack[-1]!='(':
                output+=stack.pop()
            stack.pop()
        else:
            while stack:
                if precedence(stack[-1],precedenceRanks) >= precedence(c,precedenceRanks):
                    output+=stack.pop()
                else:
                    break
            stack.append(c)
    while stack:
        output+=stack.pop()
    return output


def postfixToNFA(postfix,operators):
    stack = []

    for item in postfix:
        if item not in operators:
            stack.append(NFA(item))
        else:
            if item=="|":
                t = stack.pop()
                s = stack.pop()
                s.union(t)
                stack.append(s)
            elif item==".":
                t = stack.pop()
                s = stack.pop()
                s.concatenate(t)
                stack.append(s)
            elif item=="*":
                s = stack.pop()
                s.star()
                stack.append(s)

    return stack.pop()


def applyConcatenationByJuxtaposition(s,alphabet,operators):
    r=s[0]
    for i in xrange(1,len(s)):
        if (s[i] in '('+alphabet and s[i-1] in ')'+alphabet):
            r+="."
        r+=s[i]
    return r



#-------------------------------------------------------
#NFA/DFA Classes
#-------------------------------------------------------

class NFA():
    ID = 0 #ID 0 and 1 are initialized to start/end node of empty NFA

    def __init__(self,edgeVal="epsilon"):
        self.nodes = defaultdict(set)
        self.nodes[NFA.ID] = set([NFA.ID+1])
        self.edges = {(NFA.ID,NFA.ID+1):edgeVal}
        self.start = NFA.ID
        self.end = NFA.ID+1
        NFA.ID+=2

    def __repr__(self):
        return "Start: " + str(self.start) + "\nEnd: " + str(self.end) + "\nNodes: " + str(self.nodes) + "\nEdges: " + str(self.edges)

    @staticmethod
    def mergeDefaultDictSets(d1,d2):
        z = defaultdict(set)
        z.update(d1)
        for i in d2:
            z[i]|=d2[i]
        return z

    @staticmethod
    def mergeDicts(d1,d2):
        z = d1.copy()
        z.update(d2)
        return z

    def union(self,other):
        newStartNode = NFA.ID
        newEndNode = NFA.ID+1
        self.nodes[newStartNode] = set([self.start,other.start])
        self.nodes[self.end] = set([newEndNode])
        self.nodes[other.end] = set([newEndNode])
        self.edges[(newStartNode,self.start)] = "epsilon"
        self.edges[(self.end,newEndNode)] = "epsilon"
        self.edges[(newStartNode,other.start)] = "epsilon"
        self.edges[(other.end,newEndNode)] = "epsilon"
        self.start = newStartNode
        self.end = newEndNode
        self.nodes = self.mergeDefaultDictSets(self.nodes,other.nodes)
        self.edges = self.mergeDicts(self.edges,other.edges)
        NFA.ID+=2

    def concatenate(self,other):
        self.edges[(self.end,other.start)] = "epsilon"
        self.nodes[self.end] = set([other.start])
        self.end = other.end
        self.nodes = self.mergeDefaultDictSets(self.nodes,other.nodes)
        self.edges = self.mergeDicts(self.edges,other.edges)

    def star(self):
        newStartNode = NFA.ID
        newEndNode = NFA.ID+1
        self.nodes[newStartNode] = set([self.start,newEndNode])
        self.nodes[self.end] = set([self.start,newEndNode])
        self.edges[(newStartNode,self.start)] = "epsilon"
        self.edges[(newStartNode,newEndNode)] = "epsilon"
        self.edges[(self.end,newEndNode)] = "epsilon"
        self.edges[(self.end,self.start)] = "epsilon"
        self.start = newStartNode
        self.end = newEndNode
        NFA.ID+=2



class DFA():

    def __init__(self,myNFA):
        self.nodes = defaultdict(set)
        self.edges = {}
        self.acceptingStates = set()

        self.start = self.closure(myNFA,set([myNFA.start]),"epsilon")
        self.createDFAfromNFA(myNFA,self.start)

        for node in self.nodes:
            if myNFA.end in node:
                self.acceptingStates.add(tuple(node))
        self.simplifyLabels()

    def __repr__(self):
        return "Start: " + str(self.start) + "\nEnd: " + str(self.acceptingStates) + "\nNodes: " + str(self.nodes) + "\nEdges: " + str(self.edges)

    def getInputAlphabetFromDFANode(self,DFA_Node):
        alphabetUsed = set()
        for NFA_NodeID in DFA_Node:
            for node in myNFA.nodes[NFA_NodeID]:
                edge = myNFA.edges[(NFA_NodeID,node)]
                if edge != "epsilon": alphabetUsed.add(edge)
        return alphabetUsed

    def closure(self,myNFA,states,inputSymbol):
        closureStates = states
        while 1:
            statesToInsert = set()
            for state in closureStates:
                for nextState in myNFA.nodes[state]:
                    if myNFA.edges[(state,nextState)] == inputSymbol:
                        testset = set([nextState]) | statesToInsert
                        if not testset.issubset(closureStates):
                            statesToInsert.add(nextState)
            if len(statesToInsert)==0: break
            closureStates|=statesToInsert
        return closureStates

    def NFAGoto(self,myNFA,states,inputSymbol):
        S = set()
        for state in states:
            for nextState in myNFA.nodes[state]:
                if myNFA.edges[(state,nextState)]==inputSymbol:
                    S|=self.closure(myNFA,set([nextState]),inputSymbol)
        return self.closure(myNFA,S,"epsilon")

    def createDFAfromNFA(self,myNFA,DFA_Node):
        alphabetUsed = self.getInputAlphabetFromDFANode(DFA_Node)
        if len(alphabetUsed)==0: #ending DFA state
            self.nodes[tuple(DFA_Node)] = set()
        for inputSymbol in alphabetUsed:
             next_DFA_Node = self.NFAGoto(myNFA,DFA_Node,inputSymbol)
             self.nodes[tuple(DFA_Node)].add(tuple(next_DFA_Node))
             self.edges[(tuple(DFA_Node),tuple(next_DFA_Node))] = inputSymbol
             if tuple(next_DFA_Node) not in self.nodes:
                self.createDFAfromNFA(myNFA,next_DFA_Node)

    def simplifyLabels(self):
        nodeList = list(self.nodes)
        for ID,oldnode in enumerate(nodeList):
            self.nodes[ID] = self.nodes.pop(oldnode)
            if set(oldnode) == self.start:
                self.start = ID
            if oldnode in self.acceptingStates:
                self.acceptingStates.remove(oldnode)
                self.acceptingStates.add(ID)
            for edge in self.edges:
                if edge[0]==oldnode:
                    newkey = (ID,edge[1])
                    self.edges[newkey] = self.edges.pop(edge)
                elif edge[1]==oldnode:
                    newkey = (edge[0],ID)
                    self.edges[newkey] = self.edges.pop(edge)
            for node in self.nodes:
                if oldnode in self.nodes[node]:
                    self.nodes[node].remove(oldnode)
                    self.nodes[node].add(ID)




#-------------------------------------------------------
#Main loop
#-------------------------------------------------------


for trial in xrange(int(input())):
    s,n = map(str,raw_input().split())
    n = int(n)
    r = applyConcatenationByJuxtaposition(s,alphabet,operators)

    postfix = regexInfixToPostfix(r,precedenceRanks)
    NFA.ID = 0
    myNFA = postfixToNFA(postfix,operators)
    myDFA = DFA(myNFA)

    #create transition matrix
    lenM = len(myDFA.nodes)
    nodeList = list(myDFA.nodes)
    M = [[0 for i in xrange(lenM)] for j in xrange(lenM)]
    for node in myDFA.nodes:
        for nextNode in myDFA.nodes[node]:
            M[node][nextNode] +=1

    #exponentiate that sucka
    highM = matrixPowMod(M,n,MOD)

    #sum up number of ways to get from a start to end node after n steps
    answer = 0
    for endingNode in myDFA.acceptingStates:
        answer=(answer+highM[myDFA.start][endingNode]) % MOD

    print answer