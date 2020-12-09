#include <Windows.h>
#include <iostream>
#include <conio.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4



void gotoxy(int, int);
void printTitle();
int printMenuList();
int keyControl();
void init();
void printInfo();