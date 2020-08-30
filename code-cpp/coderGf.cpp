#include<bits/stdc++.h>
using namespace std;
string tostring(long long n)
{
   string s;
   while(n!=0)
  {
      s+=(n%10)+'0';
      n/=10;
   }
    reverse(s.begin(), s.end());
    return s;
}

long long dp[20][2][60]; //dp[index][smaller][remainder]

//For integers, the sum of digits can't be greater than 82

long long k, a, b;

string s;

long long dp_solve(string & s,int index,bool smaller,int mod1)
{
 if(index==s.length())
 {
        if(mod1==0)
        {
            return 1;

         }
     return 0;

 }
  if(dp[index][smaller][mod1]!=-1)
      {
       return dp[index][smaller][mod1];

      }
    else
    {
        int limit=9;

        if(smaller)
        {
            limit=s[index]-'0';
        }
        long long init_count=0;

        for(int i=0;i<=limit;i++)
        {
            bool ns;
            if(i<s[index]-'0')
            {
                ns=0;
            }
            else
            {
                ns=smaller;
            }

            init_count+=dp_solve(s, index+1, ns,(mod1 % k +(i * i * i) % k)%k);

        }


        dp[index][smaller][mod1]=init_count;
        return init_count;

    }

}


int main()
{
    int T;
    scanf("%d", &T);

    while (T--){
      //Find numbers between A and B whose sum of digits is divisible by K
      scanf("%lld %lld %lld",&a, &b, &k);

      //If A and B are ints, then the sum of the digits can't be greater than 82
        if(k>51)
        {
        cout<<"0\n";
        }

        string s=tostring(a-1);
        string s2=tostring(b);

        memset(dp,-1,sizeof(dp));
        long long a1=dp_solve(s,0,1,0); //Solving for a-1

        memset(dp,-1,sizeof(dp));
        long long a2=dp_solve(s2, 0, 1, 0); //Solving for b

        printf("%lld\n",a2-a1);
    }

    return 0;
}
