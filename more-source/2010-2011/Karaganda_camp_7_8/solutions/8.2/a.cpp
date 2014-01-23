#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std ;

int main( ) {
       
  char ch [ 100000 ] ; 
  cin >> ch ;
  char  st_2 [ 100000 ]  ; int x = 0 ;
  int l = strlen ( ch ) ;
  for ( int i = 0 ; i < l ; i++ ) {
    if ( ch [ i ] == '(' || ch [ i ] == '{' ||ch [ i ] == '[' ) st_2 [ x++ ] = ch [ i ] ;
    else {
      if ( x - 1 >= 0  && ch [ i ] == ')' && st_2 [ x - 1 ] == '(' ) x-- ; 
      else  if ( x - 1 >= 0  && ch [ i ] == ']' && st_2 [ x - 1 ] == '[' ) x-- ; 
      else if ( x - 1 >= 0  && ch [ i ] == '}' && st_2 [ x - 1 ] == '{' ) x-- ; 
      else {
             printf ( "no" ) ; exit ( 0 ) ;
           }
    }
     
  }
  if ( x != 0 ) {
             printf ( "no" ) ; exit ( 0 ) ;
  
  }
  printf ( "yes" ) ;
        return 0 ;

}