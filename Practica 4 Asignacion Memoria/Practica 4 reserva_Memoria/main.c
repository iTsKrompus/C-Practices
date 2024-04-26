#include <stdio.h>
#include <stdlib.h>
#define N 23

void scan_letra(char *);
void scan_dig(char *);
void scan_DNI(unsigned *);
unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );
void validar_letra_DNI(unsigned, char);  //Nueva

int main()
{ char *letrasc = (char *)malloc(sizeof(char)); //Se declaran como variables porque al reservar memoria con el malloc este devuelve la direccón
  unsigned *resto = (unsigned *)malloc(sizeof(unsigned)), *num = (unsigned *)malloc(sizeof(unsigned)); //De memoria de la memoria reservada
  *num = 0; //Por eso se indica como puntero, ya que estos son direccicones de memoria
  scan_DNI(num);


      scan_letra(letrasc);
      fflush(stdin);
      printf("\n >Letra leida: %c\n", *letrasc);
      *resto=resto_DNI(*num);
      printf("\n> RestoDNI: %u\n", *resto);
      validar_letra_DNI(*resto, *letrasc);
      free(letrasc);
      free(resto);
      free (num);

}


void scan_DNI(unsigned *num){
 unsigned i,act;
 char car;
 for(i=1;i<=8;i++){
   printf("DNI digito %u: ", i);
   scan_dig(&car);
   fflush(stdin);
   act = car - '0';
   *num=(*num)*10+act;
  }
   printf("\n > DNI: %u", *num);
 }

void scan_letra(char *letrasc){
   printf("\n¿Letra?\n");
   fflush(stdin);
   scanf(" %c", letrasc);
     if((*letrasc)>='a' && (*letrasc)<='z')
         (*letrasc)-=32;
}

void scan_dig(char *car){
     do{
      fflush(stdin);
      scanf("%c", car);
   } while(*car>'9' || *car <'0');
}

unsigned resto_DNI(unsigned num){
 return (num%23);
}

char letra_calculada(unsigned resto){
char letra[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
return letra[resto];
}

void validar_letra_DNI(unsigned resto, char letrasc){
     char letra;

     letra=letra_calculada(resto);
   if(letra==letrasc)
          printf("> Letra correcta!\n");
      else {
          printf("> Letra introducida incorrecta\n");
          printf("> Letra correcta: %c\n",letra);

  }

  //Generar numero entre 1 y 100: rand()%100+1 para generar negativos: * rand()%2? -1:1  Es 0? devuelve el pos, es 1? lo hace negativo
}


