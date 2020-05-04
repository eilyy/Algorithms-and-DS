#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> prefixFunction(string& s) {
    vector<int> prefix(s.length());
    prefix[0] = 0;

    for(int i = 1; i < s.length(); i++) {
        int k = prefix[i - 1];
        while(k > 0 && s[i] != s[k])
            k = prefix[k - 1];
        if(s[i] == s[k])
            k++;
        prefix[i] = k;
    }

    return prefix;
}

int main() {
    ifstream fin("search1.in");
    ofstream fout("search1.out");
    string str;
    fin >> str;
    vector<int> result = prefixFunction(str);

    for(int i = 0; i < result.size(); i++)
        fout << result[i] << ' ';

    return 0;
}