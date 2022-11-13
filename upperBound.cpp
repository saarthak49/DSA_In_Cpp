#include<bits/stdc++.h>
using namespace std;


// answers the questions that how many elements are actually <= key
int getUpperBound(vector<int> vec, int key)
{
    int ans = 0;
    int low = 0;
    int high = vec.size() - 1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(vec[mid] <= key)
        {
            ans = mid + 1;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
}


int main()
{
    vector<int> vec = {1, 2, 3, 4, 4, 4, 5, 5, 5, 6};
    cout<<"size of vector: "<<vec.size()<<endl;

    int upperBound = getUpperBound(vec, 4);
    cout<<"upper bound: "<<upperBound<<endl;

    return 0;
}

