outfile=io.open("testin1.txt","w")

outfile:write("1\n");

for i=1,10 do
	outfile:write(tostring(i).."\n");
	outfile:write("name"..tostring(i).."\n");
	outfile:write(tostring(i).."\n");
	outfile:write("\n");
end