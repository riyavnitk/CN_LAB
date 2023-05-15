#include <bits/stdc++.h>
using namespace std;

vector<int> generateHammingCode(vector<int> msgBits, int m, int r) {
	vector<int> hammingCode(r + m);
	for (int i = 0; i < r; ++i) {
		hammingCode[pow(2, i) - 1] = -1;
	}
	int j = 0;
	for (int i = 0; i < (r + m); i++) {
		if (hammingCode[i] != -1) {
			hammingCode[i] = msgBits[j];
			j++;
		}
	}
	for (int i = 0; i < (r + m); i++) {
		if (hammingCode[i] != -1)
			continue;
		int x = log2(i + 1);
		int one_count = 0;
		for (int j = i + 2;
			j <= (r + m); ++j) {
			if (j & (1 << x)) {
				if (hammingCode[j - 1] == 1) {
					one_count++;
				}
			}
		}
		if (one_count % 2 == 0) {
			hammingCode[i] = 0;
		} else {
			hammingCode[i] = 1;
		}
	}
	return hammingCode;
}

vector<int> findHammingCode(vector<int>& msgBit) {
	int m = msgBit.size();
	int r = 1;
	while (pow(2, r) < (m + r + 1)) {
		r++;
	}
	vector<int> ans = generateHammingCode(msgBit, m, r);
	cout << "\nMessage bits are: ";
	for (int i = 0; i < msgBit.size(); i++)
		cout << msgBit[i] << " ";
	cout << "\nHamming code is: ";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
    return ans;
}

void receiver(vector<int> hammingCode) {
    int r = 1;
    while (pow(2, r) < hammingCode.size()) {
        r++;
    }
    vector<int> errorBit(r);
    for (int i = 0; i < r; i++) {
        int parity = 0;
        for (int j = 0; j < hammingCode.size(); j++) {
            if (((j + 1) & (1 << i)) != 0) {
                if (hammingCode[j] == 1) {
                    parity = parity ^ 1;
                }
            }
        }
        errorBit[i] = parity;
    }
    int errorPos = 0;
    for (int i = 0; i < errorBit.size(); i++) {
        errorPos += errorBit[i] * pow(2, i);
    }
    if (errorPos != 0) {
        cout << "\nError at position: " << errorPos;
        hammingCode[errorPos - 1] = !hammingCode[errorPos - 1];
        cout << "\nCorrected hamming code is: ";
        for (int i = 0; i < hammingCode.size(); i++) {
            cout << hammingCode[i] << " ";
        }
    } else {
        cout << "\nNo error";
    }
}

int main() {
    int n; cout << "\nEnter the number of bits: "; cin >> n;
	vector<int> msgBit(n);
	cout << "Enter the " << n << "-bit codeword: " << endl;
	for(int i = 0; i < n; i++) cin >> msgBit[i];
	vector<int> receivedCode = findHammingCode(msgBit);
	receiver(receivedCode);
	return 0;
}

