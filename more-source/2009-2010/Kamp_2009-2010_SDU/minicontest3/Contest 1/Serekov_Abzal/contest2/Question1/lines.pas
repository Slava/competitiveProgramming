type point=record
x,y:longint;
end;
var i,j,k,l,n,u:longint;
    m,c:extended;
    a:array[1..1000]of point;
begin
assign(input,'lines.in'); reset(input);
assign(output,'lines.out'); rewrite(output);
    readln(n);
    l:=0;
     for i:=1 to n do readln(a[i].x, a[i].y);
    for i:=1 to n-1 do
     for j:=i+1 to n do begin                u:=0;
     if (a[i].x=a[j].x) then begin m:=0;u:=1; end else
         m:=(a[i].y-a[j].y)/(a[i].x-a[j].x);
         if u=0 then
         c:=a[i].y-(m*a[i].x) else c:=a[i].x;
         for k:=1 to n do
          if ((k<>i)and(k<>j)) then begin
          if ((u=0)and(a[k].y=(m*a[k].x)+c)) then inc(l);
          if ((u=1)and(a[k].x=c)) then inc(l); end;
     end;
     writeln(l);
     close(input); close(output);
end.