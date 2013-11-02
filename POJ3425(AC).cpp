#include <stdio.h>
#include <stdlib.h>

typedef enum State{
	NOT_ANSWERED,
	ANSWERED
}State;

typedef struct ListNode{
	long q;
	State state;
	int answered;
	struct ListNode *next;
}ListNode;

ListNode *CreateNode(long q)
{
	ListNode *ptr;

	ptr = (ListNode *)malloc(sizeof(ListNode));
	ptr->q = q;
	ptr->state = NOT_ANSWERED;
	ptr->answered = 0;
	ptr->next = NULL;

	return ptr;
}

ListNode *InsertNode(ListNode *head, long q)
{
	ListNode *ptr1;
	ListNode *ptr2;
	ListNode *tmp;

	tmp = CreateNode(q);
	if(head->next == NULL)
	{
		head->next = tmp;

		return tmp;
	}

	ptr1 = head;
	ptr2 = ptr1->next;

	while(1)
	{
		if(ptr2 == NULL)
		{
			ptr1->next = tmp;

			return tmp;
		}
		else if(ptr1->q < tmp->q && tmp->q < ptr2->q)
		{
			ptr1->next = tmp;
			tmp->next = ptr2;

			return tmp;
		}
		else
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}
}

ListNode *FindNode(ListNode *head, long q)
{
	ListNode *ptr;

	if(head == NULL)
	{
		return NULL;
	}

	ptr = head->next;
	while(ptr != NULL)
	{
		if(ptr->q == q)
		{
			return ptr;
		}
		else
		{
			ptr = ptr->next;
		}
	}

	return NULL;
}

int main()
{
	int i;
	int n;
	long q;
	int a;
	int x;
	long sum;
	ListNode *head;
	ListNode *current;

	head = (ListNode *)malloc(sizeof(ListNode));
	head->q = 0;
	head->state = NOT_ANSWERED;
	head->answered = 0;
	head->next = NULL;

	scanf("%d", &n);
	sum = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%ld%d%d", &q, &a, &x);
		if((current = FindNode(head, q)) == NULL)
		{
			current = InsertNode(head, q);
			if(a == 0)
			{
				sum += 10;
			}
			else if(a == 1 && x == 0)
			{
				sum += 20;
				current->state = ANSWERED;
				current->answered++;
			}
			else if(a == 1 && x == 1)
			{
				sum += 40;
				current->state = ANSWERED;
				current->answered++;
			}
		}
		else
		{
			switch(current->state)
			{
			case NOT_ANSWERED:
				if(a == 0)
				{
					sum += 10;
				}
				else if(a == 1 && x == 0)
				{
					sum += 20;
					current->state = ANSWERED;
					current->answered++;
				}
				else if(a == 1 && x == 1)
				{
					sum += 40;
					current->state = ANSWERED;
					current->answered++;
				}
				break;
			case ANSWERED:
				if(a == 0)
				{
					sum += 10;
				}
				else if(a == 1 && x == 0)
				{
					sum += 20;
					sum += current->answered * 10;
					current->answered++;
				}
				else if(a == 1 && x == 1)
				{
					sum += 40;
					sum += current->answered * 10;
					current->answered++;
				}
				break;
			}
		}
	}
	printf("%ld\n", sum);

	return 0;
}

