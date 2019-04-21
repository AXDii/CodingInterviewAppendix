/***
 * 输入一棵二叉树，求该树的深度。从根结点到叶结点依次
 * 经过的结点（含根、叶结点）形成树的一条路径，最长路
 * 径的长度为树的深度。
 * 
 * 
 * 解题思路：深度优先遍历
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
    int TreeDepth(TreeNode* pRoot)
    {
        int max = 0;
        dfs(pRoot, 0, max);
        return max;
    }

    void dfs(TreeNode* p, int num, int &max) {
        if(p == nullptr) {
            if(max < num) {
                max = num;
            }
            return;
        }
        dfs(p->left, num + 1, max);
        dfs(p->right, num + 1, max);
    }
};

int main()
{

    system("pause");
    return 0;
}