#include<iostream>
using namespace std;
int M[2][2]={1,1,1,0};
int N[2][2]={0,0,0,0};

void matmul(int M[2][2], int N[2][2], int ans[2][2])
{
	int a,b,c,d;
	int a1,b1,c1,d1;
	a=M[0][0];b=M[0][1];c=M[1][0];d=M[1][1];
	a1=N[0][0];b1=N[0][1];c1=N[1][0];d1=N[1][1];
	ans[0][0]=a*a1+b*c1;
	ans[0][1]=a*b1+b*d1;
	ans[1][0]=c*a1+d*c1;
	ans[1][1]=c*b1+d*d1;
}
void modexpo(int m[2][2], int n[2][2], int k)
{
	if(k==1)
	{
		n[0][0]=m[0][0];
		n[0][1]=m[0][1];
		n[1][0]=m[1][0];
		n[1][1]=m[1][1];
	}
	else if(k==2)
	{
		matmul(m,m,n);
	}
	else
	{
		modexpo(m,n,k/2);
		int z[2][2]={0,0,0,0};
		int I[2][2]={1,0,0,1};
		if(k%2==0)
		{
			matmul(n,n,z);
			//matmul(z,I,n); -anyone of this or below, both same
			modexpo(z,n,1);
		}
		else
		{
			matmul(n,n,z);
			matmul(m,z,n);
		}
	}
}
int fib(int n)
{
	if(n==0)
	return 0;
	else if(n==1)
	return 1;
	else
	{
		modexpo(M,N,n-1);
		return N[0][0];
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cout<<fib(i)<<endl;
	return 0;
}
