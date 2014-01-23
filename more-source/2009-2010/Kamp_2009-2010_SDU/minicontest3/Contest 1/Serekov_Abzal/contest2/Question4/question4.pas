uses crt;
type point=record x,y:extended; end;
var i,j,k,l,m,n:longint;
    s:extended;
    a:array[1..100000]of point;
    f:text;
begin
assign(input,'f.in');reset(input);
assign(output,'f.out');rewrite(output);
    readln(n);   l:=0;
    for i:=1 to n do begin readln(a[i].x, a[i].y); if frac(a[i].x)<>0 then inc(l);if frac(a[i].y)<>0 then inc(l);
    end;s:=0;
    for i:=2 to n-1 do begin
       s:=s+abs(0.5*((a[i-1].x*a[i].y+a[i].x*a[i+1].y+a[i+1].x*a[i-1].y)-(a[i-1].y*a[i].x+a[i].y*a[i+1].x+a[i+1].y*a[i-1].x)));
    end;
    s:=s-l;
 writeln(s:0:0);
 close(input);
 close(output);
end.
