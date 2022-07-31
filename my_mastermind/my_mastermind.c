#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>


int accurate_code(char* lineup);


int size_l(char* lineup);


char* copystring(char* goal, char* derivation);




int indicator(char* lineup, char z);


void confidential_c(char l[]);


int size_l(char* lineup) {


    int d = 0;

   for(int i = 0; lineup[i] != '\0'; i++) {
       d += 1;
       
   }


    return d;
}


int indicator(char* lineup, char z) {
    for(int h = 0; h < size_l(lineup); h++) {
        if(lineup[h] == z) {
            return 1;
        }
    }
    return 0;
}


int accurate_code(char* lineup) {

    int y = 1;

    if(size_l(lineup) < 4 || size_l(lineup) > 4) {

        return 0;
    }

    for(int g = 0; g < size_l(lineup); g++) {

        if(lineup[g] < '0' || lineup[g] > '7') {

            y = 0;
        }
        for(int i = 0; i < g; i++) {

            if(lineup[g] == lineup[i]) {

                y = 0;
            }
        }
    }

    if(!y) {

        return 0;

    } else {
        
        return 1;
    }
}

int check_string(char* j, char* k) {


    for(int l = 0; l < size_l(j); l++) {
        if(j[l] != k[l]) {
            return 0;
        }
    }
    return 1;
}


void confidential_c(char* cipher) {
    srand(time(NULL));
    for(int b = 0; b < 4; b++) {
        char qu = rand() % 8 + '0';
        if(indicator(cipher, qu) == 0) {
            cipher[b] = qu;
        }
    }
}


char* copystring(char* goal, char* derivation) {
    int t = 0;
    while(t < size_l(derivation)) {
        goal[t] = derivation[t];
        t += 1;
    }

    return goal;
}


int main(int ac, char* av[]) {
    int zx = 0, zy = 0, a = 0, b = 0, tries = 10;  


    char cipher[100000];

    for (int j = 1; j < ac; j++) {
        if(check_string(av[j], "-c")) {
            a = j+1;
        }
        if(check_string(av[j], "-t")) {
            b = j+1;
            tries = atoi(av[b]);
        }
    }
    
    if(a != 0) {
        copystring(cipher, av[a]);
    } else {
        confidential_c(cipher);
    }

    printf("Will you find the secret code?\n");

    for(int k = 0; k <= tries; k++) {
        zx = zy = 0;

        printf("---\n");

        printf("Round %d\n", k);

        int trueInsert;

        char insrt[100000];


        do{
            trueInsert = 1;
            printf(">");
            scanf("%s", insrt);
            if(accurate_code(insrt) == 0) {
                trueInsert = 0;
            }

            if(trueInsert == 0) {
                printf("Wrong input!\n");
            }
        } while (trueInsert != 1);

        for(int h = 0; h < 4; h++) {


            if(cipher[h] == insrt[h]) {

                zx++;
            } else if(indicator(cipher, insrt[h]) != 0 && cipher[h] != insrt[h]) {
                zy++;
            }
        }

        if(zx == 4) {

            printf("Congratulation! You did it!\n");


            return 0;


        } else {
            printf("Well placed pieces: %d\n", zx);



            printf("Misplaced pieces: %d\n", zy);
        }
    }
}