#include<bits/stdc++.h>
#include<vector>
#define lli long long int
using namespace std;

vector <lli> prime;

void soe(lli n)
{
  	lli lim=sqrt(n); 
	vector <lli> v; 
	v.assign(lim+1,0);
	
	for(lli i=2;i<=sqrt(lim);i++)
	{
		if(v[i]==0)
		{
			for(lli j=i*i;j<=lim;j+=i)
			v[j]=1;
		}
	}
	
	for(lli i=2;i<v.size();i++)
	{
		if(v[i]==0)
		prime.push_back(i);
	}
	return;
}

vector <lli> ssoe(lli a, lli b)
{
	//soe(sqrt(b));
	
	//for(lli i=0;i<prime.size();i++)
	//cout<<prime[i]<<" ";
	//cout<<"\nthank\n\n";
	
	lli n=sqrt(b-a);
	lli lo=a;
	lli hi=lo+n;
	
	vector <lli> primeInRange;
	
	while(lo<=b)
	{
		//cout<<"lo "<<lo<<" hi "<<hi<<endl;
		vector <lli> v;
		v.assign(n+1,0);
		
		for(lli i=0;((i<prime.size())&&(prime[i]<=sqrt(b)));i++)
		{
			//cout<<prime[i]<<" "<<sqrt(b)<<endl;
			
			lli start=(lo/prime[i])*prime[i];
			if(start<lo)
			start+=prime[i];
			if(start==prime[i])
			start+=prime[i];
			start-=lo;
		//	cout<<"sssssstart "<<start<<endl;
			
			while(start+lo<=hi) // because n is always n even if hi > b
			{
				v[start]=1;
		//		cout<<"start "<<start<<" "<<lo<<" "<<hi<<endl;
				start+=prime[i];
			}
		}
		
		for(lli i=0;i<=n;i++)
		{
			if((v[i]==0)&&(i+lo<=hi))
			{
				primeInRange.push_back(i+lo);	
		//		cout<<i+lo<<" ";
			}	
		}
		
		lo=hi+1;
		hi=lo+n;
		if(hi>b)
		hi=b;
		//cout<<"next\n";
	}
	
	return primeInRange;
}
int main()
{
  	lli max=2147483647;
  	soe(max);
	int tc;
	cin>>tc;
	while(tc--)
	{
		lli a,b;
		cin>>a>>b;
		vector <lli> v=ssoe(a,b);
		
		for(lli i=0;i<v.size();i++)
		cout<<v[i]<<endl;
		
		v.clear();
//prime.clear();
		
	}
	return 0;
}
