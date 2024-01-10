/****************************************************
* programme: jeu d'anagrammes						*
* devs: Mohammed Majdoubi & Ahmame Noufel			*
* date: 06/01/2024									*
*description: le jeu d'annagrame est un jeu 		*
*où les joueurs résolvent des mots mélangés pour 	*
accumuler des points.								*
****************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NOMBRE_MOT 100
#define MAX_LONGUEUR_MOT 20
#define MAX_LONGUEUR_NOM 30

char words[NOMBRE_MOT][MAX_LONGUEUR_MOT] = {"programme","informatique","algorithme","developpement",
    "langage","fonction","variable","boucle","condition",
    "tableau","aleatoire","chaine","nombre","operation","structure","pointeur","compilation",
    "debogage","memoire","optimisation","integration","plateforme","interface","graphique",
    "logiciel","materiel","reseau","securite","programmation","logique","binaire","hexadecimal",
    "octet","bit","base","donnees","requete","serveur","client","navigateur","protocole",
    "adresse","fichier","gestionnaire","systeme","exploitation","ordinateur","peripherique","stockage","sauvegarde",
	"circuit","tension","courant","resistance","capacitance","inductance","diode","transistor",
    "oscillateur","amplificateur","modulation","frequence","electronique","signal","alimentation","microcontroleur",
	"capteur","actuateur","composant","relais","transformateur","generatrice","moteur","alternatif","continu","interrupteur",
	"contacteur","interrupteur","sectionneur","connecteur","disjoncteur","fusible","condensateur","transformateur","variateur",
    "mesure","instrument","voltmetre","amperemetre","wattmetre","ohmmetre","oscilloscope","multimeter","batterie",
	"panneau","solaire","courant","appareil","continu","ligne","electrique","charge","sport"};

void MIX(char *word) {
    int length = strlen(word);
   	int i;
    for ( i = length - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}


int main() {
    srand(time(NULL));
    
    FILE* fichierwords;
    fichierwords= fopen("words.txt","w");
    int k;
    for(k=0;k<NOMBRE_MOT;k++){
    
    	fprintf(fichierwords,"%s \n ",words[k]);
	}
	fclose(fichierwords);

    char Nom[MAX_LONGUEUR_NOM];
    printf("Entrez votre nom : ");
    scanf("%s", Nom);
    
    	printf("----------------------------------\n");
    printf("Bienvenue au Jeu d'Anagrammes, %s !\n", Nom);
    printf("----------------------------------\n");
    printf("Vous avez trois vies et vous devez gagner 10 points pour gagner\n");
    printf("----------------------------------\n");
    printf("ouvrir le fichier words.txt si vous voulez jeter un oeil sur les mots existant dans ce jeu\n");
    printf("----------------------------------\n");
    printf("bonne chance %s \n",Nom);
    printf("----------------------------------\n");
    printf("Appuyez sur '0' pour commencer \n");
    char start = getchar(); 
    while (start != '0') {
        start = getchar(); 
    }
    system("clear || cls"); 

   

    int replay = 1;

    while (replay) {
        int vies = 3;
        int score = 0;

        while (vies > 0 && score < 10) {
            int indicateur = rand() % NOMBRE_MOT;
            char original[MAX_LONGUEUR_MOT];
            strcpy(original, words[indicateur]);

            char mixed[MAX_LONGUEUR_MOT];
            strcpy(mixed, original);
            MIX(mixed);

            printf("Trouvez le mot original : %s\n", mixed);

            char guess[MAX_LONGUEUR_MOT];
            scanf("%s", guess);

            if (strcmp(guess, original) == 0) {
                printf("Correct !\n");
                score++;
            } else {
                printf("Incorrect. Vies restantes : %d\n", --vies);
            }

            printf("Score : %d\n\n", score);
        }

        if (score == 10) {
            printf("Félicitations, %s ! Vous avez gagné !\n", Nom);
        } else {
            printf("Dommage, %s. Vous avez perdu.\n", Nom);
        }

        printf("Voulez-vous rejouer ? (1 pour oui, 0 pour non) : ");
        scanf("%d", &replay);

        if (replay) {
            printf("\n");
        }
    }

    printf("Merci, %s, d'avoir joué !\n", Nom);

    return 0;
}
