#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next, *arbit;
};

node *newNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->next = temp->arbit = NULL;
	return temp;
}

void reverseList(node *&head)
{
   node *currPtr = head,*prevPtr = NULL,*nextPtr;
   while(currPtr)
   {
     nextPtr = currPtr->next;
     currPtr->next = prevPtr;
     prevPtr = currPtr;
     currPtr = nextPtr;
   }
   head = prevPtr;
}

struct node *populateArbitPointers(node *head)
{
	reverseList(head);
  node *maxNode = head,*temp = head->next;
  for(;temp;temp=temp->next)
  {
    temp->arbit = maxNode;
    if(maxNode->data < temp->data) maxNode = temp;
  }
	reverseList(head);
	return head;
}

void printNextArbitPointers(node *head)
{
	printf("current Node\tNext Node\tNext greatest  Node\n");
	for(; head ; head = head->next){
		printf("%d\t\t", head->data);
		if(head->next)
			printf("%d\t\t", head->next->data);
		else
			printf("NULL\t\t");
		if(head->arbit)
			printf("%d", head->arbit->data);
		else
			printf("NULL");
		printf("\n");
	}
}

int main()
{
	node *head = newNode(5);
	head->next = newNode(15);
	head->next->next = newNode(2);
	head->next->next->next = newNode(3);
	head = populateArbitPointers(head);
	printNextArbitPointers(head);
	return 0;
}
