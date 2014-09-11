/*
 * =====================================================================================
 *
 *       Filename:  factorial_big.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/11/2014 08:15:33 PM
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
#include <string.h>

#define 	MAX_LENGTH 	3000 

int 	resault[MAX_LENGTH] ; 		//save result

int main(int argc, char *argv[])
{
	int i , j , r , s ; 		//r record the remaining of every bit , s record the result of every bit ;
	int input ;

	memset (resault , 0 , sizeof (resault)) ;
	resault[0] = 1 ; 		// init first bit as 1

	scanf ("%d" , &input);

	if ( input < 0 ) {
	 	printf ("Sorry , your input is nagative !\n") ;
		return  -1 ;
	} else if ( input == 0 ) {
	 	printf ("%d factorial is %d \n" , input , 1 ) ;
		return 	0 ;
	} else {
		for ( i = 1 ; i <= input ; ++i ) {
			r = 0 ; 	//init carry val = 0 (进位值初始化为0)
			for (j = 0 ; j < MAX_LENGTH ; ++j ) {
				s = resault[j] * i + r ;
				resault[j] = s % 10 ;
				r = s /10 ;
			} 
		}
	}

	for ( i = MAX_LENGTH - 1 ; i >= 0 ; i-- ) {
		if ( resault[i]) 
		      break ;
	}

	for ( ; i >= 0 ; i--) {
		printf ("%d",resault[i]) ;
	}

	putchar ('\n') ;
	return EXIT_SUCCESS;
}

