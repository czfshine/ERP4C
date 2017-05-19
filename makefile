PREFLE =  tui.c linklist.c goods.c serialize.c 
CC= gcc -Wall -DLOCAL -O3 -ansi
all:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	$(CC) $(PREFLE) main.c -o erp4c.exe
	erp4c.exe
release:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	gcc -Wall  -O3 -ansi $(PREFLE) main.c -o erp4c.exe
	erp4c.exe

dontclear:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	$(CC) -DDONTCLEARSCREEN -Wno-incompatible-pointer-types  $(PREFLE) main.c -o erp4c.exe
	erp4c.exe

min:
	gcc -DLOCAL -DDONTCLEARSCREEN  -O0 -ansi $(PREFLE) main.c -o erp4c.exe
	erp4c.exe
goods:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	$(CC) $(PREFLE) testgoods.c -o testgoods.exe
	testgoods.exe
linklist:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	$(CC) $(PREFLE)  testlinklist.c -o testlinklist.exe
	testlinklist.exe
serialize:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	$(CC) $(PREFLE)  testserialize.c -o testserialize.exe
	testserialize.exe