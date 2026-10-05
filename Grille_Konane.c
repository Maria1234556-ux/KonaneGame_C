#include "Grille_Konane.h"
#define TAILLE 7

void initialiserPlateau(char (*plateau)[TAILLE]) {
    for (int i=0;i<TAILLE;i++) {
        for (int j=0;j<TAILLE;j++) {
            if ((i+j)%2==0) plateau[i][j] = 'N';
            else plateau[i][j] = 'B';
                                        }
                                    }
                                                }
void afficherGrille(char (*plateau)[TAILLE]) {
    HANDLE h;
    int c;
    system("color 87");
    system("cls");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t");
    for (c = 0; c < TAILLE; c++) printf("     %d ", c+1 );
    printf("\n\n");
    for (int i=0;i<TAILLE;i++) {
        for (int hauteur = 0; hauteur < 3; hauteur++) {
            printf("\t\t\t\t\t\t\t");
             h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        if (hauteur == 1) printf(" %c|",'A'+i);
        else printf("   ");
            for (int j=0;j<TAILLE;j++) {
                h = GetStdHandle(STD_OUTPUT_HANDLE);
                if (hauteur == 1) {
                    if ((i+j)%2 == 0) {
                        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        printf("   %c   ",plateau[i][j]);
                                      }
                    else {
                        SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                        printf("   %c   ",plateau[i][j]);
                         }
                                 }
                else {
                    if ((i + j) % 2 == 0) {
                        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        printf("       ");
                                          }
                    else {
                        SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                        printf("       ");
                         }
                    }
                                    }
            printf("\n");
                                                      }
    }
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf(" ");
}
