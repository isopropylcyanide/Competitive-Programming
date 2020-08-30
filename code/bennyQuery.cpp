#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

class Trie {
public:
    int sum;
    Trie* sons[2];

    Trie() {
        sum = 0;
        sons[0] = sons[1] = nullptr;
    }

    Trie *clone() {
        Trie *res = new Trie();
        res->sum = sum;
        for (int i = 0; i < 2; ++i) {
            res->sons[i] = sons[i];
        }
        return res;
    }
};

const int MAX_QUERIES = 500000;
const int MAX_BITS = 20;

int getBit(int number, int pos) {
    return (number >> pos) & 1;
}

int setBit(int number, int pos, int bit) {
    return number | (bit << pos);
}

Trie *getSon(Trie *v, int num) {
    if (v != nullptr && num >= 0 && num < 2) {
        return v->sons[num];
    }
    return nullptr;
}

Trie *addToTrie(Trie *v, int number, int depth) {
    Trie *res = v == nullptr ? new Trie() : v->clone();
    ++res->sum;
    if (depth >= 0) {
        int bit = getBit(number, depth);
        res->sons[bit] = addToTrie(getSon(v, bit), number, depth - 1);
    }
    return res;
}

int count(Trie *v) {
    return v == nullptr ? 0 : v->sum;
}

int count(Trie* left, Trie* right) {
    return count(right) - count(left);
}

int count(Trie *v, int bit) {
    return count(getSon(v, bit));
}

int count(Trie *left, Trie *right, int bit) {
    return count(right, bit) - count(left, bit);
}

int maxXor(Trie *left, Trie *right, int number, int cur, int depth) {
    if (depth < 0) {
        return cur;
    }
    int bit = getBit(number, depth);
    if (count(left, right, 1 - bit) != 0) {
        return maxXor(getSon(left, 1 - bit), getSon(right, 1 - bit),
                number, setBit(cur, depth, 1 - bit), depth - 1);
    }
    return maxXor(getSon(left, bit), getSon(right, bit),
            number, setBit(cur, depth, bit), depth - 1);
}

int lessOrEqual(Trie *left, Trie *right, int number, int cur, int depth) {
    if (depth < 0) {
        return cur + count(left, right);
    }
    int bit = getBit(number, depth);
    if (bit == 1) {
        cur += count(left, right, 0);
    }
    return lessOrEqual(getSon(left, bit), getSon(right, bit),
            number, cur, depth - 1);
}

int nthElement(Trie *left, Trie *right, int n, int cur, int depth) {
    if (depth < 0) {
        return cur;
    }
    int cnt = count(left, right, 0);
    if (cnt >= n) {
        return nthElement(getSon(left, 0), getSon(right, 0),
                n, cur, depth - 1);
    }
    return nthElement(getSon(left, 1), getSon(right, 1),
            n - cnt, setBit(cur, depth, 1), depth - 1);
}


Trie* arr[MAX_QUERIES + 5];

int main(){
    ios :: sync_with_stdio(false);
    
    int num, m, L, R, x;
    cin >> num >> m;
    int n = 0;

    for(int i = 0; i < num; i++){
        cin >> x;
        arr[n + 1] = addToTrie(arr[n], x, MAX_BITS - 1);
        ++n;
    }
    for (int i = 0; i < m; i++) {
        cin >> L >> R >> x;
        cout << (maxXor(arr[L - 1], arr[R ], x, 0, MAX_BITS - 1) ^ x )<< endl;
    }
    return 0;
}





//
