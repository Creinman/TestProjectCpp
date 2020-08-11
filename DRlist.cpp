#include <iostream>
using namespace std;
 
struct DoubleList //�������� ���� ������
{
    int data; //�������������� ����
    DoubleList *next; //��������� �� ��������� �������
    DoubleList *prev; //��������� �� ���������� �������
};
 
 
void AddList(int value, int position);
int DeleteList(int position);
void PrintList();
void DeleteListKTimes(int k);
 
void main()
{
    setlocale(LC_ALL, "Rus");
    int value, position, x, n, k;
    do
    {
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. ������� ������" << endl;
        cout << "4. �������� ��������� ��������� �����" << endl;
        cout << "5. ������� � ����� ������ k ���������" << endl;
        cout << "0. �����" << endl;
        cout << "\n����� �������� > "; cin >> x;
        switch (x)
        {
        case 1:
            cout << "������� > "; cin >> position;
            cout << "�������� > "; cin >> value;
            AddList(value, position); break;
        case 2:
            cout << "������� > "; cin >> position;
            DeleteList(position); break;
        case 3:
            PrintList(); break;
        case 4:
            cout << "������� ��������� �� ������ �������� � ������ > "; cin >> n;
            for (int i = 0;i < n;i++)
            {
                cout << "������� > "; cin >> position;
                cout << "�������� > "; cin >> value;
                AddList(value, position);
            } break;
        case 5:
            cout << "������� ��������� �� ������ ������� �� ����� ������ > "; cin >> k;
            DeleteListKTimes(k); break;
        }
    } while (x != 0);
}
 
DoubleList *head; //���������� ���������� (��������� �� ������ ������� ������)
 
void AddList(int value, int position)
{
    DoubleList *node = new DoubleList; //�������� ������ ��������
    node->data = value; //���������� �������� ��������
    if (head == NULL) //���� ������ ����
    {
        node->next = node; //��������� ��������� next
        node->prev = node; //��������� ��������� prev
        head = node; //������������ ������ ������
    }
    else
    {
        DoubleList *p = head;
        for (int i = position; i>1; i--) p = p->next;
        if (position == 1) head = node;
        p->prev->next = node;
        node->prev = p->prev;
        node->next = p;
        p->prev = node;
    }
    cout << "\n������� ��������...\n\n";
}
//***********************�������� ��������***********************
int DeleteList(int position)
{
    if (head == NULL) { cout << "\n������ ����\n\n"; return 0; }
    if (head == head->next)
    {
        delete head;
        head = NULL;
    }
    else
    {
        DoubleList *a = head;
        for (int i = position; i>1; i--) a = a->next;
        if (a == head) head = a->next;
        a->prev->next = a->next;
        a->next->prev = a->prev;
        delete a;
    }
    cout << "\n������� ������...\n\n";
   return 1;
}
//*************************����� ������*************************
void PrintList()
{
    if (head == NULL) cout << "\n������ ����\n\n";
    else
    {
        DoubleList *a = head;
        cout << "\n�������� ������: ";
        do
        {
            cout << a->data << " ";
            a = a->next;
        } while (a != head); cout << "\n\n";
    }
}
void DeleteListKTimes(int k)
{
    DoubleList *a = head;
    int i = 0;
    do
    {
        i++;
        a = a->next;
    } while (a != head);
    for (int n = 0;n < k;n++)
    {
        if (i <= 0)
            break;
        DeleteList(i);
        i--;
    }
}