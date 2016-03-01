#include <bits/stdc++.h>

#define gc getchar_unlocked
#define MAX 100005
#define mod 1000000007
#define mod_inv 500000004
using namespace std;

typedef long long int llu;

llu fact_list[MAX],inv[MAX];

llu read_int () {
	bool minus = false;
	llu result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

/* CODE FOR AVL TREE REFERRED FROM GEEKS FOR GEEKS*/
struct node
{
    llu key;
    struct node *left;
    struct node *right;
    llu height;
    llu size;
};

llu max(llu a, llu b);

llu height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

llu size(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->size;
}

llu max(llu a, llu b)
{
    return (a > b)? a : b;
}

struct node* newNode(llu key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    node->size = 1;
    return(node);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    y->size = size(y->left) + size(y->right) + 1;
    x->size = size(x->left) + size(x->right) + 1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;

    return y;
}

llu getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, llu key, llu *count)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key, count);
    else
    {
        node->right = insert(node->right, key, count);

        *count = *count + size(node->left) + 1;
    }


    node->height = max(height(node->left), height(node->right)) + 1;
    node->size   = size(node->left) + size(node->right) + 1;

    llu balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void constructLowerArray (vector<llu>& arr, llu countSmaller[], llu n)
{
  llu i;
  struct node *root = NULL;

  for  (i = 0; i < n; i++)
     countSmaller[i] = 0;

  for (i = n-1; i >= 0; i--)
  {
     root = insert(root, arr[i], &countSmaller[i]);
  }
}

/* CODE REFERENCE ENDS*/

void precompute(){
	fact_list[0]=1,fact_list[1]=1;
	inv[0]=1,inv[1]=1;

	for(llu i=2; i<MAX; i++){
		fact_list[i]=(i*fact_list[i-1])%mod;
		inv[i]=(fact_list[i]*mod_inv)%mod;
	}

}

llu get_rotate(llu N,vector<llu>& P,vector<llu>& Q){
	llu stored=Q[0];
	llu ind= find(P.begin(),P.end(),stored)-P.begin();

	llu a_count=ind;
	llu equal=1;

	for(llu i=0; i<N; i++){
		if (P[a_count]!=Q[i]){
			equal=0;
			break;
		}
		a_count+=1;
		if (a_count==N)
			a_count=0;
	}

	if (equal)return stored;
	else return -1;
}

void  form (llu  a, vector<llu>& v){
	while(a<MAX){
		v[a]++;
		a+=a&-a;
	}
}

llu  get(llu a,vector<llu>& v){
	llu ans=0;
	while(a){
		ans+=v[a];
		a-=a&-a;
	}
	return ans;
}

llu _BIT_(vector<llu>& V,vector<llu>& P,llu &N){
	llu sum=0;

	for(llu i=N-1; i>=0; i--){
		sum+= get(P[i],V);
		form(P[i],V);
	}
	return sum;
}

llu get_parity(vector<llu>& P,llu &N){
	vector<llu> V(MAX,0);

	llu inversions=_BIT_(V,P,N);
	return pow(-1,inversions);
}

llu get_lexic_number_even(llu N,vector<llu>& Q){
	llu ans=1;

	llu count[N],number_of_smaller,f;
	constructLowerArray(Q,count,N);

	for(llu index=0; index<N; index++){
		f=fact_list[N-index-1];
		number_of_smaller=count[index];

		ans=(ans+(f*number_of_smaller)%mod)%mod;
	}
	return ans;

}

llu get_lexic_number(llu N,vector<llu>& Q){
	llu ans=mod_inv;

	llu count[N],number_of_smaller;
	constructLowerArray(Q,count,N);

	for(llu index=0; index<N-2; index++){
		number_of_smaller=count[index];

		ans=(ans+(inv[N-index-1]*number_of_smaller));
	}
	return ans;
}


void super_smart_work(vector<llu>& P,vector<llu>& Q,llu N){
	if (get_parity(P,N)==get_parity(Q,N)){
		llu base=get_lexic_number(N,Q);
		printf("%lld\n", (base+mod_inv)%mod);
	}

	else printf("-1\n");
}


int main(){
	llu testcases,N,K;
	precompute();
	testcases=read_int();

	while (testcases--){
		N=read_int();
		K=read_int();

		vector<llu>P;
		vector<llu>Q;

		for(llu i=0; i<N; i++)
			P.push_back(read_int());

		for(llu i=0; i<N; i++)
			Q.push_back(read_int());

		if (K==N)
			printf("%lld\n",get_rotate(N,P,Q));

		else if (K%2==0)
			printf("%lld\n",get_lexic_number_even(N,Q)%mod);

		else
			super_smart_work(P,Q,N);
	}



	return 0;
}
