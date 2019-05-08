#include<iostream>
using namespace std;

void display(int **a, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return;
}
void matmul(int **x, int **y, int **z, int n)
{
	//cout<<"Bring me Thanos\n";
	//display(x,n);display(y,n);display(z,n);
	//this shit isn't working god knows why
	//working when different a,b and c are sent from passing function
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int val=0;
			for(int k=0;k<n;k++)
			{
				val+=(x[i][k]*y[k][j]);
			}
			z[i][j]=val;
		}
	}
	
	//cout<<"Loading: Thanos\n";
	//display(x,n);display(y,n);display(z,n);
	return;
}
void matexpo(int **x, int **y, int n, int k)
{
	if(k==1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				y[i][j]=x[i][j];
			}
		}
		return;
	}
	else if(k==2)
	{
		matmul(x,x,y,n);
		return;
	}
	else
	{
		matexpo(x,y,n,k/2);
		
		int **temp = new int*[n];
		for(int i=0;i<n;i++)
		{
			temp[i] = new int[n];
		}
		//matmul(y,y,y,n); //doesn't work because valus of y get over-written
		if(k%2==0)
		{
			matmul(y,y,temp,n);
			matexpo(temp,y,n,1);
		}
		else
		{
			matmul(y,y,temp,n);
			matmul(x,temp,y,n);
		}
		
		for(int i=0;i<n;i++)
		delete []temp[i];
		delete []temp;
		
		return;
	}
}
int main()
{
	int n,k;
	cout<<"Size and Power\n";
	cin>>n>>k;
	
	int **arr = new int*[n];
	int **ans = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[n];
		ans[i] = new int[n];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
			ans[i][j]=arr[i][j];
		}
	}
	
	matexpo(arr,ans,n,k);
	cout<<"return\n";
	display(arr,n);
	display(ans,n);
	
	for(int i=0;i<n;i++)
	{
		delete []arr[i];
		delete []ans[i];
	}
	
	delete []arr;
	delete []ans;
	
	return 0;
}
