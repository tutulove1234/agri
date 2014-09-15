#include <stdio.h>
#include <stdlib.h>


void	bubble_sort (char * arr , int size) ;
void	selection_sort (char * arr , int size) ;
void	insertion_sort (char * arr , int size ) ;
void	shell_sort (char *arr , int size ) ;
void	merge_arr (char * arr , int start , int mid , int last , char * temp) ;
void	merge_sort (char * arr , int start , int last , char * temp ) ;
//void	heap_sort (char * arr , int size ) ;
//void	bucket_sort (char * arr , int size) ;		    //桶排序    这个不好演示，givein
//void	radix_sort (char * arr , int size ) ;		    //基数排序
//void	binary_tree_sort (char  * arr , int size );
//void	topological_sort (char * arr , int size ) ;	    //拓扑排序
void	cocktai_sort (char * arr , int size ) ;		    //鸡尾酒排序
//void	tournament_sort (char * arr , int size  ) ;	    //锦标赛排序
//void	pigeonhole_sort (char * arr , int size ) ;	    //鸽巢排序
void	show_arr (char * arr , int size ) ;
void	make_new_arr (char * new_arr , const char * old_arr , int size ) ;

void	make_new_arr (char * new_arr , const char * old_arr , int size ) {

	int	i ;

	for (i = 0 ; i < size ; ++i ) {
	
		new_arr[i] = old_arr[i] ;
	}
}

void	show_arr (char * arr , int size ) {
    
	int    i ;
    
	printf ("\n") ;

	for ( i = 0 ; i < size ; i ++) {
    
		printf ("%c  " ,  arr[i]) ;
	}

	printf ("\n") ;
}

void	bubble_sort (char * arr , int size) {
	int i , j ;
	
	char * new ;

	new = (char *) malloc (sizeof (size)) ;
	make_new_arr (new , arr , size) ;

	for (i = 0 ; i < 1 ; ++i ) {			    //这里只做一次
		for ( j = i  ; j < size - 1 ; ++j ) {
		
			if ( new[j] > new[j+1]) {
			    
				int temp ;

				temp = new[j] ;
				new[j] = new[j+1] ;
				new[j+1] = temp ;
			}
		}
		
	}
	printf ("Bubble sort : ") ;
	show_arr ( new  , size) ;

	free (new) ;
}

void	selection_sort (char * arr , int size) {
    
    int i , j ;

    char * new ;

    new =(char *) malloc (sizeof (size)) ;
    
    make_new_arr (new , arr , size) ;

    for ( i = 0 ; i < 1 ; ++i ) {
    
	    for (j = i + 1 ; j < size ; ++j ) {
	    
		    if ( new[i] > new[j] ) {
		    
			    int temp ;

			    temp = new[i] ;
			    new[i] = new[j] ;
			    new[j] = temp ;
		    }
	    }
    }
    
    printf ("Selection sort : ") ;
    show_arr ( new , size ) ;

    free (new) ;
}

void	insertion_sort (char * arr , int size)  {

	int i , j , temp_i , num_temp ;
	char * new ;

	new = (char *) malloc (sizeof (size)) ;

	make_new_arr (new , arr , size ) ;


	for ( i = 1 ; i < 2 ; ++i ) {
		
		for (j = i-1 ; j >= 0 ; --j) {
		
			if (new[j] < new[i] )		    //插入位置
			    break ;
		}		
		temp_i = i ;				    
		num_temp = new[i] ;

		while ( temp_i > j+1 ) {		    //移动
		
			new[temp_i] = new[temp_i - 1] ;
			temp_i -- ;
		}
		new[j+1] = num_temp ;
	}
	
	printf ("Insertion sort : ") ;
	show_arr (new , size) ;

	free (new) ;
}

void	shell_sort (char * arr ,  int size ) {

	int	gap , i , j , temp ;

	char *new = (char *)malloc (sizeof (size)) ;

	make_new_arr (new , arr , size) ;

	for ( gap = size/2 ; gap > 0 ; gap /= 2) {
	
		for (i = gap ; i < size ; ++i ) {
		
			for (j = i-gap ; j >= 0 && new[j] > new[gap+j] ; --j ) {
			
				temp = new[j] ;
				new[j] = new[gap + j] ;
				new[gap + j] = temp ;
			}
		}
	
	}
	printf ("Shell sort :") ;
	show_arr (new , size) ;

	free (new) ;
}

//arr represent the old arr , temp represent the new arr to save the sorted num
void	merge_arr (char * arr , int start , int mid , int last , char * temp ) {

	int i = start , j = mid + 1 , k = 0 ;

	while ( i <= mid && j <= last ) {
	
		if (arr[i] < arr[j]) 
			temp[k++] = arr[i++] ;
		else
			temp[k++] = arr[j++] ;
	}
	while (i <= mid ) 
		temp[k++] = arr[i++] ;
	while (j <= last )
		temp[k++] = arr[j++] ;

	for (i = 0 ; i < k ; ++i ) {			    //copy to old arr  
		arr[start + i] = temp[i] ;    
	}
}

void	merge_sort (char * arr , int start , int last , char * temp ) {

	if ( last > start ) {
		int	mid = start  + ( last - start ) / 2 ;	
		merge_sort (arr , start , mid , temp ) ;
		merge_sort (arr , mid + 1 , last , temp ) ;
		merge_arr (arr , start , mid ,  last , temp ) ;
	}
}

void	cocktail_sort ( char * arr , int size) {
	
	int i , j , k ;
	int temp ;
	char * new =(char * )malloc (sizeof (size)) ;

	make_new_arr (new , arr , size) ;

	for ( i = 0 ; i < size/2 ; ++i ) {
	
		for (j = i ; j < size - 1; ++j ) {
		
			if ( new[j] > new[j+1] ) {
				temp = new[j] ;	
				new[j] = new[j+1] ;
				new[j+1] = temp ;
			}
		}

		for (k = size - i -1 ;  k > 0 ; --k ) {
		
			if ( new[k] < new[k-1] ) {
			
				temp = new[k] ;
				new[k] = new[k-1] ;
				new[k-1] = temp ;
			}
		}
	}

	printf ("cocktail_sort : ") ;
	show_arr (new , size) ;
    
	free (new) ;
}

int main () 
{
    char    arr[] = {'e','b','S','D','r','u','K','7'} ;
    char    temp[8] ;
    int	    size = sizeof (arr) / sizeof (*arr) ;

    bubble_sort (arr , size) ;
    
    selection_sort (arr , size) ;

    insertion_sort (arr , size) ; 

    cocktail_sort ( arr , size) ;

    shell_sort ( arr , size ) ;

    merge_sort (arr , 0 , size-1 , temp ) ;

    printf ("\nMerge sort : ") ;
    show_arr (arr , size ) ;


    return  0 ;
}
