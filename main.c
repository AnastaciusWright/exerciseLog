#include <stdio.h>
#include <stdlib.h>

#define MAX_QUANTITY 100
#define MAX_LONGITUD 40

struct ejercicio
{
  char nombre[MAX_LONGITUD];
};

typedef struct ejercicio ejer;

struct base_datos
{
  ejer lista_ejercicios[MAX_QUANTITY];
  
};

typedef struct base_datos bd;
void nuevo_ejercicio()
{
  FILE *ptr_archivo = fopen("ejercicios.bin","ab+");
  printf("Ejercicios existentes");
  
  printf("Ingrese el nombre del nuevo ejercicio\n");
  ejer *temp1= malloc(sizeof(ejer));
  fgets(temp1->nombre,40,stdin);
  printf("El nombre del ejercicio es %s",temp1->nombre);
  fwrite(&(temp1->nombre),sizeof(ejer),1,ptr_archivo);
  fclose(ptr_archivo);
  free(temp1);

}
int main()
{

  bd *Base=malloc(sizeof(Base));
  printf("Exercise Log\n");
  printf("1.Comenzar\n");
  printf("2.Crear nuevo ejercicio\n");

  int selection=0;
  scanf("%d",&selection);
  getchar();
  
  switch(selection)
  {
    case 1:
      break;
    case 2:
      nuevo_ejercicio();
      break;
    default:
      break;
  }
  getchar();
  return 0;
}

