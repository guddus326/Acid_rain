#include < windows.h >     // windows.h를 인클루드 시킵니다.
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
	gotoxy(9, 18); cout << "회원";
	gotoxy(9, 21); cout << "비회원"<<endl;
}

int main() {
	printTitle();
	printMenuList();

	return 0;
}
