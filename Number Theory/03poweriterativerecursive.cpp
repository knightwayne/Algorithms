#include<iostream>
using namespace std;

int pow_iter(int x, int y)
{
	int ans=1;
	while(y>0)
	{
		if((y&1)==1)
		{
			ans*=x;
			//cout<<"y "<<y<<" ans "<<ans<<endl; 
		}
		y=y>>1;
		x=x*x;
	}
	return ans;
}

int pow_rec(int x, int y)
{
	if(y==0)
	return 1;
	else
	{
		int temp=pow_rec(x*x,y/2);
		if(y%2==0)
		return temp;
		else
		return temp*x;
	}
}

int pow(int x, int y)
{
	if(y==0)
	return 1;
	else
	{
		int temp=pow_rec(x,y/2);
		if(y%2==0)
		return temp*temp;
		else
		return x*temp*temp;
	}
}

int  main()
{
	int x,y;
	cin>>x>>y;
	cout<<pow_iter(x,y)<<endl;
	cout<<pow_rec(x,y)<<endl;
	cout<<pow(x,y)<<endl;
	return 0;
}
