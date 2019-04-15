/***
 * 输入n个整数，找出其中最小的K个数。
 * 例如输入4,5,1,6,2,7,3,8这8个数字，
 * 则最小的4个数字是1,2,3,4,。
 * 
 * 
 * 解题思路：堆排序
 * 
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        int a[k + 1];
        int i = 0, j = 0;
        for (i = 1; i <= k; i++)
        {
            a[i] = input[i - 1];
        }
        for (j = k / 2; j >= 1; j--)
        {
            sink(a, j, k);
        }
        for(; i <= input.size(); i++) {
            if(input[i-1] < a[1]) {
                int temp = a[1];
                a[1] = input[i-1];
                input[i-1] = temp;
                sink(a, 1, k);
            }
        }
        for(i = k; i > 1; i--) {
            int temp = a[i];
            a[i] = a[1];
            a[1] = temp;
            sink(a, 1, i-1);
        }
        vector<int> res;
        for(i = 1; i <= k; i++) {
            res.push_back(a[i]);
        }
        return res;

    }

    //小值下沉
    void sink(int *a, int index, int k)
    {
        while (2 * index <= k)
        {
            int j = 2 * index;
            if (j < k && a[j] < a[k])
            {
                j++;
            }
            if (a[index] >= a[j])
            {
                break;
            } 
            int temp = a[index];
            a[index] = a[j];
            a[j] = temp;
            index = j;
        }
    }
};
int main()
{
    vector<int> input;
    input.push_back(4);
    input.push_back(5);
    input.push_back(1);
    input.push_back(6);
    input.push_back(2);
    input.push_back(7);
    input.push_back(3);
    input.push_back(8);
    Solution s;
    vector<int> ans = s.GetLeastNumbers_Solution(input, 4);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    system("pause");
    return 0;
}