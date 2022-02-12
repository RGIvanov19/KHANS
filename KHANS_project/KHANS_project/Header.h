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
