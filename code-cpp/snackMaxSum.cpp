#include<bits/stdc++.h>
using namespace std;

int func(int arr[],int curr,int size,int max_so_far,int curr_max,int done) // done is 0 if no element is being removed
{                                                                          // done is 1 if element is ignored
   if(curr==size)
   {
        return max_so_far;
   }
   else
   {
        int curr_max_temp=max(arr[curr], curr_max+arr[curr]);
        int max_so_far_temp=max(max_so_far, curr_max_temp);

        if(done==0)
            return max( func(arr,curr+1,size,max_so_far,curr_max,1) , func(arr,curr+1,size,max_so_far_temp,curr_max_temp,0) );
        else
            return func(arr,curr+1,size,max_so_far_temp,curr_max_temp,1);
   }
}

int funcDP(int arr[], int N){
    int T[3][N];
    // T[i][j] = jth index is removed/notremoved

    T[0][0] = T[2][0] = arr[0]; //don't remove // max so far
    T[1][0] = max(0, arr[0]);    //remove

    int max_ending_here = arr[0], max_so_far = arr[0];

    for (int i = 1; i < N; i++){
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);

        T[0][i] = max_so_far;
        T[2][i] = max_ending_here;
    }

    for (int i = 1; i < N; i++){
        if (T[2][i - 1] < 0)
            T[1][i] = max(T[1][i -1], T[0][i -1] + arr[i]);
        else
            T[1][i] = max(T[1][i -1], max(T[1][i -1] + arr[i],
                            max(T[0][i -1],
                                    T[0][i])));
    }

    for (int j = 0; j < 3; j++){
        for (int i = 0; i < N; i++)
            cout << T[j][i] << " ";
        cout << endl;
    }

    return max(T[0][N -1], T[1][N -1]);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=func(arr,1,n,arr[0],arr[0],0);
    cout<<ans<<"\n";
    cout << funcDP(arr, n) << endl;
    }
}
