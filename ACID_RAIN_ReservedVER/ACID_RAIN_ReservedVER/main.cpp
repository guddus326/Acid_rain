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
	gotoxy(x, y); cout   <<"���ӽ���";
	gotoxy(x, y+1); cout <<"��������"<<endl;
	gotoxy(x, y+2); cout <<"��������" << endl;

	while (1) {//���ѹݺ�
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
	cout << "�̵��� w a s d �� �����մϴ�" << endl;
	cout << "������ �����̽��ٷ� �մϴ�" << endl;
	cout << "�����̽��ٸ� ������ ����ȭ������ ���ư��ϴ�.";
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}
int main() {
	init();
	while (1) {
		printTitle();
		int menu=printMenuList();
		if (menu == 0) {
			//���ӽ���
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
