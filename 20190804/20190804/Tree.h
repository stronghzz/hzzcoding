#pragma once
#include <iostream>
using namespace std;
typedef struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
};

// 前序遍历
void PreorderTraversal(Node *root) {
	if (root == NULL) {
		// 空树
		return;
	}

	printf("%d ", root->val);		// 根
	PreorderTraversal(root->left);	// 前序遍历左子树
	PreorderTraversal(root->right);	// 前序遍历右子树
}

// 中序遍历
void InorderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	InorderTraversal(root->left);
	printf("%d ", root->val);
	InorderTraversal(root->right);
}

// 后序遍历
void PostorderTraversal(Node *root) {
	// 终止条件
	if (root == NULL) {
		return;
	}

	// 递推的过程
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	printf("%d ", root->val);
}


int GetNodeCount(Node *root) {
	// 终止条件是什么？
	if (root == NULL) {
		return 0;
	}
	// 递推公式是什么？
	return GetNodeCount(root->left) + GetNodeCount(root->right) + 1;
}

int GetHeight(Node *root) {
	if (root == NULL) {
		return 0;
	}

	int left = GetHeight(root->left);
	int right = GetHeight(root->right);

	return (left > right ? left : right) + 1;
}