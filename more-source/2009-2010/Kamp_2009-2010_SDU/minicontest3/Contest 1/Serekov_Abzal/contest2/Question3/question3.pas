type point=record
x,y:longint;
end;
var a:array[1..100000]of point;
i,j,k,l,m,n:longint;
begin
assign(input,'a.in'); reset(input);
assign(output,'a.out'); rewrite(output);
    readln(n);
     for i:=1 to n do readln(a[i].x, a[i].y);
      for i:=1 to n do begin l:=999999999;
       for j:=1 to n do
       if ((i<>j)and(l>abs(a[j].x-a[i].x)+abs(a[j].y-a[i].y))) then begin
       k:=j; l:=abs(a[j].x-a[i].x)+abs(a[j].y-a[i].y);end;
        write(k,' ');
      end;
     close(input); close(output);
end.
