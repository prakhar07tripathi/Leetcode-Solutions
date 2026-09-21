/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    bool sametree(TreeNode* tempp, TreeNode* tempq){
        if(!tempp && !tempq)return true;
        else if(tempp && tempq){
            if(tempp->val != tempq->val){
                return false;
            }
            return sametree(tempp->left, tempq->left) && sametree(tempp->right, tempq->right);
        }
        return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return sametree(p,q);
    }
};