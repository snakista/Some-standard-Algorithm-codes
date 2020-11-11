#include <iostream>

using namespace std;
int knap(int cap,int val[],int wt[],int n)
{
    int i,c;
    int k[n+1][cap+1];
    for(int i=0;i<=n;i++)
    {
        for(c=0;c<=cap;c++)
        {
            if(c==0||i==0)
            {
                k[i][c]=0;
                continue;
            }
            if(c>=wt[i-1])
            {
                k[i][c]=max(val[i-1]+k[i-1][c-wt[i-1]],k[i-1][c]);
            }
            else
            k[i][c]=k[i-1][c];
        }
    }
    return k[n][cap];
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
