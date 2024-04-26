#include <stdio.h>
#include <stdlib.h>

int main(){
 unsigned i, num, act, resto=0;
 char letra = 'T';

for(i=1, num=0;i<=8;i++){
  do {
   printf("DNI digito %u: ", &i);
   scanf("%u", &act);
     } while(act>9 && act <0);
    num=num*10+act;
  }

printf("\n > DNI: %u\n", num);
resto = num%23;
printf("\n> RestoDNI: %u\n", resto);
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

printf("> DNI: %u           letra: %c", num, letra);


}

//Leer el numero entero con una string y meterlo en un enteero sin signo



