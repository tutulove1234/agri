#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define 	MAX_QUEUE_NUM 		1024
#define 	TRUE				1
#define 	FALSE 				0

typedef 	int 	value_type ;

/// ABS tree
typedef 	struct 	binary_tree_node {

	value_type 	value ;
	struct 		binary_tree_node 	* left  ;
	struct 		binary_tree_node 	* right ;

}	Tree_Node ,	*Tree_Node_p ;
/// ABS queue 
typedef struct 	queue_node {

	Tree_Node_p 			node_addr ;
	struct queue_node 		*next ;

}Queue_Node , *Queue_Node_p;
/// ABS oper queue 
typedef struct 	{

	Queue_Node_p 	 head ;
	Queue_Node_p 	 end ;
	int 			queue_count ;

} Queue_oper , *Queue_oper_p ;

void 	init_queue (Queue_oper_p 	q) {

	if (NULL == q ) {
		printf ("line %d , Pass in a NULL pointer !\n" , __LINE__) ;
		return ;
	}

	q->head = q->end = NULL ;	
	q->queue_count = 0 ;
}

int 	enter_queue (Queue_oper_p  q , Tree_Node_p 	tp ) {
	if (NULL == q ) {
		printf ("line %d , Pass in a NULL pointer !\n" , __LINE__) ;
		return FALSE ;
	}
	
	Queue_Node_p  	temp ;

	if ( NULL == (temp = (Queue_Node_p) malloc (sizeof (Queue_Node) )) ){
		printf ("line %d , malloc memory failed !\n" , __LINE__ ) ;	
		return FALSE ;
	}
	/// If queue is empty 
	temp ->node_addr = tp ;
	temp ->next = NULL ;
	if ( 0 ==  q->queue_count ) {
		q->head = q->end = temp ;	
		(q->queue_count) ++ ;
	}
	/// If queue is not empty , enter queue should add new node to the end of the queue . 
	else {
		q ->end ->next = temp ;
		q-> end = temp ;
		(q->queue_count) ++ ;
	}
	return 	TRUE ;
}
/// 出队列
int 	out_queue (Queue_oper_p 	q , Tree_Node_p *tp ) {
	if (NULL == q ) {
		printf ("line %d , Pass in a NULL pointer !\n" , __LINE__) ;
		return FALSE ;
	}
	Queue_Node_p 	temp ;
	if (0 == q->queue_count ) {
		printf ("Queue is empty !Can not out_queue .\n") ;
		return FALSE ;
	} else {
		*tp = q -> head ->node_addr ;
		temp = q ->head ;		
		q ->head = q->head ->next ;
		free (temp ) ;
		(q->queue_count) -- ;
	}

	return TRUE ;
}

void 	create_tree (Tree_Node_p * root ) {
	int 	input ;
	
	scanf ("%d", &input) ;
	
	if ( -1 == input ) {
		*root = NULL ;
		return ;
	}
	
	Tree_Node_p 	temp ;

	if ( NULL == ( temp = (Tree_Node_p)malloc (sizeof (Tree_Node)))) {
		printf ("line %d , malloc memory failed !\n" , __LINE__);
		return ;
	}

	temp ->value = input  ;
	*root = temp ;
	
	create_tree ( &(temp ->left)) ;
	create_tree (&(temp->right)) ;
}

void 	display_tree (const Tree_Node_p root )  {
	if ( NULL == root ) {
		return ;
	}

	printf ("%d  ",root->value ) ;
	display_tree (root->left ) ;
	display_tree (root->right ) ;
}
/// 
/// 借助队列进行广度优先遍历
void 	display_broad_first (const Tree_Node_p root) {
	Queue_oper 	q ;
	
	init_queue (&q) ;
	if (NULL == root ) {
		printf ("line %d , pass in a null pointer \n)" , __LINE__ ) ;
		return;
	}
	enter_queue (&q , root) ;
	Tree_Node_p  	temp = NULL ;
	while (0 < q.queue_count ) {
		out_queue (&q , &temp ) ;
		if (NULL != temp ) {
			printf ("%d  " , temp ->value ) ;
		}
		if (NULL != temp ->left ) {
			enter_queue (&q , temp->left) ;
		}
		if ( NULL != temp ->right ) {
			enter_queue (&q,temp->right ) ;
		}
	}
}

void 	destory_tree (Tree_Node_p 	root ) {
	if (NULL == root ) {
		return ;
	}
	destory_tree (root ->left ) ;
	destory_tree (root ->right ) ;
	printf ("%d freed\n" , root ->value) ;
	free (root) ;
}

int main () {

	Tree_Node_p 	root  = NULL ;

	create_tree (&root) ;
	display_tree (root) ;
	putchar ('\n') ;
	display_broad_first (root ) ;
	putchar ('\n');
	destory_tree (root) ;

	return 0 ;
}

