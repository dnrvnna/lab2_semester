#include <iostream>

using namespace std;

void print_number(int n) //печать наоборот
{
    if(n >= 0 && n <= 9) cout << n;
    else
    {
        cout << n % 10;
        print_number(n / 10);
    }
}

int main()
{
    int n;
    cin >> n;

    print_number(n);
    return 0;
}