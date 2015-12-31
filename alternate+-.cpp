#include<bits/stdc++.h>
using namespace std;

static int num=0;

int * merge(int *a){
	int neg=0,pos=0,k=0;
	int *merged=(int*)calloc(num,sizeof(int));

	for(int i(0); i<num; i++)
		if(a[i]>0){
			pos=i;
			break;
	}

	while(neg<=pos-1 && pos<num-1){
		merged[k++]=a[neg];
		merged[k++]=a[pos];
		neg++; pos++;
	}

	while(neg<=pos){
		merged[k++]=a[neg];
		neg++;
	}
	while(pos<num-1){
		merged[k++]=a[pos];
		pos++;
	}
 return merged;
}

void quick_divide(int low,int high,int* a){

 if(low<high){
 	int i=low,j=high,par=0;
	
	while(i<j){
			
		while(i<=high){
			if (a[i]<par)
				i++;
			else break;
	   }

		while(j>=low){
			if (a[j]>par)
				j--;
			else break;
	   }	
		if(i>=j)return;
		swap(a[i],a[j]);		
	}
  }
}

int main(int argc, char const *argv[])
{
	assert(argc>2);
	num=argc-1;

	int *a=(int*)calloc(num,sizeof(int));
	for (int i=1; i<argc; i++)
		a[i-1]=atoi(argv[i]);

	quick_divide(0,num-1,a);
	cout<<"\n Divided Order: ";
		for(int i=0; i<num; i++)
			cout<<" "<<a[i];

	a=merge(a);

	cout<<"\n Alternate Order: ";
		for(int i=0; i<num; i++)
			cout<<" "<<a[i];

	cout<<endl;
	return 0;
}