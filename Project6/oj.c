//一处链表元素
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* newhead;
	struct ListNode* newtail;
	newhead = newtail = NULL;
	struct ListNode* pcur = head;
	while (pcur) {
		if (pcur->val != val) {
			if (newhead == NULL) {
				newhead = newtail = pcur;
			}
			else {
				newtail->next = pcur;
				newtail = newtail->next;
			}
		}
		pcur = pcur->next;
	}
	if (newtail) {
		newtail->next = NULL;
	}
	returrn newhead;
}
//链表的中间节点
struct ListNode* middleNode(struct ListNode* head) {
	struct listNode* slow, * fast;
	slow = fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;

	}
	return slow;
}
//反转链表
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL) {
		return head;
	}
	struct listNode* n1, * n2, * n3;
	n1 = NULL, n2 = head, n3 = head->next;
	ListNode* pcur = head;
	while (n2) {
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3) {
			n3 = n3->next;
		}
	}
	return n1;
}
//合并链表
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListBode* list2) {
	if (list1 == NULL && list2=NULL) {
		return NULL;
	}
	if (list1 == NULL) {
		return list2;
	}
	if (list2 = NULL) {
		return list1;
	}

	struct ListNode* l1, * l2;
	l1 = list1, l2 = list2;
	struct ListNode* newhead, * newtail;
	newhead = newtail = NULL;

	while (l1 && l2) {
		if (l1->val < l2->val) {
			if (newhead == NULL) {
				newhead = newtail = l1;
			}
			else {
				newtail->next = l1;
				newtail = newtail->next;
			}
			l1 = l1->next;
		}
		else {
			if (newhead == NULL) {
				newhead = newtail = l2;
			}
			else {
				newtail->next = l2;
				newtail = newtail->next;

			}
			l2 = l2->next;
		}
		if (l1) {
			newtail->next = l1;
		}
		if (l2) {
			newtail->next = l2;
		}
	}

}
// 分割链表
struct listnode* partition(struct listnode* head, int x) {
	if (head == NULL) {
		return head;
	}
	struct listnode* lesshead, *lesstail;
	struct listnode* greaterhead, * greatertail;
	lesshead = lesstail = (struct listnode*)malloc(sizeof(struct listnode));
	greaterhead = greatertail = (struct listnode*)malloc(sizeof(struct listnode));
	struct listnode* pcur = head;
	while (pcur) {
		if (pcur->val < x) {
			lesstail->next = pcur;
			lesstail = lesstail->next;
		}
		else {
			greatertail->next = pcur;
			greatertail = greatertail->next;

		}
		pcur = pcur->next;

	}
	greatertail->next = NULL;
	lesstail->next = greaterhead->next;
	struct listnode* ret = lesshead->next;
	free(greaterhead);
	free(lesshead);
	return ret;



}


typedef struct Listnode LN;
LN* buynode(int x) {
	LN* newnode = (LN*)malloc(sizeof(LN));
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}
LN* createlist(int n) {
	LN* phead = buynode(1);
	LN* ptail = phead;
	for (int i = 2; i <= n; i++) {
		ptail->next = buynode(i);
		ptail = ptail->next;
	}
	ptail->next = phead;
	return ptail;
}
int ysf(int n, int m) {
	LN* pre = createlist(n);
	LN* pcur = pre->next;
	
	int count = 1;
	while (pcur->next != NULL) {
		if (count == m) {
			pre->next = pcur->next;
			free(pcur);
			pcur = pre->next;
			count = 1;
		else {
			pre = pcur;
			pcur = pcur->next;
			count++;
		}
		}
	}
}
