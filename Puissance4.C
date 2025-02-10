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
// Affiche la grille du Puissance 4
void affiche_grilleP4(char grille[HAUTEUR][LARGEUR]){
    int i, j;
    for(j = 0; j < LARGEUR; j++){
        printf(" %d", j + 1);
    }
    printf("\n");
    
    for(i = 0; i < HAUTEUR; i++){
        for(j = 0; j < LARGEUR; j++){
            printf("|%c", grille[i][j]);  
        }
        printf("|\n"); 
    }
    printf("\n");
}

// Pose un jeton dans la grille et return un boolean 
int pose_jeton (char grille[HAUTEUR][LARGEUR], int hauteurs[LARGEUR], int joueur, int numero_colonne){
    if(numero_colonne>=LARGEUR || numero_colonne<0 || hauteurs[numero_colonne]==HAUTEUR){
        return 0; 
    }
    else{
        hauteurs[numero_colonne] += 1; 
        if(joueur ==1){
            grille[HAUTEUR-hauteurs[numero_colonne]][numero_colonne] = 'X'; 
        }else{
            grille[HAUTEUR-hauteurs[numero_colonne]][numero_colonne] = 'O';
        }
    }
    return 1; 
}
int main(void){
    char grille[HAUTEUR][LARGEUR];
    int hauteurs[LARGEUR];
    int numero_colonne = 0; 
    int nombre_cases = 42; 
    int boolean =0; 

    initialiser_grilleP4(grille); 
    initialiser_hauteur_colonnes(hauteurs);
    affiche_grilleP4(grille);  

    do{
        do {
            printf("Entrez le numero de la colonne (1 a %d) pour poser un jeton : ", LARGEUR);
            scanf("%d", &numero_colonne);
            numero_colonne--;
        } while (numero_colonne < 0 || numero_colonne >= LARGEUR);

        if(nombre_cases%2!=0){
            boolean = pose_jeton(grille, hauteurs, 1, numero_colonne); 
        }
        else{
            boolean = pose_jeton(grille, hauteurs, 2, numero_colonne); 
        }
        if(boolean == 1){
            nombre_cases--;
            affiche_grilleP4(grille);  
        } 

    }while(nombre_cases>0); 

    return 0; 
}