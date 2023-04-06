#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 
#define N 100
#define MAX 100
int main () {
    FILE* mesFringues = NULL;
    FILE* mesFringuesJSON = NULL;

    char ligne[N];
    int nbligneslues = 0;
    int nbcolonneslues = 0;
    char* laLigne;
    laLigne=malloc(sizeof(char)*N);
    
    mesFringues = fopen("mesFringues.csv", "r");
    mesFringuesJSON =fopen("mesFringues.json", "w+");
    if (mesFringues == NULL) {
        printf("Erreur ouverture fichier \n");
    }
    else{
        if (mesFringuesJSON != NULL) {
            printf("Fichier CSV: \n");
            while(fgets(ligne,N,mesFringues)!=NULL){
                laLigne= strtok(ligne,";");
                while (laLigne!=NULL){
                    printf("colonne N°%d => %s \n", nbcolonneslues, laLigne);
                    fprintf(mesFringuesJSON,"%s", laLigne);
                    laLigne = strtok(NULL, ";");
                    nbcolonneslues++;
                
                }
            
                printf("\n");
                nbcolonneslues=0;
                nbligneslues++;
            }   
        fclose(mesFringues);
        fclose(mesFringuesJSON);
    }
} 
return 0;
}