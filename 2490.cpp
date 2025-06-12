#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int num = 0;
    int count = 0;
    for(int q = 0; q < 3; q++)
    {
        count = 0;
        for(int i = 0; i < 4; i++)
        {
            num = 0;
            cin >> num;
            count += num;
        }
        if(count == 1)
            cout << 'C';
        else if(count == 2)
            cout << 'B';
        else if(count == 3)
            cout << 'A';
        else if(count == 4)
            cout << 'E';
        else
            cout << 'D';
        cout << "\n";
    }

}