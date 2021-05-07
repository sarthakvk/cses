#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

int tablewidth = 1;
int offset1 = 0;
int offset2 = 0;

struct type_of_node {
        char number;    //y
        char position;  //x
        struct type_of_node *next;
        struct type_of_node *previous;
};

type_of_node *Createnode(type_of_node *temp) {
        temp->next = new (type_of_node);
        temp->next->previous = temp;
        temp->next->next = NULL;
        return temp->next;
}

void cleanstuff(bool usedrows[], bool type1diagons[], bool type2diagons[]) {
        int i;
        for (i = 0; i < tablewidth; i++)
                usedrows[i] = false;
        for (i = 0; i < (2 * tablewidth - 1); i++) {
                type1diagons[i] = false;
                type2diagons[i] = false;
        }
}

char Findposition(char y, char x, bool usedrows[], bool type1diagons[], bool type2diagons[]) {
        int i;
        for (i = x + 1; i <= tablewidth; i++) {
                if (usedrows[i - 1] == false and type1diagons[i - y + offset1] == false and type2diagons[i + y + offset2] == false)
                        return i;
        }
        return -1;
}

void delusedareas(char y, char x, bool usedrows[], bool type1diagons[], bool type2diagons[]) {
        usedrows[x - 1] = false;
        type1diagons[x - y + offset1] = false;
        type2diagons[x + y + offset2] = false;
}

void markusedareas(char y, char x, bool usedrows[], bool type1diagons[], bool type2diagons[]) {
        usedrows[x - 1] = true;
        type1diagons[x - y + offset1] = true;
        type2diagons[x + y + offset2] = true;
}

void Printnodes(type_of_node *temp) {
        printf("\n--------------------------------\n");
        printf("\tCoordinates\n\tX\tY");
        while (temp->next != NULL) {
                printf("\n%d:\t%d\t%d", temp->number, temp->position, temp->number);
                temp = temp->next;
        }
        printf("\n%d:\t%d\t%d", temp->number, temp->position, temp->number);
        printf("\n");
}

void Solve_problem() {
        int i;
        bool *usedrows;
        bool *type1diagons;
        bool *type2diagons;
        time_t t1, t2;
        int answer = 0;
        printf("Adjust table dimensions with a single number\n(more than 2x2 less than 40x40)\n");
        while (answer < 3 or answer > 40)
                scanf("%d", &answer);
        tablewidth = answer;
        offset1 = tablewidth - 1;
        offset2 = -2;
        answer = 0;
        usedrows = (bool *)malloc(tablewidth * sizeof(char));
        type1diagons = (bool *)malloc((2 * tablewidth - 1) * sizeof(char));
        type2diagons = (bool *)malloc((2 * tablewidth - 1) * sizeof(char));
        cleanstuff(usedrows, type1diagons, type2diagons);
        struct type_of_node *lista, *temp;
        lista = new (type_of_node);
        lista->number = 1;
        lista->position = 1;
        lista->previous = NULL;
        lista->next = NULL;
        markusedareas(lista->number, lista->position, usedrows, type1diagons, type2diagons);
        temp = new (type_of_node);
        temp = lista;
        bool flag = 1;
        char position;
        unsigned long int counter = 0;
        for (i = 0; i < tablewidth - 1; i++) {
                temp = Createnode(temp);
                temp->number = temp->previous->number + 1;
                temp->position = 0;
        }
        temp = lista->next;
        (void)time(&t1);
        while (flag) {
                counter++;
                position = Findposition(temp->number, temp->position, usedrows, type1diagons, type2diagons);
                if (position != -1) {
                        temp->position = position;
                        markusedareas(temp->number, temp->position, usedrows, type1diagons, type2diagons);
                        if (temp->number == tablewidth) {
                                flag = false;
                                break;
                        }
                        temp = temp->next;
                } else {
                        if (temp->number == 1) {
                                flag = false;
                                break;
                        }
                        temp->position = 0;
                        temp = temp->previous;
                        delusedareas(temp->number, temp->position, usedrows, type1diagons, type2diagons);
                }
        }
        printf("\n--------------------------------");
        printf("\nNumber of steps:%d", counter);
        (void)time(&t2);
        printf("\nTime taken = %d seconds", (int)t2 - t1);
        if (temp->number == 1) {
                printf("\n--------------------------------");
                printf("\nUnable to solve the problem...\n");
        } else
                Printnodes(lista);
}

int main() {
        int answer = 0;
        Solve_problem();
        printf("\nDo you want to try another variation? (Y=Yes,N=No)\n");
        while (answer != 'N' and answer != 'n') {
                scanf("%c", &answer);
                if (answer == 'Y' or answer == 'y') {
                        Solve_problem();
                        printf("\nDo you want to try another variation? (Y=Yes,N=No)\n");
                        answer = 0;
                }
        }
        system("PAUSE");
        return 0;
}
