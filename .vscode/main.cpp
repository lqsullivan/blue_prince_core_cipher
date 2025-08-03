#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std; 

int main(void) {
    // create dictionary to relate letter to number
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    // take input of word
    // TODO: max 5 letters
    string word_in;
    cout << "word to decipher" << endl;
    cin >> word_in;

    // generate indices of letters in word
    int word_indices[word_in.length()];
    for (int i = 0; i < word_in.length(); i++) {
        word_indices[i] = alphabet.find(word_in[i]) + 1;
    }

    // compute core ciphers
    // put one of +,-,*,/ between the numbers, no repeats
    // find the smallest positive integer that results
    int core_cipher = ((word_indices[0] + word_indices[1]) - word_indices[2]) * word_indices[3];

    // print word, length, and indices
    cout << "word       : " << word_in << endl;
    cout << "indices    : ";
    for (int ele : word_indices) {
        cout << ele << " ";
    }
    cout << endl;
    cout << "core cipher: " << core_cipher << endl;

    return 0;
}