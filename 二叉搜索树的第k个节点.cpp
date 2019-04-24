/***
 * 
 * 给定一棵二叉搜索树，请找出其中的第k小的结点。
 * 例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
 * 
 * 解题思路：使用中序排序即可
 * 
 * */

#include <iostream>
// #include <vector>
// #include<algorithm>
// #include<string>
#include <stack>
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
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        int count = 0;
        // TreeNode* tree[100];
        stack<TreeNode *> tree;
        TreeNode *node = pRoot;
        while (node != NULL || !tree.empty())
        {
            while (node != NULL)
            {
                tree.push(node);
                node = node->left;
            }
            if(!tree.empty()) {
                node = tree.top();
                if(++count == k) {
                    return node;
                }
                tree.pop();
                node = node->right;
            }
        }
        return NULL;
    }
};

int main()
{

    system("pause");
    return 0;
}