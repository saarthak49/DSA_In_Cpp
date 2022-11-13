#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    vector<int> temporary(100, 0);
    vector<vector<int> > v(100, temporary);
    cout<<v[0][0]<<endl;
    cout<<v[100][99]<<endl;
}
