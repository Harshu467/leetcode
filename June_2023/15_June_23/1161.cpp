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
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        queue<TreeNode*>queue;
        queue.push(root);
        int maxLevel = 1;
        int maxSum = INT_MIN;
        int level = 1;
        while(!queue.empty())
        {
            int levelsum = 0;
            int levelsize = queue.size();
            for(int i=0;i<levelsize;i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                levelsum+=node->val;
                if(node->left!=nullptr)
                {
                    queue.push(node->left);
                }
                if(node->right!=nullptr)
                {
                    queue.push(node->right);
                }
            }
            if(levelsum >maxSum)
            {
                maxSum = levelsum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};


// Sample Input : 
//                            1
//                     7           0
//                 7       -8  

// First travel through BFS and using queue push node in it and levelup and store max value till leaf node


// For Level 1 :
//         Queue -> 1 
//         level = 1 , maxSum = 0 , maxLevel = 1 ;
//         In level 1 maxSum is 1 so maxSum = 1;
//         and before leaving level 1 check left and right nodes whether they are null and if not then push in queue
//         and pop the node
//         so Queue become = > 0 7

// For Level 2 :
//         Queue -> |0 | 7 | -> FIFO
//         level = 1 , maxSum = 1 , maxLevel = 1 ;
//         In level 2 maxSum is 7 so maxSum = 1;
//         and before leaving level 2 check left and right nodes whether they are null and if not then push in queue
//         and pop the node
//         so Queue become = > 7 -8

// For Level 3 :
//         Queue -> |7 | -8 | -> FIFO
//         level = 2 , maxSum = 7 , maxLevel = 2 ;
//         In level 3 maxSum is -1 so maxSum = 7;
//         and before leaving level 3 check left and right nodes whether they are null and if not then push in queue
//         and pop the node
//         so Queue become empty
