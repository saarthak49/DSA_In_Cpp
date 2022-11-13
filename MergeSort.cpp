#include<bits/stdc++.h>
using namespace std;

void merge_sort(vector<int> &vec, int start, int end)
{
    if(start >= end)
        return;

    int mid = start + (end-start)/2;
    merge_sort(vec, start, mid);
    merge_sort(vec, mid+1, end);
    vector<int> temp;
    int i = start;
    int j = mid+1;
    while(i<=mid && j<=end)
    {
        int d = vec[i]<vec[j]? vec[i++]: vec[j++];
        temp.push_back(d);
    }
    while(i<=mid)
        temp.push_back(vec[i++]);
    while(j<=end)
        temp.push_back(vec[j++]);

    for(int k=start;k<=end;k++)
        vec[k]=temp[k-start];
    
}

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
    merge_sort(v, 0, n-1);
    for(auto it: v)
    {
        cout<<it<<" ";
    }
}