#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <bits/stdc++.h>

using namespace std ;
using namespace __gnu_pbds;

#define mp make_pair
typedef long long ll;

typedef tree<
    pair<ll, ll>,
    null_type,
    less< pair<ll, ll> >,
    rb_tree_tag,
    tree_order_statistics_node_update
>
ordered_set ;


vector< vector<ll> > points ;
vector< vector<ll> > A ;
vector<ll> ans ;
vector<ll> T(5);
ll N ;

void solveHorizontal(){
    // Insert horizontal lines. For such a line you need to first add left most point
    // else if its a vertical line, add lower y with both x1 and x2
    ll x1, y1, x2, y2, id ;
    for(ll i = 0 ; i < N ; i++){
        x1 = A[i][0], y1 = A[i][1], x2 = A[i][2], y2 = A[i][3], id = i ;
        if(x1 == x2){
            if(y1 > y2)
                swap(y1, y2) ;

            T[0] = x1, T[1] = 0, T[2] = y1 ;
            T[3] = y2, T[4] = id;
            points.push_back(T) ;
        }
        else{
            if(x1 > x2)
                swap(x1, x2) ;

            T[0] = x2, T[1] = 1, T[2] = y1 ;
            T[3] = 0, T[4] = id;
            points.push_back(T) ;

            T[0] = x1, T[1] = -1, T[2] = y1 ;
            T[3] = 0, T[4] = id;
            points.push_back(T) ;
        }
    }
    sort(points.begin(), points.end()) ;
}

void solveVertical(){
    // Insert vertical lines. For such a line you need to first add lower y
    // else if its a horz line, add lower x with both y1 and y2
    ll x1, y1, x2, y2, id ;
    for(ll i = 0 ; i < N ; i++){
        x1 = A[i][0], y1 = A[i][1], x2 = A[i][2], y2 = A[i][3], id = i ;
        if(y1 == y2){
            if(x1 > x2)
                swap(x1, x2) ;

            T[0] = y1, T[1] = 0, T[2] = x1 ;
            T[3] = x2, T[4] = id;
            points.push_back(T) ;
        }
        else{
            if(y1 > y2)
                swap(y1, y2) ;
            T[0] = y2, T[1] = 1, T[2] = x1 ;
            T[3] = 0, T[4] = id;
            points.push_back(T) ;

            T[0] = y1, T[1] = -1, T[2] = x1 ;
            T[3] = 0, T[4] = id;
            points.push_back(T) ;
        }
    }
    sort(points.begin(), points.end()) ;
}

void solve(){
    ordered_set myset;

    for(ll i = 0 ; i < (ll)points.size() ; i++){
        T = points[i] ;
        ll type = T[1] ;
        if(type == 1){
            ll xy = T[2] ;
            myset.erase( mp(xy, 0) ) ;
        }
        else if(type == -1){
            ll xy = T[2] ;
            myset.insert( mp(xy, 0) ) ;
        }
        else{
            ll from = T[2] ;
            ll to = T[3] ;
            ll id = T[4] ;

            ll start = myset.order_of_key( mp(from, -1) )  ;
            ll end = myset.order_of_key( mp(to, 1) ) ;
            ans[id] += end - start ;
        }
    }
}

void removEndpoints(){
    map< pair<int, int>, int > counter ;
    for(int i = 0 ; i < N ; i++){
        counter[ mp(A[i][0], A[i][1]) ]++ ;
        counter[ mp(A[i][2], A[i][3]) ]++ ;
    }

    for(int i = 0 ; i < N ; i++){
        if(counter[ mp(A[i][0], A[i][1]) ] > 1)
            ans[i]-- ;
        if(counter[ mp(A[i][2], A[i][3]) ] > 1)
            ans[i]-- ;
    }
}

int main(){
    ios::sync_with_stdio(0) ;
    cin.tie(NULL);

    cin >> N ;
    A.assign(N, vector<ll>(4)) ;
    ans.assign(N, 0) ;

    for(ll i = 0 ; i < N ; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2] >> A[i][3] ;

    solveHorizontal() ;
    solve() ;
    points.clear() ;
    solveVertical() ;
    solve() ;

    removEndpoints() ;

    ll tot = 0 ;

    for(ll i = 0 ; i < N ; i++)
        tot += ans[i] ;

    cout << (tot/2) << "\n" ;

    for(ll i = 0 ; i < N ; i++)
        cout << ans[i] << " " ;

    return 0 ;
}
