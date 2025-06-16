#include <iostream>
using namespace std;

int main()
{
    int max;
    int arr[9];
    int index = 0;
    
    for(int i = 0; i < 9; i++)
        cin >> arr[i];
    
    max = arr[0];
    
    for(int i = 0; i < 9; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }
    for(int i = 0; i < 9; i++)
    {
        if(max == arr[i])
            break;
        index++;
    }
    cout << max << endl << index+1;
}