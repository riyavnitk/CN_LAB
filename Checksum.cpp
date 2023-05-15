#include <bits/stdc++.h>
using namespace std;

void checksum(int N, int arr[]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    sum = ~sum;
    cout << "Checksum: " << sum << endl;
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    int arr[N];
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    checksum(N, arr);
    return 0;
}