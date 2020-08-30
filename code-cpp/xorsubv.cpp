#include <iostream>
#include <vector>
	using namespace std;
						//maximum value of K ⊕ F(P), over all possible subsets P of A?

unsigned t,n,k,i,j;
unsigned *set=new unsigned[1000];  		
  					
  long long unsigned power(unsigned x,unsigned n)
  {
    long long unsigned pro=1;
    for (i=0; i<n; i++)
    pro*=x;
    return pro;
  }

  int main()
 {
   cin>>t;
   
   while(t>=1 && t<=10)
  {
    cin>>n;
    cin>>k;
    
    for(i=0; i<n; i++)
    cin>>set[i];
    
    long long unsigned pow_set_size=power(2,n);
    long long unsigned counter,maximum=0,tmp=0;
 
    vector<long long unsigned>temp;
    
    for(counter = 0; counter < pow_set_size; counter++)
    {
      for(j=0; j<n; j++)
       {
          if(counter & (1<<j))
            tmp^=set[j];
       }
       temp.push_back(tmp^k);
       maximum=((tmp^k)>=maximum)?(tmp^k):maximum ;
       tmp=0;
    }

    cout<<maximum<<endl;
    temp.clear();
     t--;
   }
   
   return 0;
 } 
   
    
