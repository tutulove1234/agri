#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 虽然题比较简单 ， 但是越简单的题 ， 就越多要考虑到的东西 。 
// 1. 空指针问题 （考虑到了）
// 2. 输入数据的合法性问题

int 	str_to_int (const char * str ) {
	int 	flag = 0 ;
	int 	ret = 0 ;

	if ( NULL == str ) {
		printf ("Pass in a NULL pointer!\n") ;
		exit (1) ;
	}
	
	if (str[0] == '-') {
		flag = 1 ;
		str ++ ;
	} else if (str[0] == '+') {
		str++ ;
	}

	for ( ; *str ; str++ ) {
		if ( isdigit (*str) ) {
			ret = ret * 10 + (*str - '0') ;	
		} else {
			printf ("Input error !\n") ;
			exit (1) ;
		}
	}

	if (flag == 1) {
		return -ret ; 
	}
	return ret ;
}

int main () {
	
	char 	str[10] ;

	fgets (str , sizeof (str) , stdin ) ;
	str[strlen(str) -1] = 0 ;
	str_to_int (str) ;

	printf ("input convert to int is %d .\n" , str_to_int (str) ) ;

	return 0;
}

