struct TreeNode
{
	int val;
	int liss;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), liss(0), left(NULL), right(NULL){}
};

int LISS(TreeNode* root)
{
	if(!root)
	{
		return 0;
	}
	if(root->liss)
		return root->liss;

	if(root->left == NULL && root->right == NULL)
		return (root->liss = 1);

	int root_included = 1;
	if(root->left)
		root_included += LISS(root->left->left) + LISS(root->right->right);

	if(root->right)
		root_included += LISS(root->right->left) + LISS(root->right->right);

	int root_excluded = LISS(root->left) + LISS(root->right);
	root->liss = max(root_excluded, root_included);;
	return root->liss;
}