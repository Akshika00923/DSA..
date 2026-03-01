#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val ;
        left = NULL;
        right = NULL;
    }
};

vector<int> allTraversals(TreeNode* root) {
    if(root == NULL) return {};

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;

    while(!st.empty()) {
        auto &it = st.top();
        TreeNode* node = it.first;
        int &state = it.second;

        if(state == 1) {
            pre.push_back(node->data);
            state++;
            if(node->left) st.push({node->left,1});
        }
        else if(state == 2) {
            in.push_back(node->data);
            state++;
            if(node->right) st.push({node->right,1});
        }
        else {
            post.push_back(node->data);
            st.pop();
        }
    }

    // Combine all three traversals into one vector for return (pre + in + post)
    vector<int> result;
    result.insert(result.end(), pre.begin(), pre.end());
    result.insert(result.end(), in.begin(), in.end());
    result.insert(result.end(), post.begin(), post.end());
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = allTraversals(root);
    for(auto val: result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}