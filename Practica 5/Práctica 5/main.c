#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define K 9
#define N 100


void rand_dig (char *);
void rand_DNI (unsigned *);
void rand_DNIs (unsigned [N], char [N]);
void print_DNIs (unsigned [N], char [N]);
void calcular_frecuencias (char [N], unsigned [26], float [26]);
void print_frecuencias (unsigned [26], float [26]);
void print_barra (float); //Es lo de imprimir los asteriscos

char letra_calculada(unsigned );
unsigned resto_DNI(unsigned );

int main()
{ unsigned dnis[N] = {0}, numLetras[26]={0};
   char letras[N];
   float frecuencias[26];
    srand(time(NULL));
    printf("> DNIs y letras:\n");
    rand_DNIs(dnis,letras);
    print_DNIs(dnis,letras);
    calcular_frecuencias(letras,numLetras,frecuencias);
    print_frecuencias(numLetras,frecuencias);
}

void rand_DNI (unsigned *dni){
  int i;
  char digito;
  for(i=1;i<=K;i++){
  rand_dig(&digito);
  *dni = (*dni*10) + (digito - '0');
  }
}

void rand_dig (char *digito){
  *digito=rand()%10+'0';
}



char letra_calculada(unsigned resto){
char letra[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
return letra[resto];
}

unsigned resto_DNI(unsigned num){
 return (num%23);
}
void print_DNIs (unsigned dnis[N], char letras[N]){
int i;
  for(i=0;i<N;i++)
    printf("%u-%c ", dnis[i],letras[i]);

}
void rand_DNIs (unsigned nums[N], char chars[N]){
  unsigned dni=0, i, resto;
  char letra;
  for(i=0;i<N;nums[i]=dni, chars[i]= letra, i++){
    rand_DNI(&dni);
    resto = resto_DNI(dni);
    letra=letra_calculada(resto);
   }
}
void calcular_frecuencias(char letras[N], unsigned numLetras[26], float frec[26]){
int i;
 for(i=0;i<N;i++){
    numLetras[letras[i]-'A']++;
 }
 for(i=0;i<26;i++)
    frec[i]=((float)numLetras[i]/N);
}

void print_frecuencias (unsigned numLetras[26], float frecuencias[26]){
 int i;
 printf("\n> Frecuencias absolutas, relativas y diagrama de barras:");
 for(i=0;i<26;i++){
    printf("\n%c      %u  %f ", 'A'+i,numLetras[i],frecuencias[i]);
    print_barra(frecuencias[i]);
 }
}
void print_barra(float frecuencia){
int i;
  for(i=0, frecuencia*=100;i<frecuencia;i++)
    printf("*");
}



