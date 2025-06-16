#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int arr[26] = {0};
    string s;
    cin >> s;

    for(int i = 0; s[i] != '\0'; i++)
        arr[s[i] - 'a']++;
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
        cout << arr[i] << ' ';
}