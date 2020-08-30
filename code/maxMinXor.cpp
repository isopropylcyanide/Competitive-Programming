#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define MAX 200005

void scanint(int &x){
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int t, n, k;
int A[MAX];

struct node{
        int data;
        struct node * left;
        struct node * right;
        int pos;
};

struct node * root;

void generateBinary(int n);
int findMax(struct node *, struct node *);
int bits;

void generateBinary(int n)
{
    int binary[bits];
    for(int i=bits-1; i>=0; i--)
    {
            int k = n >> i;

            if(k & 1)
              binary[bits-i-1] = 1;
            else
              binary[bits-i-1] = 0;
    }

    struct node * p = root;
    for(int i=0; i<bits; i++)
    {
            if(binary[i] == 0)
            {
                    if(!p->left)
                    {
                            struct node * q = new struct node;
                            q->data = 0;
                            q->pos = bits-i-1;
                            p->left = q;
                    }
                    p = p->left;
            }
            else
            {
                    if(!p->right)
                    {
                            struct node * q = new struct node;
                            q->data = 1;
                            q->pos = bits-i-1;
                            p->right = q;
                    }
                    p = p->right;
            }
    }
}

int findMax(struct node * p, struct node * q)
{
        if(p == root)
        {
                if(p->left && p->right)
                  return (findMax(p->left, p->right));
                if(p->left)
                  return (findMax(p->left, p->left));
                if(p->right)
                  return (findMax(p->right, p->right));
        }
        if(p->pos == 0)
        {
                return (p->data ^ q->data);
        }
        int x = pow(2, p->pos);

        int value = x * (p->data ^ q->data);

        if((p->left && q->right) || (p->right && q->left))
        {
                int x1 = 0, x2 = 0;

                if(p->left && q->right)
                {
                        x1 = value + findMax(p->left, q->right);
                }
                if(p->right && q->left)
                {
                        x2 = value + findMax(p->right, q->left);
                }
                return (max(x1, x2));
        }

        if(!p->right && !q->right)
        {
                return(value + findMax(p->left, q->left));
        }
        if(!p->left && !q->left)
        {
                return(value + findMax(p->right, q->right));
        }
        return 0;
}

int findMin(struct node * p, struct node * q)
{
        if(p == root)
        {
                if(p->left && p->right)
                  return (findMin(p->left, p->right));
                if(p->left)
                  return (findMin(p->left, p->left));
                if(p->right)
                  return (findMin(p->right, p->right));
        }
        if(p->pos == 0)
        {
                return (p->data ^ q->data);
        }
        int x = pow(2, p->pos);

        int value = x * (p->data ^ q->data);

        if((p->left && q->right) || (p->right && q->left))
        {
                int x1 = 0, x2 = 0;

                if(p->left && q->right)
                {
                        x1 = value + findMin(p->left, q->right);
                }
                if(p->right && q->left)
                {
                        x2 = value + findMin(p->right, q->left);
                }
                return (min(x1, x2));
        }

        if(!p->right && !q->right)
        {
                return(value + findMin(p->left, q->left));
        }
        if(!p->left && !q->left)
        {
                return(value + findMin(p->right, q->right));
        }
        return 0;
}

int main(){
    scanint(t);
    while (t--){
        scanint(n);
        memset(A, 0, sizeof(A));
        root = new struct node;

        root -> data = 0;
        bits = 0;

        for (int i =  0; i < n; i++){
            scanint(A[i]);
            if (A[i] > bits)
                bits = A[i];
        }
        if (bits == 0)
            bits = 1;
        else
            bits = log2(bits) + 1;

        for (int i = 0; i < n; i++)
            generateBinary(A[i]);

        struct node * p = root;
        int maxm =  findMax(root, root);
        sort(A, A + n);
        int minm = INT_MAX;
        for (int i = 0; i < n-1; i++)
            minm = min(minm, A[i] ^ A[i -1]);

        scanint(k);
        if (maxm - minm > k)
            printf("YOU ARE READY.\n");
        else printf("YOU HAVE TO WAIT.\n");
    }
    return 0;
}
