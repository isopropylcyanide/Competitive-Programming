#include<bits/stdc++.h>
using namespace std;

         
/**
 *   1      2
 *    2    1     
 *  
 *          3 
 *        2
 *      1
 *   2
 * 1   3
 * 
 * */
 

int numTrees(int n) {
        if(n == 0) return ;
        
        if(n == 1) return 1;
        
        if(n == 2) return 2;
        
        int ans = 0;
        
        for(int i = 1; i<=n; i++){
            ans += numTrees(i-1)*numTrees(n - i);
        }
        
        return ans;
}

int main(){
    int n;
    cin >> n;
    cout << numTrees << endl;
    
}
    