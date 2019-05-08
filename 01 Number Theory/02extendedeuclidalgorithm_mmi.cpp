#include<iostream>
using namespace std;

class trio
{
	public:
		
	int x,y,gcd;
};
//int gcd(int a, int b);
trio eea(int a, int b)
{
	trio ans;
	if(b==0)
	{
		ans.x=1;
		ans.y=0;
		ans.gcd=a;
		return ans;
	}
	else{
		ans.x=eea(b,a%b).y;
		ans.y=eea(b,a%b).x-((a/b)*eea(b,a%b).y);
		ans.gcd=/*gcd(a,b)/*gcd(b,a%b)*/eea(b,a%b).gcd;
		return ans;
	}
}
/*int gcd(int a, int b)
{
	if(b==0)
	return a;
	else if(b>a)
	return  gcd(b,a);
	else
	return gcd(b,a%b);
}*/
int main()
{
	while(true){
	int a,b;
	cin>>a>>b;
	trio val = eea(a,b);//extended_euclid_algo
	cout<<"a "<<a<<" b "<<b<<" gcd "<<val.gcd<<endl;
	cout<<"x "<<val.x<<" y "<<val.y<<endl;
	cout<<"MMI "<<val.x<<" quotient "<<val.y*-1<<endl;
	}
	return 0;
}
