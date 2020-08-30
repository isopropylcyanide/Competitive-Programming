#include <bits/stdc++.h>
using namespace std;

int main(){

	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);

	int mh[6][5];
	int mv[5][6];

	for(int i=0; i<6;i++)
		for(int j=0; j<5; j++)
			cin>>mh[i][j];

	for(int i=0; i<5;i++)
		for(int j=0; j<6; j++)
			cin>>mv[i][j];

	 int initial_possible = 0;
	 int shape_1=0;				// |-|
	 int shape_2=0;				// |_|
	 int shape_3=0;				// =|
	 int shape_4=0;				// |=

	 //Count Shape-1
	 for(int i=0; i<5;i++)
		for(int j=0; j<5; j++)
			if (mh[i][j]==1 && mv[i][j]==1 && mv[i][j+1]==1)
					shape_1+=1;
		

	 //Count Shape-2
	 for(int i=1; i<6;i++)
		for(int j=0; j<5; j++)
			if (mh[i][j]==1 && mv[i-1][j]==1 && mv[i-1][j]==1)
					shape_2+=1;
			
		

	//Count Shape-3
	 for(int i=0; i<5;i++)
		for(int j=1; j<6; j++)
			if (mv[i][j]==1 &&  mh[i][j]==1 && mh[i-1][j]==1)
					shape_3+=1;
		
	//Count Shape-4
	 for(int i=0; i<5;i++)
		for(int j=0; j<4; j++)
			if (mv[i][j]==1 &&  mh[i][j]==1 && mh[i+1][j]==1)
					shape_4+=1;

	if (shape_1==shape_3==shape_2==shape_4==0){
		int flag=0;

		 for(int i=0; i<6;i++)
			for(int j=0; j<5; j++)
				if (mh[i][j]==0){
					mh[i][j]=1;
					flag=1;
					break;
				}
		
		for(int i=0; i<5;i++)
			for(int j=1; j<6; j++)
				if (mv[i][j]==0){
					mv[i][j]=1;
					flag=1;
					break;
				}
	}

	else if (max(shape_1,shape_2)>max(shape_4,shape_3)){
		if (shape_1>shape_2)
			mh[shape_1-1][shape_2-1]=1;
		
		else 
			mh[shape_2-1][shape_1-1]=1;
	}

	else {
		if (shape_3>shape_4)
			mv[shape_3-1][shape_4-1]=1;
		
		else
			mv[shape_3-1][shape_4-1]=1;
	}


	for(int i=0; i<6;i++){
		for(int j=0; j<5; j++)
			cout<<mh[i][j]<<" ";
		cout<<endl;
	}

	for(int i=0; i<5;i++){
		for(int j=0; j<6; j++)
			cout<<mv[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}