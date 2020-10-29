#include <Windows.h>
#include <iostream>
#include <conio.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

using namespace std;

void gotoxy(int, int);
void printTitle();
int printMenuList();
int keyControl();
void init();
void printInfo();
int maplistDraw();

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void init() {
	system("mode con cols=60 lines=40");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

}
void printTitle() {
	
	cout << endl << endl << endl << endl;
	cout <<"      #       ###   ###    ###       \n";
	cout << "     ##     ##       #     #  #      \n";
	cout << "    #  #   ##        #     #   #     \n";
	cout << "   #####    ##       #     #  #      \n";
	cout << "   #   #      ###   ###    ###       \n";

	cout << endl << endl;
	cout << "             ###         #    ###   ##   # \n";
	cout << "             #  #      #  #    #    # #  # \n";
	cout << "             ###      #####    #    #  # # \n";
	cout << "             #  #    #     #   #    #   ## \n";
	cout << "             #   #  #      #  ###   #    # \n";
	cout << endl << endl << endl;
}

int printMenuList() {
	int x=20;
	int y=20;
	gotoxy(x, y); cout   <<"게임시작";
	gotoxy(x, y+1); cout <<"게임정보"<<endl;
	gotoxy(x, y+2); cout <<"게임종료" << endl;

	while (1) {//무한반복
		int n = keyControl();
		switch (n) {
			case UP: {
				if (y > 20) {
					gotoxy(x - 2, y);
					cout << " ";
					gotoxy(x - 2, --y);
					cout << ">";
				}
				break;
			}
			case DOWN: {
				if (y < 22) {
					gotoxy(x - 2, y);
					cout << " ";
					gotoxy(x - 2, ++y);
					cout << ">";
				}break;
			}
			case SUBMIT: {
				return y-20;
			}
		}
	}
}


int keyControl() {
	char temp = _getch();

	if (temp == 'w' || temp == 'W') {
		return UP;
	}else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}else if (temp == 's' || temp == 'S') {
		return DOWN;
	}else if (temp == ' ') {
		return SUBMIT;
	}

}
void printInfo() {
	system("cls");
	cout << "이동은 w a s d 로 조작합니다" << endl;
	cout << "선택은 스페이스바로 합니다" << endl;
	cout << "스페이스바를 누르면 메인화면으로 돌아갑니다.";
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}

int maplistDraw() {
	int x = 24;
	int y = 6;
	system("cls");
	cout << endl<<endl;

	cout << "[스테이지 선택]" << endl << endl;

	gotoxy(x , y);
	cout << "1 단 계";
	gotoxy(x , y+1);
	cout << "2 단 계";
	gotoxy(x , y+2);
	cout << "3 단 계";
	gotoxy(x, y + 3);
	cout << "4 단 계";
	gotoxy(x, y + 4);
	cout << "5 단 계";
	gotoxy(x, y + 5);
	cout << "뒤   로";

	while (1) {//무한반복
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 6) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 11) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}break;
		}
		case SUBMIT: {
			return y - 20;
		}
		}
	}
}
int main() {
	init();
	while (1) {
		printTitle();
		int menu=printMenuList();
		if (menu == 0) {
			int n = maplistDraw();

			if (n == 0) {
				cout << "1단계 선택";
				Sleep(1000);
			}else if (n == 1) {
				cout << "2단계 선택";
				Sleep(1000);
			}else if (n == 2) {
				cout << "3단계 선택";
				Sleep(1000);
			}else if (n == 3) {
				cout << "4단계 선택";
				Sleep(1000);
			}else if (n == 4) {
				cout << "5단계 선택";
				Sleep(1000);
			}
		}
		else if (menu == 1) {
			printInfo();
		}
		else if (menu == 2) {
			return 0;
		}
		system("cls");
	}
	return 0;
	
	
}
