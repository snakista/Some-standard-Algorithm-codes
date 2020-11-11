
#include <iostream>

using namespace std;
int knap(int cap,int val[],int wt[],int n)
{
    if(cap<=0||n<=0)
    return 0;
    if(wt[n-1]>cap)
    return knap(cap,val,wt,n-1);
    else
    {
        return max(val[n-1]+knap(cap-wt[n-1],val,wt,n-1),knap(cap,val,wt,n-1));
    }
}
int main()
{
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int cap=50;
    int n=3;
    cout<<knap(cap,val,wt,n);
    return 0;
}
