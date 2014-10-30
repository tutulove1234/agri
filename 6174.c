/*
 * =====================================================================================
 *
 *       Filename:  6174.c
 *
 *    Description:  解决问题6174
 *
 *        Version:  1.0
 *        Created:  10/30/2014 10:27:14 PM
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

int  cmp (const void * dec , const void * scr) {
	int *num1 , *num2 ;

	num1 = (int*)dec ;
	num2 = (int*)scr ;

	return *num1 - *num2 ;
}

void reserv (int * num , int size ) {
	int i , temp ;

	for ( i = 0 ; i < size/2 ; ++i) {
		temp = num[i] ;
		num[i] = num[size-i-1] ;
		num[size-i-1] = temp ;
	}
}

int make_int (int *num , int size ) {
	int i ;
	int ret = 0 ;

	for ( i = 0 ; i < size ; ++i ) {
		ret = ret*10 + num[i] ;
	}

	return ret ;
}

void reput (int * num , int size , int a) {
	int i ; 

	for ( i = 0 ; i < size ; ++i ) {
		num[i] = a % 10 ;
		a /= 10 ;
	}
}

int main(int argc, char *argv[])
{
	int 	num[4] = {1,2,3,4} ;
	int 	temp = 1234 , min , max ;

	printf ("%d  " , temp ) ;
	for ( ; ; ) {

		if ( temp != 6174 ) {
			printf (" -> ") ;
			qsort(num , 4 , sizeof (int) , cmp );
			min = make_int (num, 4);
			reserv (num , 4) ;
			max = make_int (num , 4) ;
			reput (num , 4 , max-min) ;
			temp = max - min ;
			printf (" %d  " , temp ) ;
		} else {
			break ;
		}
	}
	
	putchar ('\n') ;

	return EXIT_SUCCESS;
}

