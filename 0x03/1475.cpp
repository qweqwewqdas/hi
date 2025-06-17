#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int set = 0;
    vector<int>num(10);
    string str  = to_string(N);

    for(int i = 0; i < str.size(); i++)
        num[str[i] - '0']++;

    int six_nine = num[6] + num[9];
    int six_nine_set = (six_nine + 1) / 2;

    num[6] = six_nine_set;
    num[9] = 0;
    for(int i = 0; i < num.size(); i++)
    {
        if(set < num[i])
            set = num[i];
    }
    cout << set << endl;
    
}