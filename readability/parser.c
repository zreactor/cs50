#include <stdio.h>
#include <readability.h>
#include <string.h>
#include <stdbool.h>

bool isSentenceEnderChar(char item);
bool inIntList(int item, int list[], int listLength);
float getScore(int words, int letters, int sentences);
bool isLetter(char c);


int END_SENTENCE_CHARS[] = {33, 46, 63};
const int LEN_END_SENTENCE_CHARS = 3;


int readabilityParser(char inputText[]) {

    int n = strlen(inputText);

    printf("We got this input... %s %i \n", inputText, n);

    int sentences = 0;
    int words = 0;
    int letters = 0;

    for (int i = 0; i < n; i++) {
        if ((int) inputText[i + 1] == 0) {
            // last character
            words ++;
            
        } else {
            if ((int) inputText[i] == 32) {
                // don't double-count double spaces
                if ((int) inputText[i + 1] == 32) {
                    continue;
                } else {
                    words ++;
                }
            } else if (isSentenceEnderChar(inputText[i])) {
                if (isSentenceEnderChar(inputText[i + 1])) {
                    continue;
                } else {
                    sentences ++;
                }
            } else {
                if (isLetter(inputText[i])) {
                    letters ++;
                } 
            }
        }  
    }
    printf("Words: %i \n", words);
    printf("Sentences: %i \n", sentences);
    printf("Letters: %i \n", letters);
    
    float score = getScore(words, letters, sentences);
    printf("Score: %f, %i \n", score, (int) (score + 0.5));

    return 0;
};

bool isLetter(char c) {
    if ((int) c >= 97 && (int) c <= 122) {
        return true;
    }
    if ((int) c >=65 && (int) c <= 90) {
        return true;
    }
    return false;
}

float getScore(int words, int letters, int sentences) {
    // L: the average number of letters per 100 words in the text
    // S: the average number of sentences per 100 words in the text

    float L = ((float) letters/words) * 100.0;
    float S = ((float) sentences)/words * 100.0;
    printf("L, S %f, %f\n", L, S);
    return (0.0588 * L - 0.296 * S - 15.8);
};



bool inIntList(int item, int *list, int listLength) {
    for (int i = 0; i < listLength; i++) {
        if (list[i] == item) return true;
    }
    return false;
};

bool isSentenceEnderChar(char item) {
    
    int *p = END_SENTENCE_CHARS;
    // const int *il[3] = &END_SENTENCE_CHARS;

    if (inIntList( (int) item, p, LEN_END_SENTENCE_CHARS)) {
        return true;
    }
    return false;
}
