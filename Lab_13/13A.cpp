#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> nativeStringMatcher(string& p, string& s) {
    int pLen = p.length();
    int sLen = s.length();
    vector<int> entry;
    for(int i = 0; i <= sLen - pLen; i++)
        if(s.substr(i, pLen) == p)
            entry.push_back(i + 1);
    return entry;
}

int main() {
    ifstream fin("search1.in");
    ofstream fout("search1.out");
    string pattern, str;
    fin >> pattern >> str;
    vector<int> result = nativeStringMatcher(pattern, str);
    fout << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
        fout << result[i] << ' ';
    return 0;
}