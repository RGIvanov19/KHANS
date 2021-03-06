#include <iostream>
#include <locale>
#include <string>
#include <windows.h>
#include <iomanip>
#include <math.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

struct Event {
    int day;
    int month;
    int year;
    string whatHappened;
    Event* next = NULL;
};

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//needed for being able to input in bulgarian
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

int findLinkedListLength(Event* head) {
    int counter = 1;
    while (head->next != NULL) {
        head = head->next;
        counter++;
    }
    return counter;
}

//gets the position of the event that is going to be removed
int positionToRemove(Event* head)
{
    int pos;
    do {
        cout << endl;
        cout << "???????? ?????? ?? ?????????, ????? ?????? ?? ??????????: ";
        cin >> pos;
        //if incorrect data is inputted
        if (pos < 1 || pos > findLinkedListLength(head)) {
            cout << "???????? ??? ?????? ?????????? ????? :(" << endl;
            cout << "???????? ??????" << endl << endl;
        }
    } while (pos < 1 || pos > findLinkedListLength(head));
    return pos;
}

//gets the position of the event that is going to be edited
int positionToEdit(Event* head)
{
    int pos;
    do {
        cout << endl;
        cout << "???????? ?????? ?? ?????????, ????? ?????? ?? ???????????: ";
        cin >> pos;
        //if incorrect data is inputted
        if (pos < 1 || pos > findLinkedListLength(head)) {
            cout << "???????? ??? ?????? ?????????? ????? :(" << endl;
            cout << "???????? ??????" << endl << endl;
        }
    } while (pos < 1 || pos > findLinkedListLength(head));
    return pos;
}

void color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//leaves space before output
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int getDecNum() {
    int decNum;
    cout << "???????? ????????? ?????: ";
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

//prints all events
void printList(Event* head) {
    int counter = 1;
    int row = 17;
    while (head != NULL)
    {
        gotoxy(22, row);
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
            gotoxy(22, row);
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
            gotoxy(22, row);
            cout << counter << " --> " << head->day << "." << head->month << "." << head->year << " - " << head->whatHappened << endl;
            counter++;
            row++;
        }
        head = head->next;
    }
}

//gets info what is going to be edited
int ?ditOptions() {
    int option;
    cout << "???????? 1 ?? ?? ????????? ????? ?? ? ???????" << endl;
    cout << "???????? 2 ?? ?? ????????? ????" << endl;
    cout << "???????? 3 ?? ?? ????????? ??????" << endl;
    cout << "???????? 4 ?? ?? ????????? ????????" << endl;
    do {
        cout << endl;
        cout << "????? ? ?????? ?????: ";
        cin >> option;
        //if incorrect data is inputted
        if (option < 1 || option > 4) {
            cout << "???????? ??? ?????? ?????????? ????? :(" << endl;
            cout << "???????? ??????" << endl << endl;
        }
    } while (option < 1 || option > 4);
    return option;
}

//gets data for the event that is being edited
void getNewData(int option, Event* head) {
    switch (option) {
        //the day is going to be edited
    case 2:
        int newDay;
        do {
            cout << "???????? ????? ???: ";
            cin >> newDay;
            //if incorrect data is inputted
            if (newDay < 1 || newDay > 31) {
                cout << "???????? ??? ?????? ?????????? ????? :(" << endl;
                cout << "???????? ??????" << endl << endl;
            }
        } while (newDay < 1 || newDay > 31);
        head->day = newDay;
        break;
        //the month is going to be edited
    case 3:
        int newMonth;
        do {
            cout << "???????? ????? ?????: ";
            cin >> newMonth;
            //if incorrect data is inputted
            if (newMonth < 1 || newMonth > 12) {
                cout << "???????? ??? ?????? ?????????? ????? :(" << endl;
                cout << "???????? ??????" << endl << endl;
            }
        } while (newMonth < 1 || newMonth > 12);
        head->month = newMonth;
        break;
        //the year is going to be edited
    case 4:
        int newYear;
        do {
            cout << "???????? ?????? ??????: ";
            cin >> newYear;
            //if incorrect data is inputted
            if (newYear < 1 || newYear > 2022) {
                cout << "???????? ??? ?????? ?????????? ????? :(" << endl;
                cout << "???????? ??????" << endl << endl;
            }
        } while (newYear < 1 || newYear > 2022);
        head->year = newYear;

        break;
        // what happened is going to be edited
    case 1:
        string newWhatHappened;
        cout << "???????? ????? ?? ? ???????: ";
        cin.ignore();
        getline(cin, newWhatHappened);
        //to bulgarian
        head->whatHappened = toBG(newWhatHappened);
        break;
    }
}

//makes a number with witch two events are compared by date
long int calcDate(Event* event) {
    long int date = event->year * 10000 + event->month * 100 + event->day;
    return date;
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

//sorts events in ascending order by date
void sortEvents(Event* head, Event* newEvent, Event* tail) {
    Event* current = head;
    bool isSorted = false;
    while (current->next != NULL && isSorted == false) {
        Event* currentNext = current->next;
        if (calcDate(newEvent) > calcDate(currentNext)) {
            current = current->next;
        }
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

    cout << "????? ?? ? ???????:  ";
    getline(cin, info);
    //to bulgarian
    newEvent->whatHappened = toBG(info);

    cout << endl << "???? ?? ? ??????? ??????????" << endl;

    do {
        cout << "???: ";
        cin >> dateInfo;
        //if incorrect data is inputted
        if (dateInfo < 1 || dateInfo > 31) {
            cout << "???????? ??? ?????? ?????????? ????? :(" << endl;
            cout << "???????? ??????" << endl << endl;
        }
    } while (dateInfo < 1 || dateInfo > 31);
    newEvent->day = dateInfo;

    do {
        cout << endl;
        cout << "?????: ";
        cin >> dateInfo;
        //if incorrect data is inputted
        if (dateInfo < 1 || dateInfo > 12) {
            cout << "???????? ??? ?????? ?????????? ????? :(" << endl;
            cout << "???????? ??????" << endl << endl;
        }
    } while (dateInfo < 1 || dateInfo > 12);
    newEvent->month = dateInfo;

    do {
        cout << endl;
        cout << "??????: ";
        cin >> dateInfo;
        //if incorrect data is inputted
        if (dateInfo < 1 || dateInfo > 2022) {
            cout << "???????? ??? ?????? ?????????? ????? :(" << endl;
            cout << "???????? ??????" << endl << endl;
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

//move the edited event at the end of the list in order the list to be sorted
void moveToEnd(Event* head, Event* eventToMove) {
    Event* tail = findTail(head);
    Event* current = head;

    //if the edited event is the first one
    if (eventToMove == head) {
        swapValues(current, current->next);
        eventToMove = current->next;
        while (current->next != eventToMove && current->next != NULL) {
            current = current->next;
        }
        current->next = current->next->next;
    }
    else {
        while (current->next != eventToMove && current->next != NULL) {
            current = current->next;
        }
        current->next = current->next->next;
    }

    eventToMove->next = NULL;
    tail->next = eventToMove;
    sortEvents(head, eventToMove, tail);
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
    getNewData(?ditOptions(), current);
    moveToEnd(head, current);
}

void printLine(int a, int b) {
    gotoxy(a, b);
    color(4);
    cout << "____________________________________________________";
}

//prints the menu
void printOptions(Event* head) {
    int Set[] = { 7, 7, 7, 7, 7, 7, 7, 7 };
    int counter = 2;
    char key;

    //infinite loop in order to print the menu untill the option for stopping the programme is selected
    while (1) {
        printLine(35, 2);

        gotoxy(44, 4);
        color(Set[0]);
        cout << "<< ??? ?????? ??? ?????? ??????? >>";

        gotoxy(40, 5);
        color(Set[1]);
        cout << "<< ??? ?????? ??? ????????? ????? 1900?.>>";

        gotoxy(40, 6);
        color(Set[2]);
        cout << "<< ??? ?????? ??? ????????? ???? 1900?. >>";

        gotoxy(50, 7);
        color(Set[3]);
        cout << "<< ?????? ??????? >>";

        gotoxy(49, 8);
        color(Set[4]);
        cout << "<< ???????? ??????? >>";

        gotoxy(48, 9);
        color(Set[5]);
        cout << "<< ?????????? ??????? >>";

        gotoxy(46, 10);
        color(Set[6]);
        cout << "<< ?????????? ? ???? ??? >>" << endl;

        gotoxy(47, 11);
        color(Set[7]);
        cout << "<< ???????? ?????????? >>" << endl;

        printLine(35, 12);

        color(7);

        key = _getch();

        cout << endl << endl;
        if (key == 72 && (counter >= 2 && counter <= 8)) {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 7)) {
            counter++;
        }
        if (key == '\r') {
            //print all events option
            if (counter == 1) {
                system("CLS");
                printList(head);
            }
            //print events before 1900 option
            if (counter == 2) {
                system("CLS");
                printEventsBefore1900(head);

            }
            //print events after 1900 option
            if (counter == 3) {
                system("CLS");
                printEventsAfter1900(head);
            }
            //add event option
            if (counter == 4) {
                system("CLS");
                addNewEvent(head);
                system("CLS");
            }
            //remove event option
            if (counter == 5) {
                system("CLS");
                printList(head);
                removeEvent(head, positionToRemove(head));
                system("CLS");
            }
            //edit event option
            if (counter == 6) {
                system("CLS");
                printList(head);
                editEvent(head, positionToEdit(head));
                system("CLS");
            }
            //gray code option
            if (counter == 7) {
                system("CLS");
                cout << "????? ???? ????????????? ???? ??? ?? ????: " << decToGray() << endl;
                system("pause");
                system("CLS");
            }
            //stop the programme option
            if (counter == 8) {
                system("CLS");
                gotoxy(47, 4);
                cout << "?? ???? ?????! :)" << endl << endl;
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

    Event* Tail = new Event{ 16, 9, 1913, "??????? ? ??????????? ???????", NULL };
    Event* nineteenthEvent = new Event{ 28, 7, 1913, "??????? ? ????????? ??????? ?? ????????? ?? ????????? ???? ??????????? ?????", Tail };
    Event* eighteenthEvent = new Event{ 19, 5, 1913, "????????? ?? ???? ??????-??????? ???????", nineteenthEvent };
    Event* seventeenthEvent = new Event{ 17, 5, 1913, "????????? ?? ?????????? ????? ???????", eighteenthEvent };
    Event* sixteenthEvent = new Event{ 5, 10, 1912, "????????? ?? ??????????? ?????", seventeenthEvent };
    Event* fifteenthhEvent = new Event{ 29, 2, 1912, "???????? ? ??????????? ??????? ????? ???????? ? ??????", sixteenthEvent };
    Event* fourteenthEvent = new Event{ 22, 9, 1908, "????????? ?? ?????????????? ?? ????????", fifteenthhEvent };
    Event* thirteenthEvent = new Event{ 2, 8, 1903, "????????? ?? ??????????-????????????? ????????", fourteenthEvent };
    Event* twelfthEvent = new Event{ 9, 8, 1886, "???????? ??????? ????? ???? ?????????? 1", thirteenthEvent };
    Event* eleventhEvent = new Event{ 24, 3, 1886, "??????????? ??? ? ????????", twelfthEvent };
    Event* tenthEvent = new Event{ 19, 2, 1886, "??????? ? ????????? ???????", eleventhEvent };
    Event* ninthEvent = new Event{ 5, 11, 1885, "??????? ??? ????????", tenthEvent };
    Event* eightEvent = new Event{ 6, 9, 1885, "?????????? ?? ????????? ???????? ? ??????? ???????", ninthEvent };
    Event* seventhEvent = new Event{ 10, 2, 1885, "?????? ??????? ??????? ???? ??????? ? ??. ???????", eightEvent };
    Event* sixthEvent = new Event{ 1, 7, 1881, "??????? ? ??????? ?????? ??????? ????????", seventhEvent };
    Event* fifthEvent = new Event{ 27, 4, 1881, "???????? ? ???? ?? ???????? ???????", sixthEvent };
    Event* fourthEvent = new Event{ 5, 7, 1879, "????????? ? ??????? ????????? ????????????",fifthEvent };
    Event* thirdEvent = new Event{ 16, 4, 1879, "?????? ? ??????? ????????? ???????????", fourthEvent };
    Event* secondEvent = new Event{ 10, 2, 1879, "???????? ?? ??????????? ???????? ? ??. ?????? ???????", thirdEvent };
    Event* Head = new Event{ 3, 3, 1878, "????????? ?? ??? ????????? ????? ???????", secondEvent };

    printName();
    //waits until any button is pressed
    system("pause");
    //clears the screen
    system("CLS");
    //starts printing the menu
    printOptions(Head);

    return 0;
}
