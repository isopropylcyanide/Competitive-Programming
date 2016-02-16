#include <iostream>
using namespace std;

int main()
{
        unsigned int n;
        int t,sa[200];
        cin>>t;

        while(t<=100 && t--)
        {
                cin>>n;
                int i,j,temp=0,x,m=1;
                sa[0]=1;

                for(j=2; j<=n; j++)
                {

                        for(i=0; i<m; i++)
                        {
                                x=sa[i]*j+temp;
                                sa[i]=x%10;
                                temp=x/10;
                        }
                        while(temp>0)
                        {
                                sa[m]=temp%10;
                                temp=temp/10;
                                m++;
                        }
                }
                for(i=m-1; i>=0; i--)
                        cout<<sa[i];

                cout<<endl;

        }
        return 0;
}
