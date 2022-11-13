#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cin>>n;
    int t=n;
    vector<int> v;
    while(t--)
    {
        int d;
        cin>>d;
        v.push_back(d);
    }
    int k;
    cin>>k;
    sort(v.begin(),v.end());
    int i = 0;
    int j = 1;
    while(i<=n-1 && j<=n-1)
    {
        if(i==j)
            j++;
        if(j==n || i==n)
            break;
        if(v[j]-v[i]<k)
            j++;
        else if(v[j]-v[i]>k)
            i++;
        else {   
            cout<<"found\n";
            return 0;
        }
    }
    cout<<"Not found\n";
    return 0;
}