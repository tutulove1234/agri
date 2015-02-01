#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <strings.h>

int 	search_array[][5] ={{1 , 2 , 3 , 4 , 5 },\
							{6 , 7 , 8 , 9 , 10},\
							{11, 12, 13, 14, 15},\
							{16, 17, 18, 19, 20},\
							{21, 22, 23, 24, 25}\
							};

void print () {
	for ( int i = 0 ; i < 5 ; ++i ) {
		for ( int j = 0 ; j < 5 ; ++j ) {
			printf ("%5d ",search_array[i][j]);
		}
		putchar ('\n') ;
	}
}

int main () {

	int 	input = 0 ;
	int 	i = 0 ;
	int 	j = 4 ;

	print () ;
	printf ("Please input a key which you want to search : ") ;
	scanf ("%d",&input);

	for (  ; j >= 0 && i < 5 ;  ) {
			if (input < search_array[i][j]) {
				j -- ;
				continue ;
			}else if ( input == search_array[i][j]) {
				printf ("%d's position is %d,%d\n",input , i+1,j+1);
				exit (0);
			}else {
				i ++ ;
			}
	}
	printf ("The number %d is not in this matrix.\n",input) ;

	return 0 ; 
}

