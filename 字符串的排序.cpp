/***
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
 * 则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 * 
 * 解题思路：使用递归法进行全部遍历
 * 
 * 
 * */

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        int len = str.size();
        int sign[len];
        for(int i = 0; i < len; i++) {
            sign[i] = 0;
        }
        string ans = str;
        vector<string> a;
        if(len == 0) {
            return a;
        }
        dfs(str, sign, ans, 0, len, a);
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        return a;
    }

    void dfs(string &str, int* sign, string &ans,int next, int n, vector<string> &a){
        if(next == n){
            string str = ans;
            a.push_back(str);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(sign[i] == 1) {
                continue;
            }
            ans[next] = str[i];
            sign[i] = 1;
            dfs(str, sign, ans, next + 1, n, a);
            sign[i] = 0;
        }
    }
};

int main(){


    string str = "abcd";
    Solution s;
    s.Permutation(str);

    system("pause");
    return 0;
}