/* Includes -------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Prototypes -------------------------------- */

int premier(int nombre);
int reste(int a, int b);
int pgcd(int a, int b);
int inverse(int e, int phi);
int det_e(int phi);
void cle();
void crypter();
void decrypter();

/* Main function -------------------------------- */

int main(void){
    /* 
        Écrire  -> cle() pour créer la clé publique et privée
                -> crypter() pour crypter un message
                -> decrypter() pour décrypter un message
    */     
    return 0;
}

/* Functions -------------------------------- */

int premier(int nombre){
    int i;
    int c = 0;
    for(i=2; i<nombre; i++){
        if(nombre%i == 0){
            c++;
        }
    }
    if(c == 0){
        return 1;
    }
    return 0;
}


int reste(int a, int b){
    return a%b;
}


int pgcd(int a, int b){
    
    int *tab_a = (int *) malloc(sizeof(int) * 0);;
    int nombre_diviseurs_a = 1;
    for(int i=1; i<=a; i++){
        if(reste(a, i) == 0){
            nombre_diviseurs_a++;
            tab_a = (int*) realloc(tab_a, nombre_diviseurs_a * sizeof(int*));
            tab_a[nombre_diviseurs_a - 2] = i;
        }
    }

    int *tab_b = (int *) malloc(sizeof(int) * 0);;
    int nombre_diviseurs_b = 1;
    for(int k=1; k<=b; k++){
        if(reste(b, k) == 0){
            nombre_diviseurs_b++;
            tab_b = (int*) realloc(tab_b, nombre_diviseurs_b * sizeof(int*));
            tab_b[nombre_diviseurs_b - 2] = k;
        }
    }

    int comp = 0;
    int *commun = (int*) malloc(sizeof(int) * comp);
    for(int m=0; m<nombre_diviseurs_a; m++){
        for(int l=0; l<nombre_diviseurs_b; l++){
            if(tab_a[m] == tab_b[l]){
                comp++;
                commun = (int *)realloc(commun, sizeof(int *) * comp);
                commun[comp-1] = tab_a[m];
            }
            
        }
    }

    int pgcd = commun[0];
    for(int p=0; p<comp-1; p++){
        if(commun[p] > pgcd){
            pgcd = commun[p];
        }
    }


    free(tab_a);
    free(tab_b);
    free(commun);
    
    return pgcd;
}


int inverse(int e, int phi){
    int d = 1;
    int produit = d*e;
    while(reste(produit, phi) != 1){
        d++;
        produit = d*e;
    }
    return d;
}

int det_e(int phi){
    int e = 2;
    while(pgcd(e, phi) != 1){
        e++;
    }
    return e;
}

void cle(){
    int p;
    printf("Entrez un nombre premier: ");
    scanf("%d", &p);
    while(premier(p) != 1){
        printf("Le nombre rentré n'est pas premier. Entrez en un à nouveau: ");
        scanf("%d", &p);
    }

    int q;
    printf("Entrez un autre nombre premier: ");
    scanf("%d", &q);
    while(premier(q) != 1){
        printf("Le nombre rentré n'est pas premier. Entrez en un à nouveau: ");
        scanf("%d", &q);
    }

    int n = p*q;
    int phi = (p-1)*(q-1);
    int e = det_e(phi);
    int d = inverse(e, phi);
    printf("\nClé publique: \n");
    printf("    n ->  %d \n", n);
    printf("    e ->  %d \n", e);
    printf("Clé privée: \n");
    printf("    d ->  %d \n\n", d);
}

void crypter(){
    int m;
    printf("Quel message souhaitez vous crypter(entier naturel): ");
    scanf("%d", &m);
    
    int n;
    printf("Valeur n de la clé publique: ");
    scanf("%d", &n);

    int e;
    printf("Valeur e de la clé publique: ");
    scanf("%d", &e);

    printf("Le message crypté est %d \n", (int)pow(m, e)%n);
}

void decrypter(){
    int x;
    printf("Entrez le message crypté: ");
    scanf("%d", &x);

    int d;
    printf("Quelle est votre clé privée ? ");
    scanf("%d", &d);

    int n;
    printf("Quelle est la valeur n de la clé publique ?");
    scanf("%d", &n);

    printf("Le message initial est %d", (int)pow(x, d)%n);
}