#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){


    srand(time(NULL));
    int comp = 1 + rand() % 3;
    int peop;
    char answ;

    printf("Do you want to play [y or N] ? \n");
    scanf("%c", &answ);

    srand(time(NULL));
    
    while (answ == 'y'){
        printf("1 - ROCK \n2 - PAPER \n3 - SCISSORS \n");
        printf("Please, give a number:");
        scanf("%d", &peop);

        
        int comp = 1 + rand() % 3; 
        
        switch (comp){
            case 1: 
                (peop == 1) ? printf("We have a DRAW\n") : (peop == 2) ? printf("YOU'VE WIN\n") : printf("Computer win\n") ;
                break;
            case 2:
                (peop == 1) ? printf("Computer win\n") : (peop == 2) ? printf("We have a DRAW\n") : printf("YOU'VE WIN\n") ;
                break;
            case 3: 
                (peop == 1) ? printf("YOU'VE WIN\n") : (peop == 2) ? printf("Computer win\n") : printf("We have a DRAW\n") ;
                break;
        }

        printf("Do you want to play? \n");
        scanf(" %c", &answ);
    }

    ///Для консоли на винде
    printf("Press Enter---");
    fflush(stdout);
    getchar();
    //
    return 0;

}