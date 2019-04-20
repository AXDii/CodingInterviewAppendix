/***
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，
 * 因此输出2。如果不存在则输出0。
 * 
 * 解题思路：使用一个map存储出现次数
 * 
 * */

#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        map<int, int> counts;
        for(int i = 0; i < numbers.size(); i++) {
            if(counts.find(numbers[i]) == counts.end()) {
                counts[numbers[i]] = 1;
            } else
            {
                counts[numbers[i]]++;
            }
        }
        map<int, int>::iterator it;
        it = counts.begin();
        int k = numbers.size() / 2;
        while(it != counts.end()) {
            if(it->second > k) {
                return it->first;
            }
            it++;
        }
        return 0;
    }
};

int main(){

    Solution s;
    vector<int> numbers;
    numbers.push_back(71);
    numbers.push_back(13);
    numbers.push_back(12);
    numbers.push_back(2);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(5);
    numbers.push_back(1);
    numbers.push_back(1);
    cout<<s.MoreThanHalfNum_Solution(numbers);
    system("pause");
    return 0;
}