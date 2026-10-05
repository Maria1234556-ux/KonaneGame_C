#include "Interface_Menu.h"


void KONANE_Menu(){
HANDLE h;
h = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(h, BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("\t\t\t                       ________               _______               ______             \n");
printf("\t\t\t       *    |    /    |        | |\\        | |       | |\\        | |          *        \n");
printf("\t\t\t     *      |   /     |        | | \\       | |       | | \\       | |            *      \n");
printf("\t\t\t   *        |  /      |        | |  \\      | |       | |  \\      | |              *    \n");
printf("\t\t\t *          | /       |        | |   \\     | |_______| |   \\     | |                *  \n");
printf("\t\t\t*           |/        |        | |    \\    | |       | |    \\    | |______            *\n");
printf("\t\t\t *          |\\        |        | |     \\   | |       | |     \\   | |                *  \n");
printf("\t\t\t  *         | \\       |        | |      \\  | |       | |      \\  | |               *   \n");
printf("\t\t\t   *        |  \\      |        | |       \\ | |       | |       \\ | |             *     \n");
printf("\t\t\t     *      |   \\     |________| |        \\| |       | |        \\| |______     *       \n");
printf("\t\t\t                                                                                       \n\n");
SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("\n\n\n\n\n");
};

void song() {
              Beep(784, 600);
            }
void GREEN_background_text(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void color_console(){
                    system("color 87");
                    system("cls");
                    }
void HOME()
{
    int a,choix;
    GREEN_background_text();
    do{
    printf("\n\t\t\tTaper ***1*** pour revenir au menu : ");
    scanf("%d",&a);
    if (a==1) choix=0;}while(a!=1);

}
void titre_primaire(){
    printf("-------------------------------------------******************KONANE*******************-----------------------------------------------\n");
    printf("\t\t\t\t\t^^^^^^^^^^^^^^^^HAWAIIAN CHECKERS^^^^^^^^^^^^^^^^^^\n");
    printf("\n\n\n\n");}
void titre_secondaire(){
    printf("\t\t\t\t\t\t\t\tKONANE\n");
    printf("\t\t\t\t\t\t\t^^^^HAWAIIAN CHECKERS^^^^\n");
    printf("\n\n\n\n");
}

void Score(){
    titre_secondaire();
    printf("\n\n\n\n");
    printf("\t\t\tScore not available   \n\n\n");
    printf("\t\t\tNumber of playing not available \n\n\n");
    HOME();
            }
void Precise_quitter(){
    GREEN_background_text();
    printf("\t\t\t\t\t _____________________________________________________ \n");
    printf("\t\t\t\t\t|      Are you sure you want to quit the game :(((    |\n");
    printf("\t\t\t\t\t|                                                     |\n");
    printf("\t\t\t\t\t|                                                     |\n");
    printf("\t\t\t\t\t|      1.YES                                          |\n");
    printf("\t\t\t\t\t|                                                     |\n");
    printf("\t\t\t\t\t|      2.NO,return                                    |\n");
    printf("\t\t\t\t\t|                                                     |\n");
    printf("\t\t\t\t\t|_____________________________________________________|\n");
}
void Precise_return(){
    GREEN_background_text();
    printf("\t\t\t\t\t _____________________________________________________ \n");
    printf("\t\t\t\t\t|    Return to game :))                               |\n");
    printf("\t\t\t\t\t|                                                     |\n");
    printf("\t\t\t\t\t|      1.YES                                          |\n");
    printf("\t\t\t\t\t|                                                     |\n");
    printf("\t\t\t\t\t|      2.NO                                           |\n");
    printf("\t\t\t\t\t|                                                     |\n");
    printf("\t\t\t\t\t|_____________________________________________________|\n");
}
void Rules(){
    titre_primaire();
    printf("\n\n\n");
    printf("\t\t\tRULES : \n\n");
    printf("\t\t\tLe jeu se joue sur un plateau.\n\n");
    printf("\t\t\tLes joueurs enlevent alternativement des pions.\n\n");
    printf("\t\t\tLe joueur qui ne peut plus jouer perd.\n\n");
    HOME();
            }
void Menu_First(char name[50]){
    printf("\t\t\t\t\t\t\t WELCOME %s \n",name);
    printf("\t\t\t\t\t\t ______________________________\n");
    printf("\t\t\t\t\t\t/          KONANE !!!!!        \\");
    printf("\n\n\n\n\n");
    GREEN_background_text();
    printf("\t\t\t1.Start game\n\n\n");
    printf("\t\t\t2.Rules\n\n\n");
    printf("\t\t\t3.Score\n\n\n");
    printf("\t\t\t4.Quit\n\n\n");
    printf("\t\t\t\t\t\t ~~~~Select option : ");
}

void Menu_Second(){
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    titre_primaire();
    GREEN_background_text();
    printf("\t\t\t1.Learn how to play ^^^\n\n\n");
    printf("\t\t\t2.Continue\n\n\n");
    printf("\t\t\t3.HOME\n\n\n");
    printf("\t\t\t4.Quitter\n\n\n");
    printf("\t\t\t\t\t\t ~~~~Select option : ");
}
void Learn_Play(){
    titre_secondaire();
    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t *************No available***********\n\n");
    HOME();
}
void Continue(){
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    titre_secondaire();
    GREEN_background_text();
    printf("\n\n\n");
    printf("\t\t\t1.HUMAN VS HUMAN\n\n\n");
    printf("\t\t\t2.HUMAN VS COMPUTER (Simple AI)\n\n\n");
    printf("\t\t\t3.HUMAN VS COMPUTER (Advanced AI)\n\n\n");
    printf("\t\t\t\t\t\t ~~~~Select option : ");
}

void HumanVSComputer_Simple(){
    titre_secondaire();
    printf("\n\n\n");
    printf("\t\t\t\t\t\t*******NO AVAILABLE******** \n");
}
void HumanVSComputer_advanced(){
    titre_secondaire();
    printf("\n\n\n");
    printf("\t\t\t\t\t\t*******NO AVAILABLE******** \n");
}
