void quitaespacios(char* cadena){
    int i,j;
    i=0;
    j=0;
    char * cadenaaux;
    while (cadena[i]!='\0') {
        if(cadena[i]!=' '){
            cadenaaux[j]=cadena[i];
            j++;
        }
        i++;
    } 
}
void quitasalto(char* cadena){
    int i=0;
    while (cadena[i]!='\0') {
    if(cadena[i]=='\n'){
        cadena[i]='\0';
    }
    i++;
    }
}

int cadenatododigito(char* cadena){
    int res;
    for (int i = 0; cadena[i]; i++){
        if (isdigit(cadena[i])!=1)
        {
            return 0;
        } 
    }
    return 1;
}