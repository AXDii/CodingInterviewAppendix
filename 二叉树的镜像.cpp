/***
 * 
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
 * 
 * 解题思路：法一：递归；法二：非递归，栈
 * 
 * */

#include <iostream>
#include <stack>
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
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == NULL)
        {
            return;
        }
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }

    void Mirror2(TreeNode *pRoot)
    {
        if (pRoot == NULL)
        {
            return;
        }
        stack<TreeNode *> s;
        s.push(pRoot);
        while (!s.empty())
        {
            pRoot = s.top();
            s.pop();
            swap(pRoot->left, pRoot->right);
            if (pRoot->left != NULL)
            {
                s.push(pRoot->left);
            }
            if (pRoot->right != NULL)
            {
                s.push(pRoot->right);
            }
        }
    }

    void swap(TreeNode *&p1, TreeNode *&p2)
    {
        TreeNode *tmp = p1;
        p1 = p2;
        p2 = tmp;
    }
};

int main()
{
    return 0;
}