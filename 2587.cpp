#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int arr[5] = {0};
    int sum = 0;
    int size = sizeof(arr) / sizeof(int);
    for(int i = 0; i < 5; i++)
        cin >> arr[i];
    
    for(int i = 0; i < 5; i++)
        sum += arr[i];
    
    sort(arr,arr + size);
    cout << sum / 5 << endl << arr[2];
    
}