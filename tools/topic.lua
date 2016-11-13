package.path=package.path..";./luagy/?.lua"

attr=require "file/attrdir"
match=require "string/match"
local has=match.has

local list={}
attr("../src",function (filename,path)


	--print(path)
	--print(path:gsub(".+/(.+)%.c",print))

	if has(".+/(.+)%.c",path,function(s) out=s end) then
		--print(out)

		out:gsub("uoj(%d+)",function (n)
			table.insert(list,n)
		end )
	end

end
)

table.foreach(list,function (_,v)



end
)
