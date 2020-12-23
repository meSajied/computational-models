#include <vector>
#include <cstring>

#ifndef TREE_H
#define TREE_H

class Tree{
private:
    class TreeNode{
    public:
        string name;
        vector <TreeNode> children;
        TreeNode* left;
        TreeNode* right;
    };

public:
    TreeNode root;
    
    void in_order_travrsal(TreeNode node);
    void post_order_travrsal(TreeNode node);
};

#endif