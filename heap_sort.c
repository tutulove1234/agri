#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	int data ;
	int l_child ;
	int r_child ;
}Node , * Node_p ;

void show_arr (Node_p arr , int size) ;

void swap (void * dest , void *source , int size ) {
	void * p ;
	
	p = malloc (size) ;
	memcpy (p , dest , size ) ;
	memcpy (dest , source , size) ;
	memcpy (source , p , size ) ;
	
	free (p) ;
}

void insert_max_heap (Node_p head , int * arr , int size ) {
	int i , temp , n ;
	///i point to the next position , temp will save i , n will point to arr 
	n= 0 ;
	i = 1 ;
	head[i++].data = arr[n++] ; 
	for ( ; n < size ; ++n ) {
		temp = i ;
		for (; i != 1 && arr[n] > head[i/2].data ; i/=2) {
			swap (&head[i].data,&head[i/2].data,sizeof(Node)) ;
		}
		head[i].data = arr[n] ;
		i = temp + 1 ;
	}
}

void delete_max_heap (Node_p head , int size ) {
	int child , parent , length , n ; 
	Node temp ;
	
	length = size  ; 				// 数组的长度 ~ 
	parent = 1 ;
	child = parent * 2 ;
	
	for ( ; length >= 1 ; length-- ) {
		parent = 1 ;
		child = parent * 2 ;
		n = length - 1 ;
		swap (&head[1] , &head[length] , sizeof (int)) ;
		
		temp = head[1] ;	
		while (child <= n ) {
			if ((child < n) && head[child].data <= head[child+1].data )
					child ++ ;
			if (temp.data >= head[child].data) break ;
			swap (&head[parent].data , &head[child].data ,  sizeof (int)) ;
			parent = child ;
			child *= 2 ;
		}
			head[parent] = temp ;
		show_arr (head , size) ;	
	} 
	
} 

void show_arr (Node_p arr , int size ) {
	int i ;

	for (i = 1 ; i < size+1 ; ++i ) {
		printf ("%d  " , arr[i]) ;
	}
	
	putchar ('\n') ;
}

int main () 
{
	int arr[] = {3,4,1,2,3,0,10,9,123,30,23,1,90} ;
	Node head[128] ;
	
	insert_max_heap (head , arr , sizeof (arr)/sizeof (*arr)) ;	
	show_arr (head , sizeof (arr)/sizeof (*arr)) ;
	delete_max_heap (head , sizeof(arr)/sizeof (*arr)) ; 
		
	return 0 ; 
	
}
 
 
