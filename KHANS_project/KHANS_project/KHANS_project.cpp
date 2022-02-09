#include <iostream>
#include <math.h>
using namespace std;
struct Node {

    int data;
    Node* next;
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
void deleteNode(Node** head_ref, int key)
{
    Node* temp = *head_ref;
    Node* prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        delete temp;
    }
}
void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    int n;
    cin >> n;
    int gray = numToGray(n);
   

}