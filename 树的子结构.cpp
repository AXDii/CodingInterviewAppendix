/**
 * 输入两棵二叉树A，B，判断B是不是A的子结构。
 * （ps：我们约定空树不是任意一个树的子结构）
 * 
 * 解题思路：使用递归的方式判断
 * 
 * */
#include <iostream>
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
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        bool result = false;
        if (pRoot1 != NULL && pRoot2 != NULL)
        {
            if (pRoot1->val == pRoot2->val)
            {
                result = equal(pRoot1, pRoot2);
            }
            if (!result)
            {
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            if (!result)
            {
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return result;
    }

    bool equal(TreeNode *p1, TreeNode *p2)
    {
        if (p2 == NULL)
        {
            return true;
        }
        if (p1 == NULL)
        {
            return false;
        }
        if (p1->val != p2->val)
        { //不相等则返回false
            return false;
        }
        return equal(p1->left, p2->left) && equal(p1->right, p2->right); //左右是否相同
    }
};

int main()
{

    system("pause");
    return 0;
}