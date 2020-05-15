#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ILYA EVDOKIMOV
// M3104

void prefixFunction(string& str, vector<int>& prefix) {
    prefix[0] = 0;

    for(int i = 1; i < str.length(); i++) {
        int k = prefix[i - 1];
        while(k > 0 && str[i] != str[k])
            k = prefix[k - 1];
        if(str[i] == str[k])
            k++;
        prefix[i] = k;
    }
}

void KMP_Automata(string &str, int power, vector<vector<int>>& result) {
    int len = str.length();
    vector<int> prefix(str.length());
    prefixFunction(str, prefix);

    for(int q = 0; q <= len; q++)
        for(int sym = 0; sym < power; sym++) {
            if(q > 0 && char(97 + sym) != str[q]) {
                result[q][sym] = result[prefix[q - 1]][sym];
            }
            else if(char(97 + sym) == str[q]) {
                result[q][sym] = q + 1;
            }
            else {
                result[q][sym] = q;
            }
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int power;
    string str;
    cin >> power >> str;

    vector<vector<int>> result(str.length() + 1, vector<int>(power));
    KMP_Automata(str, power, result);

    for(int i = 0; i <= str.length(); i++) {
        for(int j = 0; j < power; j++)
            cout << result[i][j] << ' ';
        cout << endl;
    }

    return 0;
}