struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int LISS(TreeNode* root)
{
	if(!root)
	{
		return 0;
	}

	int root_included = 1;
	if(root->left)
		root_included += LISS(root->left->left) + LISS(root->right->right);

	if(root->right)
		root_included += LISS(root->right->left) + LISS(root->right->right);

	int root_excluded = LISS(root->left) + LISS(root->right);

	return max(root_excluded, root_included);
}