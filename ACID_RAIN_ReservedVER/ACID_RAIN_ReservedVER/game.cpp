#include "game.h"
#include <thread>
using namespace std;


class WordInput {
private:
	string answer;
protected:
	string setanswer() {
		gotoxy(0, 26);
		cout << "입력 : "; cin >> answer;
		return answer;
	}
};

class WordOutput :public WordInput {
private:
	string word;
	string getanswer;
	int score = 0;
public:
	void getWord()
	{
		static clock_t start = clock();
		ifstream fin;
		fin.open("word_list.txt");
		while (fin.eof() == false) {
				gotoxy(45, 1);
				cout << "점수 : " << score;
				int x = (rand() % 50) + 1;
				int y = (rand() % 15) + 5;

				gotoxy(x, y);

				fin >> word;
				cout << word;
				getanswer = setanswer();

				if (word == getanswer) {
					InitGameWindow();
					score += 10;

				}
				else {
					InitGameWindow();
					score -= 10;
				}
				clock_t end = clock();
				gotoxy(1, 1);
				cout <<"시간 : "<<(double)(end - start) / CLOCKS_PER_SEC<<end;
				if ((double)(end - start) / CLOCKS_PER_SEC>30) {
					GameEnd(score);
				}
			}
		fin.close();
	}
};

void GameStart() {
	init();
	system("cls");
	gotoxy(0,0);
	cout << "3"<< endl;
	cout << "   ";
	Sleep(1000);
	gotoxy(0, 0);
	cout << "2";
	cout << "   ";
	Sleep(1000);
	gotoxy(0, 0);
	cout << "1";
	cout << "   ";
	Sleep(1000);
	gotoxy(0, 0);
	cout << "START" << endl;
	Sleep(1000);
	GameWindow();

}

void GameWindow() {
	init();
	system("cls");
	
	gotoxy(0, 0);
	cout << "=======================================================" << endl;
	gotoxy(0, 2);
	cout << "=======================================================" << endl << endl;
	gotoxy(0, 25);
	cout << "=======================================================" << endl;
	gotoxy(0, 27);
	cout << "=======================================================" << endl << endl;
	gotoxy(0, 26);	
	wordcheck();	
}

void InitGameWindow() {
	init();
	system("cls");
	

	gotoxy(0, 0);
	cout << "=======================================================" << endl;
	gotoxy(0, 2);
	cout << "=======================================================" << endl << endl;
	gotoxy(0, 25);
	cout << "=======================================================" << endl;
	gotoxy(0, 27);
	cout << "=======================================================" << endl << endl;
	gotoxy(0, 26);
	gotoxy(40, 1);
	
}

void Timer()
{
	static int time = 30;
	gotoxy(1, 1);
	cout << "시간 : "<<time;
	cout << "   ";
	Sleep(1000);
	time--;
	Timer();
}

void wordcheck()
{
	WordOutput W0;
	W0.getWord();
}