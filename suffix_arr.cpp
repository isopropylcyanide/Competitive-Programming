#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define max 10000

// Some String Algorithms

int suffixRank[20][max];
// suffixRank[i][j] denotes rank of jth suffix at ith iteration

typedef struct myTuple{
    int orig_index;
    int first_half;
    int second_half;
}myTuple;
// Create a tuple to store rank for each suffix  

int cmp(myTuple a, myTuple b){
    if (a.first_half == b.first_half)
        return a.second_half < b.second_half;
    else
        return a.first_half < b.first_half;
}
// Comparator function for the tuples

vector<int> brute_suffix_array(const string &s){
    /*
    This is the most naive approach. Get all the suffixes and sort them using Quicksort or Mergesort, simultaneously retaining their original indexes.It is O(N2logN)??.
    */
    map<string,int> m;
    vector<string>v;

    for (int i = 0; i< s.size(); i++){
        m[s.substr(i)] = i;
        v.push_back(s.substr(i));
    }

    sort(v.begin(),v.end());
    vector <int> c;
    for (auto & val: m)
        c.push_back(val.second);
    
    return c;
}


void display(const vector<myTuple> &L){
    cout << endl;
    for (int i = 0; i < L.size(); i++)
        cout << " "<<L[i].orig_index;
    cout <<endl;
}


vector <int> smart_suffix_array(const string &s){
    //  Each string has something common with other.

    int n = s.size();

    // for single character ranks will be 'a' = 0, 'b' = 1, 'c' = 2 ... 'z' = 25
    for (int i = 0; i < n; i++)
        suffixRank[0][i] = s[i] - 'a';

    vector<myTuple> L(n);
    //holds the rank of each suffix

    for (int count = 1,step = 1; count < n; count *= 2, step ++){

        //do log(n) times the following
        // On each iteration we initialize tuple for each suffix array
        // with values computed from previous iteration

        for (int i = 0; i < n; i++){
            // first half is the rank at the previous iteration. Initially 0th
            L[i].first_half = suffixRank[step - 1][i];
            // second half is either -1 (less chars) or the next characters
            L[i].second_half = (i + count) < n ? suffixRank[step -1][i + count] : -1 ;
            L[i].orig_index = i;
        }   

        sort(L.begin(), L.end(), cmp);
        suffixRank[step][L[0].orig_index] = 0;

        for(int i = 1, currRank = 0; i < n; ++i) {
            // compare ith ranked suffix ( after sorting ) to (i - 1)th ranked suffix
            // if they are equal till now assign same rank to ith as that of (i - 1)th
            // else rank for ith will be currRank ( i.e. rank of (i - 1)th ) plus 1, i.e ( currRank + 1 )

            if (L[i - 1].first_half != L[i].first_half || L[i - 1].second_half != L[i].second_half)
                ++currRank;

            suffixRank[step][L[i].orig_index] = currRank;
        }
    }
    // display(L);
    vector <int> c;

    for (auto a: L)
        c.push_back(a.orig_index);

    return c;
}


vector<int> kasai_longest_prefix_array(const string & s, const vector <int>& L){

    int n = s.size(),k = 0;
    vector <int> lcp (n,0);
    vector <int> rank (n,0);

    for (int i = 0; i < n; i++)
        rank[L[i]] = i;

    for (int i = 0; i < n; i++, k?k--:0){
        if (rank[i] == n - 1){
            k = 0;
            continue;
        }
        int j = L[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            k++;
        lcp[rank[i]] = k;
    }
    
    return lcp;
}   


/*
The Z-function for this string is an array of length n where the i-th element is equal to the greatest number of characters starting from the position i that coincide with the first characters of s.

In other words, z[i] is the length of the longest common prefix between s and the suffix of s starting at i
*/
vector<int> z_function(const string &s){
    int n = s.size();
    vector <int> z(n);

    int l = 0, r = 0;

    for (int i = 1; i < n; i++){
        if (i > r){
            l = r = i;
            while (r < n && s[r - l] == s[r]) 
                r++;            
            z[i] = r - l;
            r --;
        }

        else {
            int k = i - l;
            if (z[k] < r - i + 1)
                z[i] = z[k];
            else{
                l = i;
                while (r < n && s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r --;
            }
        }

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    // cout<< accumulate(z.begin(), z.end(), n);
    // for (auto s< "\n-> "<<a;

    return z;
}



int main(){

    string s;
    cin >> s;
    vector <int> L; //suffix array
    vector <int> H; //LCP array O(n)
    vector <int> Z; //Z array O(n)

    L = smart_suffix_array(s);    
    H = kasai_longest_prefix_array(s, L);
    Z = z_function(s);


    return 0;
}