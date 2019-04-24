/***
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么
 * 一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对
 * 数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}
 * ， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}
 * ， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 * 
 * 
 * 解题思路：使用双端队列,详细如注释
 * 
 * */

#include <iostream>
#include <vector>
// #include<algorithm>
// #include<string>
// #include <stack>
#include <queue>
// #include <map>
// #include <stdlib.h>
using namespace std;

class Solution
{
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> res;
        deque<int> s;
        for(unsigned int i = 0; i < num.size(); i++) {
            //从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
            while(s.size() && num[s.back()] < num[i]) {
                s.pop_back();
            }
            //当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在滑动窗口中，需要弹出
            while(s.size() && i-s.front() + 1 > size) {
                s.pop_front();
            }
            s.push_back(i);//把每次滑动的num下标加入队列中
            if(size && i + 1 >= size) {
                res.push_back(num[s.front()]);
            }
        }
        return res;
    }

    
};

int main()
{

    system("pause");
    return 0;
}