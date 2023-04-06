// recibe puntero de archivo y verifica que no sea nulo
int archive_ok(FILE * fp);

int archive_ok(FILE * fp)
{

    if(fp == NULL) return 0;
    else return 1;
    
}


// Verifica si lo ingresado es un numero y luego el salto de linea. Retorna 0  de haber algun error. retorna 1 si todo es correcto.

int ingreso_numero(int *number, char *space)
{
    
    if(scanf("%d%c", number, space) != 2 || *(space) != '\n')
	return 0;
    else
	return 1;


}
