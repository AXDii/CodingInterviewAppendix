/***
 * 
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压
 * 栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序
 * 列的长度是相等的）
 * 
 * 解题思路：
 * 
 * 
 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        int stack[1000] = {0};
        int stackIndex = -1;
        int i = 0, j = 0;
        int len = pushV.size();
        while (j < len && (i < len || stackIndex >= 0))
        {
            if (i < len && pushV[i] == popV[j])
            {
                i++, j++;
                continue;
            }
            if (stackIndex >= 0 && stack[stackIndex] == popV[j])
            {
                stackIndex--;
                j++;
                continue;
            }
            stack[++stackIndex] = pushV[i++];

            if(i >= len && j < len && stackIndex >= 0 && stack[stackIndex] != popV[j]) {
                break;
            }

        }
        return j == len;
    }
};

int main()
{

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5,4,3,2,1};
    vector<int> a(arr1, arr1 + 5);
    vector<int> b(arr2, arr2 + 5);
    Solution s;
    cout << s.IsPopOrder(a, b);

    system("pause");
    return 0;
}
