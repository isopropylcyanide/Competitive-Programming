
#include <bits/stdc++.h>
using namespace std;


typedef long long llu;

#define max 10000002
#define ROOT 500
#define gc getchar_unlocked

 llu read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  llu ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}


llu prime[max + 1];
llu T[max + 1];
llu T_C[10001];
vector<llu> sieve;


void normal_sieve(){
  llu i=2;

    while (i*i<max){

        if(prime[i]==0)
          for(llu j=i*i; j<max; j+=i)
              prime[j]=1;
        // }
        i+=1;
    }
}

void sequenceSieve(){
    vector<llu>prime;
    vector<bool>V;
    prime.resize(max);
    V.resize(max);

    for (int i = 2; i < max; i +=2)
        prime[i] = 2;

    for (int i = 3; i < max; i +=2)
        if (!V[i]){
            prime[i] = i;
            for (llu j = i; (j*i) < max; j += 2){
				if (!V[j*i]){
                    V[j*i] = true;
                    prime[j*i] = i;
			    }
            }
        }
}
void precompute()
{
    T[1] = 1;
    for (llu i = 2; i<= max; ++i)
    {
        if (prime[i] == 0)
        {
            prime[i] = i;
            T[i] = i - 1;
            sieve.push_back(i);
        }
        else
        {
            //Calculating T
            if (prime[i] == prime[i / prime[i]])
                T[i] = T[i / prime[i]] * prime[i];
            else
                T[i] = T[i / prime[i]] * (prime[i] - 1);
        }
        for (llu j = 0; j < (llu)sieve.size() && sieve[j] <= prime[i] && i * sieve[j] <= max; ++j)
            prime[i * sieve[j]] = sieve[j];
    }


    for(llu N=1; N<=10000; N++){

        if(prime[N]==N){
          T_C[N] = N*(N-1) + 1;
          continue;
        }

      llu ans =0;

      for(llu i=1; i*i<=N; i++){

        if (N%i==0)
          ans += T[i]*i;

        if (N%(N/i)==0 && i!=(N/i))
          ans += T[N/i]*(N/i);
        }

        T_C[N]=ans;

    }
}


inline llu factorize(llu x){
  /*Once we have the minimum prime we can have others easily*/

  if(x == 1)
  	return 1;

  double ans = x;
  set<llu>primeFactors;

  while (prime[x]>0){
    primeFactors.insert(prime[x]);
    x/=prime[x];
  }

  primeFactors.insert(x);

  set<llu>:: iterator si = primeFactors.begin();
  for (; si!= primeFactors.end() ; ++si)
  	if (*si!=1)
  		ans *= 1 - 1.0/(*si);

    return ans;
}

void solve(){
	 llu testcases,N;
    testcases = read_int();

    while(testcases--){

      N = read_int();

      if(N<=10000){
        printf("%lld\n",T_C[N]+1);
        continue;
      }

      if(prime[N]==N){
        printf("%lld\n",N*(N-1) +1);
        continue;
      }


      llu ans =0;
      for(llu i=1; i*i<=N; i++){

        if (N%i==0)
          ans += T[i]*i;

        if (N%(N/i)==0 && i!=(N/i))
          ans += T[N/i]*(N/i);

      }
        printf("%lld\n",ans+1);
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    precompute();

    solve();



    return 0;
}
