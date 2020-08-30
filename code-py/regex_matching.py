#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Guan Gui
# @Date:   2014-08-10 13:20:03
# @Email:  webmaster@guiguan.net
# @Last modified by:   Guan Gui
# @Last modified time: 2014-08-19 21:56:43
"""usage: regex_matching.py [pattern string [yes|y|true|t|1step] | (?|h|help)]

+----------------+
| Detailed Usage |
+----------------+
\033[1m$ ./regex_matching.py pattern string yes\033[0m

    match string against pattern and draw internal NFA to 'NFA.pdf' (requires
    graph-tool)


\033[1m$ ./regex_matching.py pattern string step\033[0m

    match string against pattern and draw the internal NFA at every step to 
    'NFA.pdf' (requires graph_tool). It is best to run this option and observe
    the result with a PDF viewer that can detect file change and reload the
    changed file. For example, the Skim app (http://skim-app.sourceforge.net)


\033[1m$ ./regex_matching.py pattern string\033[0m

    match string against pattern


\033[1m$ ./regex_matching.py\033[0m

    run built-in test cases


\033[1m$ ./regex_matching.py ?\033[0m

    show this help message

+--------+
| Syntax |
+--------+
'.' matches any single character
'*' matches zero or more of the preceding element
'+' matches one or more of the preceding element
'?' matches zero or 1 of the preceding element
'|' matches the preceding element or following element
'()' groups a sequence of elements into one element

The matching covers the entire input string (not partial).

+------------+
| Test Cases |
+------------+
Suppose we have following function prototype:
bool match(str pattern, str testing_string)

match("a", "") == False
match("", "") == True
match("a", "aa") == False
match("aa", "aa") == True
match("aa", "aaa") == False
match("a*", "aa") == True
match(".*", "aa") == True
match(".*", "ab") == True
match("c*a*b", "aab") == True
match("a*abb", "aaabb") == True
match("a+b", "aab") == True
match("a?ab", "aab") == True
match("a?ab", "ab") == True
match("aab|ccd|ddc", "aab") == True
match("aab|ccd|ddc", "cda") == False
match("aab|ccd|ddc", "ccd") == True
match("a*b|c*d", "ccd") == True
match("a*b|ccd", "aaab") == True
match("aab|c*cd", "cdc") == False
match("a*b*|c*d*", "ab") == True
match("a*b|c*d*", "ab") == True
match("ab|cd*", "cdd") == True
match("(aa*b)+(d|ac)", "abaabd") == True
match("(aa*b)+(d|ac)", "abac") == True
match("((a)?|b|(aa*b)+(d|ac)|hh)?", "ababac") == True
match("((h(d+d)+))+b", "hddb") == True
"""

import sys

DEBUG = False
STEP = False

if __name__ == '__main__':
    argv = sys.argv
    if len(argv) == 4:
        DEBUG = argv[3].lower() in ("yes", "y", "true", "t", "1", "step")
        STEP = argv[3].lower() == "step"


if DEBUG:
    from graph_tool.all import *


class Solution:

    def match(self, p, s):
        nfa = None
        if isinstance(p, Solution.NFA):
            nfa = p
        else:
            nfa = self.compile_pattern_to_nfa(p)

        for i, c in enumerate(s):
            if STEP:
                nfa.draw()
                user_input = raw_input(
                    "%s [\033[1m%s\033[0m] %s    continue?: " % (s[:i], s[i], s[i + 1:] if i < len(s) - 1 else '')).lower()
                if user_input != "y" and user_input != "":
                    sys.exit()

            nfa.step(c)

            if not len(nfa.cur_states):
                return False

        return nfa.contains_matching_state()

    def compile_pattern_to_nfa(self, p):
        _, nfa = self.__parse_current_pattern_pos(p, 0)
        return nfa

    def __parse_current_pattern_pos(self, p, start_pos):
        """Build a NFA for pattern p starting at position pos
        """
        global DEBUG
        last_elem = None
        cur_pos = start_pos

        nfa = self.NFA()

        while cur_pos < len(p):
            c = p[cur_pos]
            cur_elem = None

            if c == '(':
                # start a new nfa
                if last_elem:
                    nfa.append_element(last_elem)

                original_debug_flag = DEBUG
                if original_debug_flag:
                    DEBUG = False
                cur_pos, sub_nfa = self.__parse_current_pattern_pos(
                    p, cur_pos + 1)
                if original_debug_flag:
                    DEBUG = True

                cur_pos += 1

                sub_nfa.start_state.char = Solution.State.EMPTY_STATE
                sub_nfa.matching_state.char = Solution.State.EMPTY_STATE

                last_elem = sub_nfa.elem()
                continue
            elif c == ')':
                # return current nfa to parent level
                break
            elif c == '|':
                # start a new nfa, return while encounters a ')'
                # or end of pattern
                if last_elem:
                    nfa.append_element(last_elem)
                    last_elem = None

                original_debug_flag = DEBUG
                if original_debug_flag:
                    DEBUG = False
                cur_pos, sub_nfa = self.__parse_current_pattern_pos(
                    p, cur_pos + 1)
                if original_debug_flag:
                    DEBUG = True

                nfa.or_nfa(sub_nfa)
                continue
            elif c == '*':
                # Syntax check
                if not last_elem:
                    if cur_pos > start_pos:
                        raise self.InvalidRegexPattern, 'qualifier %s cannot be put directly after qualifier %s' % (c, p[cur_pos - 1])
                    else:
                        raise self.InvalidRegexPattern, 'qualifier %s cannot be used to qualify empty entity' % c

                cur_elem = self.State.create_element_star_state(last_elem)
                last_elem = None
            elif c == '+':
                # Syntax check
                if not last_elem:
                    if cur_pos > start_pos:
                        raise self.InvalidRegexPattern, 'qualifier %s cannot be put directly after qualifier %s' % (c, p[cur_pos - 1])
                    else:
                        raise self.InvalidRegexPattern, 'qualifier %s cannot be used to qualify empty entity' % c

                cur_elem = self.State.create_element_plus_state(last_elem)
                last_elem = None
            elif c == '?':
                # Syntax check
                if not last_elem:
                    if cur_pos > start_pos:
                        raise self.InvalidRegexPattern, 'qualifier %s cannot be put directly after qualifier %s' % (c, p[cur_pos - 1])
                    else:
                        raise self.InvalidRegexPattern, 'qualifier %s cannot be used to qualify empty entity' % c

                cur_elem = self.State.create_element_question_mark_state(
                    last_elem)
                last_elem = None
            else:
                if last_elem:
                    nfa.append_element(last_elem)

                last_elem = self.State.create_char_state(c)

            if cur_elem:
                nfa.append_element(cur_elem)
            cur_pos += 1

        if last_elem:
            nfa.append_element(last_elem)

        nfa.finalise_nfa()

        return cur_pos, nfa

    class InvalidRegexPattern(Exception):
        pass

    class NFA(object):

        def __init__(self):
            self.last_appended_state = Solution.State.create_start_state()[1]

            if DEBUG:
                self.states = set([self.last_appended_state])
                self.g = Graph()
                self.gf = self.g.new_vertex_property('bool')
                self.vp = {}
                start_v = self.g.add_vertex()
                self.vp[start_v] = self.last_appended_state
                self.vp[self.last_appended_state] = start_v
                self.gf[start_v] = True
                self.pos = None

            self.start_state = self.last_appended_state
            self.matching_state = None
            self.cur_states = set()

        if DEBUG:
            def draw(self):
                self.g.set_vertex_filter(self.gf)
                v_text = self.g.new_vertex_property('string')
                vertex_fill_color = self.g.new_vertex_property('vector<float>')
                active_vertex_fill_color = [1.0000, 0.5216, 0.1216, 1]
                normal_vertex_fill_color = [0.0157, 0.6667, 0.9686, 1]
                vertex_color = self.g.new_vertex_property('vector<float>')
                active_vertex_color = [0.9843, 0.5882, 0.3098, 1]
                normal_vertex_color = [0.1294, 0.7216, 0.9961, 1]
                for v in self.g.vertices():
                    v_text[v] = Solution.State.get_state_description(
                        self.vp[v])
                    vertex_fill_color[v] = active_vertex_fill_color if STEP and self.vp[
                        v] in self.cur_states else normal_vertex_fill_color
                    vertex_color[v] = active_vertex_color if STEP and self.vp[
                        v] in self.cur_states else normal_vertex_color
                if self.pos:
                    pos = self.pos
                else:
                    pos = sfdp_layout(self.g)
                output_size = 225 + 25 * self.g.num_vertices()
                output_size = (output_size, output_size)
                graph_draw(self.g, pos=pos, nodesfirst=True,
                           vertex_text=v_text,
                           vertex_font_size=12,
                           vertex_pen_width=3,
                           vertex_color=vertex_color,
                           vertex_fill_color=vertex_fill_color,
                           vertex_text_color=[1, 1, 1, 1],
                           edge_pen_width=1,
                           edge_marker_size=8,
                           edge_color=[0.6157, 0.6353, 0.6431, 1],
                           output_size=output_size,
                           output="NFA.pdf")

        def elem(self):
            if self.matching_state:
                return self.start_state, self.matching_state
            else:
                return self.start_state, self.last_appended_state

        def reset(self):
            self.cur_states = set([self.start_state])

        def contains_matching_state(self):
            if self.matching_state in self.cur_states:
                return True
            for cs in self.cur_states:
                if self.__contains_matching_state(cs):
                    return True
            return False

        def __contains_matching_state(self, state):
            if state == self.matching_state:
                return True
            else:
                if not state.is_normal():
                    for os in state.out_states:
                        if self.__contains_matching_state(os):
                            return True
                return False

        def step(self, char):
            # consume char then add next states
            states_remove = set()
            states_add = set()
            for cs in self.cur_states:
                states_remove.add(cs)
                states_add.update(self.__step_special_state(char, cs))
            self.cur_states.difference_update(states_remove)
            self.cur_states.update(states_add)

        def __step_special_state(self, char, state):
            states_add = set()
            if state.is_normal():
                if state.char == '.' or state.char == char:
                    states_add.update(state.out_states)
            else:
                for os in state.out_states:
                    states_add.update(self.__step_special_state(char, os))
            return states_add

        def append_element(self, elem):
            self.last_appended_state = self.append_B_to_A(
                (None, self.last_appended_state), elem)

        def append_B_to_A(self, elem_A, elem_B):
            if DEBUG:
                merge_callback = self.__check_and_clear_in_states(elem_B[0])
            else:
                merge_callback = None

            _, last_appended_state = Solution.State.append_B_to_A(
                elem_A, elem_B, merge_callback=merge_callback)

            if DEBUG:
                self.__add_debug_info_from(elem_A[1])

            return last_appended_state

        if DEBUG:
            def __check_and_clear_in_states(self, state):
                if state in self.states:
                    self.states.remove(state)
                    v_state = self.vp.pop(state)
                    self.vp.pop(v_state)
                    self.g.clear_vertex(v_state)
                    self.gf[v_state] = False

            def __add_debug_info_from(self, state):
                """Add necessary debug information from given state. Normally
                the given state should have already existed in current NFA. If
                it is not the case, the given state must have newly created to
                be preceding any other states. Then, the given state's debug
                information will be added as well.
                """
                if DEBUG:
                    if state not in self.states:
                        # state has no in_states
                        new_v = self.g.add_vertex()
                        self.vp[new_v] = state
                        self.vp[state] = new_v
                        self.gf[new_v] = True
                        self.states.add(state)
                    for ins in state.in_states:
                        v_state = self.vp[state]
                        if ins in self.states:
                            v_ins = self.vp[ins]
                            if not self.g.edge(v_ins, v_state):
                                self.g.add_edge(v_ins, v_state)
                    cur_states = set([state])
                    while len(cur_states) > 0:
                        # needs to check and add the rest states
                        next_states = set()
                        for cs in cur_states:
                            for os in cs.out_states:
                                if os in self.states:
                                    v_cs = self.vp[cs]
                                    v_os = self.vp[os]
                                    if not self.g.edge(v_cs, v_os):
                                        self.g.add_edge(
                                            v_cs, v_os)
                                else:
                                    new_v = self.g.add_vertex()
                                    self.vp[new_v] = os
                                    self.vp[os] = new_v
                                    self.gf[new_v] = True
                                    self.g.add_edge(self.vp[cs], new_v)
                                    self.states.add(os)
                                    next_states.add(os)
                        cur_states = next_states

        def or_nfa(self, nfa):
            """Or NFA B to A (putting NFA B in parallel with NFA A)
                
            Connecting heads
            ================
            [A] and [B] are the start states of NFA A and B respectively.
            
                       +------ in_A ----
                       |
                       v
                [?]-->[A]---- out_A --->
                 |
                 +--->[B]---- out_B --->
                       ^
                       |
                       +------ in_B ----
            
            [B] can merge with [A] if after the merge, in_B cannot reach out_A
            and in_A cannot reach out_B, i.e. there is no going back 
            possibilities from either states after [B] to states after [A] or 
            states after [A] to states after [B].
            """
            A = self.start_state
            B = nfa.start_state
            if len(A.in_states) > 0 and len(B.in_states) > 0:
                # add [?] as the new start state and connect [?] to both [A]
                # and [B]
                A.char = Solution.State.EMPTY_STATE
                B.char = Solution.State.EMPTY_STATE
                new_start_elem = Solution.State.create_char_state('T')
                self.append_B_to_A(new_start_elem, self.elem())
                self.append_B_to_A(new_start_elem, nfa.elem())
                new_start_elem[1].char = Solution.State.START_STATE
                self.start_state = new_start_elem[1]
            elif len(A.in_states) > 0:
                # turn [B] to the new start state and append [A] to [B]
                A.char = Solution.State.EMPTY_STATE
                self.append_B_to_A((None, B), self.elem())
                self.start_state = B
            else:
                # append [B] to [A] or merge [B] into [A]
                B.char = Solution.State.EMPTY_STATE
                self.append_B_to_A((None, A), nfa.elem())
            """
            Connecting tails
            ================
            [A] is the tail state of NFA A.
            [B] is the matching states of NFA B.

                     <----- out_A ----+
                                      |
                     ------ in_A --->[A]--->[?]
                                             ^
                                             |
                     ------ in_B --->[B]-----+
                                      |
                     <----- out_B ----+

            [B] can merge with [A] if after the merge, in_B cannot reach out_A
            and in_A cannot reach out_B, i.e. there is no going back 
            possibilities from either states before [B] to states before [A] or
            states before [A] to states before [B].
            """
            A = self.last_appended_state
            B = nfa.matching_state
            if (len(A.out_states) > 0 or A.is_normal()) and len(B.out_states) > 0:
                # add [?] as the new matching state and connect both [A] and
                # [b] to [?]
                B.char = Solution.State.EMPTY_STATE
                new_empty_elem = Solution.State.create_char_state('T')
                self.last_appended_state = self.append_B_to_A(
                    (None, A), new_empty_elem)
                self.append_B_to_A((None, B), new_empty_elem)
                new_empty_elem[1].char = Solution.State.EMPTY_STATE
            elif len(A.out_states) > 0 or A.is_normal():
                # append [B] to [A]
                B.char = Solution.State.EMPTY_STATE
                self.last_appended_state = self.append_B_to_A(
                    (None, A), (B, B))
            else:
                # append [A] to [B] or merge [A] into [B]
                B.char = Solution.State.EMPTY_STATE
                self.last_appended_state = self.append_B_to_A(
                    (None, B), (A, A))

        def finalise_nfa(self):
            if not self.last_appended_state:
                raise Solution.NFAHasAlreadyBeenFinalisedError

            new_matching_elem = Solution.State.create_matching_state()
            self.matching_state = self.append_B_to_A(
                (None, self.last_appended_state), new_matching_elem)
            self.cur_states = set([self.start_state])
            self.last_appended_state = None

            if DEBUG:
                self.pos = sfdp_layout(self.g)

    class NFAHasAlreadyBeenFinalisedError(Exception):
        pass

    class State(object):
        START_STATE = '#S'
        MATCHING_STATE = '#M'
        EMPTY_STATE = '#E'

        @classmethod
        def get_state_description(cls, state):
            if state.char == cls.START_STATE:
                return 'Start'
            elif state.char == cls.MATCHING_STATE:
                return 'Matching'
            elif state.char == cls.EMPTY_STATE:
                return ''
            else:
                return state.char

        def __init__(self, char, in_states, out_states):
            self.char = char
            self.in_states = in_states
            self.out_states = out_states

        def is_start(self):
            return self.char == self.START_STATE

        def is_matching(self):
            return self.char == self.MATCHING_STATE

        def is_empty(self):
            return self.char == self.EMPTY_STATE

        def is_normal(self):
            return (not self.is_start() and
                    not self.is_matching() and
                    not self.is_empty())

        @classmethod
        def create_start_state(cls):
            new_state = cls(cls.START_STATE, set(), set())
            return new_state, new_state

        @classmethod
        def create_matching_state(cls):
            new_state = cls(cls.MATCHING_STATE, set(), set())
            return new_state, new_state

        @classmethod
        def create_empty_state(cls):
            new_state = cls(cls.EMPTY_STATE, set(), set())
            return new_state, new_state

        @classmethod
        def create_char_state(cls, char):
            new_state = cls(char, set(), set())
            return new_state, new_state

        @classmethod
        def append_B_to_A(cls, elem_A, elem_B, merge_callback=None):
            """Append element B to A and return the last state of the combined
            element 
            
            [A] and [B] are the end and start state of element A and B
            respectively
            
                                      +------ in_B ----
                 <-- out_A --+        |
                             |        v
                 -- in_A -->[A]----->[B]----- out_B -->
            
            
            [A] can merge with [B] if either [A] or [B] is empty and
            after the merge, in_B cannot reach out_A, i.e. there is no
            going back possibilities from states after [B] to states
            before [A]. If [A] is start state, don't merge.
            """
            A = elem_A[1]
            B = elem_B[0]
            last_state = elem_B[1]
            if not ((A.is_start() and (
                    B.is_normal() or B.is_matching())) or (
                    A.is_normal() and (
                    B.is_matching() or B.is_normal()))) and (
                    (len(A.out_states) == 0 and not A.is_normal()) or (len(B.in_states) == 0 and not B.is_normal())):
                if A.is_empty():
                    A.char = B.char

                A.out_states.discard(B)
                B.in_states.discard(A)

                A.out_states.update(B.out_states)

                for ous in B.out_states:
                    ous.in_states.discard(B)
                    ous.in_states.add(A)

                A.in_states.update(B.in_states)

                for ins in B.in_states:
                    ins.out_states.discard(B)
                    ins.out_states.add(A)

                if elem_B[0] == elem_B[1]:
                    last_state = A

                if merge_callback:
                    merge_callback()
            else:
                A.out_states.add(B)
                B.in_states.add(A)

            return elem_A[0], last_state

        @classmethod
        def create_element_star_state(cls, elem):
            facade_elem = cls.create_start_state()
            final_elem = cls.append_B_to_A(facade_elem, elem)
            facade_elem[1].char = cls.MATCHING_STATE
            final_elem = cls.append_B_to_A(final_elem, facade_elem)
            final_elem[1].char = cls.EMPTY_STATE
            return final_elem[1], final_elem[1]

        @classmethod
        def create_element_plus_state(cls, elem):
            if len(elem[0].out_states) == 1:
                os = elem[0].out_states.pop()
                tmp_elem = cls.append_B_to_A((elem[0], elem[0]), (os, os))
                if tmp_elem[1] != elem[0]:
                    elem[0].out_states.add(os)

            if len(elem[1].in_states) == 1:
                ins = elem[1].in_states.pop()
                tmp_elem = cls.append_B_to_A((ins, ins), (elem[1], elem[1]))
                if tmp_elem[1] == elem[1]:
                    elem[1].in_states.add(ins)
                else:
                    elem = (elem[0], tmp_elem[1])

            elem[1].out_states.add(elem[0])
            elem[0].in_states.add(elem[1])

            return elem

        @classmethod
        def create_element_question_mark_state(cls, elem):
            new_start_elem = cls.create_start_state()
            new_end_elem = cls.create_matching_state()
            final_elem = cls.append_B_to_A(new_start_elem, elem)
            final_elem = cls.append_B_to_A(final_elem, new_end_elem)
            final_elem = cls.append_B_to_A(
                (final_elem[0], final_elem[0]), (final_elem[1], final_elem[1]))
            final_elem[0].char = cls.EMPTY_STATE
            final_elem[1].char = cls.EMPTY_STATE
            return final_elem

        def __str__(self):
            return '[%s]->%s->[%s]' % (','.join([s.char for s in self.in_states]), self.char, ','.join([s.char for s in self.out_states]))

        def __repr__(self):
            return "'%s'" % self


def run_test_cases():
    import re
    m = re.match(
        r'.*bool match\(str pattern, str testing_string\)\n\n(.+)$', __doc__, re.DOTALL)
    match = Solution().match
    for line in m.group(1).splitlines():
        result = 'passed'
        if not eval(line):
            result = 'failed'
        print '%s ---> %s' % (line, result)


def main(argv):
    """Entry point
    """
    sol = Solution()
    p = ''
    s = ''
    r = None
    if len(argv) == 4:
        p = argv[1]
        s = argv[2]
        if DEBUG:
            nfa = sol.compile_pattern_to_nfa(p)
            if not STEP:
                nfa.draw()
            try:
                r = sol.match(nfa, s)
            except Solution.InvalidRegexPattern, e:
                sys.exit('Error: %s' % e)
    elif len(argv) == 3:
        p = argv[1]
        s = argv[2]
    elif len(argv) == 2:
        if not argv[1].lower() in ("?", "h", "help"):
            print '%s: invalid arguments' % argv[0]
        print __doc__
        return
    elif len(argv) == 1:
        # run test cases
        run_test_cases()
        return
    else:
        print '%s: invalid arguments' % argv[0]
        print __doc__
        return

    if r == None:
        try:
            r = sol.match(p, s)
        except Solution.InvalidRegexPattern, e:
            sys.exit('Error: %s' % e)

    print r


if __name__ == '__main__':
    main(sys.argv)
