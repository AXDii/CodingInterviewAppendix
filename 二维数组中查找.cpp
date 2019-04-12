/**在一个二维数组中（每个一维数组的长度相同），每一行
 * 都按照从左到右递增的顺序排序，每一列都按照从上到下
 * 递增的顺序排序。请完成一个函数，输入这样的一个二维
 * 数组和一个整数，判断数组中是否含有该整数。
 * 
 * 解题思路：从左下角开始扫描，比左下角大的话右移，比左下角小的话上移，等于返回
 * 
 */

#include<iostream>>
#include<vector>
#include<cstddef>//size_t

using namespace std;

void stop();
bool Find(int target, vector<vector<int>> array) {

    int row = array.size();
    int col = array[0].size();
    int i = 0, j = 0;
    for(i = row - 1, j = 0; i >= 0 && j < col;) {
        if(target == array[i][j]) {
            return true;
        } else if(target < array[i][j]) {
            i--;
            continue;
        } else if(target > array[i][j]) {
            j++;
            continue;
        }
    } 
    return false;



}

int main(){

    

    return 0;
}

void stop(){
    cout<<endl;
    system("pause");
}