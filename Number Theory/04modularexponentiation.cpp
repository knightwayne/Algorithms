#include<iostream>
using namespace std;
long long int mod = 1000000007;

long long int modexpo(long long int n, long long int k)
{
	if(k==0)
	return 1;
	else
	{
		long long int temp=modexpo(n,k/2)%mod;
		if(k%2==0)
		{
			return (temp*temp)%mod;
		}
		else
		{
			return (((temp*temp)%mod)*n)%mod;
		}
	}
}
long long int modexporec(long long int n, long long int k)
{
	if(k==0)
	return 1;
	else
	{
		long long int temp=modexporec(((((n*n)%mod)+mod)%mod),k/2);
		if(k%2==0)
		return temp;
		else
		return (((temp*n)%mod)+mod)%mod;
	}
}
long long int modexpoiter(long long int n, long long int k)
{
	long long int ans=1;
	while(k>0)
	{
		
		if(k&1==1)
		{
			ans=(((ans*n)%mod)+mod)%mod;
		}
		n=(((n*n)%mod)+mod)%mod;
		k=k>>1;
	}
	return ans;
}
int main()
{
	long long int n,k;
	cin>>n>>k;
	cout<<(modexpo(n,k)+mod)%mod<<endl;
	cout<<(modexporec(n,k)+mod)%mod<<endl;
	cout<<(modexpoiter(n,k)+mod)%mod<<endl;
	return 0;
}
