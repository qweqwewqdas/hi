#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int card[20] = {0};
    int j = 1;
    for(int i = 0; i < 20; i++)
    card[i] = j++;

    for(int i = 0; i < 10; i++)
    {
        int a,b;
        cin >> a >> b;
        int num = b-a;
        int temp = b;

        vector<int>arr(num+1);
        for(int i = 0; i < arr.size(); i++)
        {
            arr[i] = card[temp-1];
            temp--;
        }
        for(int j = 0; j <= num; j++)
        {
            card[a-1] = arr[j];
            a++;
        }
        
    }
    for(int i = 0; i < 20;i++)
        cout << card[i] << ' ';
}
