#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    cout << "word to decipher" << endl;

    string word_in;
    cin >> word_in;

    cout << "you entered " << word_in << endl;
    cout << "it\'s " << word_in.length() << " characters" << endl;

    return 0;
}