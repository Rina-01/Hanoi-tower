program Pereloji;

type res=array[0..2, 1..10] of integer;

var n, i, j:integer; m:res;

procedure display(m:res);
var k:integer;
begin
  writeln;
  for i:=10 downto 1 do
    begin
      for j:=0 to 2 do
        begin
          for k:=0 to 10-m[j,i] do write(' ');
          for k:=0 to m[j,i]-1 do write('*');
          write('|');
          for k:=0 to m[j,i]-1 do write('*');
          for k:=0 to 13-m[j,i] do write(' ')
        end;
      writeln
    end;
  write('00000000000000000000000   00000000000000000000000   00000000000000000000000');
  writeln; writeln; writeln; writeln
end;

procedure perelom(a,b:integer; var m:res);
begin
  for i:=1 to 10 do
    if m[a,i]=0 then break;
  if i>10 then writeln('error!');
  i:=i-1;
  if i<0 then writeln('error!!');
  for j:=1 to 10 do
    if m[b,j]=0 then break;
  if j>10 then writeln('error!!!');
  m[b,j]:=m[a,i];
  m[a,i]:=0;
  display(m);
  writeln('from ',a,' to ',b)
end;

procedure perenos(n,a,b:integer; var m:res);
begin
  if n=1 then perelom(a,b,m)
  else
    begin
      perenos(n-1,a,3-(a+b),m);
      perelom(a,b,m);
      perenos(n-1,3-(a+b),b,m)
    end
end;

begin
  writeln('I want number of rings.');
  readln(n); writeln;
  for i:=1 to n do begin m[0,i]:=i; m[1,i]:=0; m[2,i]:=0 end;
  for i:=1 to n do m[0,i]:=n+1-i;
  writeln('Initial:');
  display(m);
  perenos(n,0,2,m);
  readln
end.
