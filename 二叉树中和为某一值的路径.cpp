/***
 * 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为
 * 输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结
 * 点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长
 * 度大的数组靠前)
 * 
 * 解题思路：深度优先遍历
 * 
 * */

#include<iostream>
#include<vector>
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > ans;
        vector<int> aAns;
        dfs(ans, aAns, root, expectNumber, 0);
        return ans;
    }

    void dfs(vector<vector<int> >& ans, vector<int>& aAns, TreeNode* (&node) , const int& expectNumber, int sum) {
        if(node == NULL){
            return;
        }
        aAns.push_back(node->val);
        if(node->left != NULL) {
            dfs(ans, aAns, node->left, expectNumber, sum + node->val);
        }
        if(node->right != NULL){
            dfs(ans, aAns, node->right, expectNumber, sum + node->val);
        }
        
        if(node->left == NULL && node->right == NULL && sum + node->val == expectNumber) {
            vector<int> tmp(aAns.begin(), aAns.end());
            ans.push_back(tmp);
        }
        aAns.pop_back();
    }
};

int main(){



    system("pause");
    return 0;
}