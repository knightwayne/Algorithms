// the sieve of erathosthenes returns us a list/vector
// containing the set of prime numbers upto that number - n
#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
using namespace std;

vector <int> sieveOfErathosthenes(int n)
{
	vector <int> v;
	v.assign(n+1,0);
	//cout<<"vsize "<<v.size()<<endl;
	vector <int> prime;
	
	for(int i=2;i<=sqrt(n);i++)
	{
		if(v[i]==0)
		{
			//prime.push_back(i);
			for(int j=i*i;j<=n;j+=i)
			v[j]=1;
		}
	}
	
	for(int i=2;i<v.size();i++)
	{
		if(v[i]==0)
		prime.push_back(i);
	}
	
	return prime;	
}

int main()
{
	int n;
	cin>>n;
	vector <int> v=sieveOfErathosthenes(n);
	for(int i=0;i<v.size();i++)
	cout<<v[i]<<" ";
	return 0;
}
/*#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector <int> v,prime;
	int x;
	cin>>x;
	v.assign(x+1,0);
	//cout<<v.size()<<"size\n";
	for(int i=2;i<=x;i++)
	{
		if(v[i]==0)
		{
			prime.push_back(i);
			for(int j=2*i;j<=x;j+=i)
			v[j]=1;
		}
	}
	for(int i=0;i<prime.size();i++)
	cout<<prime[i]<<" ";
	cout<<"\nsize "<<prime.size()<<endl;
	return 0;
}*/
