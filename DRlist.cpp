#include <iostream>
using namespace std;
 
struct DoubleList //описание узла списка
{
    int data; //информационное поле
    DoubleList *next; //указатель на следующий элемент
    DoubleList *prev; //указатель на предыдущий элемент
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
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Вывести список" << endl;
        cout << "4. Добавить несколько элементов сразу" << endl;
        cout << "5. Удалить с конца списка k элементов" << endl;
        cout << "0. Выйти" << endl;
        cout << "\nНомер операции > "; cin >> x;
        switch (x)
        {
        case 1:
            cout << "Позиция > "; cin >> position;
            cout << "Значение > "; cin >> value;
            AddList(value, position); break;
        case 2:
            cout << "Позиция > "; cin >> position;
            DeleteList(position); break;
        case 3:
            PrintList(); break;
        case 4:
            cout << "Сколько элементов вы хотите добавить в список > "; cin >> n;
            for (int i = 0;i < n;i++)
            {
                cout << "Позиция > "; cin >> position;
                cout << "Значение > "; cin >> value;
                AddList(value, position);
            } break;
        case 5:
            cout << "Сколько элементов вы хотите удалить из конца списка > "; cin >> k;
            DeleteListKTimes(k); break;
        }
    } while (x != 0);
}
 
DoubleList *head; //глобальная переменная (указатель на первый элемент списка)
 
void AddList(int value, int position)
{
    DoubleList *node = new DoubleList; //создание нового элемента
    node->data = value; //присвоение элементу значения
    if (head == NULL) //если список пуст
    {
        node->next = node; //установка указателя next
        node->prev = node; //установка указателя prev
        head = node; //определяется голова списка
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
    cout << "\nЭлемент добавлен...\n\n";
}
//***********************УДАЛЕНИЕ ЭЛЕМЕНТА***********************
int DeleteList(int position)
{
    if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
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
    cout << "\nЭлемент удален...\n\n";
   return 1;
}
//*************************ВЫВОД СПИСКА*************************
void PrintList()
{
    if (head == NULL) cout << "\nСписок пуст\n\n";
    else
    {
        DoubleList *a = head;
        cout << "\nЭлементы списка: ";
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