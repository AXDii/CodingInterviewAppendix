/***
 * 小明很喜欢数学,有一天他在做数学作业时,
 * 要求计算出9~16的和,他马上就写出了正确答案是100。
 * 是他并不满足于此,他在想究竟有多少种连续的正数序列
 * 为100(至少包括两个数)。没多久,他就得到另一组连续
 * 正数和为100的序列:18,19,20,21,22。现在把问题交
 * 给你,你能不能也很快的找出所有和为S的连续正数序列?
 *  Good Luck!
 * 
 * 解题思路：用数学公式，遍历
 * 
 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > FindContinuousSequence(int sum)
    {
        int max = sum / 2 + 1;
        vector<vector<int> > ans;
        int i = 2, j = 1;
        while (i > j)
        {
            int n = i - j + 1;
            int tSum = ((i + j) * n) / 2;
            if (tSum == sum)
            {
                //cout<<"this is right :i = "<<i<<", j = "<<j<<endl;
                vector<int> a;
                for (int u = j; u <= i; u++)
                {
                    a.push_back(u);
                }
                //cout<<a.size()<<endl;
                ans.push_back(a);
                i++;
            }
            else if (tSum > sum)
            {
                j++;
            }
            else
            {
                i++;
            }
        }

        return ans;
    }
};

int main()
{

    Solution s;
    vector<vector<int> > tmp = s.FindContinuousSequence(100);
    //cout<<tmp.size()<<endl;
    int len = tmp.size();
    for (int i = 0; i < len; i++)
    {
        vector<int> k = tmp[i];
        //cout<<k.size()<<endl;
        int size = k.size();
        for (int j = 0; j < size; j++)
        {
            cout << k[j] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}