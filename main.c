#include <stdio.h>
#include <stdlib.h>
#include "HM_VS_AI.h"
#include "HM_VS_HM.h"
#include "Grille_Konane.h"
#include "Interface_Menu.h"
int main()
{
    char name[50]  ;
    int choix ;
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    color_console();
    titre_primaire();
    KONANE_Menu();
    song();
    SetConsoleTextAttribute(h, BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\t\t\t\t\t\t  **  ENTER YOUR NAME  ** : ");
    scanf("%49s",name);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    color_console();
    titre_primaire();
    printf("\n\n\n\n\n");
    do
    {
    color_console();
    song();
    Menu_First(name);
    scanf("%d",&choix);
    printf("\n\n\n");
    switch(choix)
    {
 case 4:
    color_console();
    titre_secondaire();
    song();
    Precise_quitter();
    int confirm;
    printf("\n\n");
    printf("\t\t\t\t\t\t ~~~~Answer : ");
    scanf("%d",&confirm);
    printf("\n\n\n\n\n");
    if (confirm == 2)
        {
            choix=0;
            break;
        }
    break;
 case 2:
     color_console();
     Rules();
     break;
 case 3 :
    color_console();
    Score();
    break;
 case 1:
    {
        color_console();
        Menu_Second();
    {
        int ans;
    scanf("%d",&ans);
    switch(ans)
    {
case 1:
    color_console();
    printf("\n\n");
    Learn_Play();
    break;
case 2:
    {
    color_console();
    song();
    Continue();
    int ans1;
    scanf("%d",&ans1);
    printf("\n");
    switch(ans1)
    {
    case 1:
       {
        char name1[50];
        color_console();
        titre_secondaire();
        GREEN_background_text();
        printf("\n");
        printf("\t\t\t******Enter Adversaire name : ",name1);
        scanf("%49s",&name1);
        printf("\n\n");
        GREEN_background_text();
        printf("\t\t\t******choose time : \n\n");
        printf("\t\t\t1/ 10 min\n\n");
        printf("\t\t\t2/ 15 min \n\n");
        printf("\t\t\t3/ 20 min \n\n");
        printf("\t\t\t4/ 0 ( Choose 0 because , the other times are unavailable for the moments) \n\n");
        GREEN_background_text();
        printf("\t\t\tyour preference :))) ----->  ");
        int time ;
        scanf("%d",&time);
        printf("\n\n");
        GREEN_background_text();
        printf("\t\t\t******Taille du table : 7x7\n\n");
        {
        printf("\t\t\tTAP 0 TO CONTINUE  ");
        int b;
        scanf("%d",&b);
        if (b==0)
    {
        color_console();
        printf("\t\t\t\t\t\t\t\tKONANE\n");
        printf("\t\t\t\t\t\t\t^^^^HAWAIIAN CHECKERS^^^^\n");
        printf("\n\n");
        song();
        printf("\n");
        Plateau jeu;
        initialiserPlateau(jeu.cases);
        jouer(&jeu,name,name1);
    }
       }
       }
    break;
    case 2:
        srand(time(NULL));
        char nom[50];
        printf("\n\n\t\t\tEntrez votre nom again ou le joueur qui va jouer : "); scanf("%s", nom);
        song() ;
        jouerHumainVsIA(nom);
        printf("\n");
        HOME();
        break;
    case 3:
        color_console();
        HumanVSComputer_advanced();
        printf("\n");
        HOME();
        break;
   case 4:
    color_console();
    choix=0;
    }
    break;
default:
    printf("\n\n");
    HOME();
    printf("\n\n\n");
    }
    }
    }
    break;
    }
 default :
    color_console();
    printf("votre choix invalide ^^^^ ");
    printf("\n\n");
    choix=0;
    }
}while (choix!=4);
    color_console();
    song();
    titre_secondaire();
    GREEN_background_text();
    printf("\t\t\t\t------------------------------GAME OVER-------------------------------------\n\n\n");
    SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}

