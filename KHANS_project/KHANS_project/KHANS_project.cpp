#include <iostream>
#include <math.h>
using namespace std;
struct Event {
    int day;
    int month;
    int year;
    string whatHappened;
    Event* next = NULL;
};

int decToBin(int n)
{
    int number = 0;
    int c = 0;
    while (n != 0)
    {
        number = number + ((n % 2) * pow(10, c));
        n = n / 2;
        c++;
    }
    return number;
}
int numToGray(int n)
{
    int value = decToBin(n);
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
    while (head != NULL)
    {
        cout << counter << " --> " << head->day << "." << head->month << "." << head->year << " " << head->whatHappened << endl;
        head = head->next;
        counter++;
    }
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

int findLinkedListLength(Event* head) {
    int counter = 1;
    while (head->next != NULL) {
        head = head->next;
        counter++;
    }
    return counter;
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

int main()
{
    int n;
    cin >> n;
    int gray = numToGray(n);
   

}