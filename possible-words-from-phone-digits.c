/*
Author: Manohar Mukku
Date: 01.08.2018
Desc: GeeksforGeeks - Arrays - Find the fine
Link: https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits/0/
*/

#include <stdio.h>
#include <stdlib.h>

#define TOT_DIGITS 8
#define MAX_N 6
#define MAX_CHARS 4

void print_possible_words(char possible_chars[TOT_DIGITS][MAX_CHARS], int* digits, int n, int curr_pos, char* answer) {
    if (curr_pos < n) {
        int curr_digit = digits[curr_pos];

        int i;
        for (i = 0; i < MAX_CHARS; i++) {
            if (possible_chars[curr_digit-2][i] != 0) {
                answer[curr_pos] = possible_chars[curr_digit-2][i];
                print_possible_words(possible_chars, digits, n, curr_pos+1, answer);
            }
        }
    }
    else {
        answer[curr_pos] = '\0';
        printf("%s ", answer);
    }
}

int main() {
    int t;
    scanf ("%d", &t);

    while (t--) {
        int n;
        scanf ("%d", &n);

        int* digits = (int*)calloc(n, sizeof(int));

        int i;
        for (i = 0; i < n; i++)
            scanf ("%d", &digits[i]);

        char possible_chars[TOT_DIGITS][MAX_CHARS] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

        char* answer = (char*)calloc(MAX_N, sizeof(char));

        print_possible_words(possible_chars, digits, n, 0, answer);
        printf("\n");

        free(digits);
    }

    return 0;
}