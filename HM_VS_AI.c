#include <stdio.h>
#include <stdlib.h>
#include "HM_VS_AI.h"
#include "HM_VS_HM.h"
#include "Interface_Menu.h"
char plateau[TAILLE][TAILLE];

int sautValide(int r1,int c1,int r2,int c2,char joueur) {
    if(!estDansPlateau(r1,c1) || !estDansPlateau(r2,c2)) return 0;
    if(plateau[r1][c1]!=joueur || plateau[r2][c2]!='.') return 0;
    int dr=r2-r1, dc=c2-c1;
    if(!((abs(dr)==2 && dc==0) || (abs(dc)==2 && dr==0))) return 0;
    int mr=r1+dr/2, mc=c1+dc/2;
    char ennemi = (joueur=='N')?'B':'N';
    return plateau[mr][mc]==ennemi;
}

void executerSaut(int r1,int c1,int r2,int c2){
    int mr=r1+(r2-r1)/2, mc=c1+(c2-c1)/2;
    plateau[r2][c2] = plateau[r1][c1];
    plateau[r1][c1] = '.';
    plateau[mr][mc] = '.';
}

int aUnSautDepuis(int r,int c,char joueur){
    if(plateau[r][c]!=joueur) return 0;
    for(int i=0;i<4;i++){
        int r2=r+2*directions[i].dr, c2=c+2*directions[i].dc;
        if(sautValide(r,c,r2,c2,joueur)) return 1;
    }
    return 0;
}

int aUnCoupLegal(char joueur){
    for(int r=0;r<TAILLE;r++)
        for(int c=0;c<TAILLE;c++)
            if(aUnSautDepuis(r,c,joueur)) return 1;
    return 0;
}
void tourIA(char coulIA){
    for(int r=0;r<TAILLE;r++){
        for(int c=0;c<TAILLE;c++){
            if(plateau[r][c]==coulIA){
                for(int i=0;i<4;i++){
                    int r2=r+2*directions[i].dr, c2=c+2*directions[i].dc;
                    if(sautValide(r,c,r2,c2,coulIA)){
                        printf("\nIA joue %c%d -> %c%d\n",'A'+r,c+1,'A'+r2,c2+1);
                        executerSaut(r,c,r2,c2);
                        afficherGrille(plateau);
                        Sleep(500);
                        return;
                    }
                }
            }
        }
    }
}
void jouerHumainVsIA(const char *nomJoueur) {
    initialiserPlateau(plateau);
    int humEstNoir = rand() % 2;
    char coulHum = humEstNoir ? 'N':'B';
    char coulIA  = humEstNoir ? 'B':'N';
    system("color 87");
    system("cls");
    titre_secondaire();
    GREEN_background_text();
    printf("\n\n\t\t\t%s, vous jouez les %s (%c).\n", nomJoueur, humEstNoir?"Noirs":"Blancs", coulHum);
    printf("\n\t\t\tL'ordinateur joue les %s (%c).\n\n", humEstNoir?"Blancs":"Noirs", coulIA);
    if (humEstNoir) {
        int r,c; char in[16];
        initialiserPlateau(plateau);
        afficherGrille(plateau);
        printf("\n\t\t\tChoisissez un pion Noir a retirer (ex: A1, D4...): "); scanf("%s", in);
        lireCoordonnee(in,&r,&c); plateau[r][c]='.';
        for(int i=0;i<4;i++){
            int nr=r+directions[i].dr, nc=c+directions[i].dc;
            if(estDansPlateau(nr,nc) && plateau[nr][nc]==coulIA){ plateau[nr][nc]='.'; break; }
        }
    } else {
        initialiserPlateau(plateau);
        afficherGrille(plateau);
        plateau[0][0]='.'; printf("\n\t\t\tL'IA a retire le pion Noir en A1.\n");
        int r,c; char in[16];
        printf("\n\t\t\tRetirez un pion Blanc adjacent a A1 (ex: A2 ou B1): "); scanf("%s", in);
        lireCoordonnee(in,&r,&c); plateau[r][c]='.';
    }
    char courant = humEstNoir ? coulHum : coulIA;
    char s1[16], s2[16];

    while(1){
        afficherGrille(plateau);
        if(!aUnCoupLegal(courant)){
            printf("Plus de coups pour %c. %s a gagne !\n", courant, (courant==coulIA)?nomJoueur:"L'ordinateur");
            break;
        }

        if(courant==coulHum){
            printf("Votre tour (%c). Entrez saut (ex: A3 A5): ", coulHum);
            scanf("%s %s", s1, s2);
            int r1,c1,r2,c2;
            if(lireCoordonnee(s1,&r1,&c1) && lireCoordonnee(s2,&r2,&c2) && sautValide(r1,c1,r2,c2,coulHum)){
                executerSaut(r1,c1,r2,c2);
                while(aUnSautDepuis(r2,c2,coulHum)){
                    afficherGrille(plateau);
                    printf("Multi-saut possible depuis %c%d. Entrez destination: ", 'A'+r2,c2+1);
                    scanf("%s", s1);
                    int nr,nc;
                    if(lireCoordonnee(s1,&nr,&nc) && sautValide(r2,c2,nr,nc,coulHum)){
                        executerSaut(r2,c2,nr,nc); r2=nr; c2=nc;
                    } else break;
                }
                courant=coulIA;
            } else printf("Coup invalide !\n");
        } else {
            tourIA(coulIA);
            courant=coulHum;
        }
    }
}
