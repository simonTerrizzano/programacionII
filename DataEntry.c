void quitaespacios(char cadenain [100], char cadenaout[20]){
    int i,j;
    i=0;
    j=0;
    while (cadenain[i]!='\0') {
        if(cadenain[i]!=' '){
            cadenaout[j]=cadenain[i];
            j++;
        }
        i++;
    }  
    i=0;
}
void quitasalto(char cadenain [100], char cadenaout[20]){
    int i=0;
    while (cadenain[i]!='\0') {
    if(cadenain[i]=='\n'){
        cadenaout[i]='\0';
    }
    i++;
    }
}

int cadenatododigito(char cadena[20]){
    int res;
    for (int i = 0; cadena[i]; i++){
        if (isdigit(cadena[i])!=1)
        {
            return 0;
        } 
    }
    return 1;
}