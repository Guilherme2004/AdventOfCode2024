#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_SIZE 3

int extractNumber(char *arr, int *initialOffset){

    int numberOutput = 0;
    int *pNumbers = malloc(MAX_NUMBER_SIZE * sizeof(int));
    int numSize = 0;
    int numberOffset = 0;
    for(numberOffset = 0; numberOffset < MAX_NUMBER_SIZE; numberOffset++){
        int valueTest = arr[*initialOffset + numberOffset];
        if(valueTest >= 48 && valueTest <= 57){
            pNumbers[numberOffset] = valueTest - 48;
            numSize++;
        }else break;
    }
    if(!numSize){
        free(pNumbers);
        return 0;
    }
    for(int numI = 1; numI <= numSize; numI++){
        int power = 1;
        for(int p = 0; p < (numSize - numI); p++) power *= 10;
        numberOutput += pNumbers[numI - 1] * power;
    }
    *initialOffset += numberOffset;

    free(pNumbers);

    return numberOutput;
}

int main(){

    FILE *pInputFile = fopen("input.txt", "r");
    if(!pInputFile){
        printf("Error reading file!");
        return 1;
    }

    size_t stringSize = 1;
    size_t inputSize = 0;
    char *pString = malloc(stringSize);

    while(fgets(pString + inputSize, stringSize - inputSize, pInputFile)){
        inputSize += strlen(pString + inputSize);

        stringSize *= 2;
        char *newBuffer = realloc(pString, stringSize);
        if(!newBuffer){
            free(pString);
            break;
        }
        pString = newBuffer;

    }

    char *temp = realloc(pString, inputSize + 1);
    if(!temp){
        printf("Failed to allocate memory!");
        return 0;
    }
    pString = temp;

    int total = 0;
    int cond = 1;
    for(int i = 0; i < inputSize - 7; i++){

        if(pString[i] == 'd' && pString[i+1] == 'o' && pString[i+2] == '(' && pString[i+3] == ')') {
            cond = 1;
            continue;
        }
        if(pString[i] == 'd' && pString[i+1] == 'o' && pString[i+2] == 'n' && pString[i+3] == '\'' && pString[i+4] == 't' && pString[i+5] == '(' && pString[i+6] == ')') {
            cond = 0;
            continue;
        }

        if(!cond) continue;

        if(pString[i] == 'm' && pString[i+1] == 'u' && pString[i+2] == 'l' && pString[i+3] == '('){
            int leftN = 0;
            int rightN = 0;

            int offset = i+4;
            leftN = extractNumber(pString, &offset);
            if(!leftN) continue;

            if(pString[offset] != ',') continue;

            offset++;
            rightN = extractNumber(pString, &offset);
            if(!rightN) continue;

            if(pString[offset] != ')') continue;

            total += leftN * rightN;

        }
    }
    printf("Mull it Over: %d", total);

    free(pString);

    return 0;
}