#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int space;
    int star;
    int temp1 = N;
    int temp2 = N;
    for(int i = 0; i < N; i++)
    {
        star = (2 * temp1)-1;
        space = i;

        for(int k = 0; k < space; k++)
            cout << ' ';
        for(int i = 0; i < star; i++)
            cout << '*';
        cout << endl;
        temp1--;
    }
    for(int i = 0; i < N-1; i++)
    {
        star += 2;
        --space;
        for(int k = 0; k < space; k++)
            cout << ' ';
        for(int i = 0; i < star; i++)
            cout << '*';
        cout << endl;

    }
}