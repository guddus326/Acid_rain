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
	setcolor(3, 0);//3 :파랑
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
void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}
int main() {
	printTitle();

	return 0;
}
