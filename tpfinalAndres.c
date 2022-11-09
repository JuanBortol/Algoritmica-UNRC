#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
	long int ddmmyyyy;
	int tmax;
	int tmin;
	int HUM;
	int PNM;
	int DV;
	int FF;
	int PP;
	int borrado;
}Tregdiario;

Tregdiario registro;

FILE * f;
FILE * backup;

char directorio[]="/home/juan/Escritorio/proyecto final/";
char nomArch[50];
char nombreFecha[50];
char ext[]=".dat";
char sn;


///////MOSTRAR //////////////////////////////////////////////
void MostrarRegistroClima(char *nomArch){
  Tregdiario aux;
  FILE *f;
  f = fopen(nomArch,"rb");
  if (feof(f)){
    printf("El archivo no tiene registros cargados.\n");
    }
  else{  
  while(fread(&aux,sizeof(Tregdiario), 1, f) > 0){  
    if (! aux.borrado){
			printf("\n----------------------------------------------------------------------------------------------\n");
      printf("Al dia %li/%li/%li, se registraron los siguientes parametros climaticos:\n\n",(aux.ddmmyyyy/1000000),((aux.ddmmyyyy/10000)%100),(aux.ddmmyyyy%10000));
      printf("Temperatura máxima:%d\n",aux.tmax);
      printf("Temperatura mínima:%d\n",aux.tmin);
      printf("Humedad promedio:%d \n",aux.HUM);
      printf("Presión atmosferica:%d hPa\n",aux.PNM);
      printf("Dirección del viento:%d  \n",aux.DV);
      printf("Velocidad del viento:%d km/h \n",aux.FF);
      printf("Precipitaciones:%d mm\n",aux.PP);
			printf("----------------------------------------------------------------------------------------------\n");

    }
  }
 }
 fclose(f);
}
/////////////////////////////////////////////////////////////


////////CARGA FECHA//////////////////////////////////////////
void CargarFecha (long int *fecha){
	int dia;
	int mes;
	int anio;
	int bisiesto;
	printf("Ingrese el año:\n");
	scanf("%d", &anio);
	if (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)){
		bisiesto = 1;
	} else {
		bisiesto = 0;
	}
	do {
		printf("Ingrese el mes:\n");
		scanf("%d", &mes);
		if (mes < 1 || mes > 12){
			printf ("El valor del mes debe ser entre 1 y 12\n");
			mes = 0;
		}
	} while (mes == 0);
	do {
		switch (mes){
			case 1: printf("Ingrese el día:\n");
					scanf("%d", &dia);
					if (dia < 1 || dia > 31){
						printf("El valor ingresado es erroneo, debe ser entre 1 y 31\n");
						*fecha = 0;
					} else {
						*fecha = anio + (mes * 10000) + (dia * 1000000);
					};break;
			case 2: printf("Ingrese el día:\n");
					scanf("%d", &dia);
					if (mes == 2 && bisiesto == 1 && (dia < 1 || dia > 29)){
						printf("El valor ingresado es erroneo, debe ser entre 1 y 29\n");
						*fecha = 0;
					}else if (mes == 2 && bisiesto == 0 && (dia < 1 || dia > 28)){
						printf("El valor ingresado es erroneo, debe ser entre 1 y 28\n");
						*fecha = 0;
					}else {
						*fecha = anio + (mes * 10000) + (dia * 1000000);
					};break;
			case 3: printf("Ingrese el día:\n");
					scanf("%d", &dia);
					if (dia < 1 || dia > 31){
						printf("El valor ingresado es erroneo, debe ser entre 1 y 31\n");
						*fecha = 0;
					} else {
						*fecha = anio + (mes * 10000) + (dia * 1000000);
					};break;
			case 4: printf("Ingrese el día:\n");
					scanf("%d", &dia);
					if (dia < 1 || dia > 30){
						printf("El valor ingresado es erroneo, debe ser entre 1 y 30\n");
						*fecha = 0;
					} else {
						*fecha = anio + (mes * 10000) + (dia * 1000000);
					};break;
			case 5: printf("Ingrese el día:\n");
					scanf("%d", &dia);
					if (dia < 1 || dia > 31){
						printf("El valor ingresado es erroneo, debe ser entre 1 y 31\n");
						*fecha = 0;
					} else {
						*fecha = anio + (mes * 10000) + (dia * 1000000);
					};break;
			case 6: printf("Ingrese el día:\n");
					scanf("%d", &dia);
					if (dia < 1 || dia > 30){
						printf("El valor ingresado es erroneo, debe ser entre 1 y 30\n");
						*fecha = 0;
					} else {
						*fecha = anio + (mes * 10000) + (dia * 1000000);
					};break;
			case 7: printf("Ingrese el día:\n");
					scanf("%d", &dia);
					if (dia < 1 || dia > 31){
						printf("El valor ingresado es erroneo, debe ser entre 1 y 31\n");
						*fecha = 0;
					} else {
						*fecha = anio + (mes * 10000) + (dia * 1000000);
					};break;
			case 8: printf("Ingrese el día:\n");
					scanf("%d", &dia);
					if (dia < 1 || dia > 31){
						printf("El valor ingresado es erroneo, debe ser entre 1 y 31\n");
						*fecha = 0;
					} else {
						*fecha = anio + (mes * 10000) + (dia * 1000000);
					};break;
			case 9: printf("Ingrese el día:\n");
					scanf("%d", &dia);
					if (dia < 1 || dia > 30){
						printf("El valor ingresado es erroneo, debe ser entre 1 y 30\n");
						*fecha = 0;
					} else {
						*fecha = anio + (mes * 10000) + (dia * 1000000);
					};break;
			case 10: printf("Ingrese el día:\n");
					 scanf("%d", &dia);
					 if (dia < 1 || dia > 31){
					 	 printf("El valor ingresado es erroneo, debe ser entre 1 y 31\n");
						 *fecha = 0;
					 } else {
						 *fecha = anio + (mes * 10000) + (dia * 1000000);
					 };break;
			case 11: printf("Ingrese el día:\n");
					 scanf("%d", &dia);
					 if (dia < 1 || dia > 31){
						 printf("El valor ingresado es erroneo, debe ser entre 1 y 31\n");
						 *fecha = 0;
					 } else {
						 *fecha = anio + (mes * 10000) + (dia * 1000000);
					 };break;
			case 12: printf("Ingrese el día:\n");
					 scanf("%d", &dia);
					 if (dia < 1 || dia > 31){
						 printf("El valor ingresado es erroneo, debe ser entre 1 y 31\n");
						 *fecha = 0;
					 } else {
						 *fecha = anio + (mes * 10000) + (dia * 1000000);
					 };break;
			default: printf("La fecha ingresada es erronea\n");
		}
	}while(fecha == 0);
	printf("La fecha ingresada es: %li \n", *fecha);
}
/////////////////////////////////////////////////////////////


////////CARGA /////////////////////////////////////////////// Falta Validacion de los datos!!!!!!
void Cargaregistro(Tregdiario *reg){
  printf ("Ingrese el valor de temperatura máxima\n ");
	scanf ("%d", &reg->tmax);
	printf ("Ingrese el valor de temperatura mínima\n ");
	scanf ("%d", &reg->tmin);
	printf ("Ingrese el porcentaje de humedad\n ");
	scanf ("%d", &reg->HUM);
	printf ("Ingrese el valor de presión atmosférica\n ");
	scanf ("%d", &reg->PNM);
	printf ("Ingrese la dirección del viento\n ");
	scanf ("%d", &reg->DV);
	printf ("Ingrese la velocidad del viento\n ");
	scanf ("%d", &reg->FF);
	printf ("Ingrese el valor total de precipitaciones\n ");
	scanf ("%d", &reg->PP);
	reg->borrado = 0;
 	}
/////////////////////////////////////////////////////////////
 

////////ALTA ////////////////////////////////////////////////
void AltaRegistro (char *nombreArch){
	Tregdiario reg;
	Tregdiario aux;
	long int fecha; // Fecha ingresada por el usuario en formato entero
	int fechaArchivo; //variable donde almaceno en un entero la fecha del archivo
  FILE *f;
  f = fopen(nombreArch,"ab+");
	char respRecargar;

	printf("Ingrese la fecha del nuevo registro\n");
	respRecargar ='n';
	do{
		CargarFecha(&fecha);
		fechaArchivo = atoi(nombreFecha); 
		if (fecha%10000 == fechaArchivo){//Comprobamos que el año ingresado coincida con el nombre del archivo
			reg.ddmmyyyy = fecha;	
		fseek(f,0,SEEK_SET);// Buscamos si el registro de esa fecha existe BUSQUEDA MARCA INICIAL
			do{
				fread(&aux, sizeof(Tregdiario), 1, f);
			} while ((fread(&aux,sizeof(Tregdiario), 1, f) > 0) && (aux.ddmmyyyy != reg.ddmmyyyy && !aux.borrado));
			if ((fread(&aux,sizeof(Tregdiario), 1, f) == 0)){
				system("clear");
				Cargaregistro(&reg);
				fwrite(&reg, sizeof(Tregdiario), 1, f);
				printf("¿Desea seguir cargando registros al archivo?\n");
				scanf("%s",&respRecargar);
			} else {
			printf ("Ya existe un registro asociado a esa fecha\n");
			printf("Desea volver a ingresar la fecha?");
			scanf("%s",&respRecargar);
			}
		}
		else {
		printf("El año ingresado no corresponde con el del archivo, para registros en otro año deberá crear un nuevo archivo.\n");
		}
	}while(respRecargar == 's' || respRecargar =='S');
  
  
	
  fclose(f);
}
/////////////////////////////////////////////////////////////


////////ELIMINAR/////////////////////////////////////////////
void Eliminar(char *nombreArch){
	long int fecha;
	Tregdiario aux;
	char msj[50];
  FILE *f;
  f = fopen(nomArch,"rb+");
	
	printf("\nIngrese la fecha que desea eliminar:\n");
	CargarFecha(&fecha);
	while(fread(&aux,sizeof(Tregdiario),1,f) >0){
		if((fecha == aux.ddmmyyyy) && (!aux.borrado)){
			aux.borrado = 1;
			fseek(f,-1*sizeof(Tregdiario),SEEK_CUR);
			fwrite(&aux, sizeof(Tregdiario), 1, f);
			fclose(f);
			return;
		}
	}
	fclose(f);
	printf("No hay registros cargados para el dia %li/%li/%li. \n\n",(aux.ddmmyyyy/1000000),((aux.ddmmyyyy/10000)%100),(aux.ddmmyyyy%10000));		
}
  

/////////////////////////////////////////////////////////////


///////MODIFICAR ////////////////////////////////////////////
void Modificar(char *nombreArch){
	long int fecha;
	Tregdiario aux;
	char msj[50];
  FILE *f;
  f = fopen(nomArch,"rb+");
	printf("\nIngrese la fecha del registro que desea modificar.\n");
	CargarFecha(&fecha);
	while(fread(&aux,sizeof(Tregdiario),1,f) >0){
		if((fecha == aux.ddmmyyyy) && (!aux.borrado)){
			fseek(f,-1*sizeof(Tregdiario),SEEK_CUR);
			Cargaregistro(&aux);
			fwrite(&aux, sizeof(Tregdiario), 1, f);
			fclose(f);
			return;
		}
	}
}
/////////////////////////////////////////////////////////////


//////APERTURA DEL ARCHIVO///////////////////////////////////
void Apertura(char *nomArch){
  printf("Ingrese el nombre del archivo\n");
	scanf("%s",nombreFecha);
	strcat(nomArch,directorio);
  strcat(nomArch,nombreFecha);
  strcat(nomArch,ext);
		if ((f = fopen(nomArch, "rb"))  == NULL){
			printf ("No existe o no puede abrirse el archivo. ¿Desea crear un archivo con ese nombre?\n");
			scanf("%s", &sn);
			if (sn == 's')
		{
			f = fopen(nomArch,"wb+");
			printf ("El archivo ha sido creado exitosamente\n");
			fclose(f);
		} else {
			printf("Se optó por no crear el archivo...\n");
		}
	} else {
		printf("Archivo abierto exitosamente\n");
		fclose(f);
	}
}
/////////////////////////////////////////////////////////////


int main() {
	system("clear");
  Apertura(nomArch);
  //AltaRegistro(nomArch);
	Eliminar(nomArch);
  MostrarRegistroClima(nomArch);
	return 0;
}
