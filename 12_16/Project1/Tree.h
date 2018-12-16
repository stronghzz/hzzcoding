#pragma once
typedef struct Node {
	int val;
	struct Node *left;
	struct Node *right;
}	Node;

// 树的根结点
#if 0	// 第一版
void Preorder(Node *root)
{
	if (root == NULL) {
		return;
	}
	else if (root->left == NULL && root->right == NULL) {
		printf("%d ", root->val);
		return;
	}
	else if (root->left != NULL && root->right == NULL) {
		printf("%d ", root->val);
		Preorder(root->left);
		return;
	}
	else if (root->left == NULL && root->right != NULL) {
		printf("%d ", root->val);
		Preorder(root->right);
		return;
	}
	else {
		printf("%d ", root->val);
		Preorder(root->left);
		Preorder(root->right);
		return;
	}
}
#endif

#if 0	// 第二版
void Preorder(Node *root)
{
	if (root == NULL) {
		return;
	}

	printf("%d ", root->val);
	if (root->left != NULL) {
		Preorder(root->left);
	}
	if (root->right != NULL) {
		Preorder(root->right);
	}
}
#endif

void Preorder(Node *root)
{
	if (root == NULL) {
		return;
	}

	printf("%d ", root->val);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node *root)
{
	if (root == NULL) {
		return;
	}

	Inorder(root->left);
	printf("%d ", root->val);
	Inorder(root->right);
}

void Postorder(Node *root)
{
	if (root == NULL) {
		return;
	}

	Postorder(root->left);
	Postorder(root->right);
	printf("%d ", root->val);
}


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL) {
		return true;
	}

	if (p == NULL || q == NULL) {
		return false;
	}

	return p->val == q->val
		&& isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}

bool isMirrorTree(struct TreeNode *p, struct TreeNode *q)
{
	if (p == NULL && q == NULL) {
		return true;
	}

	if (p == NULL || q == NULL) {
		return false;
	}

	return p->val == q->val
		&& isMirrorTree(p->left, q->right)
		&& isMirrorTree(p->right, q->left);
}
