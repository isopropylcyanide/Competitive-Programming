#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
//idea to calculate the sum of digits has been taken from the http://stackoverflow.com/questions/33602290/finding-the-digit-sum-in-a-arthematic-sequence,just for calculating the ap of sum of dgits
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        unsigned long long a,k;
        unsigned long long l,m;
        cin>>a>>k>>l>>m;
        long long a1[11],a2[11];
        unsigned long long  count1=m-l+1;
        unsigned long long  first=a+(l-1)*k;
for(long long i=1,j=first;i<=9;j=j+k,i++)
{
if(j%9==0)
{
a1[i]=9 ;
a2[i]=9;
}
else
{
a1[i]=j%9;
a2[i]=j%9;
}
}
 
unsigned long long k1=count1/9;
unsigned long long  k2=count1%9;
for(long long i=1;i<=9;i++)
{
    a1[i]=a1[i]*k1;
}
for(long long i=k2+1;i<=9;i++)
{
    a2[i]=0;
}
unsigned long long  sum=0;
for(long long i=1;i<=9;i++)
{
 
    sum=sum+a1[i]+a2[i];
}
cout<<sum<<"\n";
    }
    return 0;
}
