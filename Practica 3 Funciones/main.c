#include <stdio.h>
#include <stdlib.h>
void scan_letra(char *);
void scan_dig(char *);
void scan_DNI(unsigned *);
unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );
void print_menu ();
void scan_opcion(char * );

int main()
{ char opcion_menu, letrasc, letra;
  unsigned resto = 0, *num = 0;
do{
 print_menu();
 scan_opcion(&opcion_menu);
  if(opcion_menu=='1'){
   scan_DNI(&num);
   printf("\n > DNI: %u\n", num);
   resto=resto_DNI(num);
   printf("\n> RestoDNI: %u\n", resto);
   letra=letra_calculada(resto);
   printf("> DNI: %u letra: %c\n", num, letra);
  } else if(opcion_menu=='2'){
      scan_DNI(&num);
      printf("\n > DNI: %u\n", num);
      scan_letra(&letrasc);
      fflush(stdin);
      printf("\n >Letra leida: %c\n", letrasc);
      resto=resto_DNI(num);
      printf("\n> RestoDNI: %u\n", resto);
      letra=letra_calculada(resto);
      printf("> DNI: %u letra calculada: %c\n", num, letra);
      if(letra==letrasc)
          printf("Letra correcta!\n");
      else
          printf("Letra introducida no corresponde\n");
  }
num = 0;
 } while (opcion_menu!='0');
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
 }

void scan_letra(char *letrasc){
   printf("¿Letra?\n");
   scanf(" %c", letrasc);
   fflush(stdin);
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
char letra;

switch(resto){
case 0: letra = 'T';
break;
case 1: letra = 'R';
break;
case 2: letra = 'W';
break;
case 3: letra = 'A';
break;
case 4: letra = 'G';
break;
case 5: letra = 'M';
break;
case 6: letra = 'Y';
break;
case 7: letra = 'F';
break;
case 8: letra = 'P';
break;
case 9: letra = 'D';
break;
case 10: letra = 'X';
break;
case 11: letra = 'B';
break;
case 12: letra = 'N';
break;
case 13: letra = 'J';
break;
case 14: letra = 'Z';
break;
case 15: letra = 'S';
break;
case 16: letra = 'Q';
break;
case 17: letra = 'V';
break;
case 18: letra = 'H';
break;
case 19: letra = 'L';
break;
case 20: letra = 'C';
break;
case 21: letra = 'K';
break;
case 22: letra = 'E';
break;
}
fflush(stdin);
return letra;
}

void print_menu(){
printf("1-Calculador de letras DNI\n");
printf("2-Comprueba si tu letra del DNI es correcta\n");
printf("0-Para acabar\n");
}

void scan_opcion(char *opcion_menu ){
 scanf(" %c",opcion_menu);
}
