#include<bits/stdc++.h>
using namespace std;


int choose_pivot(vector<int> &vec, int start, int end){
    srand(time(0));
    int pivot_index = start + rand() % (end - start + 1);
    int temp = vec[end];
    vec[end] = vec[pivot_index];
    vec[pivot_index] = temp;

    int i = start;
    int index = start;
    while(i<=end - 1)
    {
        if(vec[i]<vec[end])
        {
            int temp = vec[index];
            vec[index] = vec[i];
            vec[i] = temp;
            index++;
        }
        i++;
    }
    int temp1 = vec[index];
    vec[index] = vec[end];
    vec[end] = temp1;
    return index;

}


void quick_sort(vector<int> &vec, int start, int end)
{
    if(start >= end)
        return;

    int index = choose_pivot(vec, start, end);
    // cout<<"Called for "<<start<<" "<<end<<" and the pivot index was "<<index<<endl;
    quick_sort(vec, start, index - 1);
    quick_sort(vec, index + 1, end);
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
    // cout<<choose_pivot(v, 0 , n-1);
    quick_sort(v, 0, n-1);
    for(auto it: v)
    {
        cout<<it<<" ";
    }
}