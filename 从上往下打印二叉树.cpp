/***
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 * 
 * 解题思路：广度遍历
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        bfs(root, ans);
        return ans;
    }

    void bfs(TreeNode* root, vector<int>& ans) {
        vector<TreeNode*> queen;
        int index = 0;
        if(root != NULL) {
            queen.push_back(root);
        }
        while(index < queen.size()) {
            TreeNode* node = queen[index++];
            if(node->left != NULL) {
                queen.push_back(node->left);
            }
            if(node->right != NULL) {
                queen.push_back(node->right);
            }
        }

        for(int i = 0; i < queen.size(); i++) {
            ans.push_back(queen[i]->val);
        }
    }
};

int main(){


    system("pause");
    return 0;
}