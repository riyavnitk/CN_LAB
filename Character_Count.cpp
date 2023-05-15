#include <bits/stdc++.h>
using namespace std;

void characterCountSenderFrame(string s) {
    int l = s.length();
    int headerCount = l + 1;
    string frame = (headerCount + "0") + s;
    cout << "Sender Frame: " << frame << endl;
}

void characterCountReceiverFrame(string s) {
    int header = s[0] - '0';
    string frame = s.substr(1, header - 1);
    cout << "Receiver Frame: " << frame << endl;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    characterCountSenderFrame(s);
    
    string rs;
    cout << "Enter the received string: ";
    cin >> rs;
    for(int i = 0; i < rs.length(); i++) {
        if(rs[i] - '0' >= 0 && rs[i] - '0' <= 9) {
            characterCountReceiverFrame(rs.substr(i, rs[i] - '0' + 1));
            i += rs[i] - '0';
        } else {
            cout << "Invalid Frame" << endl;
            break;
        }
    }
    return 0;
}