#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std; 

// TODO: command line or i/o file, unit tests
// https://code.visualstudio.com/docs/sourcecontrol/intro-to-git 
// https://www.geeksforgeeks.org/dsa/print-all-possible-permutations-of-an-array-vector-without-duplicates-using-backtracking/
// https://stackoverflow.com/questions/11315854/input-from-command-line

string get_input_word() {
    // TODO: max 5 letters
    string word_in;
    cout << "word to decipher" << endl;
    cin >> word_in;

    return word_in;
}

vector<int> get_letter_numbers(string word) {
    // create dictionary to relate letter to number
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    // generate indices of letters in word
    vector<int> word_indices(word.length());
    for (int i = 0; i < word.length(); i++) {
        word_indices[i] = alphabet.find(word[i]) + 1;
    }

    return word_indices;
}

float do_operation(float a, int b, int op_index) {
    float out;

    if (op_index == 1) {
        out = a - b;
    } else if (op_index == 2) {
        out = a * b;
    } else if (op_index == 3) {
        // TODO: how to handle fractions correctly? just trust floats?
        out = a / b;
    } 
    // TODO: error handling for bad operator index?

    return out;
}

float do_core_cipher(vector<int> word_values, vector<int> operation_seq) {
    if (word_values.size() + 1 < operation_seq.size()) {
        throw logic_error("Not enough operations for word length");
    }

    float c = word_values[0];
    for (int i = 1; i < word_values.size(); i ++) {
        c = do_operation(c, word_values[i], operation_seq[i - 1]);
    }

    return c;
}

bool is_float_int(float value) {
    bool is_int; 
    return floor(value) == value;
}

float find_smallest_core_cipher(vector<int> word_values) {
    // over all permutations, get core cipher, return smallest above 0
    float smallest_core_cipher = 0;

    // treat each operation as an integer, make permutations of those integers
    string operation_perm = "123";
    do 
    {
        // store operation_permutation as vector
        vector<int> operation_perm_int(operation_perm.length());
        for (int i = 0; i < operation_perm.length(); i++) {
            operation_perm_int[i] = operation_perm[i] - '0';
        }
        // compute the core cipher
        float core_cipher = do_core_cipher(word_values, operation_perm_int);
        // identify smallest (0 is sentinel value for no answer)
        // only assign if it's a positive integer and smaller than the existing one
        if (is_float_int(core_cipher)) {
            if ((smallest_core_cipher == 0 & core_cipher > 0) or
                (core_cipher > 0 & core_cipher < smallest_core_cipher)) {
                smallest_core_cipher = core_cipher;
            }
        }
    }
    while (std::next_permutation(operation_perm.begin(), operation_perm.end()));

    return smallest_core_cipher;
}

int main(void) {
    // get input word
    string word_in = get_input_word();
    // turn word's letters into numbers
    vector<int> word_indices = get_letter_numbers(word_in);
    // find smallest of possible core ciphers
    float core_cipher = find_smallest_core_cipher(word_indices);

    // print word, length, and indices
    cout << "word       : " << word_in << endl;
    cout << "indices    : ";
    for (int ele : word_indices) {
        cout << ele << " ";
    }
    cout << endl;
    cout << "core cipher: " << core_cipher << endl;

    return core_cipher;
}