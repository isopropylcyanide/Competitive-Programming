#include <bits/stdc++.h>
using namespace std;

/*
You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P

*/
#include <bits/stdc++.h>
using namespace std;

/*
You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P

*/

 struct RopeNode { //Rope Data Structure
     int height;
     int count; //store count in leftSubTree + 1
     RopeNode *left;
     RopeNode *right;
     RopeNode(int x) : height(x), count(1), left(NULL), right(NULL) {}
 };

 vector<int> inorderTraversal(RopeNode* A) {
     //Performs iterative inorder traversal
     vector<int> ans;
     if (!A)
         return ans;

     stack<RopeNode *> s;
     RopeNode *p = A;
     while (p){
         s.push(p);
         p = p-> left;
     }

     while (!s.empty()){
         p = s.top();
         ans.push_back(p -> height);
         s.pop();
         if (p -> right){
             p = p -> right;
             while (p){
                 s.push(p);
                 p = p-> left;
             }
         }
     }
     return ans;
 }

 bool compare(pair<int, int> a, pair<int, int> b){
    //Custom comparator for the map
    if (a.first > b.first)
        return true;
    return false;
}

RopeNode * insert(RopeNode *root, int newHeight, int curCount){
    //Inserts a new node in the rope data structure. Don't forget to change the height of the subtree
    if (root == NULL)
        root = new RopeNode(newHeight);

    else if (root -> count > curCount){
        root -> count += 1;
        root -> left = insert(root -> left, newHeight, curCount);
    }

    else if (root -> count <= curCount){
        curCount = (curCount - root -> count < 0) ? 0 : curCount - root -> count;
        root -> right = insert(root -> right, newHeight, curCount);
    }

    return root;
}


vector<int> order(vector<int> &heights, vector<int> &infronts) {
     //You need to return list of actual order of persons’s height
     vector<pair<int, int> > P;

     if (heights.empty()  || (heights.size() == 1))
        return heights;

     for (int i = 0; i < heights.size(); i++)
        P.push_back(make_pair(heights[i], infronts[i]));

    sort(P.begin(), P.end(), compare);

    RopeNode * t = new RopeNode(P[0].first);
    RopeNode * r;

    for (int i = 1; i < P.size(); i++){
        r = t;
        insert(r, P[i].first, P[i].second);
    }

    vector<int> orderedH = inorderTraversal(t);
    return orderedH;
 }



int main(){
    vector<int> H = {86, 92, 49, 21, 62, 27, 90, 59};
    vector<int> F = {2, 0, 0, 2, 0, 2, 1, 3};
    for (auto a : order(H, F))
        cout << a << " ";

    return 0;
}
