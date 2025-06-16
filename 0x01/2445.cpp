#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int space;
    int star;
    int temp = N;

    for(int i = 0; i < N; i++)
    {
        star = (1 * i) + 1;
        space = (2 * temp) - 2;

        for(int i = 0; i < star; i++)
            cout << '*';
        for(int k = 0; k < space; k++)
            cout << ' ';
        for(int i = 0; i < star; i++)
            cout << '*';
        cout << endl;
        temp--;
    }
    for(int i = 0; i < N; i++)
    {
        --star;
        space = (2 * temp) + 2;

        for(int j = 0; j < star; j++)
            cout << '*';
        for(int k = 0; k < space; k++)
            cout << ' ';
        for(int j = 0; j < star;j++)
            cout << '*';
        cout << endl;
        temp++;
    }
}