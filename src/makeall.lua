require 'lfs'

sep="/"
function attrdir (path)
	for file in lfs.dir(path) do
		if file ~= "." and file ~= ".." then
			local f = path..sep..file
			print ("\t=> "..f.." <=")
			local attr = lfs.attributes (f)
			assert (type(attr) == "table")
			if attr.mode == "directory" then
				attrdir (f)
			else
				os.execute(" g++ "..file.." -o "..file:sub(1,-3))
			end
		end
	end
end

attrdir(".")
