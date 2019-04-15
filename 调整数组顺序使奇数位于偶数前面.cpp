/***
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
 * 所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 * 
 * 解题思路：这道题不难，记得虎牙有一题类似的，但是要使得数组有序，而且时间复杂度为O(n)， 空间复杂度为O(1)
 * 解法1：空间换时间 / 解法2：时间换空间
 * */

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        int a[array.size()];
        int a2[array.size()];
        int i = 0;
        int j = 0;
        for (int u = 0; u < array.size(); u++)
        {
            if (array[u] % 2 == 1)
            {
                a[i++] = array[u];
            }
            else
            {
                a2[j++] = array[u];
            }
        }
        int u = 0;
        for (; u < i; u++)
        {
            array[u] = a[u];
        }
        for (u = 0; u < j; u++)
        {
            array[i + u] = a2[u];
        }
    }
};

int main()
{
    vector<int> a;
    a.push_back(5);
    a.push_back(3);
    a.push_back(4);
    a.push_back(7);
    a.push_back(2);
    a.push_back(1);
    a.push_back(8);
    Solution s;
    s.reOrderArray(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
}