#include "main.h"

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
void userInput();

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void init() {
	system("mode con cols=55 lines=30");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

}
void printTitle() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << endl << endl << endl << endl;
	cout <<"       #       ###   ###    ###       \n";
	Sleep(200);
	cout << "      ##     ##       #     #  #      \n";
	Sleep(200);
	cout << "     #  #   ##        #     #   #     \n";
	Sleep(200);
	cout << "    #####    ##       #     #  #      \n";
	Sleep(200);
	cout << "    #   #      ###   ###    ###       \n";
	Sleep(200);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << endl << endl;
	cout << "             ###         #    ###   ##   # \n";
	Sleep(200);
	cout << "             #  #      #  #    #    # #  # \n";
	Sleep(200);
	cout << "             ###      #####    #    #  # # \n";
	Sleep(200);
	cout << "             #  #    #     #   #    #   ## \n";
	Sleep(200);
	cout << "             #   #  #      #  ###   #    # \n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	cout << "												예";
	Sleep(500);
	cout << "약";
	Sleep(500);
	cout << "어";
	Sleep(500);
	cout << "버";
	Sleep(500);
	cout << "전";
	Sleep(500);
	
	cout << endl << endl << endl;
}

int printMenuList() {
	int x=20;
	int y=20;
	gotoxy(x-4, y); cout   <<"->  게 임 시 작";
	gotoxy(x, y+2); cout <<"게 임 정 보"<<endl;
	gotoxy(x, y+4); cout <<"게 임 종 료" << endl;

	while (1) {//무한반복
		int n = keyControl();
		switch (n) {
			case UP: {
				if (y > 20) {
					gotoxy(x-4, y);
					cout << "   ";
					gotoxy(x -4, --y);
					gotoxy(x - 4, --y);
					cout << "->";
					
				}
				break;
			}
			case DOWN: {
				if (y < 24) {
					gotoxy(x - 4, y);
					cout << "   ";
					gotoxy(x - 4, ++y);
					gotoxy(x - 4, ++y);
					cout << "->";
					
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

	cout << "스페이스바를 눌러 주세요" << endl;
	while (1) {
		if (keyControl() == SUBMIT) {
			
		}
	}
}

void userInput() {
	string name;
	system("cls");
	gotoxy(3,1);
	cout << "<<이름 입력>>"<<endl;
	cout << "----------------------------------"<<endl;
	cout << "-                                -" << endl;
	cout << "----------------------------------";
	gotoxy(3, 2);
	gotoxy(3, 3);
	cin >> name;
	while (1) {
		if (keyControl() == SUBMIT) {

		}
	}
}

int main() {
	init();
	while (1) {
		printTitle();	
		int menu=printMenuList();
	
		if (menu == 0) {
			userInput();
		}
		else if (menu == 2) {
			printInfo();
		}
		else if (menu == 4) {
			return 0;
		}
		system("cls");
	}
	return 0;
}
