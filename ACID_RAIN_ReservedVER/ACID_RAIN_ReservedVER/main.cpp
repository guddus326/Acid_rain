#include < windows.h >     // windows.h�� ��Ŭ��� ��ŵ�ϴ�.
#include <iostream>
using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void consoleSetting(struct _gameStatus* gameStatus) {
	system("title Acid Rain");
	system("mode con: cols=64 lines=10");
}

void printTitle() {

	cout << endl << endl << endl << endl;
	printf("      #       ###   ###    ###       \n");
	printf("     ##     ##       #     #  #      \n");
	printf("    #  #   ##        #     #   #     \n");
	printf("   #####    ##       #     #  #      \n");
	printf("   #   #      ###   ###    ###       \n");

	cout << endl << endl;
	printf("             ###         #    ###   ##   # \n");
	printf("             #  #      #  #    #    # #  # \n");
	printf("             ###      #####    #    #  # # \n");
	printf("             #  #    #     #   #    #   ## \n");
	printf("             #   #  #      #  ###   #    # \n");
	cout << endl << endl << endl;
}

void printMenuList() {
	gotoxy(9, 18); cout << "ȸ��";
	gotoxy(9, 21); cout << "��ȸ��"<<endl;
}

int main() {
	printTitle();
	printMenuList();

	return 0;
}
