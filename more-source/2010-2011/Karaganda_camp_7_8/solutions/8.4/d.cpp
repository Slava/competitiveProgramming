#include <iostream>
#include <stdio.h>

using namespace std ;


int main( ) {
       
  int n , a [ 100 ] ;
  scanf ( "%d" , &n ) ;
  for ( int i = 0 ; i < n ; i++ )
    scanf ( "%d" , &a [ i ] ) ;
  sort ( a , a + n ) ;
  int d [ 100 ] ;
  d [ 0 ] = 0 ;
  d [ 1 ] = a [ 1 ] - a [ 0 ] ;
  d [ 2 ] = a [ 2 ] - a [ 0 ] ;
  for ( int i = 3 ; i < n ; i++ )
    d [ i ] = min ( d [ i - 1 ] , d [ i - 2 ] ) + a [ i ] - a [ i - 1 ] ;   
  printf ( "%d" , d [ n - 1 ] ) ;

        return 0 ;

}