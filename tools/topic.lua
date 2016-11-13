package.path=package.path..";./luagy/?.lua"

attr=require "file/attrdir"
match=require "string/match"
local has=match.has

attr("../src",function (filename,path)


	print(path)
	--print(path:gsub(".+/(.+)%.c",print))

	if has(".+/(.+)%.c",path,function(s) out=s end) then
		print(out)
	else
		--print("This world is mad !")
	end

end
)
