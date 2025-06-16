#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
    int A,B,C;
    vector<int>arr(10);
    int result = 0;

    cin >> A >> B >> C;
    result = A*B*C;
    string str = to_string(result);

    for(int i = 0; i < str.size(); i++)
        arr[str[i] - '0']++;
    
    for(int i = 0; i < arr.size(); i++)
          cout << arr[i] << endl;
}