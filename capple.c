#include <stdio.h>

int main()
{
        int test,n,apple,i;
        scanf("%d",&test);

        while(test--)
        {
                int arr[100010]={0};
                int count=0;

                scanf("%d",&n);
                for(i=0; i<n; i++)
                {
                        scanf("%d",&apple);
                        arr[apple]++;
                }

                for(i=0; i<100010; i++)
                {
                        if(arr[i]!=0)
                                count++;
                }

                printf("%d\n",count);
        }
        return 0;
}
