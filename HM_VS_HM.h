#ifndef HM_VS_HM_H_INCLUDED
#define HM_VS_HM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
# define TAILLE 7
#include "Grille_Konane.h"

typedef struct {
    char cases[TAILLE][TAILLE];
} Plateau;

typedef struct {
    int dr;
    int dc;
} Direction;

extern Direction directions[4];
void jouer(Plateau *p,const char *j1,const char *j2);
int aUnCoupLegal1(Plateau *p,char j);
int aUnSautDepuis1(Plateau *p,int r,int c,char j);
void executerSaut1(Plateau *p,int r1,int c1,int r2,int c2);
int sautValide1(Plateau *p,int r1,int c1,int r2,int c2,char joueur);
void phaseOuverture(Plateau *p,const char *noir,const char *blanc);
int estAdjacentOrthogonal(int r1,int c1,int r2,int c2);
int ouvertureAutoriseeX(int r,int c);
int estDansPlateau(int r,int c);
int lireCoordonnee(const char *s, int *r, int *c);


#endif // HM_VS_HM_H_INCLUDED
