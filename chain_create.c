/*
 * =====================================================================================
 *
 *       Filename:  chain_create.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/04/2015 11:58:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  windleaves (Litong), tonglovejin1@163.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

#define 	FALSE 		0
#define 	TRUE 		1

typedef		int 	ValueType;

typedef struct node {
	ValueType 	value ;
	struct 	node 	*next ;
} Node , *Node_p ;



void 	create_chain (Node_p * head , ValueType value) {

	Node_p 	temp_value ;

	if ( NULL == *head ) {
		if ( NULL == ( temp_value = (Node_p) malloc (sizeof (Node)) ) ) {
			printf ("malloc error, no free memory !\n") ;
			return ;	
		} else {
			temp_value -> value = value ;
			temp_value -> next = NULL ;
			*head = temp_value ;
		}
	} else {
		if ( NULL == ( temp_value = (Node_p) malloc (sizeof (Node))) ) {
			printf ("malloc error, no free memory !\n") ;
			return ;	
		} else {
			Node_p 	temp = *head ;
			temp_value -> value = value ;
			*head = temp_value ;
			(*head)->next = temp ;
		}
	}	
}

void 	show_chain (const Node_p head ) {
	Node_p 	temp = head ;
	if ( NULL == temp ) {
		printf ("Chain is empty !\n") ;
		return ;
	}
	for ( ; temp ; temp = temp ->next ) {
		printf ("value is %d ",temp ->value ) ;
	}
	putchar ('\n') ;
}

void 	destory_chain (Node_p * head ) {
	if (NULL == *head ) {
		printf ("Chain is empty !\n") ;
		return ;
	}
	Node_p 	front , next ;
	front =  *head ;
	next = front -> next ;

	for ( ; next ; next = next -> next  ) {
		front = next ;
		free (front) ;	
	}
	*head = NULL ;
}

int 	delete_key_node (Node_p *head , ValueType key ) {
	
	if ( NULL == *head || NULL == head) {
		printf ("Chain is empty !\n") ;
		return FALSE ;
	} 

	Node_p 	temp = (*head)  ;
	Node_p 	temp_next = (*head) ->next;
	int 	flag = 0 ;
	/// When the first node is the key node , just delete .
	if ( key == (*head)->value ) {
		temp = (*head) ->next ;
		free ((*head)) ;
		*head = temp ;

		return 	TRUE ;
	} else {
		while ( temp_next && key != temp_next ->value ) {

			temp = temp_next ;
			temp_next = temp ->next ;
		}
		flag = 1 ;
		Node_p 	tmp = temp_next->next ;
		free ( temp_next ) ;
		temp -> next = tmp ;
		return 	TRUE ;
	}
	return FALSE ;
}

/// 由于要逆向打印链表 , 如果不改变链表的结构 , 那么就可以用STL的栈来实现
/// 这里通过递归 , 使用系统栈
void 	show_chain_reverse (const Node_p head ) {
	if (NULL == head ) {
		return ;
	}	
	/// 递归的方式逆向打印
	show_chain_reverse ( head->next) ;
	printf ("value is %d ",head ->value ) ;
}
///  逆置可以用头插法搞
void 	reverse_chain (Node_p *head ) {
	Node_p 	front , next , temp , temp_next ;	

	if ( NULL == head || NULL == *head ) {
		printf ("Pass in NULL pointer\n") ;
		return ;
	}
	// 用front 先代替我的头节点	
	front = *head ;
	// 头插的过程
	next = front ->next ;
	front ->next = NULL ;
	while ( next ) {
		temp_next = next ->next ;
		temp = front ;
		front = next ;
		next ->next = temp ;
		next = temp_next ;
	}
	// 将头节点修改掉
	*head = front ;
}

int main(int argc, char *argv[])
{
	Node_p 	head = NULL ;

	for (int i = 0 ; i < 10 ; i ++ ) {
		create_chain (&head , i ) ;
	}

	show_chain (head) ;
	if ( TRUE == delete_key_node (&head , 0) ) {
		printf ("key found , already deleted .\n") ;
	} else {
		printf ("key not found \n") ;
	}
	reverse_chain (&head);
	show_chain (head) ;
	show_chain_reverse (head) ;
	putchar ('\n');
	destory_chain (&head) ;

	return EXIT_SUCCESS;
}

