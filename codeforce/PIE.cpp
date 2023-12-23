#include <bits/stdc++.h>
using namespace std;

int main() {
    int testcase, friends, pie_count;
    int height = 1, r;
    int hold = 0;

    double pi = 3.14159265359 * height;
    double left = 0, right = 0, mid = 0;
    double mid_volume;
    double num;

    cin >> testcase;
    while (testcase != 0)
    {
        right = left = 0;
        cin >> pie_count >> friends;
        friends += 1; //adds one to the people count to include host
        double pie_radii[pie_count];
        for(int i = 0; i < pie_count; i++)
        {
            cin >> r; pie_radii[i] = r;
            //putting each radius in an array
            if(pie_radii[i] > right)
            //finding the largest in the array to use it as upper bound
            right = pie_radii[i];
        }
        while( (right-left) > (1e-8) ) //using 10^-8 as loop condition because the range needs to be close
        {
            mid = (left + right)/2;
            mid_volume = pi * mid * mid;
            //find volume
            for (int j = 0; j < pie_count; j++) {
                hold += pie_radii[j]*pie_radii[j]*pi/mid_volume;
            }
            if (hold >= friends) {
                left = mid;
            }
            else {
                right = mid;
            }
            hold = 0;
        }
        num = pi*right*right;
        printf("%.6f\n",num);
        testcase--;
    }
    return 0;
}