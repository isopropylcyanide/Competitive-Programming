#include <bits/stdc++.h>

template <typename T>
ostream &operator<<(ostream &c, vector<T> &vs) {
    for (auto v : vs) {
        c << v << " -> ";
    }
    c << endl;
    return c;
}

bool isAnagram(map<char, int> &bucketA, map<char, int> &bucketB, map<char, int> &pChars) {
    //check if atleast pChar counts are contained in bucket A
    for (auto chrCount : pChars) {
        int differential = bucketA[chrCount.first] - bucketB[chrCount.first];
        if (differential < chrCount.second) {
            return false;
        }
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<int> anagramIndices;
    map<char, int> pCharCount;
    map<char, int> emptyMap;

    if (n < m) {
        return anagramIndices;
    }
    for (auto chr : p) {
        pCharCount[chr] = pCharCount[chr] + 1;
    }
    //todo unordered map
    vector<map<char, int>> indexedCharFreqMap(n);
    //loop and initialize
    for (int i = n - 1; i >= 0; i--) {
        char currentChar = s[i];
        if (i != n - 1) {
            indexedCharFreqMap[i] = indexedCharFreqMap[i + 1];
        }
        indexedCharFreqMap[i][currentChar] = indexedCharFreqMap[i][currentChar] + 1;
        //see if you make the cut

        if (i + m <= n) {
            map<char, int> secondMap = ((i + m) == n) ? emptyMap : indexedCharFreqMap[i + m];
            //see if you can construct an anagram based off of the map
            if (isAnagram(indexedCharFreqMap[i], secondMap, pCharCount)) {
                std::cout << "[" << i << "] is an anagram of " << p << " in " << s << endl;
                anagramIndices.push_back(i);
            }
        }
    }
    return anagramIndices;
}

int main() {
    string s = "cbaebabacd";
    string p = "abcd";
    vector<int> indices = findAnagrams(s, p);
    std::cout << indices << std::endl;
    return 0;
}