#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second<=b.second;
}

int main()
{
    vector<pair<int,int> > v = {{1, 7}, {2, 1}, {3, 5}, {6, 9}, {10, 2}};
    sort(v.begin(), v.end(), cmp);
    for(auto it: v)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}