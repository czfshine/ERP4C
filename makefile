all:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	gcc -Wall -DLOCAL -O3 -ansi main.c -o erp4c.exe
	erp4c.exe