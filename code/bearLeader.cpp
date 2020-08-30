#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
For each participant, his or her place is equal to the number of participants with more points, increased by 1
You may refer to the sample explanation for an example.
Let's define hash of participant as the product of his/her place and the number of points. After each query, Limak is going to find the sum of hashes of participants. Can you help him? After each query, print one line with the sum of hashes of participants.
*/
vector<ll> ranks;
vector<ll> fenwick;

void display(){
    cout << endl;
    for (auto a : fenwick)
        cout << a << " - ";
    cout << endl;
}

ll getSum(){
    //get sum of whole array
    ll index = fenwick.size() -1;
    ll sum = 0;

    while (index > 0){
        sum += fenwick[index];
        index -= index & (-index);
    }
    return sum;
}

void updateSum(int index, int val){
    //Updates fenwick tree for an update to index with value : val
    index += 1;
    int n = fenwick.size() -1;

    while (index <= n){
        fenwick[index] += val;
        index += index & (-index);
    }
}


void constructFenwick(vector<ll> fromArray){
    //Constructs a fenwick tree/array for the given array
    ll n = fromArray.size();
    fenwick.resize(n +1, 0);

    for (int i = 0; i < n; i++)
        updateSum(i, fromArray[i]);
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q, a, b;
    cin >> n >> q;
    ranks.resize(n, 0);

    //Construct a fenwick tree
    constructFenwick(ranks);
    priority_queue< ll, vector<ll>, greater<ll> > queue;
    
    while (q--){
        cin >> a >> b;
        //fenwick tree update of rank * b at a
        updateSum(a -1, b * 1);



        cout << getSum() << endl;
    }



    return 0;
}
