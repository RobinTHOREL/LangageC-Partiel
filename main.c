#include <stdio.h>
#include <string.h>

int wordInDict() { //Partie 2. - 1

    char word[30];
    char buffer[30];
    char bufferMin[30] = {'\0'};

    FILE *fichier = fopen("C:\\Users\\Kush\\CLionProjects\\Partiel\\dict.txt", "r");

    if(fichier != NULL){
        //action
        printf("Le fichier existe\nEcrire un mot de la langue francaise : \n");
        scanf("%s",word);

        while(fgets(buffer, sizeof(word),fichier)!=NULL){
            strncpy(bufferMin, buffer, strlen(word));
           if(strcmp(word, bufferMin) == 0) {
                printf("Le mot est %s a ete trouve dans le dictionnaire\n", word);
               return 1;
            }
        }
        printf("Fermeture du fichier");
        fclose(fichier);
    } else {
        printf("Erreur (le fichier existe-t-il vraiment?)");
        return 0;
    }

}

void putWordIntoDict(){ //Partie 2. - 2
    char word[30];
    char buffer[30];
    char bufferMin[30] = {'\0'};
    int i = 0;

    FILE *fichier = fopen("C:\\Users\\Kush\\CLionProjects\\Partiel\\dict.txt", "r+");

    if(fichier != NULL){
        printf("Le fichier existe\nEcrire un mot a inserer : \n");
        scanf("%s",word);

       //action
        while(fgets(buffer, sizeof(word),fichier)!=NULL){
            strncpy(bufferMin, buffer, strlen(word));

            while((word[i] == bufferMin[i]) && (word[i] != '\0' && bufferMin[i] != '\0')) {
                if(fputs(word, fichier)){
                    printf("Le mot a ete inserer\n");
                    i++;
                }
            }

        }

        printf("Fermeture du fichier");
        fclose(fichier);
    } else {
        printf("Erreur (le fichier existe-t-il vraiment?)");
    }
}

void deleteWordFromDict() {// Partie 2. - 3
    char word[30];
    char buffer[30];
    char bufferMin[30] = {'\0'};

    FILE *fichier = fopen("C:\\Users\\Kush\\CLionProjects\\Partiel\\dict.txt", "r+");
    FILE *fichierFinal = fopen("C:\\Users\\Kush\\CLionProjects\\Partiel\\dictSuppr.txt", "w");

    if(fichier != NULL && fichierFinal != NULL){
        //action
        printf("Le fichier existe\nEcrire un mot a supprimer du dictionnaire : \n");
        scanf("%s",word);

        while(fgets(buffer, sizeof(word),fichier)!=NULL){
            strncpy(bufferMin, buffer, strlen(word));
            if(strcmp(word, bufferMin) == 0)
                printf("Le mot %s a ete rencontrer\n", bufferMin);
            else
                fputs(bufferMin, fichierFinal);
        }
        printf("Fermeture des fichiers");
        fclose(fichier);
        fclose(fichierFinal);
    } else {
        printf("Erreur (le fichier existe-t-il vraiment?)");
    }
}

int main(int argc, char *argv[]) {
    int choice=0;
    printf("Choisissez l'action : \n1 : Rechercher un mot dans un fichier\n2 : Inserer un mot dans un fichier\n"
                   "3 : Supprimer un mot du fichier\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            wordInDict();
            break;
        case 2:
            putWordIntoDict();
            break;
        case 3:
            deleteWordFromDict();
            break;
        default:
            break;
    }
    return 0;
}