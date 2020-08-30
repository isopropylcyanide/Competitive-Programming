#include<bits/stdc++.h>

typedef std::pair<int, int> pii;

ostream & operator <<(ostream &c, pii &a){
    c << "("<<a.first<<","<<a.second<<") ";
    return c;
}

int gcd(int a , int b)
{
   if(b == 0){
       return a;
   }
   a %= b;
   return gcd(b,a);
}

int max(int a , int b)
{
   return a > b ? a : b;
}

pii reduceFraction(int x, int y) 
{ 
    int d; 
    d = gcd(x, y); 
  
    x = x / d; 
    y = y / d; 
  
    return {x, y};
} 

ostream & operator <<(ostream &c, set<pii> &a){
    for (auto x : a){
        c << "("<<x.first<<","<<x.second<<") " << " | ";
    }
    return c;
}


ostream& operator<<(ostream &c, vector<vector<int>> vec){
    int N = vec.size();
    if (N != 0){
        int M = vec[0].size();
        for (int i = 0; i < N; i++){
            c << "_ ";
        }
        c << endl;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                c << vec[i][j] << "|" ;
            }
            c << endl;
        }
    }
    c << endl;
    return c;
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        std::map<pii, std::set<pii>> slopePointMap;

        for (int i = 0; i < points.size() - 1; i++){
            for (int j = i + 1; j < points.size(); j++){
                std::cout << "\n*********************************************";
                std::cout << "\n\n Making pair (" << i << ", " << j << ")";
          
                std::cout << "\nP1: (" << points[j][0] << ", " << points[j][1] << ")" << std::endl;
                std::cout << "\nP2: (" << points[i][0] << ", " << points[i][1] << ")" << std::endl;
                int y_slope = points[j][1] - points[i][1];
                int x_slope = points[j][0] - points[i][0];
                if (y_slope == 0 && x_slope == 0){
                    continue;
                }
                pii slopePair = make_pair(x_slope, y_slope);
                std::cout << "\n Slope pair: " << slopePair;
                
                pii reducedPair = reduceFraction(x_slope, y_slope);
                std::cout << "\n Reduced pair: " << reducedPair ;
                // if (slopePointMap.find(slopePair) != slopePair.end()){
                slopePointMap[reducedPair].insert({points[j][0], points[j][1]});
                slopePointMap[reducedPair].insert({points[i][0], points[i][1]});
               
            }
        }
        //At the end, find the largest value
        int ans = points.size() == 0 ? 0 : 1;
        for( auto it = slopePointMap.begin(); it != slopePointMap.end(); ++it ){
             ans = max(ans, (it -> second).size());
        }
        return points.size() == 0 ? 0 : ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    std::vector<vector<int>> v = {
                {1, 1},
                {3, 2},
                {5, 3},
                {4, 1},
                {2, 3},
                {1, 4}
    };
    Solution solution;
    std::cout << solution.maxPoints(v) << std::endl;
}
