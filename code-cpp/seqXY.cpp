#include<bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;

#define MAX 1000005 
const ll MOD = 1e9 + 7;
int sp[MAX], isPrime[MAX];
vector<ll> primes;

ll T;
ll X, Y;

ostream & operator<<(ostream &c, vector<ll> &T){
    for (auto t : T){
        c << t << " ";
    }
    return c;
}

vector<ll> primeFactors(int n)  {  
    vector<ll> factors;
    factors.push_back(1);

    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        factors.push_back(2);
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            factors.push_back(i);
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2){
        factors.push_back(n);
    }
    return factors;
}  
  
bool isSubsetSum(vector<ll> set, int n, int sum) 
{ 
    // The value of subset[i][j] will be true if there is a  
    // subset of set[0..j-1] with sum equal to i 
    bool subset[n+1][sum+1]; 
   
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 
   
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 
   
     // Fill the subset table in botton up manner 
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<set[i-1]) 
         subset[i][j] = subset[i-1][j]; 
         if (j >= set[i-1]) 
           subset[i][j] = subset[i-1][j] ||  
                                 subset[i - 1][j-set[i-1]]; 
       } 
     } 
     cout << "\n";
     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", subset[i][j]); 
       printf("\n"); 
     }
     cout << "\n";
     return subset[n][sum]; 
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   
//    vector<ll> factors = primeFactors(20);
//    cout << "\n computed : " << factors;
//    cout << "\n is subset made " << isSubsetSum(factors, factors.size(), 4);
   
    cin >> T;

    while (T--){
        cin >> X, Y;
        //find prime factors of Y 
        vector<ll> factors = primeFactors(Y);
        bool canSubsetBeMade = isSubsetSum(factors, factors.size(), X);
        if (canSubsetBeMade){
            cout << factors.size() << "\n";
        }
        else{
            cout << "-1" << endl;
        }
    }

    return 0;
}