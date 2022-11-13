// to get the sliding window maximum in all subarrays of size k as input by the user

#include<bits/stdc++.h>
using namespace std;


vector<int> getSlidingWindowMax(vector<int> vec, int k)
{
    deque<int> q;
    int n = vec.size();

    for(int i = 0; i<=k-1; i++)
    {
        if(q.empty() || vec[i] < vec[q.back()])
        {
            q.push_back(i);
        }
        else
        {
            while(!q.empty() && vec[i] >= vec[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
    }

    vector<int> ans;

    ans.push_back(q.front());


    for(int i = k; i<=n - 1; i++)
    {
        if(q.empty() || vec[i] < vec[q.back()])
        {
            q.push_back(i);
        }
        else
        {
            while(!q.empty() && vec[i] >= vec[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }

        while(!q.empty() && q.front() <= (i - k))
            q.pop_front();

        ans.push_back(q.front());
    }

    return ans;
}