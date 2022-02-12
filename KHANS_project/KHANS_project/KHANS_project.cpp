//#pragma once
#include <iostream>
#include <locale>
#include <string>
#include <windows.h>
#include <iomanip>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

//#include "Header.h"
using namespace std;

struct Event {
    int day;
    int month;
    int year;
    string whatHappened;
    Event* next = NULL;
};

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//find out how this works
string toBG(string text) {
    char bgText[1000];
    OemToCharA(text.c_str(), bgText);
    return bgText;
}

void printName() {
    SetConsoleTextAttribute(h, 4);
    cout << endl << endl << endl;
    cout << R"(
                                         _   __ _   _   ___   _   _  _____ 
                                        | | / /| | | | / _ \ | \ | |/  ___|
                                        | |/ / | |_| |/ /_\ \|  \| |\ `--. 
                                        |    \ |  _  ||  _  || . ` | `--. \
                                        | |\  \| | | || | | || |\  |/\__/ /
                                        \_| \_/\_| |_/\_| |_/\_| \_/\____/ 
                                    
                                   
)" << endl;
}

int positionToRemove()
{
    int pos;
    cout << "Въведете номера на събитието, което искате да премахнете: ";
    cin >> pos;
    return pos;
}

int positionToEdit()
{
    int pos;
    cout << "Въведете номера на събитието, което искате да редактирате: ";
    cin >> pos;
    return pos;
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

int getDecNum() {
    int decNum;
    cout << "Въведете десетично число: ";
    cin >> decNum;
    return decNum;
}

int decToBin(int decNum) {
    int number = 0;
    int c = 0;
    while (decNum != 0)
    {
        number = number + ((decNum % 2) * pow(10, c));
        decNum = decNum / 2;
        c++;
    }
    return number;
}

int decToGray() {
    int value = decToBin(getDecNum());
    int a, b, gray = 0, i = 0;
    while (value != 0)
    {
        a = value % 10;
        value = value / 10;
        b = value % 10;

        if ((a && !b) || (!a && b))
            gray = gray + pow(10, i);
        i++;
    }
    return gray;
}

void printList(Event* head) {
    int counter = 1;
    int row = 17;
    while (head != NULL)
    {
        gotoxy(10, row);
        cout << counter << " --> " << head->day << "." << head->month << "." << head->year << " - " << head->whatHappened << endl;
        head = head->next;
        counter++;
        row++;
    }
}

void printEventsBefore1900(Event* head) {
    int counter = 1;
    int row = 17;
    while (head != NULL)
    {
        if (head->year < 1900) {
            gotoxy(10, row);
            cout << counter << " --> " << head->day << "." << head->month << "." << head->year << " - " << head->whatHappened << endl;
            counter++;
            row++;
        }
        head = head->next;
    }
}

void printEventsAfter1900(Event* head) {
    int counter = 1;
    int row = 17;
    while (head != NULL)
    {
        if (head->year >= 1900) {
            gotoxy(10, row);
            cout << counter << " --> " << head->day << "." << head->month << "." << head->year << " - " << head->whatHappened << endl;
            counter++;
            row++;
        }
        head = head->next;
    }
}

int еditOptions() {
    int option;
    cout << "Въведете 1 за да промените какво се е случило" << endl;
    cout << "Въведете 2 за да промените деня" << endl;
    cout << "Въведете 3 за да промените месеца" << endl;
    cout << "Въведете 4 за да промените годината" << endl;
    cout << "Какъв е вашият избор: ";
    cin >> option;
    return option;
}

void getNewData(int option, Event* head) {
    switch (option) {
    case 2:
        int newDay;
        do {
            cout << "Въведете новия ден: ";
            cin >> newDay;
            if (newDay < 1 || newDay > 31) {
                cout << "Изглежда сте въвели некоректни данни :(" << endl;
                cout << "Опитайте отново" << endl << endl;
            }
        } while (newDay < 1 || newDay > 31);
        head->day = newDay;
        break;
    case 3:
        int newMonth;
        do {
            cout << "Въведете новия месец: ";
            cin >> newMonth;
            if (newMonth < 1 || newMonth > 12) {
                cout << "Изглежда сте въвели некоректни данни :(" << endl;
                cout << "Опитайте отново" << endl << endl;
            }
        } while (newMonth < 1 || newMonth > 12);
        head->month = newMonth;
        break;
    case 4:
        int newYear;
        do {
            cout << "Въведете новата година: ";
            cin >> newYear;
            if (newYear < 1 || newYear > 2022) {
                cout << "Изглежда сте въвели некоректни данни :(" << endl;
                cout << "Опитайте отново" << endl << endl;
            }
        } while (newYear < 1 || newYear > 2022);
        head->year = newYear;

        break;
    case 1:
        string newWhatHappened;
        cout << "Въведете какво се е случило: ";
        cin.ignore();
        getline(cin, newWhatHappened);
        head->whatHappened = toBG(newWhatHappened);
        break;
    }
}

long int calcDate(Event* event) {
    long int date = event->year * 10000 + event->month * 100 + event->day;
    return date;
}

int findLinkedListLength(Event* head) {
    int counter = 1;
    while (head->next != NULL) {
        head = head->next;
        counter++;
    }
    return counter;
}

void swapValues(Event* head, Event* newEvent) {
    int tempDay = newEvent->day;
    int tempMonth = newEvent->month;
    int tempYear = newEvent->year;
    string tempWhatHappened = newEvent->whatHappened;

    newEvent->day = head->day;
    newEvent->month = head->month;
    newEvent->year = head->year;
    newEvent->whatHappened = head->whatHappened;

    head->day = tempDay;
    head->month = tempMonth;
    head->year = tempYear;
    head->whatHappened = tempWhatHappened;
}

void sortEvents(Event* head, Event* newEvent, Event* tail) {
    Event* current = head;
    bool isSorted = false;
    while (current->next != NULL && isSorted == false) {
        Event* currentNext = current->next;
        if (calcDate(newEvent) > calcDate(currentNext)) {
            current = current->next;
        }

        /*if (calcDate(newEvent) == calcDate(head)) {
            cout << "This event already exist"
        }*/
        else {
            tail->next = NULL;
            newEvent->next = current->next;
            current->next = newEvent;
            if (current == head) {
                swapValues(head, newEvent);
            }
            isSorted = true;
        }
    }
}

void getNewEvent(Event*& newEvent) {
    int dateInfo;
    string info;

    cout << "Какво се е случило:  ";
    getline(cin, info);
    newEvent->whatHappened = toBG(info);

    cout << endl << "Кога се е случило събитието?" << endl;

    do {
        cout << "Ден: ";
        cin >> dateInfo;
        if (dateInfo < 1 || dateInfo > 31) {
            cout << "Изглежда сте въвели некоректни данни :(" << endl;
            cout << "Опитайте отново" << endl << endl;
        }
    } while (dateInfo < 1 || dateInfo > 31);
    newEvent->day = dateInfo;

    do {
        cout << endl;
        cout << "Месец: ";
        cin >> dateInfo;
        if (dateInfo < 1 || dateInfo > 12) {
            cout << "Изглежда сте въвели некоректни данни :(" << endl;
            cout << "Опитайте отново" << endl << endl;
        }
    } while (dateInfo < 1 || dateInfo > 12);
    newEvent->month = dateInfo;

    do {
        cout << endl;
        cout << "Година: ";
        cin >> dateInfo;
        if (dateInfo < 1 || dateInfo > 2022) {
            cout << "Изглежда сте въвели некоректни данни :(" << endl;
            cout << "Опитайте отново" << endl << endl;
        }
    } while (dateInfo < 1 || dateInfo > 2022);
    newEvent->year = dateInfo;
}

Event* findTail(Event* head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

void addNewEvent(Event* head) {
    Event* Tail = findTail(head);
    Event* newEvent = new Event;
    getNewEvent(newEvent);
    Tail->next = newEvent;
    sortEvents(head, newEvent, Tail);
}

void removeEvent(Event* head, int eventPosition) {
    int counter = 1;
    //if we want to remove the first event
    if (eventPosition == 1) {
        eventPosition = 2;
        swapValues(head, head->next);
    }

    while (counter != eventPosition - 1) {
        head = head->next;
        counter++;
    }

    //if we want to remove the last event
    if (eventPosition == findLinkedListLength(head)) {
        eventPosition = findLinkedListLength(head) - 1;
        swapValues(head, head->next);
    }

    Event* elementToDelete = head->next;
    head->next = head->next->next;
    delete elementToDelete;
}

void editEvent(Event* head, int eventPosition) {
    int counter = 1;
    Event* current = head;
    while (counter != eventPosition) {
        current = current->next;
        counter++;
    }
    getNewData(еditOptions(), current);
    //not working
    //sortEvents(head, current, findTail(head));
}

void printOptions(Event* head) {
    int Set[] = { 7, 7, 7, 7, 7, 7, 7, 7 };
    int counter = 2;
    char key;

    //for (int i = 0; i < 100; i++)
    while (1) {
        /*gotoxy(35, 5);
        cout << "_____________________________________________";*/

        gotoxy(40, 7);
        color(Set[0]);
        cout << "<< Виж списък със свички събития >>";

        gotoxy(40, 8);
        color(Set[1]);
        cout << "<< Виж списък със събитията преди 1900г. >>";

        gotoxy(40, 9);
        color(Set[2]);
        cout << "<< Виж списък със събитията след 1900г. >>";

        gotoxy(48, 10);
        color(Set[3]);
        cout << "<< Добави събитие >>";

        gotoxy(47, 11);
        color(Set[4]);
        cout << "<< Премахни събитие >>";

        gotoxy(46, 12);
        color(Set[5]);
        cout << "<< Редактирай събитие >>";

        gotoxy(45, 13);
        color(Set[6]);
        cout << "<< Превръщане в Грей код >>" << endl;

        gotoxy(45, 14);
        color(Set[7]);
        cout << "<< Прекрати програмата >>" << endl;

        /*gotoxy(35, 16);
        cout << "_____________________________________________" << endl;*/

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 8)) {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 7)) {
            counter++;
        }
        if (key == '\r') {
            if (counter == 1) {
                system("CLS");
                //print all events
                printList(head);
            }
            if (counter == 2) {
                system("CLS");
                //print events before 1900
                printEventsBefore1900(head);

            }
            if (counter == 3) {
                system("CLS");
                //print events after 1900
                printEventsAfter1900(head);
            }
            if (counter == 4) {
                //add event
                system("CLS");
                addNewEvent(head);
                system("CLS");
            }
            if (counter == 5) {
                system("CLS");
                //remove event
                printList(head);
                removeEvent(head, positionToRemove());
                system("CLS");
            }
            if (counter == 6) {
                system("CLS");
                //redact event
                printList(head);
                editEvent(head, positionToEdit());
                system("CLS");
            }
            if (counter == 7) {
                system("CLS");
                //gray code
                cout << "Число след преобразуване чрез код на Грей: " << decToGray();
            }
            if (counter == 8) {
                system("CLS");
                gotoxy(40, 4);
                cout << "Довиждане! До нови срещи! :)" << endl << endl;
                break;
            }
        }
        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;
        Set[5] = 7;
        Set[6] = 7;
        Set[7] = 7;

        if (counter == 1) {
            Set[0] = 12;
        }
        if (counter == 2) {
            Set[1] = 12;
        }
        if (counter == 3) {
            Set[2] = 12;
        }
        if (counter == 4) {
            Set[3] = 12;
        }
        if (counter == 5) {
            Set[4] = 12;
        }
        if (counter == 6) {
            Set[5] = 12;
        }
        if (counter == 7) {
            Set[6] = 12;
        }
        if (counter == 8) {
            Set[7] = 12;
        }
    }

}

int main() {

    setlocale(LC_ALL, "Bulgarian");

    Event* Tail = new Event{ 16, 9, 1913, "Сключен е Цариградски договор", NULL };
    Event* nineteenthEvent = new Event{ 28, 7, 1913, "Сключен е Букурещки договор за разделяне на територии след Балканската война", Tail };
    Event* eighteenthEvent = new Event{ 19, 5, 1913, "Сключване на таен гръцко-сръбски договор", nineteenthEvent };
    Event* seventeenthEvent = new Event{ 17, 5, 1913, "Сключване на Лондонския мирен договор", eighteenthEvent };
    Event* sixteenthEvent = new Event{ 5, 10, 1912, "Обявяване на Балканската война", seventeenthEvent };
    Event* fifteenthhEvent = new Event{ 29, 2, 1912, "Подписан е съюзнически договор между България и Сърбия", sixteenthEvent };
    Event* fourteenthEvent = new Event{ 22, 9, 1908, "Обявяване на независимостта на България", fifteenthhEvent };
    Event* thirteenthEvent = new Event{ 2, 8, 1903, "Избухване на Илинденско-Преображенско въстание", fourteenthEvent };
    Event* twelfthEvent = new Event{ 9, 8, 1886, "Държавен преврат срещу княз Александър 1", thirteenthEvent };
    Event* eleventhEvent = new Event{ 24, 3, 1886, "Топханенски акт в Цариград", twelfthEvent };
    Event* tenthEvent = new Event{ 19, 2, 1886, "Сключен е Букурещки договор", eleventhEvent };
    Event* ninthEvent = new Event{ 5, 11, 1885, "Боевете при Сливница", tenthEvent };
    Event* eightEvent = new Event{ 6, 9, 1885, "Съединение на Княжество България и Източна Румелия", ninthEvent };
    Event* seventhEvent = new Event{ 10, 2, 1885, "Захари Стоянов създава таен комитет в гр. Пловдив", eightEvent };
    Event* sixthEvent = new Event{ 1, 7, 1881, "Свикано е Второто Велико Народно събрание", seventhEvent };
    Event* fifthEvent = new Event{ 27, 4, 1881, "Направен е опит за държавен преврат", sixthEvent };
    Event* fourthEvent = new Event{ 5, 7, 1879, "Назначено е Първото българско правителство",fifthEvent };
    Event* thirdEvent = new Event{ 16, 4, 1879, "Приета е Първата българска конституцуя", fourthEvent };
    Event* secondEvent = new Event{ 10, 2, 1879, "Свикване на Учредително събрание в гр. Велико Търново", thirdEvent };
    Event* Head = new Event{ 3, 3, 1878, "Сключване на Сан Стефански мирен договор", secondEvent };

    printName();
    system("pause");
    system("CLS");
    printOptions(Head);

    

    return 0;
}




