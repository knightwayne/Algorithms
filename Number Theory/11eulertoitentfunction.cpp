#include<bits/stdc++.h>
using namespace std;
vector <int> prime;

vector <int> sieve(int n)
{
	vector <int> v,prime;
	v.assign(n+1,1);
	v[0]=v[1]=0;
	
	for(int i=2;i*i<=n;i++)
	{
		if(v[i]==1){
			for(int j=i*i;j<=n;j+=i){
				v[j]=0;
			}
		}
	}
	
	for(int i=0;i<=n;i++){
		if(v[i]==1)
		prime.push_back(i);
	}
	//cout<<prime[0]<<" "<<prime[prime.size()-1]<<endl;
	return prime;
}
int etf(int n)
{
	int res=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			n/=i;	//removing all occurence of number i;
			
			res/=i;
			res*=(i-1);
		}
	}
	if(n>1)
	{
		res/=n;
		res*=(n-1);
	}
	return res;
}
int etfOpt(int n)
{
	int res=n;
	for(int i=0;prime[i]*prime[i]<=n;i++)
	{
		if(n%prime[i]==0){
			while(n%prime[i]==0)
			n/=prime[i];
			
			res/=prime[i];
			res*=(prime[i]-1);
		}
	}
	if(n>1)
	{
		res/=n;
		res*=(n-1);	
	}
	return res;
}
void etfRange(int n)
{
	vector <int> v;
	for(int i=0;i<=n;i++)
	v.push_back(i);
	
	for(int i=2;i<=n;i++)	//i*i<=n - eg 3x5=15 , 15 would miss out
	{
		if(v[i]==i)//prime, not encountered till now
		{
			for(int j=2*i;j<=n;j+=i) //hence not j=i*i
			{
				//if(v[j]%i==0)	//j=2*i already divisible by i
				//{
					v[j]/=i;
					v[j]*=(i-1);	
				//}
			}
			v[i]--;
		}	
	}
	
	for(int i=1;i<=n;i++)
	cout<<i<<" "<<v[i]<<endl;	
}
int main()
{
	int tc;
	cin>>tc;
	prime = sieve(1000000);
	while(tc--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		cout<<i<<" "<<etf(i)<<" "<<etfOpt(i)<<endl;
		etfRange(n);
	}
	return 0;
}
