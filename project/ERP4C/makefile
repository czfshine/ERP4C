all:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	gcc -Wall -DLOCAL -O3 -ansi goods.c main.c -o erp4c.exe
	erp4c.exe

goods:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	gcc -Wall -DLOCAL -O3 -ansi goods.c testgoods.c -o testgoods.exe
	testgoods.exe