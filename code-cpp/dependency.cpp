#include <bits/stdc++.h>
using namespace std;

//Copied from Net---//
#define MAX 100001

struct myFunc {
        bool operator() (const pair<int,int>& a, const pair<int,int>& b)
        {
                if (a.first==b.first) return a.second>b.second;
                else return a.first>b.first;
        }
};
//----------//

vector <int> newArr[MAX];

int solve(int current,int hash[]){
        if (hash[current]) return hash[current];
        hash[current] = 1;
        for (vector<int>::iterator it = newArr[current].begin(); it!=newArr[current].end(); it++) solve(*it,hash);
        return 0;
}


int main(){

        int t;
        cin >> t;
        while(t--) {
                int n,m,x,temp;
                cin>>n>>m;
                int hashArray[n+1];
                memset(hashArray,0,sizeof(hashArray));
                priority_queue < pair<int,int>, vector < pair<int,int> >, myFunc > que;
                int howMany[n+1];
                vector <int> arr[n+1];
                vector <int> rsAggarwal;

                for(int i=0; i<n+1; i++)
                        howMany[i] = 0;

                for (int i=1; i<=n; i++)
                {
                        cin>>x;
                        howMany[i] = x;
                        while(x--)
                        {
                                cin>>temp;
                                arr[temp].push_back(i);
                                newArr[i].push_back(temp);
                        }
                }

                int toBeInst[m+1];
                for (int i=0; i<m; i++)
                        cin>>toBeInst[i];



                for (int i=1; i<=n; i++) {
                        if (!howMany[i])
                                que.push(make_pair(howMany[i],i));
                }

                while(!que.empty()) {
                        int q = que.top().second;
                        que.pop();
                        if (!hashArray[q])
                        {
                                for (vector<int>::iterator it = arr[q].begin(); it!=arr[q].end(); it++) {
                                        howMany[*it]--;
                                        que.push(make_pair(howMany[*it],*it));
                                }
                                rsAggarwal.push_back(q);
                                hashArray[q] = 1;
                        }
                }

                memset(hashArray,0,sizeof(hashArray));

                for (int i=0; i<m; i++)
                        solve(toBeInst[i],hashArray);

                vector<int> ans;
                int counter = 0;

                for (vector<int>::iterator it = rsAggarwal.begin(); it!=rsAggarwal.end(); it++) {
                        if (hashArray[*it]) {
                                ans.push_back(*it);
                                counter++;
                        }
                }
                cout<<counter<<"\n";
                for (int i=0; i<counter; i++)
                        cout<<ans[i]<<" ";
                printf("\n");
                for (int i=0; i<MAX; i++)
                        newArr[i].clear();
        }
}
