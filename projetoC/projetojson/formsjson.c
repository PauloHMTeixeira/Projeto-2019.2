#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    int cha1;
    int cha2;
    int i;
    int c;
    int c2;
    char conteudo[15000];
    char arquivo[15000];
    char name[50], surname[50], nacio[50];
    int marks;
    printf("Diga o nome e sobrenome do(a) visitante: ");
    scanf("%s %s", name, surname);
    printf("Diga a nacionalidade do(a) visitante: ");
    scanf("%s", nacio);
    printf("Diga a idade do(a) visitante: ");
    scanf("%d", &marks);
    fp = fopen("banco_dados_branco.json", "w");
    fprintf(fp, ",\n{\n    !%s %s!: {\n        !Nacionalidade!:!%s!,\n        !Idade!:!%d!\n    }",name, surname, nacio, marks);
    fclose(fp);

    fp = fopen("banco_dados_branco.json", "r");
    for(i=0; !feof(fp); i++){
        fscanf(fp,"%c",&conteudo[i]);
        c++;
    }
    
    i=0;
    while(i<c-1){
        if(conteudo[i] == '!'){
            conteudo[i] = '"';
        }
        i++;
    }
    fclose(fp);

    fp = fopen("teste.json","r");
    for(i=0; !feof(fp); i++){
        fscanf(fp, "%c",&arquivo[i]);
        c2++;
    }
    i=0;
    
    fclose(fp);

    fp = fopen("teste.json","w");
    i=0;
    while(i<c2-2){
        fprintf(fp,"%c",arquivo[i]);
        i++;
    }
    fclose(fp);

    fp = fopen("teste.json","a");
    i=0;
    while(i<c-1){
        fprintf(fp,"%c",conteudo[i]);
        i++;
    }
    fprintf(fp,"}");
}