#include <iostream>
using namespace std;

#define MAX1 1000000
#define MAX2 1000000
int main()
{
    int N,X;
    cin >> N;
    int arr[MAX1];
    bool same[MAX2] = {false};

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> X;

    int count = 0;

    for(int i = 0; i < N; i++)
    {
        int target = X - arr[i];
        if(target > 0 && target <= MAX1 && same[target])
            count++;
        
        same[arr[i]] = true;
    }
    cout << count << endl;
    return (0);
}