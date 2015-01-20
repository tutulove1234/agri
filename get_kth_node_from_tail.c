#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int value ;
	struct node * next ;
} Node , * Node_p ;

void create_list (Node_p head  , char data[]) {
	
	Node_p 	temp , q  ;

	if (NULL == data ) {
		printf ("Pass in ivalid argu\n") ;
		exit (1) ;
	}
	
	while ( *data ) {
		temp = (Node_p)malloc (sizeof (Node)) ;
		temp ->next = NULL ;
		temp->value = *data ;
		if (head ->next == NULL ) {
			head->next = temp;
		} else {
			q->next = temp;	
		}
		q = temp ; 
		data++ ;
	}
}
void show_list (Node_p head) {
	if (NULL == head ) {
		printf ("Empty list\n") ;
		return ;
	}
	
	for (head = head->next  ; head ; head = head->next  ) {
		printf ("value is %c\n", head->value)  ;
	}
}

void destory_list ( Node_p head ) {
	Node_p 	front , after ;
	
	if (NULL == head ) {
		printf ("Pass in iviald argu\n") ;
		return ;
	}

	front = head ->next ;
	after = front->next ;
	
	for ( ; after ; after = after ->next ) {
		printf ("free node value is %c\n" , front->value) ;
		free (front) ;
		front = after ;
	}
	printf ("free node value is %c\n" , front->value) ;
	free (front) ;
}

void 	del_kth_node( Node_p head , int k ) {
	if (NULL == head ) {
		printf ("pass in ivaild argu!\n") ;
		return ;
	}
	if ( k <= 0 ) {
		printf ("Your input is illeagel\n") ;
		return ;
	}
	
	Node_p front = head ->next , rear = head->next ;

	for ( int i = 0 ; (i <= k) && front ; ++i , front = front ->next ) {}

	while ( front ) {
		rear = rear ->next ;
		front = front -> next ;
	}
	// There you need to deal that the value of k greater than max length of this list . 	
	Node_p 	temp = rear->next ->next ;

	free (rear->next) ;
	rear->next = temp ; 
}

int main (void) {
	char 	data[20] ;
	Node 	head = {0,NULL}  ;

	fgets(data , sizeof (data) , stdin) ;
	data[strlen(data)-1] = 0  ;

	create_list (&head , data) ;
	show_list (&head);

	int 	k ;

	scanf ("%d",&k) ;
	del_kth_node (&head , k);
	show_list (&head) ;
	destory_list (&head) ;

	return 0 ;
}

