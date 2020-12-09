#include "game.h"
using namespace std;

int GameEnd(int score) {
	init();
	string choice = "";
	system("cls");
	cout << "=======================게임 종료=======================" << endl << endl;
	cout << "기록을 남기시겠습니까[Y/N] : ";
	cin >> choice;
	cout << endl;
	if (choice == "Y") {
		GameRecord(score);
	}
	else {
		cout << "게임을 종료하겠습니다";
		Sleep(2000);
		exit(0);
	}
}

int GameRecord(int score)
{
	string choice = "";
	string name;
	cout << "=======================랭킹 등록=======================" << endl << endl;
	cout << "이름을 입력하세요 : ";
	cin >> name;
	cout<< endl;

	ofstream output("result.txt",ios::app);
	output <<"이름 : "<<name <<setw(10)<<"점수 : "<<score<<endl;
	output.close();

	cout << "랭킹을 확인하러 가시겠습니까? [Y/N] : ";
	cin >> choice;
	if (choice == "Y") {
		Ranking();
	}
	else {
		cout << "게임을 종료하겠습니다";
		Sleep(3000);
		return 0;
	}
}

void Ranking() {
	init();
	system("cls");
	string name;
	string scroe;
	cout << "=======================랭킹 확인=======================" << endl << endl;
	ifstream myfile("result.txt");
	string buffer;
	while (myfile.peek() != EOF) {
		getline(myfile, buffer);
		cout << buffer << endl;
	}
	cout << endl << endl;
	cout << "스페이스를 누르면 게임이 종료됩니다." << endl;
	if (keyControl() == SUBMIT) {
		exit(0);
	}
}