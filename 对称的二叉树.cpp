/***
 * 
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。
 * 注意，如果一个二叉树同此二叉树的镜像是同样的，定
 * 义其为对称的。
 * 
 * 解题思路：使用递归的方法，判断left->right 和 right->left 与 left->left 和 right->right是否相等
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

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    bool isSymmetrical(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
        {
            return true;
        }
        return dfs(pRoot->left, pRoot->right);
    }

    bool dfs(TreeNode *left, TreeNode *right)
    {
        bool b = true;
        if(left == nullptr) {
            return right == nullptr;
        }
        if(right == nullptr) {
            return false;
        }
        if(left->val != right->val) {
            return false;
        }
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};

int main()
{

    system("pause");
    return 0;
}