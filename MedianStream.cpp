#include<bits/stdc++.h>
using namespace std;


void adjust(multiset<int> &leftBucket, multiset<int> &rightBucket)
{
    if(rightBucket.size() > leftBucket.size())
    {
        int elemStart = *rightBucket.begin();
        rightBucket.erase(rightBucket.find(elemStart));
        leftBucket.insert(elemStart);
    }
    else if(leftBucket.size() == rightBucket.size() + 2)
    {
        int elemStart = *leftBucket.rbegin();
        leftBucket.erase(leftBucket.find(elemStart));
        rightBucket.insert(elemStart);
    }
}


int main()
{
    int t;
    cin>>t;
    
    multiset<int> leftBucket;
    multiset<int> rightBucket;
    while(t--)
    {
        int num;
        cin>>num;
        if(leftBucket.empty()){
            leftBucket.insert(num);
        }
        else
        {
            if(num > *leftBucket.rbegin())
                rightBucket.insert(num);
            else
                leftBucket.insert(num);

        }
        adjust(leftBucket, rightBucket);

        // for(auto it: leftBucket)
        //     cout<<it<<", ";
        // cout<<"\t";

        // for(auto it: rightBucket)
        //     cout<<it<<", ";
        // cout<<endl;


        if((leftBucket.size()+rightBucket.size())%2==0)
            cout<<"The median is "<< (*leftBucket.rbegin() + *rightBucket.begin())/2.0<<endl;
        else    
            cout<<"The median is "<<*leftBucket.rbegin()<<endl;

    }





    return 0;
}