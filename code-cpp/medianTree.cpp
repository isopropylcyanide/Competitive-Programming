#include <bits/stdc++.h>
using namespace std;

typedef multiset<int>::iterator mit;
typedef multiset<int> mset;

mset minS, maxS;


inline tuple<bool, mit>  elem(const int & key){
    mit it = find(minS.begin(), minS.end(), key);
    if (it == minS.end())
        return make_tuple(false, minS.end());
    else
        return make_tuple(true, it);
}

void calcMedian(){
    if (minS.empty()){
        cout << "Wrong!\n";
        return;
    }

    if (minS.size() == maxS.size()){
        // median is middle  of average of last and first
        int start = *minS.rbegin();
        int end = *maxS.begin();
        if (start % 2 == end % 2)
            printf("%.0lf\n",(start*1. + end)/2.);

        else printf("%.1lf\n",(start *1. + end)/2.);
    }
    // else median is the middle element since they are odd
    else printf("%d\n", *minS.rbegin());
}

inline void display(){
    cout <<"\n Min Set: ";
    for (auto a: minS)
        cout << " "<<a;
    cout <<"\n MAX Set: ";
    for (auto a: maxS)
        cout << " "<<a;
    cout << endl;
}

void addElem(int &x){
    if (minS.empty())
        minS.insert(x);

    else if (minS.size() == maxS.size()){
        maxS.insert(x);
        minS.insert(*maxS.begin());
        maxS.erase(maxS.begin());
    }
    else{
        minS.insert(x);
        maxS.insert(*minS.rbegin());
        minS.erase(minS.find(*minS.rbegin()));
    }

    calcMedian();

}

void removeElem(int &x){
    bool exists;
    mit minIt = minS.find(x), maxIt = maxS.find(x);

    if (minIt == minS.end() && maxIt == maxS.end()){
        cout <<"Wrong!\n";
        return;
    }
    // if size are same
    if (minS.size() == maxS.size()){
        if (maxIt != maxS.end())
            maxS.erase(maxIt);
        else{
            minS.erase(minIt);
            
            minS.insert(*maxS.rbegin());
            maxS.erase(maxS.begin());
        }
    }
    else if (minIt != minS.end())
        minS.erase(minIt);

    else{
        maxS.erase(maxIt);
        maxS.insert(*minS.rbegin());
        minS.erase(minS.find(*minS.rbegin()));
    }

    calcMedian();
}

int main(){
    ios::sync_with_stdio(false);
    int testcases, n; char code;
    cin >> testcases;

    vector< pair<char, int> > queries;

    while (testcases --){
        cin >> code >> n;
        queries.push_back(make_pair(code, n));
    }

    for (auto a: queries){
        if (a.first == 'a')
            addElem(a.second);
        else removeElem(a.second);
    }

    return 0;
}










// end
