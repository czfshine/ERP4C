package.path=package.path..";./luagy/?.lua"

attr=require "file/attrdir"
match=require "string/match"
local has=match.has

net=require "network/connector"

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
require("socket")
function sleep(n)
   socket.select(nil, nil, n)
end


table.foreach(list,function (_,v)
	infile=io.open("../data/uoj"..v..".html","w")
	r,c,cookie=net.http.get("http://172.26.14.60:8000/uoj/common_problem_view_PUBLIC.html?identity=f139b91c0058db9039f8090cf6d56e4a&problemId="..v,
		{cookie="JSESSIONID=99ECD3D3646A3F74EFD3637EFCC7689B; cotree=1; cstree=14; OUTFOX_SEARCH_USER_ID_NCOO=1992381091.4441192"} )
	infile:write(r)
	print(v)
	infile:close()
	print(c)
	sleep(15)
end
)
