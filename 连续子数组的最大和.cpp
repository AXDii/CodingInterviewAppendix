/***
 * HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:
 * 在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很
 * 好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
 * 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
 * 给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
 * 
 * 解题思路：从左往右扫描一遍，用一个max记录最大值，用一个sum记录每一段的值
 * 
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int max = array[0];
        int sum = 0;
        for (int i = 0; i < array.size(); i++)
        {
            if (sum + array[i] > 0)
            {
                sum += array[i];
                if (max < sum)
                {
                    max = sum;
                }
            }
            else
            {
                if (max < array[i])
                {
                    max = array[i];
                }
                sum = 0;
            }
        }
        return max;
    }
};

int main()
{

    vector<int> a;
    a.push_back(-2);
    a.push_back(5);
    a.push_back(-1);
    a.push_back(7);
    a.push_back(-9);
    Solution s;
    cout << s.FindGreatestSumOfSubArray(a);
    system("pause");
    return 0;
}
