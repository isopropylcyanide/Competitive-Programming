#include<iostream>
#include<algorithm>
#define llu long long unsigned

int main()
{
  llu n,x,k,p,c,y; int t,flag;
  std::cin>>t;

  while (t--)
  {
    std::cin>>x>>y>>k>>n;
    flag=0;

    while (!flag && n)
     {	
       std::cin>>p>>c;
       if (p>=(x-y) && k>=c)
	   {flag=1; break;}
       n--;
     }	
    if (flag)
	std::cout<<"LuckyChef\n";
    else std::cout<<"UnluckyChef\n";
    t--;
  }
  return 0;
}
