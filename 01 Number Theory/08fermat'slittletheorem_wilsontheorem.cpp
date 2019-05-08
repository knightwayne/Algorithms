#include<bits/stdc++.h>
#define lli long long int
using namespace std;

lli modexpo(lli a, lli b, lli mod)
{
	if(b==0)
	return 1;
	else
	{
		lli temp=modexpo(a,b/2,mod)%mod;
		temp=(temp+mod)%mod;
		temp=(((temp*temp)%mod)+mod)%mod;
		if(b%2==0)
		return temp;
		else
		return (((temp*a)%mod)+mod)%mod;
		
	}
}

lli fermat(lli a, lli p)
{
	return modexpo(a,p-2,p);
}

lli wilson(lli n, lli p)
{
	
	if(n>=p)
	return 0;
	else
	{
		lli prod=p-1;
		lli i=n+1;
		while(i<p)
		{
			prod=prod*fermat(i,p);
			prod=((prod%p)+p)%p;
			i++;
		}
		return prod;
	}
}
int main()
{
	lli a,p;
	cin>>a>>p;
	for(int i=2;i<=sqrt(p);i++)
	{
		if(p%i==0)
		{
			cout<<"P not prime\n";
			break;
		}
	}
	
	cout<<"Modulo-Inverse: "<<fermat(a,p)<<endl;
	cout<<"n!%p: "<<wilson(a,p)<<endl;
	return 0;
}
