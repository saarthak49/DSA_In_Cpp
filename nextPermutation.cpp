#include <bits/stdc++.h>
using namespace std;

bool usingInbuilt(vector<int> &vec)
{
    return next_permutation(vec.begin(), vec.end());
}


bool generateNextPermutation(vector<int> &vec)
{
    int n = vec.size() - 1;

    for(; n>=1; n--)
    {
        if(vec[n-1] < vec[n])
            break;
    }

    if( !n )
        return false;



    int swapIndex = n - 1;

    int index = n;

    n = vec.size();

    for(int i = n - 1; i>=0; i--)
    {
        if(vec[i] > vec[swapIndex])
        {
            swap(vec[i], vec[swapIndex]);
            break;
        }
    }

    sort(vec.begin() + index, vec.end());


    return true;
}



int main()
{
    vector<int> vec = {1, 2, 3};

    cout<<"original array permutation"<<endl;

    for(auto it: vec)
    {
        cout<<it<<" ";
    }
    cout<<endl;


    while(generateNextPermutation(vec))
    {
        cout<<"generating next permutation"<<endl;

        for(auto it: vec)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}