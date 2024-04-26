#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 9

void rand_dig (char *);
void rand_DNI (unsigned *);
void rand_DNIs (unsigned [N], char [N]);
void print_DNIs (unsigned [N], char [N]);
void calcular_frecuencias (char [N], unsigned [26], float [26]);
void print_frecuencias (unsigned [26], float [26]);
void print_barra (float);

char letra_calculada(unsigned );
unsigned resto_DNI(unsigned );

int main()
{ unsigned *dni, resto;
   char letra;
    srand(time(NULL));
    rand_DNI(&dni);
    resto = resto_DNI(dni);
    letra=letra_calculada(resto);
    printf("dni: %u", dni);
}

void rand_DNI (unsigned *dni){
  int i;
  char car, digito;
  for(i=1;i<=N;i++){
  printf("/nDNI digito %u: ", i);
  rand_dig(&digito);
  *dni = *dni*10 + (digito + '0');
  }
}

void rand_dig (char *digito){
  digito=rand()%10+'0';
}



char letra_calculada(unsigned resto){
char letra[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
return letra[resto];
}

unsigned resto_DNI(unsigned num){
 return (num%23);
}

