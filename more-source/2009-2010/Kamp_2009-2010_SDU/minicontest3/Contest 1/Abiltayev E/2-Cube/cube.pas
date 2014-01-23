var n,i,f,b,r,l,u,d: byte;
begin
assign(input,'cube.in');reset(input);
assign(output,'cube.out');rewrite(output);
readln(n);
for i:=1 to n do
begin
        readln(f,b,l,r,u,d);
        if (f=l)or(f=r)or(b=l)or(b=r) then writeln('YES')
        else if (f=u)or(f=d)or(b=u)or(b=d) then writeln('YES')
        else if (l=u)or(l=d)or(r=u)or(r=d) then writeln('YES')
        else writeln('NO');
end;

close(input);close(output); end.
