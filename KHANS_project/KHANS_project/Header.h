#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void printName() {
	SetConsoleTextAttribute(h, 4);
	cout << R"(
                                _   __ _   _   ___   _   _  _____ 
                               | | / /| | | | / _ \ | \ | |/  ___|
                               | |/ / | |_| |/ /_\ \|  \| |\ `--. 
                               |    \ |  _  ||  _  || . ` | `--. \
                               | |\  \| | | || | | || |\  |/\__/ /
                               \_| \_/\_| |_/\_| |_/\_| \_/\____/ 
                                   
                                   
)" << endl;
}

void color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void optionPlay() {
	system("cls");
	int Set[] = { 7,7,7 };
	int counter = 2;
	char key;

	for (int i = 0; i < 100; i++)
	{
		gotoxy(10, 10);
		color(Set[0]);
		cout << "                        Search   ";

		gotoxy(10, 11);
		color(Set[1]);
		cout << "                        Add event   ";

		gotoxy(10, 12);
		color(Set[2]);
		cout << "                        Exit   ";

		key = _getch();

		if (key == 72 && (counter >= 2 && counter <= 3)) {
			counter--;
		}
		if (key == 80 && (counter >= 1 && counter <= 2)) {
			counter++;
		}
		if (key == '\r') {
			if (counter == 1) {
				//tuk dobavqsh funckiite
			}
			if (counter == 2) {
				//tuk dobavqsh funckiite
			}
			if (counter == 3) {
				break;
			}
		}
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;

		if (counter == 1) {
			Set[0] = 12;
		}
		if (counter == 2) {
			Set[1] = 12;
		}
		if (counter == 3) {
			Set[2] = 12;
		}

	}
}