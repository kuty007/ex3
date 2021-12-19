#include <stdio.h>
#include <string.h>

#define WORD 30
#define TXT 1025

int toLowerCase(char c)
/**
 * Function to return a lowercase letter from input (convert uppercase to lowercase if needed), return ASCII value of letter
 * If letter is not from the english ABC, return 0
 * @param c
 * @return
 */

{
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 1;
    }
    return 0;
}

int valueOfWord(char arr[WORD]) {
    int sum = 0;
    for (int i = 0; i < strlen(arr); i++) {
        sum += toLowerCase(arr[i]);
    }
    return sum;
}

void compareASCII(char word[], char text[]) {
    int wantedValue = valueOfWord(word);
    printf("Gematria Sequences: ");
    int firstIter = 0;
    for (int i = 0; i < strlen(text); i++) {
        int tempSum = 0;
        if (toLowerCase(text[i]) != 0) {
            for (int j = i; j < strlen(text); j++) {
                tempSum += toLowerCase(text[j]);
                if (tempSum == wantedValue) {
                    if (firstIter != 0) {
                        printf("~");
                        for (int k = i; k <= j; k++) {
                            printf("%c", text[k]);
                        }
                    }
                    if (firstIter == 0) {
                        for (int k = i; k <= j; k++) {
                            printf("%c", text[k]);
                        }
                    }
                    firstIter++;
                    break;
                }
                if (tempSum > wantedValue) {
                    break;
                }
            }
        }
    }
    printf("\n");
}

void *atbash(char *word, char *ret) {
    int i = 0;
    for (; i < strlen(word); i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            ret[i] = 'z' - (word[i] - 'a');
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            ret[i] = 'Z' - (word[i] - 'A');
        } else {
            ret[i] = word[i];
        }
    }
    ret[i] = '\0';
}

void textContainsAtbashSequence(char word[], char text[]) {
    int count = strlen(word);


    char atba[strlen(word) + 1];
    atbash(word, atba);
    int firstIter = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (toLowerCase(text[i]) != 0) {
            char tempWord[strlen(text) + 1];
            tempWord[strlen(text)] = '\0';
            for (int k = 0; k < strlen(text); k++) {
                tempWord[k] = '\0';
            }
            int j = i;
            int counterCopy = count;

            char tempWord2[strlen(text) + 1];
            tempWord2[strlen(text)] = '\0';
            for (int k = 0; k < strlen(text); k++) {
                tempWord2[k] = '\0';
            }
            int j2 = i;
            int counterCopyRev = count;
            int flagInOrder = 0;
            int flagReverseOrder = 0;

            while (counterCopy != 0 && counterCopyRev != 0 && (flagInOrder == 0 || flagReverseOrder == 0)) {
                if (flagInOrder == 0) {
                    int temp = toLowerCase(text[j]);
                    if (temp != 0) //if text[j] is a letter
                    {
                        if (text[j] != atba[count - counterCopy]) {
                            flagInOrder = 1;
                        }
                        if (flagInOrder == 0) counterCopy--;
                    }
                    if (flagInOrder == 0) {
                        tempWord[j - i] = text[j];
                        if (counterCopy == 0) {
                            if (firstIter == 0) {
                                printf("%s", tempWord);
                            } else {
                                printf("~%s", tempWord);
                            }
                            firstIter++;
                            flagInOrder = 1;
                        }
                        j++;
                    }
                }

                if (flagReverseOrder == 0) {
                    int temp2 = toLowerCase(text[j2]);
                    if (temp2 != 0) //if text[j] is a letter
                    {
                        char toCheck = atba[strlen(atba) - (count - counterCopyRev) - 1];
                        if (text[j2] != toCheck) {
                            flagReverseOrder = 1;
                        }
                        if (flagReverseOrder == 0) counterCopyRev--;
                    }
                    if (flagReverseOrder == 0) {
                        tempWord2[j2 - i] = text[j2];
                        if (counterCopyRev == 0) {
                            if (firstIter == 0) {
                                printf("%s", tempWord2);
                            } else {
                                printf("~%s", tempWord2);
                            }
                            firstIter++;
                            flagReverseOrder = 1;
                        }
                        j2++;
                    }
                }
            }
        }
    }
    printf("\n");
}

void anagram(char word[], char text[]) {
    printf("Anagram Sequences: ");
    int firstIter = 0;
    for (int i = 0; i < strlen(text); i++) {
        char copyWord[strlen(text) + 1];
        strcpy(copyWord, word);
        char tempWord[strlen(text) - i + 1];
        for (int j = 0; j < strlen(text) - i + 1; j++) {
            tempWord[j] = '\0';
        }

        for (int j = i; j < strlen(text); j++) {
            if (toLowerCase(text[i]) != 0) {
                char *ptrIndexOf = strchr(copyWord, text[j]);
                if ((text[j] == ' ' || ptrIndexOf != NULL) && strlen(copyWord) != 0) {
                    tempWord[j - i] = text[j];
                } else {
                    break;
                }
                if (ptrIndexOf != NULL) {
                    int indToDel = ptrIndexOf - copyWord;
                    for (int k = indToDel + 1; k < (strlen(copyWord) + 1); k++) {
                        copyWord[k - 1] = copyWord[k];
                    }
                }
                if (strlen(copyWord) == 0) {
                    if (firstIter == 0) {
                        printf("%s", tempWord);
                    } else {
                        printf("~%s", tempWord);
                    }
                    firstIter++;
                }
            }
        }
    }
}

int main() {
    char arr[TXT + WORD];
    char word[WORD];
    char text[TXT];

    scanf("%[^~]s", &arr);

    int i = 0;
    for (; arr[i] != ' ' && arr[i] != '\n' && arr[i] != '\t'; i++) {
        word[i] = arr[i];
    }
    word[i] = '\0';

    int j = 0;
    for (; arr[i] != '\0'; i++) {
        text[j] = arr[i];
        j++;
    }
    text[j] = '\0';
    compareASCII(word, text);
    printf("Atbash Sequences: ");
    textContainsAtbashSequence(word, text);
    anagram(word, text);
    return 0;
}
