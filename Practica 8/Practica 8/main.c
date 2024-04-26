#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 100

void strings_swap(char [10], char [10]);
void strings_bubbleSort(char [N][10]);
void print_strings_DNIs(char [N][10]);
void rand_strings_DNIs(char [N][10]);
void rand_str_DNI(char [10]);
unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );


int main()
{ char matriz_DNIs[N][10];

    srand(time(NULL));
    rand_strings_DNIs(matriz_DNIs);

    printf("> DNIs aleatorios:\n");

    print_strings_DNIs(matriz_DNIs);

    printf("\n> DNIs ordenados:\n");

    strings_bubbleSort(matriz_DNIs);

    print_strings_DNIs(matriz_DNIs);

    return 0;
}

void rand_str_DNI(char dni[10]){
  int i, num;
  for(i=0;i<8;i++)  //Obtenemos el Dni aleatorio en un string
    dni[i]=rand()%10 + '0';
  for(i=0, num = 0;i<8;i++) //Pasamos el dni en string a un tipo int para calcular la letra
    num= (num*10) + (dni[i] - '0');
  dni[i] = letra_calculada(resto_DNI(num));  //Calculamos la letra
  dni[i+1] = '\0';

}



unsigned resto_DNI(unsigned num){
 return (num%23);
}

char letra_calculada(unsigned resto){
char letra[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
return letra[resto];
}

void rand_strings_DNIs(char matriz_DNIs[N][10]){
  int i;
  char dni[10];
  for(i=0;i<N;i++){
    rand_str_DNI(dni);
    strcpy(matriz_DNIs[i],dni);
  }
}

void print_strings_DNIs(char matriz_DNIs[N][10]){
int i;
   for(i=0;i<N;i++)
     printf("%s ", matriz_DNIs[i]);
   printf("\n");
 }

void strings_bubbleSort(char matriz_DNIs[N][10]){
int i,j;
 for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
        if(memcmp(matriz_DNIs[j],matriz_DNIs[j-1],9)<0)
            strings_swap(matriz_DNIs[j],matriz_DNIs[j-1]);
    }
 }

}

void strings_swap(char string1[10],char string2[10]){
char aux[10];
 strcpy(aux,string1);
 strcpy(string1,string2);
 strcpy(string2,aux);

}




