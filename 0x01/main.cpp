#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + size);  // 오름차순 정렬

    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
}