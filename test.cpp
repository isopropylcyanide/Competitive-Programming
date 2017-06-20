#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int t,n,k;
string s;

void minRemoval(){
        //Toggle bits so that size of largest consecutive component is minimized
        int last = 0, end = 0, c = 0, cc = 0;
        multiset<pii > v;
        v.clear();
        for(int i=0; i<n; i++) {
                if(s[i] == '1' && c == 0) {
                        cc = i, last = i, end = i;
                        c++;
                }
                else if(s[i] == '1' && c > 0)
                        end = i;
                else if(c > 0)
                {
                        if(cc == 0)
                                v.insert(make_pair(end - last + 1, 0));
                        else
                                v.insert(make_pair(end - last + 1, end - last + 1));
                        c = 0;
                }
        }
        if(s[n - 1] == '1')
                v.insert(make_pair(end - last + 1, n - 1));
        c = 0, cc = 0;
        for(int i = 0; i < n; i++) {
                if(s[i] == '0' && c == 0) {
                        cc = i, last = i, end = i;
                        c++;
                }
                else if(s[i] == '0' && c > 0)
                        end = i;
                else if(c > 0) {
                        if(cc == 0)
                                v.insert(make_pair(end - last + 1, 0));
                        else
                                v.insert(make_pair(end - last + 1,end - last + 1));
                        c = 0;
                }
        }
        if(s[n-1] == '0')
                v.insert(make_pair(end-last+1,n-1));
        multiset<pii >::iterator itr;
        if(v.size() >= 1) {
                while(k > 0) {
                        multiset<pii >::iterator itr=v.end();
                        itr--;
                        if((*itr).first == 2)
                                break;
                        pii a = *itr;
                        if(a.first % 2 == 0) {
                                k--;
                                v.erase(itr);
                                v.insert(make_pair(a.first / 2, (*itr).second));
                                v.insert(make_pair(a.first / 2 - 1,(*itr).second));
                        }
                        else{
                                k--;
                                v.erase(itr);
                                v.insert(make_pair(a.first / 2,(*itr).second));
                                v.insert(make_pair(a.first / 2,(*itr).second));
                        }
                }
        }
        if(k > 0) {
                int c = 0;
                for(itr = v.begin(); itr != v.end(); itr++) {
                        int a =( *itr).first,b=(*itr).second;
                        if((b == 0 || b % 2 !=0) && a == 2)
                                c++;
                }
                if(c / 2 <= k)
                        cout << 1<< endl;
                else
                        cout << 2 <<endl;
        }
        else
                cout << (*(--v.end())).first<<endl;
}

int main(){
        cin>>t;
        while(t--) {
                cin >> n >> k;
                cin >> s;
                minRemoval();
        }
        return 0;
}
