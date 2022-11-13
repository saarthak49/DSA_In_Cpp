#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string str)
{
    int n = str.size();
    n = 2*n + 1;
    int C = 1;
    int R = 2;
    vector<int> lps(n, 0);
    int start = -1;
    int length = 0;
    for(int i = 1; i<= n-1; i++)
    {
        bool expand = false;
        int left = 2*C - i;
        int diff = R - i;
        if(diff >= 0)
        {
            if( i + lps[left] > R)
            {
                lps[i] = diff;
            }
            else if( i + lps[left] == R)
            {
                lps[i] = lps[left];
                expand = true;
            }
            else 
            {
                lps[i] = lps[left] ;
            }
        }
        else
        {
            expand = true;
        }
        //  A   B   C 
        //_ 1 _ 1 0 1 0
 
        if(expand)
        {
            int j = i + lps[i] + 1;
            int k = i - lps[i] - 1;
            while(k>=0 && j<=n-1 && (j%2 == 0 || (j%2 == 1 && str[(j - 1)/2] == str[(k - 1)/2] )))
            {
                lps[i]++;
                j++;
                k--;
            }

            if( i + lps[i] > R)
            {
                R = i + lps[i];
                C = i;
            }
        }

        if(lps[i] > length)
        {
            length = lps[i];
            start = (i - lps[i] )/2;
        }

    }
    string result = "";
    for(int i = 0; i<=length-1; i++)
        result += str[start + i];
    return result;
    
}










int main()
{
    string str = longestPalindrome("aaaa");
    cout<<str<<endl;
    return 0;
}