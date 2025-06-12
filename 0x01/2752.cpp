#include <iostream>
#include <vector>
using namespace std;
int main() {
    int min;
    vector<int> arr(3);
    for (int i = 0; i < 3; i++) 
        cin >> arr[i];
    min = arr[0];

    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < 3; i++)
        {
            if(arr[i] > arr[i+1] && i+1 < 3)
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    for(int q = 0; q < 3; q++)
        cout << arr[q] << " ";   
}