#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define A 80

typedef struct
{ unsigned dia,mes,anyo;
} DATE;

struct ALUMNO
{ char DNI[9+1];
  char nom_comp [20+1];
  DATE nac;
};

//PROTOTIPOS DE ESTA PRACTICA

void all_swap(struct ALUMNO *, struct ALUMNO *);
void all_bubbleSort(struct ALUMNO  [A], unsigned);
void fprint_DATE(FILE *, DATE);
void fprint_ALUMNO (FILE *, struct ALUMNO);

//PROTOTIPOS DE PRACTICAS ANTERIORES

void print_DATE(DATE );
void print_ALUMNO (struct ALUMNO );
void rand_DATE(DATE  *);
void rand_nom_comp(char [20+1]);
void rand_ALUMNO(struct ALUMNO  *);
unsigned es_fecha_valida(DATE );

unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );
void rand_str_DNI(char [10]);


int main()
{ struct ALUMNO alumnos[A], alum;
  unsigned i, anyo, opc;
  FILE *f_in,*f_out, *f_ordenado;
  char buscNombre, linea[120];

    srand(time(NULL));
    printf("generandose datos aleatorios...\n");
    for(i=0;i<A;i++){
        rand_ALUMNO(&alumnos[i]);
        print_ALUMNO(alumnos[i]);
    }

    printf("\ngenerandose fichero de texto...\n");  // Apertura del fichero de texto 1
    if(!(f_out=fopen("alum.txt", "w"))){
        printf("Error en la apertura del fichero de texto\n");
        return(1);
    }
    for(i = 0;i<A;i++){
        fprint_ALUMNO(f_out,alumnos[i]);
        fprint_DATE(f_out,alumnos[i].nac);
    }

    printf ("\ngenerandose fichero binario...\n");  // Apertura del fichero binario
    if(!(f_in=fopen("alum.bin", "wb"))){
        printf("Error en la apertura del fichero binario\n");
        return(2);
    }
    fwrite(&alumnos,sizeof(struct ALUMNO),A,f_in);
    fclose(f_out);
    fclose(f_in);

    if(!(f_in=fopen("alum.bin", "rb"))){ //Apertura fichero binario para lectura
        printf("Error en la apertura del fichero binario\n");
        return 3;
    }

    printf("anyo a buscar en los datos del fichero binario? ");
    fflush(stdin);
    scanf("%u", &anyo);
    while(fread(&alum,sizeof(struct ALUMNO),1,f_in)){
        if(alum.nac.anyo == anyo){
            print_ALUMNO(alum);
        }
    }

    if(!(f_ordenado=fopen("alumOrd.txt", "w"))){
        printf("Error en la apertura del fichero de texto Ordenado\n");
        return(4);
    }

    printf("\ngenerar fichero de texto con datos ordenados por dni (1) o por nombre completo (2)?\n ");
    do{
    fflush(stdin);
    scanf("%u", &opc);
    } while (opc != 1 && opc != 2);
    all_bubbleSort(alumnos, opc);
    for(i=0;i<A;i++){
    fprint_ALUMNO(f_ordenado,alumnos[i]);
    fprint_DATE(f_ordenado,alumnos[i].nac);
    }

    printf("Nombre completo a buscar en los datos del fichero ordenado de texto? \n");
    fflush(stdin);
    scanf("%s", &buscNombre);
    while (fgets(&linea,120,f_ordenado)){
        if(strstr(linea,buscNombre)){
            printf("%s\n", linea);
        }
    }
    fclose(f_ordenado);
    fclose(f_in);
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

 void fprint_ALUMNO (FILE *f_out, struct ALUMNO alum){
 fprintf(f_out, "%10s    %-23s",alum.DNI,alum.nom_comp );
 }

 void fprint_DATE (FILE *f_out, DATE nac){
fprintf(f_out, "%02u-%02u-%04u\n", nac.dia, nac.mes, nac.anyo);
 }

void all_swap(struct ALUMNO *a1, struct ALUMNO *a2){
struct ALUMNO aux;
aux=*a1;
*a1=*a2;
*a2=aux;
}
void all_bubbleSort(struct ALUMNO alumnos[A], unsigned selec){
unsigned i,j;

    if(selec == 1){       //Generar fich y ordenarlo por dni

     for(i=A;i-1;i--){
        for(j=0;j<i;j++){
            if(strcmp(alumnos[j].DNI,alumnos[j+1].DNI)> 0){
                all_swap(&alumnos[j],&alumnos[j+1]);
            }
        }
     }

    } else if(selec == 2){            //Generar fich y ordenarlo por nombre completo
       for(i=A;i;i--){
        for(j=0;j<i;j++){
            if(strcmp(alumnos[j].nom_comp,alumnos[j+1].nom_comp)> 0){
                all_swap(&alumnos[j],&alumnos[j+1]);
                                                                 }

                        }
                     }
               }
}

