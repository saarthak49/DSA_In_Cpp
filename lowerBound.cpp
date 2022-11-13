#include<bits/stdc++.h>
using namespace std;

// answers how many elements > key
int getLowerBound(vector<int> vec, int key)
{
    int low = 0;
    int high = vec.size() - 1;

    int ans = 0;
    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(vec[mid] >= key)
        {
            high = mid - 1;
        }
        else 
        {
            ans = mid + 1;
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{

    vector<int> vec = {1, 2, 3, 4, 5, 5, 5, 7, 7, 7, 8};

    int indexLowerBound = getLowerBound(vec, 100);

    cout<<indexLowerBound<<endl;
}