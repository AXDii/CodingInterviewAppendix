/***
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的
 * 双向链表。要求不能创建任何新的结点，只能调整树中结
 * 点指针的指向。
 * 
 * 解题思路：使用中层遍历法，不断更新前继节点
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
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if(pRootOfTree == nullptr) {
            return nullptr;
        }
        TreeNode* pre = nullptr;
        dfs(pRootOfTree, pre);
        TreeNode* p = pRootOfTree;
        while(p->left) {
            p=p->left;
        }
        return p;
    }

    void dfs(TreeNode *node, TreeNode* &pre)
    {
        if(node == nullptr) {
            return;
        }
        dfs(node->left, pre);
        node ->left = pre;
        if(pre) pre->right = node;
        pre = node;
        dfs(node->right, pre);
    }
};

int main()
{

    system("pause");
    return 0;
}