#include <iostream>
#include <stdio.h>                              
using namespace std ;


int main( ) {
       
  string s ;
  getline ( cin , s ) ;
  int n = s .length () ;
  for ( int i = 0 , j = n - 1 ; i <= j ; i++ , j-- ) {
    while ( s [ i ] == ' ' ) i++ ;
    while ( s [ j ] == ' ' ) j-- ;
    if ( s [ i ] != s [ j ] ) {
      printf ( "NO" ) ;
      exit ( 0 ) ;
    } 
  }          
  printf ( "YES" ) ;
        return 0 ;

}