#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[9];
    int sum = 0;
    
    for(int i = 0; i < 9; i++)
        cin >> arr[i];

    for(int i = 0; i < 8; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            sum = 0;
            for(int k = 0; k < 9; k++)
            {
                if(k != i && k != j)
                    sum += arr[k];
            }
            
            if(sum == 100)
            {
                int selected[7];
                int idx = 0;
                
                for(int k = 0; k < 9; k++)
                {
                    if(k != i && k != j)
                        selected[idx++] = arr[k];
                }

                sort(selected, selected + 7);
                for(int k = 0; k < 7; k++)
                {
                    cout << selected[k] << endl;
                }
                return 0;
            }
        }
    }

    return 0;
}