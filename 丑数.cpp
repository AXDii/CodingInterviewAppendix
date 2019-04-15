/***
 * 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
 * 例如6、8都是丑数，但14不是，因为它包含质因子7。 习
 * 惯上我们把1当做是第一个丑数。求按从小到大的顺序的第
 * N个丑数。
 * 
 * 
 * */

#include<iostream>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index == 1) {
            return 1;
        } else {
            int count = 1;
            int i = 2;
            while(true) {
                if(i % 2 == 0 || i % 3 == 0 || i % 5 == 0) {
                    if(++count == index) {
                        return i;
                    }
                }
                i++;
            }
        }
    }
};

int main(){

    int i = 0;
    cin>>i;
    Solution s;
    cout<<s.GetUglyNumber_Solution(i);

    system("pause");
    return 0;
}