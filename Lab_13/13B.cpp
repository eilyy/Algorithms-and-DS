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

vector<int> KMP(string& pat, string& str) {
    int patLen = pat.length();
    int strLen = str.length();
    pat += '#' + str;
    vector<int> result;
    vector<int> prefix = prefixFunction(pat);

    for(int i = 0; i < strLen; i++)
        if(prefix[patLen + i + 1] == patLen)
            result.push_back(i + 2 - patLen);

    return result;
}

int main() {
    ifstream fin("search2.in");
    ofstream fout("search2.out");
    string str, pattern;
    fin >> pattern >> str;
    vector<int> result = KMP(pattern, str);

    fout << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
        fout << result[i] << ' ';

    return 0;
}