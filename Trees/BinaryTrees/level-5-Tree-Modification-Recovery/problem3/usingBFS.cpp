
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        int currDepth=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode * rootNode=q.front();
                q.pop();
                if(depth-1==currDepth){
                    TreeNode *leftChild=new TreeNode(val);
                    TreeNode *rightChild=new TreeNode(val);

                    leftChild->left=rootNode->left;
                    rightChild->right=rootNode->right;

                    rootNode->left=leftChild;
                    rootNode->right=rightChild;
                }
                if(rootNode->left) q.push(rootNode->left);
                if(rootNode->right) q.push(rootNode->right);
            }
            currDepth++;
            if(currDepth==depth) return root;
        }
        return root;
    }
};
