var i,j,k,l,m,n:longint;
    a:array[1..6]of 1..10;
begin
assign(input,'cube.in'); reset(input);
assign(output,'cube.out'); rewrite(output);
    readln(n);
     for i:=1 to n do begin
         for j:=1 to 6 do read(a[j]);
          l:=0;
           if ((a[5]=a[4])or (a[4]=a[1])or (a[1]=a[5])) then l:=1;
           if ((a[3]=a[5])or (a[3]=a[1])) then l:=1;
           if ((a[5]=a[2])or (a[3]=a[2])) then l:=1;
           if ((a[6]=a[4])or (a[6]=a[3])) then l:=1;
           if ((a[6]=a[1])or (a[6]=a[2])) then l:=1;
           if (l=1) then writeln('YES') else writeln('NO');
     end;
    close(input); close(output);
end.