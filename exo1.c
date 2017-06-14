#include <stdio.h>
#include<string.h>
int motsEgaux(char* str1,char* str2)
    {
         return (strcmp(str1, str2));

    }
int main() {
    char mot1[100];
    char mot2[100];
    printf("Entrer deux mots pour tester s ils sont egaux : \n");
    printf("Mot 1 :");
    scanf("%s", &mot1);
    printf("Mot 2 :");
    scanf("%s",&mot2);
    if(motsEgaux(mot1,mot2) ==0)
    {
        printf("Les deux mots sont identiques.");
    }
    else if(motsEgaux(mot1,mot2)==1){
        printf("L'ordre alphabetique des deux mots est : %s puis %s.",mot2,mot1);
    }
    else{
        printf("L'ordre alphabetique des deux mots est : %s puis %s.",mot1,mot2);
    }



}
