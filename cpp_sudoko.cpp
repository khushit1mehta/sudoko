#include <iostream>
#include <cmath>
using namespace std;


bool is_valid(int mat[][9],int i,int j,int num ,int n){

	//row cosr

	for(int k=0;k<n;k++){
		if(mat[i][k] == num){
			return false;
		}
	}

	//co

	for(int k=0;k<n;k++){
		if(mat[k][j]==num){
			return false;
		}
	}


	n = sqrt(n);

	int src = (i/n)*n;

	int scc = (j/n)*n;

	for(int p= src; p< src + n ;p++){
		for(int q = scc ;q<scc + n;q++){
			if(mat[p][q] == num){
				return false;
			}
		}
	}

	return true;

}



bool sudokosolver(int mat[][9],int i,int j,int n){

	//base case

	if(i == n){
		for(int k = 0;k<n;k++){
			for(int m=0;m<n;m++){
				cout<<mat[k][m]<<" ";
			}
			cout<<endl;
		}
		//cout<<endl;

		return true;
	}

	if(j==n){
		return sudokosolver(mat,i+1,0,n);
	}

	if(mat[i][j]!=0){

		return sudokosolver(mat,i,j+1,n);
	}

	// ek kamm mereko krna h

	for(int num = 1 ;num<= 9;num++){

		if(is_valid(mat ,i,j,num,n)){
			mat[i][j] = num;

			bool answer_will = sudokosolver(mat,i,j+1,n);

			if(answer_will){
				return true;
			}
			
			mat[i][j] = 0;

		}
	}

	return false;


}

int main()
{

	int mat[9][9];
	int n; 

	cin>>n;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
cout<<endl<<"answer"<<endl;

	sudokosolver(mat,0,0,9);

	return 0;
}
/*
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
*/
/*
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
*/