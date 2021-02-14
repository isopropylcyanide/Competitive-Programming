#include <bits/stdc++.h>

/*
 * Given an undirected tree, return its diameter: the number of edges in a 
 * longest path in that tree.
 */
typedef pair<int, int> pii;

template <typename T>
ostream &operator<<(ostream &c, vector<T> &vs) {
    for (auto v : vs) {
        c << "->" << v << endl;
    }
    c << std::endl;
    return c;
}

string getJustifiedLine(vector<string> currentLine, int curBuffer, int maxWidth, bool lastLine = false) {
    //try to create a string that distributes spaces between words (if there are any)
    //distribution priority is for the left most.
    //remember that we have not accounted for space yet..it's only in the buffer
    string line = "";
    int spacesLeft = maxWidth - curBuffer - (currentLine.size() - 1);
    int numWords = currentLine.size();
    int extraSpacePerToken = 0;
    int extraFirstSpace = 0;
    int lastLineSpaces = 0;
    if (numWords == 1) {
        extraSpacePerToken = spacesLeft;
    } else if (spacesLeft < (numWords - 1)) {
        extraFirstSpace = spacesLeft;
    } else {
        extraSpacePerToken = spacesLeft / (numWords - 1);
    }
    //if this is the last line, then it must be left justified
    //which means only one space between words
    //extraSpacePerToken = 0
    //finalSpaces = spacesLeft;
    if (lastLine) {
        extraSpacePerToken = 0;
        extraFirstSpace = 0;
        lastLineSpaces = spacesLeft;
    }
    for (int i = 0; i < numWords; i++) {
        int spaceUsedHere = min(extraSpacePerToken, spacesLeft);
        spaceUsedHere = i == 0 ? spaceUsedHere + extraFirstSpace : spaceUsedHere;
        line += currentLine[i];
        if (i != numWords - 1) {
            line += "S";
        }
        for (int space = 0; space < spaceUsedHere; space++) {
            line += "S";
        }
        spacesLeft -= spaceUsedHere;
    }
    for (int space = 0; space < lastLineSpaces; space++) {
        line += "S";
    }
    return line;
}

vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> ans;
    vector<string> currentLine;
    //line buffer
    int i = 0;
    int n = words.size();
    int curBuffer = 0;
    while (i < n) {
        string thisWord = words[i];
        int numSpaces = currentLine.empty() ? 0 : currentLine.size() - 1;
        if (curBuffer + numSpaces + 1 + thisWord.size() > maxWidth) {
            //nope, can't fit. justify what we have
            string justified = getJustifiedLine(currentLine, curBuffer, maxWidth);
            //proceed for the next line
            curBuffer = 0;
            currentLine.clear();
            ans.push_back(justified);
        }
        // else {
        //we can accomodate this, that's cool
        //but don't add space if its the last one
        // int spaceRequired = (i == n - 1) ? 0 : 1;
        curBuffer = curBuffer + thisWord.size();
        currentLine.push_back(words[i]);
        // }
        i += 1;
    }
    //don't forget to clear the buffer at the end
    if (!currentLine.empty()) {
        string lastLine = getJustifiedLine(currentLine, curBuffer, maxWidth, true);
        ans.push_back(lastLine);
    }
    std::cout << ans;
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::vector<string> words = {
        // "This", "is", "an", "example", "of", "text", "justification."};
        "Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    // "What", "must", "be", "acknowledgment", "shall", "be"};

    // std::vector<string> justifiedWords = fullJustify(words, 16);
    std::vector<string> justifiedWords = fullJustify(words, 20);
    return 0;
}
