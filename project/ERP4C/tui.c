/*
Text User Interface (TUI)
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
The user interface in console.
�ı��û����棨Text User Interface����
������Ļ�����ѣ����룬����Ⱥ�����
*/
#include "tui.h"

/*�汾С��*/
int buildnum[] = {
	#include "BUILDNUM"
};

/*�汾��*/
char version[] = "dev 1.0.1";

/*****************����**********************/
int WantNum() {
	/*��������*/
	/*note: The input num must be > 0*/
	/*��������ֱ���Ϊ��Ȼ�������صĴ�����Ϊ��*/
	int res = 0;
	char ch,flag = 0;
	while ((ch = getchar()) != '\n') {
		if (isdigit(ch)) {
			res = res * 10 + ch - '0';
			if (res < 0) {
				/*���*/
				InputClean();
				return WANTLONGERROR;
			}
			flag = 1;
		}
		else {
			/*��֧�ֵ��ַ�����[^0-9]*/
			InputClean();
			return WANTTYPEERROR;
		}
	}
	if (flag)  return res;
	else  return WANTNULLERROR;/*δ����*/
}

char * WantString() {
	/*�����ַ���*/
	/*�þ�̬���ͷ�ֹ�ڴ�й©*/
	/*TODO*/
	static char * a = NULL;
	if (a == NULL)
		a = (char *)malloc(255);


	char ch;
	int i = 0;
	while ((ch = getchar()) != '\n') {
		a[i++] = ch;
	}
	a[i] = 0;
	return a;

}

char * WantName() {
	/*������Ʒ��*/
	printf("Please input the good's name:");
	return WantString();

}

int WantId() {
	printf("Please input the good's id:");

	/*Ĭ��Ϊ����˵��δ��ȷ����*/
	int id = -1;

	while (id < 0) {

		id = WantNum();

		switch (id) {
		case WANTTYPEERROR:
		case WANTNULLERROR:
			printf("ERROR:Please input a positive integer\n");
			printf("Please input the good's id:");
			break;

		case WANTLONGERROR:
			printf("ERROR:Input id too long ,please input a small number!\n");
			printf("Please input the good's id:");
			break;
		}

	}
	/*ֱ��idΪ���ŷ���*/

	return id;
}

int WantCount() {

	printf("Please input the good's count:");

	int count = -1;

	while (count < 0) {
		count = WantNum();
		switch (count) {
		case WANTTYPEERROR:
		case WANTNULLERROR:
			printf("ERROR:Please input a positive integer\n");
			printf("Please input the good's count:");
			break;
		case WANTLONGERROR:
			printf("ERROR:Input number too long ,please input a small number!\n");
			printf("Please input the good's count:");
			break;
		}

	}

	return count;

}

void WantEnter() {
	/*��ͣ���̣��ȴ��û�����*/
	puts("Push Enter to contuine.");
	InputClean();
}

/********���ͼ��******************/
char * TYPENAME[] = {
	"number",
	"string"
};
void TypeError(INPUTTYPE T) {
	printf("ERROR: Expect a %s but got another\n", TYPENAME[T]);
}
void TypeNullError(INPUTTYPE T) {
	printf("ERROR: you must input a %s\n", TYPENAME[T]);
}
void TypeLongError(INPUTTYPE T) {
	printf("ERROR: input %s is too long,try input a small %s\n", TYPENAME[T], TYPENAME[T]);
}
#define mainstr {\
"Please choose a option:\n"\
"1)\tloggin goods\n"\
"2)\tchange goods\n"\
"3)\tremove goods\n"\
"4)\tloggin stock&sale info\n"\
"5)\tquery goods\n"\
"6)\tstatis goods\n"\
"7)\thelp\n"\
"0)\texit\n"\
"Input your choice:"\
}\

Screen(Main, mainstr)

Notice(MainMenu,mainstr)
Notice(Help, {
	"This a help doc\n"
	"More infomation to see https://github.com/czfshine/my_oj\n"
	"Thanks you !\n"
})

Screen(Loggin, {
		"Loggin goods infomation:\n"
		"Note : You can input a id equal 0 to exit loggin.\n"
})

Notice(LogginSuccess, {
		"The goods was success loggined.\n"
})

Screen(Change, {
		"Change goods infomation:\n"
		"Note : You can input a id equal 0 to exit loggin.\n"
})

Notice(ChangeType, {
		"Please choose you want change infomation type:\n"
		"1) good's name\n"
		"2) good's count\n"
		"Input your choice:"
})

Notice(ChangeSuccess, {
		"The goods was success changed.\n"
})

Screen(Remove, {
		"Remove goods from the store:\n"
		"Please choose a option:\n"
		"1) remove good by id\n"
		"2) remove good by name\n"
		"0) return the main menu\n"
		"Input your choice:"
})

Notice(RemoveSuccess, {
		"Remove good(s) success!\n"
})

Screen(Loggin2S, {
		"Sale or Stock good:"
		"Please choose a option:\n"
		"1) Sale good(s).\n"
		"2) Stock good(s).\n"
		"0) Exit.\n"
		"Input your choice:"
})
Screen(Sale, {
		"Sell the goods:\n"
		"Note : You can input a id equal 0 to exit loggin.\n"
})

Notice(SaleCount, {
		"How many good(s) you want to sell: "
})

Notice(SaleSuccess, {
		"The goods was  success sold!\n"
})

Screen(Stock, {
		"Stock the good:\n"
		"Note : You can input a id equal 0 to exit loggin.\n"
})

Notice(StockCount, {
		"How many good(s) you want to stock: "
})

Notice(StockSuccess, {
		"The goods was  success stocked!\n"
})


Notice(SumCount, {
		"The sum of the good's count is:"
})

Notice(IdCount, {
		"The sum of good's type is:"
})

Screen(Statis, {
		"Statis good's infomation:\n "
		"Please choose a option:\n"
		"1) Count sum of good's count.\n"
		"2) Count sum of good's type. \n"
		"0) Exit\n"
		"Input your choice:"
})

Screen(Query, {
		"Show all goods:\n"
})

Notice(RemoveNull, {
		"Not good in the store,remove error.\n"
})

Notice(GoodNotFound, {
		"The good can't found!\n"
})

Notice(StoreEmpty, {
		"The Store is emtpy.\n"
})

Notice(InputTypeError, {
		"This choice isn't correct.\n"
})
Notice(GoodsCountLess, {
	"The good's count is less than innput number!\n"
})


void ShowGoodsExist(int id) {

	char str[] = {
		"The Goods id:%d is exist,please input another id\n"
	};

	printf(str, id);

}
void ShowCantFind(int id) {
	char str[] = {
		"The Good with id:%d isn't exist,please input another id\n"
	};

	printf(str, id);
}


void SayHello() {
	printf("ERP4C %s | dev-build %04d\n", version, buildnum[0]);
}
void SayGoodbye() {
	CleanScreen();
	printf("Thanks you use ERP4C!\n");
	printf("Goodbye~~~\n");
}