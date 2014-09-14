/*
 * =====================================================================================
 *
 *       Filename:  binary_search_tree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/14/2014 01:49:21 PM
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

#define 	LEFT 	1 
#define 	RIGHT 	2 

typedef int  elemtype ;

typedef struct node {
	elemtype data ;

	struct node * lchild ;
	struct node * rchild ;
} Node ,* Node_p ;

void show_tree ( Node_p head ) {
	
	if ( head == NULL ) {
		return ;
	}

	printf ("%d  " , head ->data ) ;
	show_tree ( head ->lchild) ;
	show_tree ( head ->rchild) ;
}

int main(int argc, char *argv[])
{
	int 	input[10] ;
	int 	i , flag ;
	Node_p 	p , front , head ;

	for ( i = 0 ; i < 10 ; ++i ) {
		scanf ("%d" , &input[i]) ;
	}

	p = (Node_p)malloc (sizeof (Node)) ; 
	p ->data = input[0] ;
	p->lchild = NULL ;
	p->rchild = NULL ;

	head = p ;

	for ( i = 1 ; i < 10   ; ++i ) {
		for ( p = head  ;  ; ) {
			front = p ; 			//save father node 

			if ( input[i] > p->data ) {
				p = p ->rchild ;
				if ( p == NULL ) {
					flag = RIGHT ;
					break ;
				}
			} else {
				p = p ->lchild ;
				if ( p == NULL ) {
					flag = LEFT ;
					break ;
				}
			}
		} 
		if ( flag == LEFT ) {
			front->lchild = (Node_p)malloc (sizeof (Node)) ;
			front->lchild->data = input[i] ;
			front->lchild->lchild = NULL ;
			front->lchild->rchild = NULL ;
		} else {
			front->rchild = (Node_p)malloc (sizeof (Node)) ;
			front->rchild->data = input[i] ;
			front->rchild->lchild = NULL ;
			front->rchild->rchild = NULL ;
		}
	}
	show_tree (head) ;

	return EXIT_SUCCESS;
}

