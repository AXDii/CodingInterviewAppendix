/***
 * 
 * 
 * 
 * 
 * */

#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        int arr[52][2] = {0};
        int stackSize = -1;
        int stack[52] = {0};
        for (unsigned i = 0; i < str.length(); i++)
        {
            int index = 0;
            if (str[i] >= 65 && str[i] <= 90)
            {
                index = str[i] - 65;
                cout<<str[i]<<" "<<index<<endl;
            }
            else
            {
                index = str[i] - 71;
                cout<<str[i]<<" "<<index<<endl;
            }
            arr[index][0]++;
            if (arr[index][0] == 1)
            {
                stack[++stackSize] = index;
            }
            arr[index][1] = i;
        }
        int res = -1;
        for (int i = 0; i <= stackSize; i++)
        {
            if (arr[stack[i]][0] == 1)
            {
                res = arr[stack[i]][1];
                break;
            }
        }
        return res;
    }
};
//'A-z':65-90; 'a-z':97-122;
int main()
{
    Solution s;
    string str = "aafskatfs";
    cout<<s.FirstNotRepeatingChar(str);
    system("pause");
    return 0;
}