#include <iostream>
#include <stdio.h>
 
int main( ) {
       
        int n , m ;
        scanf ( "%d%d" , &n , &m ) ;
        int l = 0 , r = 0 ;
        for ( int i = 0 ; i < m ; i++ ) {
           int x ; 
           scanf ( "%d" , &x ) ;
           if ( l == 0 ) l = r = x ;
          else {
            if ( x - 1 == r ) r = x ;
            else {
              if( r == l ) { printf ( "%d," , l ) ; l = r = x ; }
              else { printf ( "%d-%d," , l , r ) ; l = r = x ; }
            } 
          }
            
        }
        if ( r == l ) printf ( "%d" , l ) ;
        else printf ( "%d-%d" , l , r ) ;
        return 0 ;

}
 
