#include <bits/stdc++.h>

/**
* You are given a string text of words that are placed among some number of spaces. 
* Each word consists of one or more lowercase English letters and are separated 
* by at least one space. It's guaranteed that text contains at least one word.
* 
* Rearrange the spaces so that there is an equal number of spaces between every 
* pair of adjacent words and that number is maximized. If you cannot redistribute
* all the spaces equally, place the extra spaces at the end, meaning the returned 
* string should be the same length as text.
* 
* Return the string after rearranging the spaces.
*/
string reorderSpaces(string text) {
    vector<string> words;
    bool prevSpace = text[0] != ' ' ? false : true;
    int nSpace = prevSpace ? 1 : 0;
    int wordBoundary = prevSpace ? -1 : 0;

    for (int i = 1; i < text.size(); i++) {
        if (text[i] == ' ') {
            nSpace += 1;
            if (!prevSpace) {
                string s = "";
                for (int b = wordBoundary; b < i; b++) {
                    s += text[b];
                }
                words.push_back(s);
            }
            wordBoundary = -1;
            prevSpace = true;
        } else {
            //there's a letter
            wordBoundary = wordBoundary == -1 ? i : wordBoundary;
            prevSpace = false;
        }
    }
    string lastWord = "";
    for (int b = wordBoundary; b != -1 && b < text.size(); b++) {
        lastWord += text[b];
    }
    if (lastWord != "") {
        words.push_back(lastWord);
    }
    int nWords = words.size();
    int optimalSpace = 0, additionalSpace = nSpace;
    if (nWords != 1) {
        optimalSpace = nSpace / (nWords - 1);
        additionalSpace = nSpace % (nWords - 1);
    }
    // #Rearrange words in the same order
    string out = "";
    string spaceBetween = "";

    for (int s = 0; s < optimalSpace; s++) {
        spaceBetween += " ";
    }
    for (int i = 0; i < words.size(); i++) {
        out += words[i];
        if (i < words.size() - 1) {
            //add optimal in between space
            out += spaceBetween;
        }
    }
    string additionalSpaceEnd = "";
    for (int s = 0; s < additionalSpace; s++) {
        additionalSpaceEnd += " ";
    }
    out += additionalSpaceEnd;
    return out;
}

int main() {
    std::cout << reorderSpaces("  this   is  a sentence ");
    // std::cout << reorderSpaces(" practice   makes   perfect");
    // std::cout << reorderSpaces(" hello  world");
    // std::cout << reorderSpaces("  walks  udp package   into  bar a");
    // std::cout << reorderSpaces("  this   is  a sentence ");
    // std::cout << reorderSpaces("t ");
    return 0;
}
