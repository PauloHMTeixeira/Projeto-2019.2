//forms utilizado "a" para dar append nno arquivo txt

#include <stdio.h>
#include <stdlib.h>
int main() {
	char name[50], nacio[50];
	int marks,i,n;
	printf("Insira número de visitantes: ");
	scanf("%d",&n);
	FILE *fptr;
	fptr=(fopen("visitantes.txt","a"));
	if(fptr==NULL) {
		printf("Error!");
		exit(1);
	}
	for (i=0;i<n;++i) {
		printf("Para visitante%d\nInsira nome: ",i+1);
		scanf("%s",name);
		printf("Insira nacionalidade: ");
		scanf("%s",nacio);
		printf("Insira idade: ");
		scanf("%d",&marks);
		fprintf(fptr,"\nName: %s \nIdade: %d \nNacionalidade: %s \n",name,marks,nacio);
	}
	fclose(fptr);
	return 0;
}
