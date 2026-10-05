#ifndef HM_VS_AI_H_INCLUDED
#define HM_VS_AI_H_INCLUDED
#include "HM_VS_HM.h"
#include <windows.h>
#include "Grille_Konane.h"
#include <string.h>
#include <ctype.h>
#include <time.h>
#define TAILLE 7

extern Direction directions[4];
int lireCoordonnee(const char *s, int *r, int *c);
int estDansPlateau(int r, int c);
int sautValide(int r1,int c1,int r2,int c2,char joueur);
void executerSaut(int r1,int c1,int r2,int c2);
int aUnSautDepuis(int r,int c,char joueur);
int aUnCoupLegal(char joueur);
void afficherGrille(char (*plateau)[TAILLE]);
void initialiserPlateau(char (*plateau)[TAILLE]);
void tourIA(char coulIA);
void jouerHumainVsIA(const char *nomJoueur);


#endif // HM_VS_AI_H_INCLUDED
