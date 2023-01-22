/**
 * @brief Gestion des actions que peuvent faire les joueurs, et qui sont choisies aléatoirement
 * @author Maxence & Aymeric
 */


#include "actions.h"

#define NB_ACTIONS 28

static Action ACTIONS[NB_ACTIONS] = {
    { "Tu dois répondre\nà la question\ndes autres !",                  FAMILLE | APERO | HARD,     FALSE,  3 },
    { "Prend une\ncuillère de\nsauce piquante !",                       FAMILLE | APERO,            FALSE,  2 },
    { "Bois une\ngorgée !",                                             APERO | HARD,               FALSE,  1 },
    { "Fait cul sec !",                                                 HARD,                       FALSE,  3 },
    { "Tente une\nvanne !",                                             FAMILLE | APERO,            FALSE,  1 },
    { "Bois 3 shots !",                                                 HARD,                       FALSE,  3 },
    { "Imite la voix\nde Nicolas\nSarkozy !",                           FAMILLE | APERO | HARD,     TRUE,   1 },
    { "Imite la voix\nde Jean-Marie\nBigard !",                         APERO | HARD,               TRUE,   1 },
    { "Imite la voix\nde Jean-Marie\nLepen !",                          APERO | HARD,               TRUE,   1 },
    { "Imite la voix\nde Homer\nSimpson !",                             FAMILLE | APERO | HARD,     TRUE,   1 },
    { "Imite la voix\nde l'âne de\nShrek !",                            FAMILLE | APERO,            TRUE,   1 },
    { "Imite la personne\nde ton choix à\ncette table !",               FAMILLE | APERO | HARD,     TRUE,   2 },
    { "Donne le nom\nde 5 MST !",                                       APERO | HARD,               FALSE,  2 },
    { "Donne le nom\nde 5 actrices X !",                                APERO | HARD,               FALSE,  2 },
    { "Donne le nom\nde 10 animés !",                                   FAMILLE | APERO,            FALSE,  2 },
    { "Imite le\npersonnage\nde ton choix !",                           FAMILLE | APERO | HARD,     FALSE,  1 },
    { "Sors dehors et crie\n\"Vive Zemmour\" !",                        HARD,                       FALSE,  3 },
    { "Mime l'expression\n\"Remuer le couteau\ndans la plaie\" !",      FAMILLE | APERO,            TRUE,   1 },
    { "Mime l'expression\n\"Avoir une langue\nde vipère\" !",           FAMILLE | APERO,            TRUE,   1 },
    { "Mime l'expression\n\"Couper l'herbe\nsous le pied\" !",          FAMILLE | APERO,            TRUE,   1 },
    { "Mime l'expression\n\"Etre haut comme\ntrois pommes\" !",         FAMILLE | APERO,            TRUE,   2 },
    { "Mime l'expression\n\"Ne pas chercher\n12h à 14h\" !",            FAMILLE | APERO,            TRUE,   2 },
    { "Mime l'expression\n\"Mettre la charrue\navant les boeufs\"!",    FAMILLE | APERO,            TRUE,   2 },
    { "Chante une chanson\nchoisie par les\nautres !",                  FAMILLE | APERO | HARD,     FALSE,  2 },
    { "Donne le nom\nde 10 séries !",                                   FAMILLE | APERO,            FALSE,  1 },
    { "Donne le nom\nde 10 films !",                                    FAMILLE | APERO,            FALSE,  1 },
    { "Fait deviner un\nfilm avec une\nréplique !",                     FAMILLE | APERO,            FALSE,  1 },
    { "Termine le verre\nde tous les joueurs !",                        HARD,                       FALSE,  4 }
};

static Action* current = &ACTIONS[0];

Action* ACTIONS_GetCurrent(void) {
    assert(current != NULL);
    return current;
}

Action* ACTIONS_ChooseRandom() {
    while (TRUE) {
        current = &ACTIONS[RANDOM_Get(0, NB_ACTIONS - 1)];
        if (current->modes & MODE_Get()) {
            return current;
        }
    }
}