#include <iostream>
using namespace std;
//вариант 3

struct Node
{
    int info;
    Node * prev;
    Node * next;
};
void AddBack(Node * sent, int info)//добавление узлов в конец
{
    Node * p = new Node;
    p -> info = info;
    p -> prev = sent -> prev;
    p -> next = sent;
    sent -> prev -> next = p;
    sent -> prev = p;
}
void Print(Node * sent)
{
    Node * p = sent -> next;
    while(p != sent)
    {
        cout << p -> info << endl;
        p = p -> next;
    }
}
void Clear(Node * sent)
{
    Node * p = sent -> next;
    while(p != sent)
    {
        Node * tmp = p;
        p = p -> next;
        delete tmp;
    }
    sent->next = sent;
    sent->prev = sent;
}

bool OnlyOdd(int n)//проверка на содержание только нечётных цифр
{
    while(n != 0)
    {
        int d = n % 10;
        if(d % 2 == 0) return false;
        n = n / 10;
    }
    return true;
}
bool OnlyEven(int n)//проверка на содержание только чётных цифр
{
    while(n != 0)
    {
        int d = n % 10;
        if(d % 2 != 0) return false;
        n = n / 10;
    }
    return true;
}
bool IsPrime(int n)//проверка на простое число
{
    if( n == 1) return false;

    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

void DeleteOdd(Node * sent)//удаление узлов с числами, состоящих из нечетных цифр
{
    Node * p = sent -> next;
    while(p != sent)
    {
        if(OnlyOdd(p -> info))
        {
            Node * tmp = p;
            p -> next -> prev = p -> prev;
            p -> prev -> next = p -> next;
            p = p -> next;
            delete tmp;
        }
        else
            p = p -> next;  
    }
}
void DuplicateEven(Node * sent)//дублирование узлов, состоящих из чётных цифр
{
    Node * p = sent -> next;
    while(p != sent)
    {
        if(OnlyEven(p -> info))
        {
            Node * q = new Node;
            q -> info = p -> info;
            q -> next = p -> next;
            q -> prev = p;
            p -> next = q;
            q -> next -> prev = q;
            p = q -> next;
        }
        else
            p = p -> next;
    }

}
void Sorted(Node * sent)//сортировка по невозрастанию
{
    for(Node * p = sent -> next; p -> next != sent; p = p -> next)
    {
        for(Node * q = p -> next; q != sent; q = q -> next)
        {
            if(p -> info < q -> info) swap(p -> info, q -> info);
        }
    }
}
bool HasPrime(Node * sent)
{
    for(Node * p = sent -> next; p != sent; p = p -> next)
        {
            if(IsPrime(p -> info)) return true;
        }
    return false;
}

int main()
{
    Node * sent = new Node;
    sent->next = sent;
    sent->prev = sent;

    int n;
    cin >> n; //

    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        AddBack(sent, x);
    }

    if(!HasPrime(sent))
    {
        Sorted(sent);
    }
    else
    {
        DeleteOdd(sent);
        DuplicateEven(sent);
    }
    Print(sent);

    Clear(sent);
    delete sent;
    return 0;
}