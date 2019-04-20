/***
 * 输入一个递增排序的数组和一个数字S，在数组中查找两
 * 个数，使得他们的和正好是S，如果有多对数字的和等于
 * S，输出两个数的乘积最小的。
 * 
 * 对应每个测试案例，输出两个数，小的先输出。
 * 
 * 解题思路：从头尾开始相加
 * 
 * */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int len = array.size();
        int i = 0, j = len - 1;

        vector<int> a;
        while(i < j) {
            int s = array[i] + array[j];
            if(s == sum) {
                a.push_back(array[i]);
                a.push_back(array[j]);
                break;
            }

            if(s > sum) {
                j--;
            } else {
                i++;
            }

        }
        return a;
    }
};


int main() {


    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    Solution s;
    s.FindNumbersWithSum(a, 5);
    system("pause");
    return 0;
}