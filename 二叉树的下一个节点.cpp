/***
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序
 * 的下一个结点并且返回。注意，树中的结点不仅包含左右
 * 子结点，同时包含指向父结点的指针。
 * 
 * 
 * 解题思路：有三种情况：
 * 1.如果存在右儿子，返回右儿子的最左儿子
 * 2.如果不存在右儿子，找父节点第一个向左走的节点
 * 3.都没有，返回空值
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

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (pNode == nullptr)
        {
            return nullptr;
        }
        TreeLinkNode *next = nullptr;
        if (pNode->right != nullptr)
        {
            next = pNode->right;
            while (next->left != nullptr)
            {
                next = next->left;
            }
            return next;
        }
        else
        {
            TreeLinkNode *child = pNode;
            TreeLinkNode *parent = child->next;
            if (parent == nullptr)
            {
                return nullptr;
            }
            if (child == parent->left)
            {
                return parent;
            }
            while (parent->next != nullptr && parent == parent->next->right)
            {
                parent = parent->next;
            }
            return parent->next;
        }
    }
};

int main()
{

    system("pause");
    return 0;
}