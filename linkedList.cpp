#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;

void insertBegin(int x)
{
    node *newNode;
    newNode = new node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertAfter(int x, int after)
{
    node *temp = head;
    node *newNode = new node();
    if (head == NULL)
    {
    }
    while (temp->data != after && temp->next != NULL)
    {
        if (temp->data == after)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (temp->next == NULL)
    {
        return;
    }
}

void insertBefore(int x, int before)
{
    node *temp1 = new node();
    node *temp2 = new node();
    temp1 = head;
    while (temp1->data != before && temp1->next != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (temp1->next == NULL)
    {
        return;
    }
    else
    {
        node *newNode = new node();
        temp2->next = newNode;
        newNode->next = temp1;
        newNode->data = x;
    }
}

void insertEnd(int x)
{
    node *newNode;
    newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteStart()
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteEnd()
{
    if (head == NULL)
    {
        return;
    }
    else if(head->next == NULL){
        free(head);
    }
    else
    {
        node *temp = head;
        node *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

void deleteKey(int key)
{
    node *temp = head;
    node *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
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
        {
            return;
        }
        else
        {
            prev->next = temp->next;
            free(temp);
        }
    }
}

void deleteIndex(int index)
{

    node *temp;
    node *prev;
    temp = head;
    prev = head;
    for (int i = 0; i < index; i++)
    {
        if (i == 0 && index == 1)
        {
            head = (head)->next;
            free(temp);
        }
        else
        {
            if (i == index - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev = temp;
                if (prev == NULL)
                {
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void deleteAfter(int after)
{
    node *temp = head;
    node *prev = NULL;
    while (temp->data != after && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteBefore(int before)
{
    node *temp = head;
    node *mid = NULL;
    node *prev = NULL;
    while (temp->data != before && temp->next != NULL)
    {
        prev = mid;
        mid = temp;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        return;
    }
    free(mid);
    prev->next = temp;
}

void printList()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << "--->" << temp->data;
        temp = temp->next;
    }
}

int main(void)
{
    insertBegin(1);
    insertBegin(2);
    printList();
    insertAfter(3, 2);
    printList();
}