#include <stdio.h>
#include <string.h>
#include <ctype.h>

void bracket_solver(const char* sentence) {
    int counter = 0;
    int invalid_counter = 0;
    char brackets[] = "";
    char invalid_brackets[] = "";
    printf("sentence length: %i\n",strlen(sentence));
    int sen_len = sizeof(sentence);
    for (int i = 0; i < sen_len; i++) {
        printf("char: %c\n", sentence[i]);
        if(sentence[i] == 123){
            brackets[counter]= sentence[i];
            counter++;
            
        }
        else if(sentence[i] == 40){
            brackets[counter]= sentence[i];
            counter++;
        }
        else if(sentence[i] == 91){
            brackets[counter]= sentence[i];
            counter++;
        }
        else if(sentence[i] == 125){
            counter--;
            if(brackets[counter] == 123){
                brackets[counter] = 0;
                
            }
            else{
                printf("invalid brackets.");
                invalid_brackets[invalid_counter] = sentence[i];
                invalid_counter++;
            }
        }
        else if(sentence[i] == 41){
            counter--;
            if(brackets[counter] == 40){              
                brackets[counter]= 0;
            }
            else{
                printf("invalid brackets.\n");
                invalid_brackets[invalid_counter] = sentence[i];
                invalid_counter++;
            }
        }
        else if(sentence[i] == 93){
            counter--;
            if(brackets[counter] == 91){
                brackets[counter] = 0;
                
            }
            else{
                printf("invalid brackets.");
                invalid_brackets[invalid_counter] = sentence[i];
                invalid_counter++;
            }
        }
       
    }
    printf("Counter: %i\n", counter);
    printf("Final opening bracket list: %s\n", brackets);
    printf("Invalid bracket list: %s\n", invalid_brackets);
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
