/***
 * 
 * 
 * 
 * 
 * */

#include<iostream>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        int a[n];
        for(int i = 0; i < n; i++) {
            a[i] = 0;
        }
        int sum = 0;
        int count = 0;
        int i = 0;
        while(true) {
            if(i == n) {
                i = 0;
            }
            if(a[i] == 1) {
                i++;
                continue;
            }
            if(a[i] == 0) {
                count++;
            }
            if(count == m) {
                a[i] = 1;
                sum++;
                count = 0;
            }
            if(sum == m) {
                break;
            }
            i++;
        }
        return i;
    }
};


int main(){

    Solution s;
    cout<<s.LastRemaining_Solution(10, 4);
    system("pause");
    return 0;
}