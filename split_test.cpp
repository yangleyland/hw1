#include <iostream>
#include <cstddef>
#include "split.h"

using namespace std;

int main()
{
    Node* odds = NULL;
    Node* evens = NULL;

    Node* in = NULL;
    for (int i = 20; i > 0; i--)
    {
      Node* temp = new Node(i, in);
      in = temp;
    }
    cout<<"number list:"<<endl;
    Node* start=in;
    while (in->next!=NULL)
    {
      cout<<in->value<<endl;
      in=in->next;
    }
    cout<<in->value<<endl;
    split(start, odds, evens);

    cout << "odds: " << endl;
    Node* cur = odds;
    cout << cur->value << endl;
    while (cur->next != NULL)
    {
      Node* temp=cur->next;
      cout << cur->next->value << endl;
      delete cur;
      cur = temp;
    }
    delete cur;

    cout << "evens: " << endl;
    cur = evens;
    cout << cur->value << endl;
    while (cur->next != NULL)
    {
      Node* temp=cur->next;
      cout << cur->next->value << endl;
      delete cur;
      cur = temp;
    }
    delete cur;
    return 0;
}