#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void swap_unsigned(unsigned*, unsigned*);
void swap_char(char*, char*);
void bubbleSort(unsigned [N], char [N]);
void rand_dig (char *);
void rand_DNI (unsigned *);
void rand_DNIs (unsigned [N], char [N]);
void print_DNIs (unsigned [N], char [N]);
unsigned resto_DNI(unsigned);
char letra_calculada(unsigned );




int main()
{ unsigned *DNIs = malloc(N*sizeof(unsigned));
  char *letras = malloc(N*sizeof(char));
 *DNIs;

    srand(time(NULL));
    rand_DNIs(DNIs,letras);
    printf("> DNIs (con letra) aleatorios:\n");
    print_DNIs(DNIs,letras);
    bubbleSort(DNIs, letras);
    printf("\n> DNIs (con letra) ordenados:\n");
    print_DNIs(DNIs,letras);


    free(DNIs);
    free(letras);
    return 0;
}


void rand_dig (char *digito){
  *digito=rand()%10+'0';
}

void rand_DNI (unsigned *dni){
  int i;
  char digito;
  for(i=1;i<=8;i++){
  rand_dig(&digito);
  *dni = (*dni*10) + (digito - '0');
  }


}

void rand_DNIs (unsigned DNIs[N], char letras[N]){
  unsigned dni=0, i, resto;
  char letra;
  for(i=0;i<N;DNIs[i]=dni, letras[i]= letra, i++, dni=0){
    rand_DNI(&dni);
    resto = resto_DNI(dni);
    letra=letra_calculada(resto);
   }
}

unsigned resto_DNI(unsigned num){
 return (num%23);
}

char letra_calculada(unsigned resto){
char letra[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
return letra[resto];
}



void print_DNIs (unsigned dnis[N], char letras[N]){
int i;
  for(i=0;i<N;i++)
    printf("%08u-%c ", dnis[i],letras[i]);  //El 08u muestra tambien el 0

}

void bubbleSort(unsigned DNIs[N], char letras[N]){
 int i,j, aux;

 for(i=0;i<N;i++){
        for(j=N-1;j>i;j--){
        if(DNIs[j]<DNIs[j-1]){
            swap_unsigned(&DNIs[j],&DNIs[j-1]);
            swap_char(&letras[j],&letras[j-1]);
          }
        }


    }

 }
 void swap_unsigned(unsigned *menor, unsigned *mayor){
 unsigned *aux = malloc(sizeof(unsigned));
   *aux = *menor;
   *menor = *mayor;
   *mayor = *aux;
   free(aux);
 }
void swap_char(char *menor, char *mayor){
char *aux = malloc(sizeof(char));
   *aux = *menor;
   *menor = *mayor;
   *mayor = *aux;
   free(aux);
 }



