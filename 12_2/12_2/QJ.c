// 移除链表元素
#if 0
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL) {
		return NULL;
	}

	struct ListNode *prev = head;
	struct ListNode *cur = head->next;

	while (cur != NULL) {
		if (cur->val != val) {
			prev = cur;
		}
		else {
			prev->next = cur->next;
			free(cur);
		}
		cur = prev->next;
	}

	struct ListNode *newHead = head;
	if (head->val == val) {
		newHead = head->next;
		free(head);
	}

	return newHead;
}
#endif

// 反转单链表
#if 0
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *newHead = NULL;
	struct ListNode *node;

	while (head != NULL) {
		// 对之前的链表做头删
		node = head;
		head = head->next;

		// 对新链表做头插
		node->next = newHead;
		newHead = node;
	}

	return newHead;
}
#endif

#if 0
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL) {
		return NULL;
	}

	struct ListNode *p0 = NULL;
	struct ListNode *p1 = head;
	struct ListNode *p2 = head->next;

	while (p1 != NULL) {
		p1->next = p0;

		p0 = p1;
		p1 = p2;
		if (p2 != NULL) {
			p2 = p2->next;
		}
	}

	return p0;
}
#endif