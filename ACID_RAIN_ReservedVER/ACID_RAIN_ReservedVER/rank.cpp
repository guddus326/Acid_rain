#include "game.h"
using namespace std;

int GameEnd(int score) {
	init();
	string choice = "";
	system("cls");
	cout << "=======================���� ����=======================" << endl << endl;
	cout << "����� ����ðڽ��ϱ�[Y/N] : ";
	cin >> choice;
	cout << endl;
	if (choice == "Y") {
		GameRecord(score);
	}
	else {
		cout << "������ �����ϰڽ��ϴ�";
		Sleep(2000);
		exit(0);
	}
}

int GameRecord(int score)
{
	string choice = "";
	string name;
	cout << "=======================��ŷ ���=======================" << endl << endl;
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;
	cout<< endl;

	ofstream output("result.txt",ios::app);
	output <<"�̸� : "<<name <<setw(10)<<"���� : "<<score<<endl;
	output.close();

	cout << "��ŷ�� Ȯ���Ϸ� ���ðڽ��ϱ�? [Y/N] : ";
	cin >> choice;
	if (choice == "Y") {
		Ranking();
	}
	else {
		cout << "������ �����ϰڽ��ϴ�";
		Sleep(3000);
		return 0;
	}
}

void Ranking() {
	init();
	system("cls");
	string name;
	string scroe;
	cout << "=======================��ŷ Ȯ��=======================" << endl << endl;
	ifstream myfile("result.txt");
	string buffer;
	while (myfile.peek() != EOF) {
		getline(myfile, buffer);
		cout << buffer << endl;
	}
	cout << endl << endl;
	cout << "�����̽��� ������ ������ ����˴ϴ�." << endl;
	if (keyControl() == SUBMIT) {
		exit(0);
	}
}