#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define A 80


typedef struct
{  unsigned dia, mes, anyo;
} DATE;

 struct ALUMNO
{ char DNI[9+1];
  char nom_comp [23];
  DATE nac;
} ;

//Prototipos de esta practica

void print_DATE(DATE );
void print_ALUMNO (struct ALUMNO );
void rand_DATE(DATE  *);
void rand_nom_comp(char [20+1]);
void rand_ALUMNO(struct ALUMNO  *);
unsigned es_fecha_valida(DATE );

//PROTOTIPOS DE PRACTICAS ANTERIORES:

unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );
void rand_str_DNI(char [10]);


int main()
{ struct ALUMNO alumnos[A];
  int i;
    srand(time(NULL));
    for(i=0;i<A;i++){
        rand_ALUMNO(&alumnos[i]);
        print_ALUMNO(alumnos[i]);
    }
    return 0;
}



unsigned es_fecha_valida (DATE fecha){

 switch (fecha.mes) {


 case 1: fecha.dia = rand()%31+1;
         break;
 case 2: if(!fecha.anyo % 4){
           fecha.dia = rand ()%29+1;
            }else{
            fecha.dia = rand()%28+1;
            }
            break;
 case 3:  fecha.dia = rand()%31+1;
          break;
 case 4:  fecha.dia = rand()%30+1;
          break;
 case 5:  fecha.dia = rand()%31+1;
          break;
 case 6:  fecha.dia = rand()%30+1;
          break;
 case 7:  fecha.dia = rand()%31+1;
          break;
 case 8:  fecha.dia = rand()%31+1;
          break;
 case 9:  fecha.dia = rand()%30+1;
          break;
 case 10: fecha.dia = rand()%31+1;
          break;
 case 11: fecha.dia = rand()%30+1;
          break;
 case 12: fecha.dia = rand()%31+1;
          break;
 }
 return fecha.dia;
}

void rand_DATE (DATE *fecha){
 fecha->anyo = rand()%7 + 1999;
 fecha->mes = rand()%12 + 1;
 fecha->dia = es_fecha_valida(*fecha);
}


 void rand_nom_comp(char nom_comp[23]){
  const char nombres[8][10+1]={"jose","roberto","fernando","mario","sandra", "raquel", "isabel", "pilar"};
  const char apellidos[8][10+1]={"garcia", "hernandez", "gutierrez", "gomez", "fernandez", "lopez", "sanchez", "perez" };
  char  delimitador[3] = ", ";


  strcpy(nom_comp, apellidos[rand()%8]);
  strcat(nom_comp, delimitador);
  strcat(nom_comp, nombres[rand()%8]);
 }

 void rand_str_DNI(char dni[10]){
  int i, num;
  for(i=0;i<8;i++) //Obtenemos el Dni aleatorio en un string
   dni[i]=rand()%10 + '0';
  for(i=0, num = 0;i<8;i++) //Pasamos el dni en string a un tipo int para calcular la letra
    num= (num*10) + (dni[i] - '0');
  dni[i] = letra_calculada(resto_DNI(num)); //Calculamos la letra
  dni[i+1] = '\0';
}

  unsigned resto_DNI(unsigned num){
    return (num%23);
}

  char letra_calculada(unsigned resto){
   char letra[23] ={'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
   return letra[resto];
}

 void rand_ALUMNO(struct ALUMNO *alumno){
  char dni[10], nom_completo[23];
  DATE fecha;

  rand_str_DNI(dni);
  strcpy(alumno->DNI, dni);
  rand_nom_comp(nom_completo);
  strcpy(alumno->nom_comp, nom_completo);
  rand_DATE(&fecha);
  alumno->nac = fecha;
 }

  void print_DATE(DATE fecha){
 printf("%u-%u-%u\n", fecha.dia, fecha.mes, fecha.anyo);
 }

 void print_ALUMNO(struct ALUMNO alumno){
 printf("%s   %s   ", alumno.DNI, alumno.nom_comp);
 print_DATE(alumno.nac);
 }



