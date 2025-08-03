#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std; 

int do_operation(int a, int b, int op_index) {
    int out;

    if (op_index == 1) {
        out = a + b;
    } else if (op_index == 2) {
        out = a - b;
    } else if (op_index == 3) {
        out = a * b;
    } else if (op_index == 4) {
        // TODO: how to handle fractions correctly? just trust floats?
        out = a / b;
    } 
    // TODO: error handling for bad operator index?

    return out;
}

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

    cout << "test operations: " << do_operation(3, 4, 1) << " " << do_operation(3, 4, 2) << " " << do_operation(3, 4, 3) << " " << do_operation(3, 4, 4) << endl;

    return 0;
}