#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // create dictionary to relate letter to number
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    // take input of word
    string word_in;
    cout << "word to decipher" << endl;
    cin >> word_in;

    // generate indices of letters in word
    int word_indices[word_in.length()];
    for (int i = 0; i < word_in.length(); i++) {
        word_indices[i] = alphabet.find(word_in[i]) + 1;
        cout << i << ": " << word_indices[i] << endl;
    }

    // print word, length, and indices
    cout << "you entered " << word_in << endl;
    cout << "it\'s " << word_in.length() << " characters" << endl;
    // for (int ele : word_indices) {
    //     cout << ele << " ";
    // }

    return 0;
}