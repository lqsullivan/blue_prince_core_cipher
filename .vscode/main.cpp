#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std; 

// TODO: put on github, permutations of operators, command line or batch mode
// https://code.visualstudio.com/docs/sourcecontrol/intro-to-git 
// https://www.geeksforgeeks.org/dsa/print-all-possible-permutations-of-an-array-vector-without-duplicates-using-backtracking/
// https://stackoverflow.com/questions/11315854/input-from-command-line

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

int do_core_cipher(vector<int> word_values, vector<int> operation_seq) {
    if (word_values.size() + 1 < operation_seq.size()) {
        throw logic_error("Not enough operations for word length");
    }

    int c = word_values[0];
    for (int i = 1; i < word_values.size(); i ++) {
        c = do_operation(c, word_values[i], operation_seq[i - 1]);
    }

    return c;
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
    char core_cipher_letter;
    if (core_cipher < 26) {
        core_cipher_letter = alphabet[core_cipher];
    }
    // print word, length, and indices
    cout << "word       : " << word_in << endl;
    cout << "indices    : ";
    for (int ele : word_indices) {
        cout << ele << " ";
    }
    cout << endl;
    cout << "core cipher: " << core_cipher + 1 << endl;
    cout << "core letter: " << core_cipher_letter << endl;

    cout << "test operations: " << do_operation(3, 4, 1) << " " << do_operation(3, 4, 2) << " " << do_operation(3, 4, 3) << " " << do_operation(3, 4, 4) << endl;

    cout << "test core cipher: " << do_core_cipher({5, 2, 3}, {3, 2}) << endl;
    // treat each operation as an integer, make permutations of those integers
    // then index into the operations
    string perm = "1234";
    do 
    {
        for (char i : perm) {
            cout << i;
        }
        cout << "\n";
        // store permutation as vector
        vector<int> perm_int(perm.length());
        for (int i = 0; i < perm.length(); i++) {
            perm_int[i] = perm[i] - '0';
        }
    }
    while (std::next_permutation(perm.begin(), perm.end()));

    return 0;
}