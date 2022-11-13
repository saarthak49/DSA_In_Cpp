#include<bits/stdc++.h>
using namespace std;

int reduceToSum(int n)
{
    int t = 0;
    while(n>0)
    {
        int d = n%10;
        n/=10;
        t += d*d;
    }
    return t;
}

int main()
{
    int n;
    cin>>n;
    // vector<int> v;
    // vector<int> dp(1e6, 0);
    // for(int i=2; i<=1e6; i++)
    //     v.push_back(i);
    int i = 1;
    while(n!=1 && n!=4)
    {
        n = reduceToSum(n);
        cout<<n<<endl;
        i++;
    }
    cout<<n<<endl;
    return 0;
}