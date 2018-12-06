void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == NULL || *pHead == NULL)
	{
		return;
	}

	ListNode* pToBeDeleted = NULL;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}
		if (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDeleted != NULL)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
void PrintListReversingly(ListNode* pHead)
{
	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}