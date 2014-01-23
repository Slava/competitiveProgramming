#include <iostream>
#include <stdio.h>

using namespace std ;


int main( ) {
       
  int n , a [ 100 ] [ 100 ] ;
  scanf ( "%d" , &n ) ;
  for ( int i = 0 ; i <  n ; i++ )
    for ( int j = 0; j< n ; j++ )
      scanf ( "%d" , &a[ i ] [ j ] ) ;
  for ( int i = 0 ; i < n ; i++  )
    for ( int  j = 0 ; j < n ; j++ )
      if ( a [ i ] [ j ] != a [ j ] [ i ] ) {printf ( "NO" ); exit (0);}                 
  printf ( "YES" );
        return 0 ;

}
