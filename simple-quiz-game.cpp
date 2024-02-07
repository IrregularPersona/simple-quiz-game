#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define Slight_delay 1.5
#define Longer_delay 2.5

void scoreCount(int score) {
    float finalScore = ((float)score /  5) *  100;
    printf("Your final score is %.2f%%\n", finalScore);
    sleep(Longer_delay);
}

void clearScreen() {
    system("cls"); 
}

void quizSection() {
    clearScreen();
    int score =  0;
    
    const char* questions[] = {
        "1. What's the short form version of 'Local Area Network'?",
        "2. What file extension is commonly associated with executable files in Windows?",
        "3. What's the short form version of 'Central Processing Unit'?",
        "4. What's the short form version of 'Solid State Drive'?",
        "5. What's the short form version of 'Random Access Memory'?"
    };
    const char* answers[] = {
        "lan",
        "exe",
        "cpu",
        "ssd",
        "ram"
    };
    
    for (int i =  0; i <  5; ++i) {
        printf("%s\n>> ", questions[i]);
        char answer[20];
        scanf(" %19s", answer);
        
        for (int j =  0; answer[j]; ++j) {
            answer[j] = tolower(answer[j]);
        }
        
        if (strcmp(answer, answers[i]) ==  0) {
            printf("\nCorrect! On to the next one!\n");
            score++;
            sleep(Slight_delay);
        } else {
            printf("\nOops, you didn't get it right! It's okay, on to the next one!\n");
            sleep(Slight_delay);
        }
        
        clearScreen();
    }
    
    scoreCount(score);
}

int main() {
    int playAgain =  1;

    while (playAgain) {
        clearScreen();
        printf("Welcome to a computer quiz!\n");

        char choice[5];
        printf("Do you want to play? (yes/no)\n>> ");
        scanf("%4s", choice);

        for (int i =  0; choice[i]; i++) {
            choice[i] = tolower(choice[i]);
        }

        if (strcmp(choice, "no") ==  0) {
            printf("Are you sure? (yes/no)\n>> ");
            scanf("%4s", choice);
            for (int i =  0; choice[i]; i++) {
                choice[i] = tolower(choice[i]);
            }

            if (strcmp(choice, "yes") ==  0) {
                printf("Thanks for playing!\n");
                playAgain =  0;
            } else {
                printf("Please enter 'yes' or 'no'.\n");
            }
        } else if (strcmp(choice, "yes") ==  0) {
        	sleep(Slight_delay);
            quizSection();
        } else {
            printf("Please select an available option! (yes/no)\n");
        }
    }

    return  0;
}
