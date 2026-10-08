#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Person{
    char name[30];
    int hp;
    int maxHP;
    int attack;
    int qHP;
}Person;

void PrintPers(Person *Pep);
void Attack(Person *Pep1, Person *Pep2);
void Choice(Person *Pep1, Person *Pep2);
void Fight(Person *Pep1, Person *Pep2);
void Treat(Person * Pep);
int Run(Person *Pep);

int main(void){
    Person Goblin = {"Goblin", 100, 100, 50, 1};

    Person One;
    printf("Name:");
    scanf("%29s", One.name);
    One.hp = 100;
    One.maxHP = 100;
    One.attack = 40;
    One.qHP = 3;


    printf("Selection on a apponent...");
    printf("%s\n",Goblin.name);

    PrintPers(&One);
    PrintPers(&Goblin);

    printf("FIGHT!\n");

    Fight(&Goblin, &One);

    printf("Press Enter---");
    fflush(stdout);
    getchar();
    //
    return 0;

}

//
//
//
//
void PrintPers(Person *Pep){

    printf("\n");
    printf("Name: %s\n", Pep->name);
    printf("HP: %d\n", Pep->hp);
    printf("Max HP: %d\n", Pep->maxHP);
    printf("Attack: %d\n", Pep->attack);
    printf("Number of potions: %d\n", Pep->qHP);

    printf("---------------\n");
}

void Fight(Person * Pep1, Person * Pep2){
    while((Pep1->hp > 0) && (Pep2->hp > 0)){
        Attack(Pep1,Pep2);

        PrintPers(Pep1);
        PrintPers(Pep2);

        Choice(Pep1,Pep2);
        

        if(Pep1->hp < 0){
            printf("%s win %s", Pep2->name, Pep1->name);
            exit(0);
        }
        if(Pep2->hp < 0){
            printf("%s win %s", Pep1->name, Pep2->name);
            exit(0);
        }
    }


}

void Attack(Person * Pep1, Person *Pep2){
    srand(time(NULL));
    int damage = 1 + rand() % Pep1->attack;
    printf("Damage: %s -%d\n", Pep2->name, damage);
    Pep2->hp = Pep2->hp - damage;

}

void Choice(Person * Pep1, Person * Pep2){
    printf("Select an action:\n1 = Attack\n2 = Treat\n3 = Run\n------------------------------------------------------------------\n");
    int  choice;
    scanf("%d", &choice);
    switch (choice){
        case 1: {Attack(Pep2,Pep1); break;}
        case 2: {Treat(Pep2);break;}
        case 3: {Run(Pep2);break;}
    }
}

void Treat(Person * Pep){
    Pep->hp += 15;
    Pep->qHP -=1;
}

int Run(Person *Pep){
    srand(time(NULL));
    int ver = 0 + rand() % 2;
    if (ver == 1){
        printf("Success");
        exit(0);
    }
    else{
        printf("Failrule");
        exit(0);
    }


}
