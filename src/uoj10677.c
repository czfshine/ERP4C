#include "stdio.h"
#include "string.h"
void Encrypt(char msg[])
{
	char key[] = "sleepiforest";
	int msgLen = strlen(msg);
	int keyLen = strlen(key);
	int offset;
	for(offset=0;offset<msgLen;++offset)
	{
		msg[offset] ^= key[offset%keyLen]; // ^是异或运算
	}
	for(offset=0;offset<msgLen;++offset)
	{
		printf("%02x ",msg[offset]); //%x是十六进制
	}
}

void Decrypt(char *msg){

	char bin[] = "53 30 39 59 0e 48 18 4f 34 0a 01 13 16 18 48 28 15 44 28 00 06 45 0d 55 0d 52 4a 4a 50";
	int len = (strlen(bin)+1)/3,d;
	char key[] = "sleepiforest";
	int keyLen = strlen(key);
	for(int i=0;i<len;++i)
	{	sscanf(bin+i*3,"%x",&d);
        printf("%x\n", d);
		msg[i] = d^key[i%keyLen];
	}
	msg[len]='\0';

}
int main(int argc, char const *argv[])
{
	//char msg[50];
	//Decrypt(msg);
	puts(" \\\\<~!~ Forget-Me-Not ~!~>// ");//wtf??
	return 0;
}