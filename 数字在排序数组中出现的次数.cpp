/***
 * 统计一个数字在排序数组中出现的次数。
 * 
 * 解题思路：使用二分查找，然后找出上界和下界
 * 解题思路2：使用二分查找查找k-0.5和k+0.5，这样能一下子找出边界，然后使用k+0.5的index减去k-0.5的index
 * */

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        int len = data.size();
        int index = find(data, k);
        int i = index, j = index;
        if(index == -1) {
            return 0;
        }
        while(i > 0) {
            if(data[i-1] == data[i]) {
                i--;
            } else {
                break;
            }
        }

        while(j + 1 < len) {
            if(data[j + 1] == data[j]) {
                j++;
            } else {
                break;
            }
        }
        // cout<<"i = "<<i<<", j = "<<j<<endl;
        return j - i + 1;
    }

    //使用递增序列的二分查找法
    int find(vector<int> data, int k)
    {
        int notFound = -1;
        int left = 0, right = data.size(), mid = 0;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            // cout<<"mid = "<<mid<<endl;
            if (data[mid] == k) {
                // cout<<"found"<<endl;
                return mid;
            } else if(data[mid] > k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }
        // cout<<"not found"<<endl;
        return notFound;
    }
};

int main()
{

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
    cout<<s.GetNumberOfK(a, 3);
    system("pause");
    return 0;
}