#include <stdio.h>
#include <string.h>
#include <ctype.h>

void bracket_solver(const char* sentence) {
    int counter = 0;
    char brackets[] = "";
    
    for (int i = 0; i < strlen(sentence); i++) {
        if(sentence[i] == "{" ){
            brackets[counter]= sentence[i];
            counter++;
            
        }
        else if(sentence[i] == "("){
            brackets[counter]= sentence[i];
            counter++;
        }
        else if(sentence[i] == "["){
            brackets[counter]= sentence[i];
            counter++;
        }
        else if(sentence[i] == "}"){
            if(brackets[counter] == "{"){
                brackets[counter] == "";
                counter--;
            }
            else{
                printf("invalid brackets.");
            }
        }
        else if(sentence[i] == ")"){
            if(brackets[counter] == "("){
                brackets[counter] == "";
                counter--;
            }
            else{
                printf("invalid brackets.");
            }
        }
        else if(sentence[i] == "]"){
            if(brackets[counter] == "["){
                brackets[counter] == "";
                counter--;
            }
            else{
                printf("invalid brackets.");
            }
        }
    }
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    if (strlen(sentence) > 0 && sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';  // remove the newline character
    }
    printf(":: %s\n", sentence);
    bracket_solver(sentence);

    return 0;
}
