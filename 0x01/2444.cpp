#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int star;
    int space;
    for(int i = 1;i <= N; i++)
    {
        space = N - i;
        star = (2 * i) - 1;
        for(int j = 0; j < space; j++)
            cout << ' ';
        for(int k = 0; k < star; k++)
            cout << '*';
        cout << endl;
    }
    int temp = N;
    for(int i = 1; i < N; i++)
    {
        space = i;
        star = (2 * --temp) - 1;
        for(int j = 0; j < space; j++)
            cout << ' ';
        for(int k = 0; k < star; k++)
            cout << '*';
        cout << endl;
    }
}