var sum:longint; i,j,n:integer; a:array[0..1001] of record x,y: integer; end;

procedure calc(i,j: integer); var k:integer;
begin
        for k:=1 to n do
        if (i<>k)and(j<>k) then
        begin
        if (a[k].x-a[i].x)*(a[j].y-a[i].y)=(a[k].y-a[i].y)*(a[j].x-a[i].x)
        then inc(sum);
        end;
end;

begin
assign(input,'lines.in');reset(input);
assign(output,'lines.out');rewrite(output);
readln(n);
for i:=1 to n do
begin readln(a[i].x,a[i].y); end;

sum:=0;
for i:=2 to n do
for j:=1 to i-1 do
begin
        calc(i,j);
end;

write(sum); close(input); close(output); end.
