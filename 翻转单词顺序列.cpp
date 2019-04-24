/***
 * 
 * 
 * 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，
 * 写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向
 * Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。
 * 后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应
 * 该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，
 * 你能帮助他么？
 * 
 * 解题思路：反转两次
 * 
 * */

#include <iostream>
// #include <vector>
#include<algorithm>
#include<string>
// #include<cstring>
// #include <stack>
// #include <queue>
// #include <map>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        string::size_type s = 0, e;       
        while((e=str.find(' ', s)) != string::npos){
            reverse(str.begin()+s, str.begin()+e);
            s = e + 1;
        }
        reverse(str.begin()+s, str.end());
        return str;
    }
};
int main()
{

    system("pause");
    return 0;
}


