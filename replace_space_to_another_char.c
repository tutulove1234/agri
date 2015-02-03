// =====================================================================================
// 
//       Filename:  replace_space_to_another_char.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  02/03/2015 10:37:02 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  windleaves (Litong), tonglovejin1@163.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define 	MAX_LINE 	1024

const char array[] = "We are happy ." ;

void 	take_replace (char *str , char * pattern) {

	int 	str_len = 0 ;
	int 	space_count = 0 ;
	int 	pattern_len = strlen(pattern) ;
	char 	*tail , *new_tail ;

	if (NULL == str || NULL == pattern ) {
		printf ("Pass in a null pointer !\n") ;
		exit (1) ;
	}
	
	// 得到字符串的长度 , 并且计算出所有的空格数
	while (str[str_len]) {
		if ( ' ' == str[str_len] ) {
			space_count ++ ;	
		}
		str_len ++ ;
	}

	tail = str + str_len ;
	// 获得新的指针的位置 , -1 是 因为我们已经有一个空格的空间的了 , 所以不需要那一个空间
	new_tail = tail + (strlen(pattern) - 1) * space_count  ; 
	// 保证其不会出错
	while ( tail >= str && new_tail >= str && tail != new_tail ) {
		if (isspace (*tail)) {
			printf ("meet a space\n") ;	
			tail -- ;
			*new_tail-- = pattern[pattern_len - 1] ;
			*new_tail-- = pattern[pattern_len - 2] ;
			*new_tail-- = pattern[pattern_len - 3] ;
		} else {
			*new_tail = *tail ;
			new_tail -- , tail -- ;
		}	
	} 

	puts (str) ;
}

int main(int argc, char *argv[])
{
	char 	str[MAX_LINE] = {0} ;	
	int 	len = strlen(array) + 1 ;

	strncpy (str , array , len ) ;

	take_replace (str , "%20") ;

	return 0;
}

