#if 0

ListNode * deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}

	ListNode *p0 = NULL;
	ListNode *p1 = pHead;
	ListNode *p2 = pHead->next;

	while (p2 != NULL) {
		if (p1->val != p2->val) {
			p0 = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else {
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}
			// 1. p2 走到链表结尾
			// 2. p2 遇到不相等的值了

			ListNode *cur = p1, *next;
			while (cur != p2) {
				next = cur->next;
				free(cur);
			}

			if (p2 == NULL) {
				if (p0 != NULL) {
					p0->next = p2;	// NULL
				}
				else {
					return NULL;
				}
				break;
			}

			if (p0 != NULL) {
				p0->next = p2;
			}
			else {
				pHead = p2;
			}
			p1 = p2;
			p2 = p2->next;
		}
	}

	return pHead;
}

#endif

#if 0

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL) {
		return l2;
	}

	if (l2 == NULL) {
		return l1;
	}

	struct ListNode *p1 = l1;
	struct ListNode *p2 = l2;
	struct ListNode *r = NULL;
	struct ListNode *rtail = NULL;	// r 链表的最后一个结点

	while (p1 != NULL && p2 != NULL) {
		if (p1->val <= p2->val) {
			// 尾插 p1 到 r 上
			if (rtail == NULL) {
				r = rtail = p1;
			}
			else {
				rtail->next = p1; rtail = rtail->next;
			}
			p1 = p1->next;
		}
		else {
			// 尾插 p2 到 r 上
			if (rtail == NULL) {
				r = rtail = p2;
			}
			else {
				rtail->next = p2; rtail = p2;
			}
			p2 = p2->next;
		}
	}

	// p1 或者 p2 为空
	if (p1 == NULL) {
		// 把 p2 整个跟在 r 的后面
		rtail->next = p2;
	}
	else {
		// 把 p1 整个跟在 r 的后面
		rtail->next = p1;
	}

	return r;
}

#endif

#if 0

ListNode* partition(ListNode* pHead, int x) {
	// 把链表分成 3 部分
	ListNode *lt = NULL;	// 比 x 小
	ListNode *ltTail = NULL; // 小的最后一个结点
	ListNode *eq = NULL;	// 和 x 相等
	ListNode *eqTail = NULL; // 相等最后一个结点
	ListNode *gt = NULL;	// 比 x 大
	ListNode *gtTail = NULL; // 大的最后一个结点

	ListNode *cur = pHead;
	while (cur != NULL) {
		if (cur->val < x) {



			// lt 这个链表为空，没有结点
			// lt 链表不为空，lt 并且指向第一个结点
			// ltTail 不为空，指向最后一个结点
			if (lt == NULL) {
				// 第一种情况
				// 把 cur 插到空链表里
				// 链表里只有一个结点
				lt = ltTail = cur;
			}
			else {
				// 尾插
				ltTail->next = cur;
				// ltTail 变成倒数第二个结点
				ltTail = ltTail->next;
			}








		}
		else if (cur->val == x) {
			if (eq == NULL) {
				eq = eqTail = cur;
			}
			else {
				eqTail->next = cur;
				eqTail = eqTail->next;
			}
		}
		else {
			if (gt == NULL) {
				gt = gtTail = cur;
			}
			else {
				gtTail->next = cur;
				gtTail = gtTail->next;
			}
		}
		cur = cur->next;
	}
}

#endif


#if 0	// 找到两个相交链表的公共结点

int GetLength(ListNode *head) {
	int len = 0;
	ListNode *cur = head;
	while (cur != NULL) {
		cur = cur->next;
		len++;
	}

	return len;
}

ListNode * GetCommon(ListNode *p1, ListNode *p2)
{
	int len1 = GetLength(p1);
	int len2 = GetLength(p2);
	ListNode *longer, *shorter;
	int diff;	// 长度差
	if (len1 >= len2) {
		longer = p1;
		shorter = p2;
		diff = len1 - len2;
	}
	else {
		longer = p2;
		shorter = p1;
		diff = len2 - len1;
	}

	// 先让长的走 diff 步
	for (int i = 0; i < diff; i++) {
		longer = longer->next;
	}

	while (longer != shorter) {	// 比较不是 val，而是结点地址
		longer = longer->next;
		shorter = shorter->next;
	}

	return longer;
}

#endif

#if 0	// 判断是否带环
bool hasCycle(struct ListNode *head) {
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	do {
		if (fast == NULL) {
			break;
		}
		fast = fast->next;
		if (fast == NULL) {
			break;
		}
		fast = fast->next;
		slow = slow->next;
	} while (fast != slow);

	if (fast == NULL) {
		return false;
	}
	else {
		return true;
	}
}
#endif

#if 0	// 复杂链表复制

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     struct RandomListNode *next;
*     struct RandomListNode *random;
* };
*/

struct RandomListNode * CreateNode(int label)
{
	struct RandomListNode *p = (struct RandomListNode *)
		malloc(sizeof(struct RandomListNode));
	p->label = label;
	p->next = p->random = NULL;
	return p;
}

struct RandomListNode *copyRandomList(struct RandomListNode *head)
{
	// 1. 复制原链表，让新的结点跟在老的结点后边
	struct RandomListNode *oldNode = head;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = CreateNode(oldNode->label);
		newNode->next = oldNode->next;
		oldNode->next = newNode;

		oldNode = oldNode->next->next;
	}

	// 处理 random 指针
	oldNode = head;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = oldNode->next;
		if (oldNode->random != NULL) {
			newNode->random = oldNode->random->next;
		}

		oldNode = oldNode->next->next;
	}

	// 把一个链表拆成两个链表
	oldNode = head;
	struct RandomListNode *newHead = head->next;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = oldNode->next;
		oldNode->next = newNode->next;
		if (oldNode->next != NULL) {
			newNode->next = oldNode->next->next;
		}
		else {
			newNode->next = NULL;	// 本身原来就是 NULL
		}

		oldNode = oldNode->next;
	}

	return newHead;
}
#endif