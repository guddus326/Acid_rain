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

void printMenuArrow(int* menuIndex) {
	for (int i = 0; i < 6; i++) {
		gotoxy(5, 18 + i); printf("  ");
	}

	setcolor(14,0);
	gotoxy(5, 18 + *menuIndex); printf("→");

	setcolor(14, 0);
	switch (*menuIndex) {
	case 0:
		gotoxy(9, 18); printf("게임시작"); break;
	case 1:
		gotoxy(9, 19); printf("랭킹"); break;
	case 2:
		gotoxy(9, 20); printf("도움말"); break;
	case 3:
		gotoxy(9, 21); printf("로그보기"); break;
	case 4:
		gotoxy(9, 22); printf("개발자 설정"); break;
	case 5:
		gotoxy(9, 23); printf("끝내기"); break;
	}
}

void printMenuList() {
	gotoxy(9, 18); printf("게임시작");
	gotoxy(9, 19); printf("랭킹");
	gotoxy(9, 20); printf("도움말");
	gotoxy(9, 21); printf("로그보기");
	gotoxy(9, 22); printf("개발자 설정");
	gotoxy(9, 23); printf("끝내기");
}
void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}
int main()
{
	setcolor(3, 0);//3 :파랑
	cout << endl << endl << endl << endl;
	printf("      #       ###   ###    ###       \n"); 
	printf("     ##     ##       #     #  #      \n");
	printf("    #  #   ##        #     #   #     \n");
	printf("   #####    ##       #     #  #      \n");
	printf("   #   #      ###   ###    ###       \n");

	cout << endl << endl;
	printf("              ###         #    ###   ##   # \n");
	printf("              #  #      #  #    #    # #  # \n");
	printf("              ###      #####    #    #  # # \n");
	printf("              #  #    #     #   #    #   ## \n");
	printf("              #   #  #      #  ###   #    # \n");
	cout << endl << endl << endl;
	
	printMenuList();
	
	
	

}