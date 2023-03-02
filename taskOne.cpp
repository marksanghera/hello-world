#include <iostream>
#include <fstream>
#include <array>
#include <iomanip>
#include "taskOne.h"

/**
 * Name: Mark Sanghera
 * Class: CPSC 122, Spring 2023
 * Date: February 26, 2023
 * Programming Assignment: PA4                                   
 * Description: This file implements functiosn to create a histogram
 * Notes:
**/

using namespace std;

void resetLetterOccurCounter(LetterOccurrence* letterOccurrence) {
    // reset letterOccurance back to zero
    for(int i = 0; i < (sizeof(letterOccurrence) / sizeof(LetterOccurrence)); i++) {
        letterOccurrence[i].count = 0;
        letterOccurrence[i].frequency = 0;
        letterOccurrence[i].isMax = false;
        cout << "Character: " << i << "Count: " << letterOccurrence[i].count << "Frequency: " << letterOccurrence[i].frequency << endl;
    }
}

void processString(const string s/*UserInput*/, LetterOccurrence letterOccs[]) {
    int currentMaxIndex = -1;
    for(int i = 0; i < s.size(); i++) {
       if(s[i] != ' ' && s[i] != '\t') { 
            int ascciiCode = s[i];
            letterOccs[ascciiCode].count++;
            letterOccs[ascciiCode].frequency = letterOccs[ascciiCode].count / (double)s.size();
            if(currentMaxIndex < 0 || letterOccs[currentMaxIndex].count < letterOccs[ascciiCode].count){
                currentMaxIndex = ascciiCode;
            }
       }
    }
    letterOccs[currentMaxIndex].isMax = true;
}

int getLetterWithMaximumOccurances(const LetterOccurrence letterOccs[]) {
    const LetterOccurrence* ptr = letterOccs;
    for(int i = 'A'; i <= 'z'; i++) {
        if(letterOccs[i].isMax){
            return i;
        }
    }
    return 0;
}

void computeMaximumOccurences(const LetterOccurrence letterOccs[], char* c/*char with max occurances*/, int* count /*maxOccurance*/, double* freq/*maxFrequency*/) {
    int maxOccurenceIndex = getLetterWithMaximumOccurances(letterOccs);
    *c = maxOccurenceIndex;
    *count = letterOccs[maxOccurenceIndex].count;
    *freq = letterOccs[maxOccurenceIndex].frequency; 
}

void printHistogram(LetterOccurrence LetterOccurrence[], int maxOccurances) {
    for(int i = maxOccurances; i > 0; i--) {
        for(int j = 'A'; j <= 'z'; j++) {
            if(j < 'a' && j > 'Z') {
                continue;
            }
            if(i <= LetterOccurrence[j].count) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << endl;
    }
    cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" << endl;
}


void taskOne() {
    string userInput;
    LetterOccurrence letterOccurrence[123];
    int maxOccurrences = 0;
    char charWithMaxOccurances = 0; 
    double maxFrequency = 0;


    do {
        // Step 1: Propmt the user for a string
        cout << "Give me a string or I will self destruct." << endl;
        getline(cin, userInput);

        if(userInput == "quit") {
            break;
        } 

        // reset letterOccurance back to zero
        for(int i = 'A'; i <= 'z'; i++) {
            letterOccurrence[i].count = 0;
            letterOccurrence[i].frequency = 0;
            letterOccurrence[i].isMax = false;
        }
        // Step 2: Proccess the String and compute max occurrences
        processString(userInput, letterOccurrence);
        computeMaximumOccurences(letterOccurrence, &charWithMaxOccurances, &maxOccurrences, &maxFrequency);
        
        // Step 3: Print the Histogram
        printHistogram(letterOccurrence, maxOccurrences);
        
        /* Step 4: print The letter with the maximum number of occurrences
            The number of occurrences of the letter with the maximum number of occurrences
            The frequency of the letter with the maximum number of occurrences 
        */
        cout << "Letter with the max number of occurrences: " << charWithMaxOccurances << endl
            << "Number of occurances: " << maxOccurrences << endl
            << "Frequency of the letter: " << setprecision(5) << " " << maxFrequency << endl;
        
    } while(1); 


}