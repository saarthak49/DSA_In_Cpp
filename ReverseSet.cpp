#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    multiset<int, greater<int> > s;
    while(t--)
    {
        int num;
        cin>>num;
        s.insert(num);
    }
    for(auto it = s.begin(); it!= s.end(); it++)
        cout<<*it<<", ";
    cout<<endl;



    return 0;
}