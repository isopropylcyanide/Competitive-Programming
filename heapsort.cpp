#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a,int *b)
{
        *a=*a^*b;
        *b=*a^*b;
        *a=*a^*b;
}

int n,i,j,temp,*par,flag,int_state;
vector<int>A;
char child;

void printHeap(vector<int>H)
{
        for(int k=0; k<n; k++)
                cout<<" "<<H[k];
}

vector<int> create_heap(vector<int>H)
{
        for(i=1; i<n; i++)
        {
                j=i;    //j is the current index
                H[j]=A[j];

                printHeap(H); cout<<" :: ";
                while(j) { //recur j=parent until root

                        if (j&1) flag=1;
                        else flag=0;

                        if(flag) par=&H[j/2];  //to compare with the right parent
                        else par=&H[(j-1)/2];

                        if (H[j]>*par)
                                swap(H[j],*par);

                        //if element underwent swap,there is a possibility that the swapped up
                        //element is greater than its parent. Hence we need to continue checking.

                        //To check we set new parent according to whether its odd or even,eg
                        //3th pos,and swapped then 3/2=0 is new j, if at 4, (4-1)/2=1 is parent

                        if(flag) j=j/2;
                        else j=(j-1)/2;
                };

                printHeap(H); cout<<endl; //system("sleep 0.25");
        }
        return H;
}

vector<int> sort_heap(vector<int>H,int k,vector<int>S,int j,int int_state)
{
        if(!int_state)
        {
                S[k]=H[0];
                H[0]=H[k--];
        }

        if(j>=k) return S;

        int * bigger;
        cout<<"\n New Loop:-> j : "<<j<<" inter : "<<int_state<<" "; printHeap(H); cout<<" and : "; printHeap(S);

        if(int_state)
        {
                if (H[2*j+1]>H[2*j+2])
                        bigger=&H[2*j+1];
                else
                        bigger=&H[2*j+2];

                child=(*bigger==H[2*j+1]) ? 'l' : 'r';
        }

        else
        {
                if (H[1]>H[2])
                        bigger=&H[1];
                else
                        bigger=&H[2];

                child=(*bigger==H[1]) ? 'l' : 'r';
        }

        if (*bigger>H[j]) //swap root and bigger
        {
                cout<<"\n Root is : "<<H[j]<<" and bigger child : "<<*bigger;
                cout<<"\n Swapped "<<*bigger<<" and "<<H[j];
                swap(*bigger,H[j]);
                j=(child=='l') ? (2*j+1) : (2*j+2);
                int_state=1;
        }

        else{
                cout<<"\n The root : "<<H[j]<<" was the greatest : ";
                int_state=0;
                cout<<"\n Heap completed for root= "<<H[0]<<endl;
        }
        sort_heap(H,k,S,j,int_state);
        return S;
}

int main()
{
        cout<<"\n HEAP SORT PROGRAM \n";
        cout<<"\n Enter the input size: "; cin>>n;
        cout<<"\n Enter the input array : ";

        for(i=0; i<n; i++) {
                cin>>temp;
                A.push_back(temp);
        }

        vector<int>H(n);
        vector<int>S(n);
        H[0]=A[0];

        cout<<"\n Creating heap : \n\n";
        H=create_heap(H);
        cout<<"\n Heap successfully created. ";
        cout<<"\n Applying heapsort : \n";
        S=sort_heap(H,n-1,S,0,0);
        cout<<"\n Sorted heap : "; printHeap(S); cout<<"\n";
}
