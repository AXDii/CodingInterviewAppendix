/***
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、
 * else、switch、case等关键字及条件判断语句（A?B:C）。
 * 
 * 解法：短路求值原理
 * 
 * */
#include <iostream>
using namespace std;
class Solution {
public:
    int Sum_Solution(int n) {
        return func(n);
    }

    int func(int n) {
        int ans = n;
        ans && (ans = (ans + func(n-1)));
        return ans;
    }
};

int main() {

    Solution s;
    cout<<s.Sum_Solution(100);
    system("pause");
    return 0;
}