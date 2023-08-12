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
public:
    int sub(TreeNode *root, int &ans )
    {
        int left = 0, right = 0;
        // int ans = 0;

        if(root == NULL)
        {
            return 0;
        }
        if(root->left != NULL)
        {
            left =  sub(root->left, ans);
            // cout << root->left->val << " " <<ans << endl;
        }
        if(root->right != NULL)
        {
            right = sub(root->right, ans);
            // cout << root->right->val << " " <<ans << endl;
        }

        if(root->left!= NULL and root->left->val == root->val)
        {
            left += 1;
            ans = max(ans, left);
        }
        else{
            left = 0;
        }

        if(root->right!= NULL and root->right->val == root->val)
        {
            right += 1;
            ans = max(ans, right);

        }
        else{
            right = 0;
        }
        
        if((root->left != NULL && root->right != NULL) &&(root->val == root->left->val ) && (root->val == root->right->val))
        {
           ans = max(ans, left+right);   
        }
        
        if(root->right == NULL and root->left == NULL)
        {
            return 0;
        }
        else{
            return max(left, right);
        }


    }
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        sub(root, ans);
        return ans;
        
    }
};