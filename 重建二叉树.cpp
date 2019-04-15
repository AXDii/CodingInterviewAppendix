/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
* 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输
* 入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,
* 8,6}，则重建二叉树并返回。
* 
* 解题思路：使用递归
*/

#include<iostream>
#include<vector>
using namespace std;
 
 //Definition for binary tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, int startPre, int endPre, vector<int> vin, int startVin, int endVin) {
        if(startPre > endPre || startVin > endVin) {
            return NULL;
        }
        TreeNode* parent = new TreeNode(pre[startPre]);
        for(int i = startVin; i <= endVin; i++) {
            if(pre[startPre] == vin[i]) {
                parent->left = reConstructBinaryTree(pre, startPre + 1, startPre + i - startVin, vin, startVin, i-1);
                parent->right = reConstructBinaryTree(pre, startPre + i + 1 - startVin, endPre, vin, i+1, endPre);
                break;
            }
        }

        return parent;
    }

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode* parent = reConstructBinaryTree(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
        return parent;
    }
    
    
};