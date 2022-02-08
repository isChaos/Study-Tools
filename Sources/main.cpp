#include<bits/stdc++.h>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;


#pragma comment(lib, "winmm.lib")


HWND _ConsoleWindow = GetConsoleWindow();
HMENU _ConsoleMenu = GetSystemMenu(_ConsoleWindow, FALSE); 
char code[1000]; char buffer[1024] = {0};


void HideCursor(void) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &CursorInfo);
}


void setup(void) {  // Setup the Program.
	SetConsoleTitle("Study Tools");
	EnableMenuItem(_ConsoleMenu, SC_CLOSE, MF_GRAYED); // 使关闭按钮失效
}


int mctv(int x) {
	int s = 1;
	for (int i = 1; i <= x; i++) {
		s = s * i;
	} return s;
}


double mctp(double x, int y) {
	double s = 1.0;
	if (y == 0) {
		return 1.0;
	}
	for (int i = 1; i <= y; i++) {
		s = s * x;
	}
	return s;
}


void StudentMain(void) {
	system("cls"); 
	printf("你想做什么？\n");
	printf("1.学习工具\n");
	char project = getch(); 
	if (project == '1') {
		system("cls"); printf("您想做什么？\n");
		printf("1.计算器\n");
		printf("2.学习编程\n");
		char funpower = getch();
		if (funpower == '1') {
			system("cls");
			printf("请输入算式（算式数字与符号之间严格用空格空开）：");
			double num1, num2;
			char calcer;
			cin >> num1 >> calcer;
			if (calcer == '!') {
				printf("%d! = %d", (int) num1, mctv((int) num1));
			}
			else if (calcer == '$') {
				printf("%f $ = %f", num1, sqrt(num1));
			}
			else {
				cin >> num2; 
				switch (calcer) {
					case '+' :
						system("cls");
						printf("%f + %f = %f", num1, num2, num1 + num2);
						break;
					case '-' :
						system("cls");
						printf("%f - %f = %f", num1, num2, num1 - num2);
						break;
					case '*' :
						system("cls");
						printf("%f * %f = %f", num1, num2, num1 * num2);
						break;
					case '/' :
						system("cls");
						printf("%f / %f = %f", num1, num2, num1 / num2);
						break;
					case '^' :
						system("cls");
						printf("%f ^ %f = %f", num1, num2, mctp(num1, (int)num2));
						break;
				}
			} printf("\n");
			system("pause");
			system("cls");
		}
		else if (funpower == '2') {
			system("cls");
			printf("函数大全:\n");
			printf("cout 输出（简单但较慢）\n");
			printf("printf 输出（快但非常究极世界超级混沌无敌天下难！）\n");
			printf("_________________________________________________\n");
			printf("                 懒得告诉你们了！\n");
			system("pause");
			system("cls");
		} 
		else {
			MessageBox(NULL, "Error", "Error", MB_OK + 48);
		}
	}
	else {
		MessageBox(NULL, "Error", "Error", MB_OK + 48);
	}
}


void ParentsMain(void) {
	system("cls");
	printf("您想做什么？\n");
	printf("1.电脑锁屏（使孩子科学地使用电脑。）\n");
	printf("2.关闭顽固窗口（例如关不掉的弹窗）\n");
	int funpower;
	printf("在此处输入："); scanf("%d", &funpower);
	if (funpower == 1) {
		system("cls"); int sec = 0;
		printf("请输入要锁屏的秒数："); cin >> sec;
		time_t start = time(NULL);
		time_t end = time(NULL) + sec;
		system("cls"); printf("您的电脑已被家长管控。");
		ShowWindow(_ConsoleWindow, SW_MAXIMIZE);
		POINT p; GetCursorPos(&p);
		while (true) {
			SetCursorPos(p.x, p.y);
			time_t now = time(NULL);
			if (now >= end) {
				system("cls"); printf("控制已解除。");
				break;
			}
		}
		Sleep(1000);
	}
	else if (funpower == 2) {
		system("cls");
		printf("请置顶需关闭窗口，5秒后关闭"); Sleep(5000);
		HWND windowClose = GetForegroundWindow();
		if (windowClose != NULL) {
			system("cls");
			SendMessage(windowClose, WM_CLOSE, NULL, NULL);
			printf("窗口已关闭！"); system("cls");
		}
		else{
			system("cls");
			MessageBox(NULL, "未找到窗口!", "致命错误", MB_OK + 48);
		}
	}
	else {
		ShowWindow(_ConsoleWindow, SW_HIDE); 
		MessageBox(NULL, "Error", "Error", MB_OK);
		ShowWindow(_ConsoleWindow, SW_RESTORE);
	}
}


void imp_Main(void) { // important Main 
	printf("Welcome...\n");
	printf("请等待，我正在加载...\n");
	Sleep(3000); system("cls");  // CleanScreen
	printf("Tips:\n");
	printf("	阅读README.md以查看快捷键技巧。\n");
	Sleep(3000); system("cls");
	while (true) {
		printf("海内存知己，天涯若比邻。\n");
		printf("    嗨，别来无恙啊！\n");
		printf("请选择您的身份：\n");
		printf("1.我是家长\n");
		printf("2.我是学生\n");
		printf("请在此输入       ");
		int identity = getch();
		if (identity == 'q') {
			ShowWindow(_ConsoleWindow, SW_SHOWMINIMIZED);
			system("cls");
		}
		else if (identity == 'e') {
			ShowWindow(_ConsoleWindow, SW_RESTORE);
			system("cls");
		}
		else{
			if (identity == '1') {
				ParentsMain();
			}
			else if (identity == '2') {
				StudentMain();
			}
			else {
				ShowWindow(_ConsoleWindow, SW_HIDE);
				MessageBox(NULL, "你是故意来找茬是吧！", "警告", MB_YESNO + 48);
				system("taskkill /f /im ConsolePauser.exe");  // 关闭控制台暂停 
				exit(0);
			}
		}
	}
	
}


int main() {
	HideCursor();
	setup();
	imp_Main();
	return 0;
}
