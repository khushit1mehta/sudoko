#include <iostream>
#include <cmath>
using namespace std;


bool is_valid(int mat[][9],int i,int j,int num ,int n){

	//row 

	for(int k=0;k<n;k++){
		if(mat[i][k] == num){
			return false;
		}
	}

	//column

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
	cout<<endl<<" --------Solution------- "<<endl;

	sudokosolver(mat,0,0,9);

	return 0;
}
