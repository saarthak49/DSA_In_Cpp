#include <bits/stdc++.h>
using namespace std;

// DESCRIPTION: You are given two integer arrays of the same length nums1 and nums2. In one operation, 
// you are allowed to swap nums1[i] with nums2[i].

// For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to 
// obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
// Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. 
// The test cases are generated so that the given input always makes it possible.


void minSwap(vector<int> nums1, vector<int> nums2, vector<int> &dp1, vector<int> &dp2)
{
    int n = nums1.size();
    for(int i = 1; i<=n-1; i++)
    {
        dp1[i] = INT_MAX;
        dp2[i] = INT_MAX;
        if( nums1[i] > nums1[i-1] && nums2[i] > nums2[i - 1])
        {
            dp1[i] = dp1[i-1];
            dp2[i] = 1 + dp2[i-1];
        }
        if(nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1])
        {
            dp1[i] = min(dp2[i-1], dp1[i]);
            dp2[i] = min(1 + dp1[i-1], dp2[i]);
        }
    }
}



int minSwap(vector<int> &nums1, vector<int> &nums2)
{

    int n = nums1.size();

    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);

    dp1[0] = 0;
    dp2[0] = 1;
    
    minSwap(nums1, nums2, dp1, dp2);

    return min(dp1[n-1], dp2[n-1]);


}