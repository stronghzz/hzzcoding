#pragma once
#include <iostream>
using namespace std;
typedef struct Node 
{
	int val;
	Node* left;
	Node* right;
}Node;

typedef struct {
	Node *root;		// 创建好的树的根结点
	int	used;		// 创建树过程中用掉的 val 个数
}	Result;

Result CreateTree(int preorder[], int size) {
	if (size == 0) {
		Result result = { NULL, 0 };

		return result;
	}

	char rootValue = preorder[0];
	if (rootValue == '#') {
		Result result = { NULL, 1 };

		return result;
	}

	// 创建根结点
	Node *root = (Node *)malloc(sizeof(Node));
	root->val = rootValue;

	// 创建左子树
	Result left_result = CreateTree(preorder + 1, size - 1);
	/*
	left_result.root;	// 创建好的左子树的根结点
	left_result.used;	// 创建左子树过程中用掉的 val 的个数
	*/
	// 创建右子树
	Result right_result = CreateTree(preorder + 1 + left_result.used, size - 1 - left_result.used);
	root->left = left_result.root;
	root->right = right_result.root;

	Result result = { root, 1 + left_result.used + right_result.used
	};
	return result;
}