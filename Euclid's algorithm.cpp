#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0)
#define ll long long int
using namespace std;
#define mod 1000000007
ll gcd(ll a,ll b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
int main()
{
	fast;
	cout<<gcd(6,10);
}
