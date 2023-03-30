// recibe puntero de archivo y verifica que no sea nulo
int archive_ok(FILE * fp);

int archive_ok(FILE * fp)
{

    if(fp == NULL) return 0;
    else return 1;
    
}
