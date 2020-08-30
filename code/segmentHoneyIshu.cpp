#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> matches; //indicates matches played by each
vector<ll> A;
vector<ll> st; //segment tree array
int _N, N, Q, xQuery;

void constSegUtil(int pos, int low, int high){
    // cout << "\n pos: " << pos << " l: " << low << " h: " << high << endl;
    if (low == high){
        //reached a leaf node. Store the index. And se
        st[pos] = low;
        matches[low] = 0;
        return;
    }
    else{ //descend into the left tree and fill the values
        int mid = (low + high) /2;
        constSegUtil(2 * pos + 1, low, mid);       //left child
        constSegUtil(2 * pos + 2, mid +1, high);   //right child
        int lC = st[2 * pos + 1];
        int rC = st[2 * pos + 2];

        // cout << "\n For matches between " << low << " and " << high;
        // if either or the child has a value -1.. no match is played
        if (A[lC] == -1 || A[rC] == -1){
            // cout << "\n\t No matches will be played here";
            st[pos] = A[lC] > A[rC] ? lC : rC;
        }
        else{
            matches[lC] ++; matches[rC]++;
            // cout << "\n\t lC: " << lC << " : " << A[lC] << " and rC: " << rC << " : " << A[rC] << endl;
            // cout << "\n\tmatch["<<lC<<"] to: " << matches[lC];
            // cout << "\n\tmatch["<<rC<<"] to: " << matches[rC] << endl;
            st[pos] = A[lC] > A[rC] ? lC : rC;
            // cout << "\twinner is : " << max(A[lC], A[rC]) << " that is: " << st[pos] << endl;;
        }
    }
}

void initSegmentTree(){
    int sizeSegTree =  pow(2, int(ceil(log2(A.size()) ) )) * 2 -1;
    st.resize(sizeSegTree, 0);
    constSegUtil(0, 0, N -1);
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    _N = N;
    A.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    int nearPow = pow(2, int(ceil(log2(N))));
    for (int i = 0; i < nearPow - N; i++)
        A.push_back(-1);

    N = nearPow;
    matches.resize(nearPow, 0);
    // Now construct segment tree for the fights and as you're creating them,
    // the indices in comparison, should have their matches incereased by one
    initSegmentTree();

    // for (int i = 0; i < N; i++)
    //     cout << i << " played: " << matches[i] << " matches\n";

    while (Q --){
        cin >> xQuery;
        cout << matches[xQuery -1] << endl;
    }

    return 0;
}
