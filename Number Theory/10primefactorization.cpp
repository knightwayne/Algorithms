#include<bits/stdc++.h>
using namespace std;

vector <int> smallestPF(int n)
{
	vector <int> v;
	for(int i=0;i<=n;i++)
	v.push_back(i);
	
	for(int i=2;i*i<=n;i++)
	{
		if(v[i]==i)
		{
			for(int j=i*i;j<=n;j+=i)
			{
				if(v[j]==j)
				v[j]=i;
			}
			
		}
	}
	
	//for(int i=1;i<=n;i++)
	//cout<<i<<" spf: "<<v[i]<<endl;
	return v;
}

void primeFactors(int n)
{
	cout<<"Prime Factors: ";
	while(n%2==0)
	{
		cout<<2<<" ";
		n/=2;
	}
	
	for(int i=3;i*i<=n;i+=2)
	{
		while(n%i==0)
		{
			cout<<i<<" ";
			n/=i;
		}
	}
	if(n>1) //this condition is for perfect squares and cubes
	cout<<n;
	cout<<endl;
}

void primeFactorsOptimized(int n)
{
	//use SPF to calculate smallest prime factor;
	//run it once, store value using precomputation;
	vector <int> prime=smallestPF(n);
	cout<<"primeFactors ";
	while(n>1)
	{
		cout<<prime[n]<<" ";
		n=n/prime[n];
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	
	vector <int> prime=smallestPF(n);
	for(int i=1;/*i<prime.size()*/i<=n;i++) //prime.size()=128 , max value of i = 127, n=127
	cout<<i<<" spf: "<<prime[i]<<endl;
	
	primeFactors(n);
	
	primeFactorsOptimized(n);
	
	return 0;
}
