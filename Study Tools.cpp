#include<bits/stdc++.h>
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
FILE* setting;  // Setting File Handle 


void HideCursor(void) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &CursorInfo);
}


void setup(void) {  // Setup the Program.
	SetConsoleTitle("Study Tools");
	setting = fopen("data\\setting.ini", "w+");
	EnableMenuItem(_ConsoleMenu, SC_CLOSE, MF_GRAYED); // ʹ�رհ�ťʧЧ
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
	printf("������ʲô��\n");
	printf("1.ѧϰ����\n");
	printf("2.������Ϸ\n");
	char project = getch(); 
	if (project == '1') {
		system("cls"); printf("������ʲô��\n");
		printf("1.������\n");
		char funpower = getch();
		if (funpower == '1') {
			system("cls");
			printf("��������ʽ����ʽ���������֮���ϸ��ÿո�տ�����");
			double num1, num2;
			char calcer;
			cin >> num1 >> calcer >> num2;
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
			Sleep(3000);
			system("cls");
		}
		else {
			MessageBox(NULL, "Error", "Error", MB_OK + 48);
		}
	}
	else if (project == '2') {
		
	}
	else {
		MessageBox(NULL, "Error", "Error", MB_OK + 48);
	}
}


void ParentsMain(void) {
	system("cls");
	printf("������ʲô��\n");
	printf("1.����������ʹ���ӿ�ѧ��ʹ�õ��ԡ���\n");
	printf("2.�ر���̴��ڣ�����ز����ĵ�����\n");
	int funpower;
	printf("�ڴ˴����룺"); scanf("%d", &funpower);
	if (funpower == 1) {
		system("cls"); int sec = 0;
		printf("������Ҫ������������"); cin >> sec;
		time_t start = time(NULL);
		time_t end = time(NULL) + sec;
		system("cls"); printf("���ĵ����ѱ��ҳ��ܿء�");
		ShowWindow(_ConsoleWindow, SW_MAXIMIZE);
		POINT p; GetCursorPos(&p);
		while (true) {
			SetCursorPos(p.x, p.y);
			time_t now = time(NULL);
			if (now >= end) {
				system("cls"); printf("�����ѽ����");
				break;
			}
		}
		Sleep(1000);
	}
	else if (funpower == 2) {
		system("cls");
		printf("���ö���رմ��ڣ�5���ر�"); Sleep(5000);
		HWND windowClose = GetForegroundWindow();
		if (windowClose != NULL) {
			system("cls");
			SendMessage(windowClose, WM_CLOSE, NULL, NULL);
			printf("�����ѹرգ�"); system("cls");
		}
		else{
			system("cls");
			MessageBox(NULL, "δ�ҵ�����!", "��������", MB_OK + 48);
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
	printf("��ȴ��������ڼ���...\n");
	Sleep(3000); system("cls");  // CleanScreen
	printf("Tips:\n");
	printf("	�Ķ�README.md�Բ鿴��ݼ����ɡ�\n");
	Sleep(3000); system("cls");
	while (true) {
		printf("���ڴ�֪�������������ڡ�\n");
		printf("    �ˣ�����������\n");
		printf("��ѡ��������ݣ�\n");
		printf("1.���Ǽҳ�\n");
		printf("2.����ѧ��\n");
		printf("���ڴ�����       ");
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
				MessageBox(NULL, "���ǹ������Ҳ��ǰɣ�", "����", MB_YESNO + 48);
				system("taskkill /f /im ConsolePauser.exe");  // �رտ���̨��ͣ 
				exit(0);
			}
		}
	}
	
}


int main() {
	HideCursor();
	setup();
	if (setting == NULL) {
		MessageBox(NULL, "Cannot open the setting file.", "Fatal Error", MB_OK + 48); 
		perror("�������ļ����������������°���ܻ���������");
	}
	else {
		imp_Main(); 
		fclose(setting);
	}
	return 0;
}
