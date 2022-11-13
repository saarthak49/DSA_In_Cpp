#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 3, 5, 5, 5, 6, 6, 6, 6, 8, 9, 10};

    cout<< upper_bound(v.begin(), v.end(), 6) - lower_bound(v.begin(), v.end(), 6);
}