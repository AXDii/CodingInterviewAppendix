/***
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 * 
 * 
 * 解题思路：从最低部开始比较，保留left和right
 * 
 * */

#include <iostream>
// #include <vector>
// #include<algorithm>
// #include<string>
// #include <stack>
// #include <queue>
// #include <map>
// #include <stdlib.h>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
        return dfs(pRoot) == -1;
    }

    int dfs(TreeNode* p) {
        if(p == nullptr) {
            return 0;
        }
        int left = dfs(p->left);
        int right = dfs(p->right);
        if(left == -1) return -1;
        if(right == -1) return -1;
        return abs(left - right) > 1 ? -1 :1 + max(left, right);

    }

    int abs(int num){
        if(num < 0) {
            return -num;
        }
        return num;
    }

    int max(int a, int b) {
        if(a > b) {
            return a;
        }
        return b;
    }
    
};

int main()
{

    system("pause");
    return 0;
}