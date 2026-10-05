#include "HM_VS_HM.h"
#include "Grille_Konane.h"
#include <time.h>

Direction directions[4] = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};

int lireCoordonnee(const char *s, int *r, int *c){
    if(strlen(s)<2) return 0;
    char ligne = toupper(s[0]);
    *r = ligne - 'A';
    *c = atoi(s+1) - 1;
    if(*r<0 || *r>=TAILLE || *c<0 || *c>=TAILLE)
        return 0;
    return 1;
}

int estDansPlateau(int r,int c){ return r>=0 && r<TAILLE && c>=0 && c<TAILLE;}

int ouvertureAutoriseeX(int r,int c){
    if((r==0&&c==0)||(r==0&&c==6)||(r==6&&c==0)||(r==6&&c==6)||(r==3 && c==3))
        return 1;
    return 0;
}

int estAdjacentOrthogonal(int r1,int c1,int r2,int c2){
    return (abs(r1-r2)==1 && c1==c2) || (abs(c1-c2)==1 && r1==r2);
}


void phaseOuverture(Plateau *p,const char *noir,const char *blanc){
    int rb,cb,rw,cw;
    char tap_user[16];

    initialiserPlateau(p->cases);
    afficherGrille(p->cases);

    printf("\n%s retire une pierre noire ^^^^ \n", noir);
    while(1){
        scanf("%15s",tap_user);
        if(!lireCoordonnee(tap_user,&rb,&cb)) continue;
        if(!ouvertureAutoriseeX(rb,cb)) continue;
        if(p->cases[rb][cb] != 'N') continue;
        p->cases[rb][cb]='.';
        break;
    }
    afficherGrille(p->cases);
    printf("\n%s retire une blanche adjacente ^^^^\n", blanc);
    while(1){
        scanf("%15s",tap_user);
        if(!lireCoordonnee(tap_user,&rw,&cw)) continue;
        if(p->cases[rw][cw] != 'B') continue;
        if(!estAdjacentOrthogonal(rw,cw,rb,cb)) continue;
        p->cases[rw][cw]='.';
        break;
    }
    afficherGrille(p->cases);
}

int sautValide1(Plateau *p,int r_depart,int c_depart,int r_arrive,int c_arrive,char joueur){
    if(!estDansPlateau(r_depart,c_depart) || !estDansPlateau(r_arrive,c_arrive))
        return 0;

    if(p->cases[r_depart][c_depart] != joueur || p->cases[r_arrive][c_arrive] != '.')
        return 0;

    int dr = r_arrive - r_depart;
    int dc = c_arrive - c_depart;

    if(!((abs(dr)==2 && dc==0) || (abs(dc)==2 && dr==0)))
        return 0;

    int mr = r_depart + dr/2;
    int mc = c_depart + dc/2;

    char ennemi;
    if(joueur == 'N') ennemi = 'B';
    else ennemi = 'N';

    return p->cases[mr][mc] == ennemi;
}

void executerSaut1(Plateau *p,int r_depart,int c_depart,int r_arrive,int c_arrive){
    int mr = r_depart + (r_arrive-r_depart)/2;
    int mc = c_depart + (c_arrive-c_depart)/2;
    p->cases[r_arrive][c_arrive] = p->cases[r_depart][c_depart];
    p->cases[r_depart][c_depart] = '.';
    p->cases[mr][mc] = '.';
}

int aUnSautDepuis1(Plateau *p,int r,int c,char j){
    if(p->cases[r][c] != j) return 0;
    for(int i=0;i<4;i++){
        int r_arrive = r + 2*directions[i].dr;
        int c_arrive = c + 2*directions[i].dc;
        if(sautValide1(p,r,c,r_arrive,c_arrive,j))
            return 1;
    }
    return 0;
}

int aUnCoupLegal1(Plateau *p,char j){
    for(int r=0;r<TAILLE;r++){
        for(int c=0;c<TAILLE;c++){
            if(aUnSautDepuis1(p,r,c,j))
                return 1;
        }
    }
    return 0;
}

void jouer(Plateau *p,const char *j1,const char *j2){
    phaseOuverture(p,j1,j2);
    char courant = 'N';
    const char *nom = j1;
    char tap_user1[16], tap_user2[16];
    while(1){
        afficherGrille(p->cases);
        if(!aUnCoupLegal1(p,courant)){
            if(courant=='N')
                printf("\n%s gagne , felicitation ***********\n",j2);
            else
                printf("\n%s gagne ! , felicitation ***********\n",j1);
            break;
        }
        printf("\nTour --> %s (%c): ", nom, courant);
        scanf("%15s %15s", tap_user1, tap_user2);
        int r_depart,c_depart,r_arrive,c_arrive;
        if(!lireCoordonnee(tap_user1,&r_depart,&c_depart) ||
           !lireCoordonnee(tap_user2,&r_arrive,&c_arrive) ||
           !sautValide1(p,r_depart,c_depart,r_arrive,c_arrive,courant)){
            printf("\nCoup invalide :(\n");
            continue;
        }
        executerSaut1(p,r_depart,c_depart,r_arrive,c_arrive);
        int cr = r_arrive, cc = c_arrive;
        while(aUnSautDepuis1(p,cr,cc,courant)){
            afficherGrille(p->cases);
            printf("\nMulti-saut obligatoire depuis %c%d -> ",'A'+cr, cc+1);
            scanf("%15s %15s", tap_user1, tap_user2);
            int nr_depart,nc_depart,nr_arrive,nc_arrive;
            if(!lireCoordonnee(tap_user1,&nr_depart,&nc_depart) ||
               !lireCoordonnee(tap_user2,&nr_arrive,&nc_arrive)){
                printf("Coordonnées invalides.\n");
                continue;
            }
            if(nr_depart != cr || nc_depart != cc){
                printf("Le multi-saut doit partir de la case actuelle.\n");
                continue;
            }
            if(!sautValide1(p,nr_depart,nc_depart,nr_arrive,nc_arrive,courant)){
                printf("Saut invalide.\n");
                continue;
            }
            executerSaut1(p,nr_depart,nc_depart,nr_arrive,nc_arrive);
            cr = nr_arrive;
            cc = nc_arrive;
        }
        if(courant=='N'){
            courant='B';
            nom=j2;
        } else {
            courant='N';
            nom=j1;
        }
    }
}
