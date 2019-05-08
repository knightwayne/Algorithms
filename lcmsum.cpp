#include<bits/stdc++.h>
using namespace std;
vector <long long int> store;

vector <long long int> precal(int n){
	vector <long long int> v,res;
	for(int i=0;i<=n;i++)
	{
		v.push_back(i);
		res.push_back(0);
	}
	
	for(int i=2;i<=n;i++)
	{
		if(v[i]==i)
		{
			for(int j=2*i;j<=n;j+=i)
			{
				v[j]/=i;
				v[j]*=(i-1);
			}
			v[i]--;
		}
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		v[i]*=i;
//		//cout<<v[i]<<"v ";
//	}
	for(int i=1;i<=n;i++)	//divisor
	{
		for(int j=i;j<=n;j+=i)	//number
		{
			//if(i%j==0)
			//{
				res[j]+=v[i]*i;
			//}
		}
	}
	return res;
}
int main()
{
	int tc;
	cin>>tc;
	store=precal(1000000);
	//for(int i=0;i<store.size();i++)
	//cout<<i<<" "<<store[i]<<"\n";
	while(tc--)
	{
		int n;
		cin>>n;
		long long int res=store[n]+1;
		res/=2;
		res*=n;
		cout<<res<<"\n";
	}
	return 0;
}
