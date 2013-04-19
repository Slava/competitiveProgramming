set line [gets stdin]
set x 0
scan $line "%d" x
set r 1
while {$x>1} {
 set r [expr $r*$x]
 set x [expr $x-1]
}
puts $r



// lang: Tcl
// memory: 2300 KB
// author: imslavko
// submit_date: Feb 22, 2011 7:37:01 AM
// contest: 64
// link: /contest/64/submission/295941
// time: 50 ms
// verdict: Accepted
// problem: 64A - Factorial
// ID: 295941
// downloaded by very stupid script
