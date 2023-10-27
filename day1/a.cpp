#include <iostream>
using namespace std;



int main() {
    int n,pos =0;
    string pattern;
    cin >> pattern >> n;
    for (int i =0;i < pattern.size();i++) {
        if (pattern[i] == '*') {
            pos = i;
            break;
        }
    }
    

    for (int i =0;i < n;i ++) {

    }
    return 0;
}