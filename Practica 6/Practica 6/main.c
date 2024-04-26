#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 100
void buscar_substring(char [N][10]);
void buscar_letra(char [N][10]);
void print_menu ();
void print_strings_DNIs(char [N][10]);
void rand_strings_DNIs(char [N][10]);
void rand_str_DNI(char [10]);
unsigned resto_DNI(unsigned);
char letra_calculada(unsigned );

//funcion swap de la siguiente es para intercambiar 2 caracteres solo

int main()
{
char matriz_DNIs[N][10],opcion;
    srand(time(NULL));
    rand_strings_DNIs(matriz_DNIs);
    print_strings_DNIs(matriz_DNIs);
    print_menu();
    do{
    fflush(stdin);
    opcion = getch();
    if(opcion == '1')
        buscar_letra(matriz_DNIs);
    else if(opcion == '2')
        buscar_substring(matriz_DNIs);


    } while (opcion != '0');
    return 0;

}
void rand_str_DNI(char DNI[10]){
int i, num;

 for(i=0;i<8;i++)  //Genera la parte numerica random
    DNI[i] = rand()%10 + '0';
for(i=0, num = 0;i<8;i++) //Pasa la string a un int
        num = num*10 + (DNI[i] - '0');
 DNI[i]=letra_calculada(resto_DNI(num));
 DNI[i+1]='\0';
}
unsigned resto_DNI(unsigned num){
 return (num%23);
}

char letra_calculada(unsigned resto){
char letra[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
return letra[resto];
}

void rand_strings_DNIs(char matriz_DNIs [N][10]){
int i;
char DNI[10];
for(i=0;i<N;i++){
    rand_str_DNI(DNI);
    strcpy(matriz_DNIs[i],DNI);
  }
}

void print_strings_DNIs(char matriz_DNIs [N][10]){
    int i;
 for(i=0;i<N;i++)
    printf("%s ", matriz_DNIs[i]);
printf("\n");
}

void print_menu(){
 printf("\n1 buscar letra\n");
 printf("2 buscar substring\n");
 printf("0 para acabar(END)\n");
}

void buscar_letra(char matriz_DNIs[N][10]){
    char letra;
    int i;

printf("Letra a buscar?: \n");
do{
   fflush(stdin);
   letra = getch();
   if (letra >= 'a' && letra <= 'z')
        letra-=32;
  } while(letra < 'A' || letra > 'Z');

for(i=0;i<N;i++){
    if(strchr(matriz_DNIs[i], letra)){
        printf("> %s  ", matriz_DNIs[i]);
    }
  }
    printf("\n");
}

void buscar_substring(char matriz_DNIs[N][10]){
int i;
    char substring[10];
printf("Substring a buscar?: \n");
  fflush(stdin);
  scanf("%s", substring);

for(i=0;i<N;i++){
    if(strstr(matriz_DNIs[i], substring)){
        printf("> %s  ", matriz_DNIs[i]);
    }
  }
  printf("\n");
}





