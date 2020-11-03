#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0)
#define ll long long int
using namespace std;
#define mod 1000000007
ll modexp(ll x,ll n)
{
	ll result=1;
	while(n>0)
	{
		if(n%2==1)
	    result=(result*x)%mod;
	    x=(x*x)%mod;
	    n=n/2;
	}
	return result;
}
int main()
{
	fast;
	cout<<modexp(3,10);
}
