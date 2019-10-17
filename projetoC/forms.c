//forms utilizando "w" para write no arquivo txt (quando não criado ainda).

#include <stdio.h>
#include <stdlib.h>
int main() {
	char name[50], surname[50], nacio[50];
	int marks,i,n;
	printf("Insira número de visitantes: ");
	scanf("%d",&n);
	FILE *fptr;
	fptr=(fopen("visitantes.txt","w"));
	if(fptr==NULL) {
		printf("Error!");
		exit(1);
	}
	for (i=0;i<n;++i) {
		printf("Para visitante%d\nInsira nome: ",i+1);
		scanf("%s %s",name, surname);
		printf("Insira nacionalidade: ");
		scanf("%s",nacio);
		printf("Insira idade: ");
		scanf("%d",&marks);
		fprintf(fptr,"\nName: %s %s \nIdade: %d \nNacionalidade: %s \n",name,surname,marks,nacio);
	}
	fclose(fptr);
	return 0;
}
