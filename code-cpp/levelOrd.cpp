#include <bits/stdc++.h>
using namespace std;

/*Print a line by line level order traversal*/

struct Tree {
     int val;
     Tree *left, *right, *next;
     Tree(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void levelOrd(Tree* A) {
    //levelOrd next pointers.
    queue<Tree*> q;
    if (!A || (!(A -> left) && !(A -> right)))
        return;

    q.push(A);
    q.push(NULL); //insert null marker initially for the root
    Tree *cur = NULL;

    while (!q.empty()){
        cur = q.front();
        q.pop();

        if (cur == NULL){
             //if we received a NULL marker, then it signifies end of the level
            cout << endl;
            if (!q.empty())
                q.push(NULL);   //don't forget to push NULL again
            continue;
        }
        cout << cur -> val << " ";
        if (cur -> left)
            q.push(cur -> left);
        if (cur -> right)
            q.push(cur -> right);
    }
}

int main(){
    /*
                1
              /   \
             2     3
            / \   /  \
           4   5 6    7
    */
    Tree * t = new Tree(1);
    t -> left = new Tree(2);
    t -> right = new Tree(3);
    t -> left -> left = new Tree(4);
    t -> left -> right = new Tree(5);
    t -> right -> left = new Tree(6);
    t -> right -> right = new Tree(7);

    levelOrd(t);
    return 0;
}
