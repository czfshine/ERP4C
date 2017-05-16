all:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	gcc -Wall -DLOCAL -O3 -ansi tui.c linklist.c goods.c main.c -o erp4c.exe
	erp4c.exe
release:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	gcc -Wall  -O3 -ansi tui.c linklist.c goods.c main.c -o erp4c.exe
	erp4c.exe

dontclear:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	gcc -Wall -DLOCAL -DDONTCLEARSCREEN -Wno-incompatible-pointer-types -O3 -ansi tui.c linklist.c goods.c main.c -o erp4c.exe
	erp4c.exe

min:
	gcc -DLOCAL -DDONTCLEARSCREEN  -O0 -ansi tui.c linklist.c goods.c main.c -o erp4c.exe
	erp4c.exe
goods:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	gcc -Wall -DLOCAL -O3 -ansi linklist.c goods.c testgoods.c -o testgoods.exe
	testgoods.exe
linklist:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	gcc -Wall -DLOCAL -O3 -ansi linklist.c testlinklist.c -o testlinklist.exe
	testlinklist.exe
serialize:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	gcc -Wall -DLOCAL -O3 -ansi linklist.c  goods.c serialize.c testserialize.c -o testserialize.exe
	testserialize.exe