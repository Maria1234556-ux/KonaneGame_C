<div align="center">

# 🌺 Kōnane

### Le jeu de stratégie hawaïen, en C

*Capturez. Sautez. Bloquez votre adversaire.*

![Langage](https://img.shields.io/badge/Langage-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Plateforme](https://img.shields.io/badge/Plateforme-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![Interface](https://img.shields.io/badge/Interface-Console-4D4D4D?style=for-the-badge)
![Statut](https://img.shields.io/badge/Statut-Jouable-2ea44f?style=for-the-badge)

</div>

---

##  Présentation

**Kōnane** est l'un des plus anciens jeux de stratégie de Polynésie, pratiqué à Hawaï bien avant le XVIIIᵉ siècle. Ce projet en propose une version numérique complète, jouable dans la console Windows, avec une interface colorée et soignée.

Deux joueurs, les **Noirs** et les **Blancs**, s'affrontent sur un plateau **7×7**. Pas de hasard : seulement de la réflexion et de l'anticipation.

>  Projet réalisé à l'**École Hassania des Travaux Publics** (Département de Mathématiques, Informatique et Géomatique, filière Systèmes d'Information Géographique), dans le cadre du module *Programming Techniques*, sous l'encadrement de **Mme Mariam Cherrabi**.

---

##  Règles du jeu

| Étape | Description |
|-------|-------------|
| **1. Plateau** | Grille 7×7 entièrement remplie de pierres noires et blanches en damier. |
| **2. Ouverture** | Le Noir retire une pierre (au centre ou dans un coin), puis le Blanc retire une pierre adjacente à la case vide. |
| **3. Capture** | Chaque coup est obligatoirement un saut par-dessus une pierre adverse, vers une case vide. La pierre sautée est retirée. |
| **4. Direction** | Les sauts sont orthogonaux (horizontaux ou verticaux). Les diagonales sont interdites. |
| **5. Sauts multiples** | Un joueur peut enchaîner plusieurs captures, à condition de rester dans la même direction. |
| **6. Victoire** | Le dernier joueur capable de jouer remporte la partie. |

---

##  Fonctionnalités

###  Interface
- Plateau en mode « graphique ASCII » : chaque case occupe 3 lignes, avec couleurs de fond et de texte
- Repérage intuitif : lignes **A à G**, colonnes **1 à 7**
- Écran d'accueil avec titre ASCII et saisie du nom du joueur
- Menus interactifs avec confirmation avant de quitter
- Rafraîchissement de l'écran à chaque tour pour une lecture fluide

###  Modes de jeu
- ** Humain vs Humain** : phase d'ouverture, validation des coups et alternance des tours
- ** Humain vs Ordinateur (IA simple)** : l'ordinateur joue le premier coup valide qu'il trouve

###  Moteur de jeu
- Validation complète des coups (limites du plateau, orthogonalité, pierre adverse, case d'arrivée vide)
- Gestion des sauts multiples dans une même direction
- Détection automatique de la fin de partie dès qu'un joueur est bloqué

---

##  Architecture du projet

Le code est organisé de façon **modulaire**, avec un fichier source et un fichier d'en-tête par module.

| Module | Rôle |
|--------|------|
| `Grille_Konane.c / .h` | Initialisation et affichage du plateau |
| `HM_VS_HM.c / .h` | Mode Humain vs Humain : ouverture, validation, exécution des sauts, boucle de jeu |
| `HM_VS_AI.c / .h` | Mode Humain vs Ordinateur : tour de l'IA et boucle de jeu |

**Structures de données principales :**
- `Plateau` : tableau 2D de caractères `7×7` (`N` = pierre noire, `B` = pierre blanche, `.` = case vide)
- `Direction` : déplacements orthogonaux (haut, bas, gauche, droite)

---

##  Installation et lancement

**Prérequis :** un compilateur C (GCC / Code::Blocks) et Windows, car le projet utilise `windows.h`.

1. Cloner ou télécharger le dépôt
2. Compiler l'ensemble des fichiers `.c`
3. Lancer l'exécutable depuis la console Windows
4. Saisir votre nom, choisir un mode de jeu et jouer

###  Comment jouer

Un coup se saisit en indiquant la **case de départ** puis la **case d'arrivée**.

```
Tour --> Maria (N): C1 A1
```

Ici, la pierre en `C1` saute par-dessus la pierre adverse située en `B1` et atterrit en `A1`.

---

##  Technologies

- **Langage C**
- **Windows API** (`windows.h`) pour la gestion des couleurs et de l'affichage console

---

##  Perspectives d'amélioration

- [ ] IA avancée (par exemple Minimax avec élagage alpha-bêta)
- [ ] Calcul et affichage des scores en fin de partie
- [ ] Gestion d'un temps maximal par partie
- [ ] Mode « Learn how to play » expliquant les règles
- [ ] Aide au joueur : suggestion d'un saut possible


<div align="center">

*Réalisé avec passion à l'École Hassania des Travaux Publics* 🇲🇦

</div>
