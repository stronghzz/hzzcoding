#pragma once
#define _CRT_SECURE_NO_WARNINGS


#include "CreatTree.h"



//中序遍历
void Inorder(Node *root)
{
	if (root == NULL) {
		return;
	}

	Inorder(root->left);
	printf("%d ", root->val);
	Inorder(root->right);
}
void Preorder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ",root->val);
	Preorder(root->left);
	Preorder(root->right);
}

// 遍历的思路
int n;
void GetSize(Node *root) {
	if (root == NULL) {
		return;
	}

	GetSize(root->left);
	n++;
	GetSize(root->right);
}

// 递推的思路
int GetSize2(Node *root) {
	if (root == NULL) {
		return 0;
	}

	return GetSize2(root->left)
		+ GetSize2(root->right)
		+ 1;
}

// 叶子结点个数
int leaf_n;
void GetLeafSize(Node *root) {
	if (root == NULL) {
		return;
	}

	if (root->left == NULL && root->right == NULL) {
		leaf_n++;
	}

	GetLeafSize(root->left);
	GetLeafSize(root->right);
}

// 递推的思路
int GetLeafSize2(Node *root) {
	if (root == NULL) {
		return 0;
	}

	if (root->left == NULL && root->right == NULL) {
		return 1;
	}

	return GetLeafSize2(root->left) + GetLeafSize2(root->right);
}

int LevelK(Node *root, int k) {
	if (root == NULL) {
		return 0;
	}

	if (k == 1) {
		return 1;
	}

	return LevelK(root->left, k - 1) + LevelK(root->right, k - 1);
}


// 在树中查找 val 值，树的 val 一定不重复
// 查找次序，有序判断根，根不是，去左子树找，左子树没找到，继续右子树
// 返回包含 val 的结点地址，没找到返回 NULL
Node * Find(Node *root, char val) {
	if (root == NULL) {
		return NULL;
	}

	// 先判断根
	if (root->val == val) {
		return root;
	}

	// 去左子树找
	Node *r = Find(root->left, val);
	if (r != NULL) {
		return r;
	}
	// 没找到
	// 判断左子树有没有找到
	// 决定是否去右子树找
	r = Find(root->right, val);
	if (r != NULL) {
		return r;
	}

	// 右子树也没找到
	return NULL;
}


#include <queue>
// 层序遍历
void LevelOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	// 来个队列，队列中存的数据类型是 Node *
	// 命名空间
	// 模板
	queue<Node *> q;

	q.push(root);

	while (!q.empty()) {
		Node * node = q.front();	// 取队首结点
		q.pop();					// 弹出队首结点
		printf("%c ", node->val);

		if (node->left != NULL) {
			q.push(node->left);
		}

		if (node->right != NULL) {
			q.push(node->right);
		}
	}
}

bool IsCompleteTree(Node *root) {
	if (root == NULL) {
		return true;
	}

	// 来个队列，队列中存的数据类型是 Node *
	// 命名空间
	// 模板
	queue<Node *> q;

	q.push(root);

	while (1) {
		Node * node = q.front();	// 取队首结点
		q.pop();					// 弹出队首结点
		if (node == NULL) {
			// 在层序遍历的过程中遇到空结点
			break;
		}
		q.push(node->left);
		q.push(node->right);
	}

	// 检查剩下结点中有没有非空结点
	while (!q.empty()) {
		Node *node = q.front(); q.pop();
		if (node != NULL) {
			return false;
		}
	}

	return true;
}

#include <stack>
// 前序遍历非递归
void PreorderTraversalNoR(Node *root) {
	stack<Node *>	s;	// 栈
	Node *cur = root;
	Node *top = NULL;

	while (cur != NULL || !s.empty()) {
		// 一路向左的过程
		while (cur != NULL) {
			printf("%c ", cur->val);
			s.push(cur);
			cur = cur->left;
		}

		// 一定是向左遇到 NULL
		// 利用栈处理剩余的右子树
		top = s.top();	s.pop();
		//top = StackTop(&s); StackPop(&s);

		cur = top->right;
	}
}

void InorderTraversalNoR(Node *root) {
	stack<Node *>	s;	// 栈
	Node *cur = root;
	Node *top = NULL;

	while (cur != NULL || !s.empty()) {
		// 一路向左的过程
		while (cur != NULL) {
			// 第一次遇到的结点的位置
			s.push(cur);
			cur = cur->left;
		}

		// 一定是向左遇到 NULL
		// 利用栈处理剩余的右子树
		top = s.top();	s.pop();
		//top = StackTop(&s); StackPop(&s);
		// 第二次遇到的地方
		printf("%c ", top->val);

		cur = top->right;
	}
}


void PostorderTraversalNoR(Node *root) {
	stack<Node *>	s;	// 栈
	Node *cur = root;
	Node *top = NULL;
	Node *last = NULL;

	while (cur != NULL || !s.empty()) {
		// 一路向左的过程
		while (cur != NULL) {
			// 第一次遇到的结点的位置
			s.push(cur);
			cur = cur->left;
		}

		// 一定是向左遇到 NULL
		// 利用栈处理剩余的右子树
		top = s.top();
		if (top->right == NULL) {
			printf("%c ", top->val);
			s.pop();
			last = top;
		}
		else if (top->right == last) {
			printf("%c ", top->val);
			s.pop();
			last = top;
		}
		else {
			cur = top->right;
		}
	}
}


#if 0
long long sum(int n) {
	if (n == 1) {
		return 1;
	}

	return sum(n - 1) + n;
}
#endif





//
//char buff[100 * 10000];
//int index;
//
//
//void PreorderBracket(struct Node *root) {
//	if (root == NULL) {
//		return;
//	}
//
//	index += sprintf(buff + index, "(");
//	index += sprintf(buff + index, "%d", root->val);
//	if (root->left == NULL && root->right == NULL) {
//		index += sprintf(buff + index, ")");
//		return;
//	}
//
//	if (root->left != NULL && root->right == NULL) {
//		PreorderBracket(root->left);
//		index += sprintf(buff + index, ")");
//		return;
//	}
//
//	if (root->left == NULL && root->right != NULL) {
//		index += sprintf(buff + index, "()");
//		PreorderBracket(root->right);
//		index += sprintf(buff + index, ")");
//		return;
//	}
//
//	PreorderBracket(root->left);
//	PreorderBracket(root->right);
//	index += sprintf(buff + index, ")");
//}
//
//char * tree2str(struct Node *root) {
//	memset(buff, 0x0, 100 * 10000);
//	index = 0;
//	PreorderBracket(root);
//
//	buff[index - 1] = 0;
//	return buff + 1;
//}




