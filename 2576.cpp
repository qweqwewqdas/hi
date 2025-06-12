#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i;
    int count = 0;
    int sum = 0;
    vector<int>arr(7);
    int temp[7] = {0};
    int size = sizeof(temp) / sizeof(temp[0]);

    for(int q = 0; q < arr.size();q++)
        cin >> arr[q];
        
    for(i = 0; i < arr.size(); i++)
    {
        if(arr[i] % 2 != 0)
        {
            temp[count++] = arr[i];
        }
    }

    int minval = *min_element(temp,temp + count);
    for(i = 0; i < count; i++)
        sum += temp[i];
    cout << sum << endl << minval;

}