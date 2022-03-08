#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    if (!SetConsoleOutputCP(65001))
    printf ("ERREUR\n");

    typedef struct
    {
        int valeur;
        int cache;
    }Position;

    int N, M, B, BT;
    int y, x, i;
    int Result = 0, Victoire = 0, Reponse = 1, Partie = 1;
    double temps, Score[6] = {{0}, {0}, {0}, {0}, {0}, {0}};     //La valeur du tableau est déclaré à 0 à cause de son type double

//--------------------CREATION DE L'AIRE DE JEU------------------------------------------------------------------------------------------------------------------------------------------------------//

//--------------------DEMANDE DES DIMENSIONS---------------------------------//

    printf ("Bienvenue au jeu du demineur!!!\nVous allez maintenant devoir rentrer des valeurs qui ne pourront plus etre modifie!\n");

    printf ("Veuillez saisir la hauteur : ");
    scanf ("%d,", &N);

    printf ("Veuillez saisir la largeur : ");
    scanf ("%d,", &M);

    printf ("Veuillez saisir le nombre de bombe : ");
    scanf ("%d,", &B);
    BT = B;

    Position tableau [N][M];

//--------------------DECLARATION DES FONCTIONS------------------------------//

//POUR QUE LA FONCTION MARCHE ELLE DOIT-ETRE DECLARE APRES QUE LE "tableau[N][M]" SOIT CREEE

            int Decouverte (int ry, int rx)
                {
                    switch (tableau[y][x].valeur){
                        case 0 :if (tableau[ry][rx+1].valeur > 0 && tableau[ry][rx+1].valeur < 9 && tableau[ry][rx+1].cache == 1){
                                    tableau[ry][rx+1].cache = 0;
                                };
                                if (tableau[ry][rx+1].valeur  == 0 && tableau[ry][rx+1].cache == 1){
                                    tableau[ry][rx+1].cache = 0;
                                    Decouverte(ry, rx+1);
                                };
                                if (tableau[ry][rx-1].valeur > 0 && tableau[ry][rx-1].valeur < 9 && tableau[ry][rx-1].cache == 1){
                                    tableau[ry][rx-1].cache = 0;
                                };
                                if (tableau[ry][rx-1].valeur  == 0 && tableau[ry][rx-1].cache == 1){
                                    tableau[ry][rx-1].cache = 0;
                                    Decouverte(ry, rx-1);
                                };

                                if (ry > 0){
                                    if (tableau[ry-1][rx+1].valeur > 0 && tableau[ry-1][rx+1].valeur < 9 && tableau[ry-1][rx+1].cache == 1){
                                        tableau[ry-1][rx+1].cache = 0;
                                    };
                                    if (tableau[ry-1][rx+1].valeur  == 0 && tableau[ry-1][rx+1].cache == 1){
                                        tableau[ry-1][rx+1].cache = 0;
                                        Decouverte(ry-1, rx+1);
                                    };
                                    if (tableau[ry-1][rx-1].valeur > 0 && tableau[ry-1][rx-1].valeur < 9 && tableau[ry-1][rx-1].cache == 1){
                                        tableau[ry-1][rx-1].cache = 0;
                                    };
                                    if (tableau[ry-1][rx-1].valeur  == 0 && tableau[ry-1][rx-1].cache == 1){
                                        tableau[ry-1][rx-1].cache = 0;
                                        Decouverte(ry-1, rx-1);
                                    };
                                    if (tableau[ry-1][rx].valeur > 0 && tableau[ry-1][rx].valeur < 9 && tableau[ry-1][rx].cache == 1){
                                        tableau[ry-1][rx].cache = 0;
                                    };
                                    if (tableau[ry-1][rx].valeur  == 0 && tableau[ry-1][rx].cache == 1){
                                        tableau[ry-1][rx].cache = 0;
                                        Decouverte(ry-1, rx);
                                    };
                                };

                                if (ry+1 < N){
                                    if (tableau[ry+1][rx-1].valeur > 0 && tableau[ry+1][rx-1].valeur < 9 && tableau[ry+1][rx-1].cache == 1){
                                        tableau[ry+1][rx-1].cache = 0;
                                    };
                                    if (tableau[ry+1][rx-1].valeur  == 0 && tableau[ry+1][rx-1].cache == 1){
                                        tableau[ry+1][rx-1].cache = 0;
                                        Decouverte(ry+1, rx-1);
                                    };
                                    if (tableau[ry+1][rx+1].valeur > 0 && tableau[ry+1][rx+1].valeur < 9 && tableau[ry+1][rx+1].cache == 1){
                                        tableau[ry+1][rx+1].cache = 0;
                                    };
                                    if (tableau[ry+1][rx+1].valeur  == 0 && tableau[ry+1][rx+1].cache == 1){
                                        tableau[ry+1][rx+1].cache = 0;
                                        Decouverte(ry+1, rx+1);
                                    };
                                    if (tableau[ry+1][rx].valeur > 0 && tableau[ry+1][rx].valeur < 9 && tableau[ry+1][rx].cache == 1){
                                        tableau[ry+1][rx].cache = 0;
                                    };
                                    if (tableau[ry+1][rx].valeur  == 0 && tableau[ry+1][rx].cache == 1){
                                        tableau[ry+1][rx].cache = 0;
                                        Decouverte(ry+1, rx);
                                    };
                                };
                                return Result = 0; break;
                        case 9 : return Result = 1; break;
                        default: tableau[y][x].cache = 0;
                                 return Result = 0; break;
                    };
                };

//--------------------REMPLISSAGE DU TABLEAU---------------------------------//

do {

    for (y = 0; y < N; y++){

        for (x = 0; x < M; x++){

            tableau[y][x] = (Position) {0, 1};
            }
    }

//--------------------PLACEMENT DES BOMBES-----------------------------------//

    while (B != 0){
        x = rand () % N;
        y = rand () % M;

        tableau[y][x].valeur = 9;

        B--;
    };

//--------------------BOMBES ALENTOURS---------------------------------------//

    for (y = 0; y < N; y++){

        for (x = 0; x < M; x++){

            if (tableau[y][x].valeur >= 9){
                    tableau[y-1][x].valeur ++;
                    tableau[y+1][x].valeur ++;

                if (x > 0){
                    tableau[y][x-1].valeur ++;
                    tableau[y-1][x-1].valeur ++;
                    tableau[y+1][x-1].valeur ++;
                }
                if (x+1 < M) {
                    tableau[y][x+1].valeur ++;
                    tableau[y+1][x+1].valeur ++;
                    tableau[y-1][x+1].valeur ++;
                }
            }
        }
    }

//--------------------AFFICHAGE DU TABLEAU-----------------------------------//

    clock_t debut = clock();

    do {
        printf ("\nPartie : %d \n", Partie);
        printf ("\nNombres de bombes : %d \n\n     ", BT);
        for (int e = 0; e < M; e++){
            printf ("%d ", e);
        }
        printf ("\n     ___________________\n");

        for (y = 0; y < N; y++){

            printf (" %d | ", y);

            for (x = 0; x < M; x++){
                if (tableau[y][x].valeur > 9){
                    tableau[y][x].valeur = 9;
                }
                if (tableau[y][x].cache == 1) {
                    printf ("# ");
                }
                else {
                    printf ("%d ", tableau[y][x].valeur);
                }
                if (tableau[y][x].valeur == 9 && tableau[y][x].cache == 1){
                    Victoire = 1;
                }
            }
            printf ("\n");
        }

//--------------------CODAGE DU JEU------------------------------------------------------------------------------------------------------------------------------------------------------------------//

//--------------------SAISIE DE L'UTILISATEUR--------------------------------//

            do {
                printf ("\nVeuillez saisir dans l'ordre la ligne et la colonne de la case a decouvrir :\n");
                scanf ("%d", &y);
                scanf ("%d", &x);

            } while(x < 0 || x > M || y < 0 || y > N || tableau[y][x].cache == 0);

            printf ("\nCoordonnees valide\n");

//--------------------REVELATION DES CASES-----------------------------------//

            Decouverte(y, x);

//--------------------VERIFICATION SI LES BOMBES ONT ETE TROUVEES------------//

        for (y = 0; y < N; y++){
            for (x = 0; x < M; x++){
                if (tableau[y][x].valeur < 9 && tableau[y][x].cache == 1){
                    Victoire = 0;
                }
            }
        }

    } while (Result == 0 && Victoire == 0);

//--------------------RESULTATS----------------------------------------------//

    switch (Victoire) {
        case 0 : printf ("\nBOOM! Vous avez saute sur une bombe...\nDommage! Vous avez Perdu!\n"); break;
        case 1 : printf ("\nBravo ! Vous avez trouvez toutes les bombes !\nVous avez Gagnez!\n"); break;
    }

    clock_t fin = clock();
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf ("\nVotre temps : %.1lf secondes\n", temps);


    if (Victoire == 1){

        for (int b = 1; b < 6; b++){
            if (Score[b] == 0){
                Score[b] = temps;
                break;
            }
        }

        for (int a = 1; a < 6; a++){
                if (Score[a] > temps){
                    for (int o = 6; o > a-1; o--){
                        Score[o] = Score[o-1];
                    }
                    Score[a] = temps;
                    break;
                }
        }

        if (Score[1] > temps || Partie == 1){
            printf ("\nC'EST UN NOUVEAU RECORD\n");
        }
        else {
            if (Partie > 1){
                printf ("\nVous auriez pu mieux faire...\n");
            }
        }
        Partie++;
    }

    for (int s = 1; s < 6; s++){
        printf ("\n %d : %.1lf s", s, Score[s]);
        if (Score[s] == temps){
            printf (" <----- Votre temps");
        }
        printf("\n");
    }

    printf ("\nVoulez-vous essayer de battre votre temps ?\nTapez 1 pour oui, et 0 pour non : ");
    scanf ("%d,", &Reponse);

    B = BT;
    Result = 0;
    Victoire = 0;

//--------------------FIN----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

} while (Reponse == 1);

    return 0;
}
