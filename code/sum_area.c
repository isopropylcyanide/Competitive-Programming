#include<stdio.h>

int pre[3][3];

int arr[3][3] = {
                {0,1,4},
                {2,3,2},
                {1,2,7}
                };

void preprocess()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i>0 && j>0)
            {
                 pre[i][j] = arr[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
            else if(i>0 && j==0)
            {
                pre[i][j] = arr[i][j] + pre[i-1][j];
            }
            else if(j>0 && i==0)
            {
                pre[i][j] = arr[i][j] + pre[i][j-1];
            }
            else
            {
                pre[i][j] = arr[i][j];
            }                    
        }
    }
}

int subsum(int x1, int y1, int x2, int y2)
{
    preprocess();

    int ans = pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
    return ans;
}

int main()
{            
    printf("%d\n",subsum(1,1,2,2));
    return 0;
}
