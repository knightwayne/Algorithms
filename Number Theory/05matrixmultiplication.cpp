#include<iostream>
using namespace std;

int main()
{
	int x,y,z;
	cout<<"Size of matrix1 and matrix2(just 3)\n";
	cin>>x>>y>>z;
	int arr1[x][y], arr2[y][z], arr[x][z];
		
	cout<<"Matrix1\n";
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			cin>>arr1[i][j];
		}
	}
	cout<<"Matrix2\n";
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<z;j++)
		{
			cin>>arr2[i][j];
		}
	}
	
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<z;j++)
		arr[i][j]=0;
	}
	
	cout<<"Matrix1\n";
	for(int i=0;i<x;i++)
	{	
		for(int j=0;j<y;j++)
		{
			cout<<arr1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Matrix2\n";
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<z;j++)
		{
			cout<<arr2[i][j]<<" ";
		}
		cout<<endl;
	}
		
	cout<<"Matrix Result\n";
	
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<z;j++)
		{
			for(int k=0;k<y;k++)
			{
				arr[i][j]+=arr1[i][k]*arr2[k][j];
			}
		}
	}
	
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<z;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
	
