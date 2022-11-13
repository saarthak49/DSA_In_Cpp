#include<bits/stdc++.h>
using namespace std;



double getSquareRoot(double number, double epsilon)
{
    double low = 1;
    double high = number/2.0;

    double mid = low + (high - low)/2.0;

    double delta = abs(mid * mid - number);
    
    double answer = mid;

    while( delta  > epsilon )
    {
        mid = low + (high - low)/2.0;


        cout<<delta<<" "<<epsilon<<endl;

        // cout<< (delta < epsilon) ? "true" : "false" <<endl;

        if( mid * mid < number)
        {
            answer = mid;
            delta = number - (mid * mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return answer;


}

int main()
{
    double number = 102;
    double epsilon = 0.0001;

    cout<<getSquareRoot(number, epsilon);
}