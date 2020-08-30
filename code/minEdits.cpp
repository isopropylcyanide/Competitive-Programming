#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
      string n,x ,y;
       cin>>n;

       int cnt=0;

       if(n.size()%2 != 0){
                x=n.substr(0,n.size()/2);
                y=n.substr(n.size()/2+1);
               reverse(y.begin(),y.end());
          }
    else if(n.size()%2==0){
        x=n.substr(0,n.size()/2);
        y=n.substr(n.size()/2);
        reverse(y.begin(),y.end());
    }
        for(int i=0;i<n.size();i++)
            if(x[i]!=y[i])
            cnt++;
      cout<<cnt<<endl;
    //   cout << " x: " << x << " y: " << y << endl;
      if (x < y){
          string yy(x);
          reverse(yy.begin(),yy.end());
          cout << x + yy << endl;
      }
      else{
          string yy(y);
          reverse(yy.begin(),yy.end());
          cout << y + yy << endl;
      }
      return 0;

  }
