#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int M = 0;
    int Y = 0;

    for(int i = 0; i < N; i++)
    {
        int t;
        cin >> t;

        Y += ((t/30)+1) * 10;
        M += ((t/60)+1) * 15;
    }
    if(M < Y)
        cout << 'M' << ' '<< M;
    else if(M > Y)
        cout << 'Y' << ' ' << Y;
    else
        cout << 'Y' <<' '<< 'M' << ' ' << M;
    
    cout << endl;
    return (0);
}