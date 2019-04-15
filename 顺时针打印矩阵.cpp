/***
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 * 
 * 解题思路：蛇形矩阵
 * 
 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        int count = 0;
        int i = -1;
        int j = -1;
        int rowLen = matrix.size();
        int colLen = matrix[0].size();

        int rowStart = 0;
        int rowEnd = rowLen;
        int colStart = 0;
        int colEnd = colLen;

        vector<int> res;
        int sum = rowLen * colLen;
        while(count < sum) {
            while(++j < colEnd && count< sum) {
                res.push_back(matrix[i+1][j]);
                count++;
            }
            i++;

            while(++i < rowEnd && count < sum) {
                res.push_back(matrix[i][j-1]);
                count++;
            }
            j--;

            while(--j >= colStart && count < sum) {
                res.push_back(matrix[i-1][j]);
                count++;
            }
            i--;

            while(--i >= rowStart + 1 && count < sum){
                res.push_back(matrix[i][j+1]);
                count++;
            }
            j++;

            colStart++;
            rowStart++;
            colEnd--;
            rowEnd--;
        } 
        return res;
    }
};

int main()
{
    Solution s;
    vector< vector<int> > arr;
    vector<int> a1(3);
    vector<int> a2(3);
    vector<int> a3(3);

    arr.push_back(a1);
    arr.push_back(a1);
    arr.push_back(a3);
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = ++count;
        }
    }
    s.printMatrix(arr);
    system("pause");
    return 0;
}