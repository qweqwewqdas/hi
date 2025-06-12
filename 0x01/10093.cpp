#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long A,B;
    long long num;
    cin >> A >> B;

    if(A > B)
    {
        long long temp = A;
        A = B;
        B = temp;
    }
    if(B - A <= 1)
        cout << 0 << "\n";
    else
        cout << B-A-1 << "\n";
    
    for(long long i = A + 1; i < B; i++)
        cout << i << ' ';
    cout << "\n";

    return (0);

}