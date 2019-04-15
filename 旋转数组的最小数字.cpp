/**
 * 
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
 * 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数
 * 组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 * 
 * 解题思路：查找两个序列的边界，但是，查找的时候，可以使用普通匹配和二分法查找。
 * 法一：使用普通匹配，速度慢。
 * 法二：使用二分查找法
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        int size = rotateArray.size();
        if (size == 0)
        {
            return 0;
        }

        if (size == 1)
        {
            return rotateArray[0];
        }

        for (int i = 1; i < size; i++)
        {
            if (rotateArray[i] < rotateArray[i - 1])
            {
                return rotateArray[i];
            }
        }
        return rotateArray[0];
    }

    int minNumberInRotateArray2(vector<int> rotateArray)
    {
        int size = rotateArray.size();
        if (size == 0)
        {
            return 0;
        }

        if (size == 1 || rotateArray[0] < rotateArray[size - 1])
        {
            return rotateArray[0];
        }

        int left = 0;
        int right = size - 1;
        int mid = 0;

        while (true)
        {
            mid = left + (right - left) / 2;
            if (rotateArray[mid] > rotateArray[right] && mid < right)
            {
                left = mid + 1;
                continue;
            }
            else if (rotateArray[mid] < rotateArray[right])
            {
                right = mid;
                if (rotateArray[mid - 1] > rotateArray[mid])
                {
                    return rotateArray[mid];
                }
            }
            else
            {
                return rotateArray[mid];
            }
        }
    }
};