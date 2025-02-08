#include <stdio.h>

#define HAUTEUR 6
#define LARGEUR 7

// Initialise la grille avec des espaces
void initialiser_grilleP4(char grille[HAUTEUR][LARGEUR]){
    int i, j; 
    for(i = 0; i < HAUTEUR; i++){
        for(j = 0; j < LARGEUR; j++){
            grille[i][j] = ' ';
        }
    }
}

// Initialise les hauteurs des colonnes avec 0
void initialiser_hauteur_colonnes(int hauteurs[LARGEUR]){
    int i; 
    for(i = 0; i < LARGEUR; i++){
        hauteurs[i] = 0;
    }
}

int main(void){
    return 0; 
}