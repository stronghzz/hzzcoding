#include <stdio.h>
#include <stdlib.h>

typedef int TDataType;
typedef struct BNode
{
	TDataType data;
	struct BNode *left;
	struct BNode *right;
}BNode;

static BNode* CreateNode(TDataType data)
{
	BNode* node = (BNode*)malloc(sizeof(BNode));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}


//BNode* CreateTree(TDataType preorder[], int size)
//{
//
//
//}




int main()
{
	BNode* p = (BNode*)malloc(sizeof(BNode));

	return 0;
}