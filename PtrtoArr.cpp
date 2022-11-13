#include<bits/stdc++.h>
using namespace std;

int main()
{
     int arr[2][3] = {{1,2,3},{4,5,6}};
     int (*p)[3] = arr;
     cout<<**(p+1)<<endl;

     return 0;
}