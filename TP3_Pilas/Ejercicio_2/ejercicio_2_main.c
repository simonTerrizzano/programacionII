#include "ejercicio_2.c"

int main(void)
{
    Pila pila = p_crear();
    Pila duplicada;
    TipoElemento x;
    int eleccion;
    int clave;
    bool salir = false;
    int posicion_1;
    int posicion_2;

    printf("Eliga el modo de carga de la pila: \n 1.Aleatoria \n 2.Por teclado \n");

    eleccion = ingreso_normalizado_enteros(1, 2);

    if (eleccion == 1)
    {
        for (int i = 1; i < 9; i++)
        {
            x = te_crear(i);
            p_apilar(pila, x);
        }
    }
    else
    {
        printf("Ingrese cantidad de elementos para cargar en la pila.\n");
        int cantidad = ingreso_normalizado_enteros(0, 10);

        for (int i = 0; i < cantidad; i++)
        {
            printf("Ingrese clave del %iº elemento a apilar: ", i+1);
            clave = ingreso_normalizado_enteros(-1000, 1000);
            x = te_crear(clave);
            p_apilar(pila, x);
        }
    }

    p_mostrar(pila);
    printf("\n\n")

    do
    {
        printf("-No se puede insertar elemento en posiciones mayores al Tamaño máximo establecito \n");
        printf("-No se puede insertar elemento en posiciones mayores a la cantidad de elemento + 1\n\n");
        printf( "\n   1. Buscar elemento en la pila. ");
        printf( "\n   2. Insertar elemento en una posicion ordinal. ");
        printf( "\n   3. Eliminar elemento en una posicion ordinal. ");
        printf( "\n   4. Intercambiar posicion de 2 elementos en la pila. " );
        printf( "\n   5. Duplicar pila. " );
        printf( "\n   6. Saber el largo de la pila ingresada. " );
        printf( "\n   7. Salir " );
        printf( "\n\n   Introduzca opcion (1-7): ");

        eleccion=ingreso_normalizado_enteros(1,7);

        /* Inicio del anidamiento */

        switch ( eleccion )
        {
            case 1: if (p_es_vacia(pila)){
                        printf("--La lista está vacia, no hay elemento que buscar.--\n\n");
                    }
                    
                    printf("Ingrese un número a buscar en la pila: ");
                    clave = ingreso_normalizado_enteros(-1000, 1000);
                    if (p_buscar_clave(pila, clave))
                    {
                        printf("--La clave se encuentra en la pila.--\n\n");
                    }
                    else
                    {
                        printf("--La clave no se encuentra en la pila.--\n\n");
                    }
                    break;

            case 2: if (p_es_llena(pila))
                    {
                        printf("--La pila está llena, no se puede insertar elementos--\n\n.");
                    }else{
                        printf("Ingrese la posición del elemento a ingresar: ");
                        posicion_1 = ingreso_normalizado_enteros(1, (p_contar_elementos(pila)+1));
                        printf("Ingrese clave de elemento a insertar: ");
                        clave=ingreso_normalizado_enteros(-1000,1000);
                        x=te_crear(clave);
                        p_insertar(pila,x,posicion_1);
                        p_mostrar(pila);
                        printf("\n\n");
                    }
                    break;

            case 3: if (p_es_vacia(pila))
                    {
                        printf("--La pila está vacia, no hya elementos que eliminar.--\n\n");
                    }else{
                        printf("Ingrese clave de elemento a eliminar: ");
                        clave=ingreso_normalizado_enteros(-1000,1000);
                        p_eliminar_elemento(pila,clave);  
                        p_mostrar(pila);
                        printf("\n\n");
                    }
                    break;
            case 4: if(p_es_vacia(pila)){
                        printf("--La pila está vacia, no hya elementos que intercambiar.--");

                    }else if ((p_contar_elementos(pila)==1))
                    {
                        printf("--La pila la pila solo tiene 1 elemento, no hay elementos que intercambiar.--\n\n");
                    }else{
                        printf("Ingrese la 1ra posición del elemento a intercambiar: ");
                        posicion_1 = ingreso_normalizado_enteros(1, (p_contar_elementos(pila)));
                        printf("Ingrese la 2da posición del elemento a intercambiar: ");
                        posicion_2 = ingreso_normalizado_enteros(1, (p_contar_elementos(pila)));
                        p_intercambiar(pila,posicion_1,posicion_2);
                        p_mostrar(pila);
                        printf("\n\n");
                    }
                    break;
            case 5: if (p_es_vacia(pila))
                    {
                        printf("--No hay pila que duplicar.--\n\n");
                    }else{
                        duplicada=p_duplicar(pila);
                        printf("Pila original:");
                        p_mostrar(pila);
                        printf("Pila duplicada:");
                        p_mostrar(duplicada);
                        printf("\n\n");
                    }
                    break;
            case 6: printf("--La largo de la pila actualmente es de %i.--\n\n",p_contar_elementos(pila));
                    break;

            case 7: salir=true;
                    
         }


         /* Fin del anidamiento */

    } while ( salir==false );



    // while (salir == false)
    // {
    //     printf("-No se puede insertar elemento en posiciones mayores al Tamaño máximo establecito \n");
    //     printf("-No se puede insertar elemento en posiciones mayores a la cantidad de elemento + 1\n\n");
    //     printf("Ingrese una operación a reliazar : \n");
    //     printf("1.Buscar elemento en la pila. \n");
    //     printf("2.Insertar elemento en una posición ordinal. \n");
    //     printf("3.Eliminar elemento en una posición ordinal. \n");
    //     printf("4.Intercambiar posicion de 2 elementos en la pila. \n");
    //     printf("5.Duplicar pila. \n");
    //     printf("6.Saber el largo de la pila ingresada.\n");
    //     printf("0. Salir. \n");
    //     eleccion=ingreso_normalizado_enteros(0,5);
    //     if (eleccion==1)
    //     {
    //         if (p_es_vacia(pila))
    //         {
    //             printf("La lista está vacia, no hay elemento que buscar.");
    //         }
            
    //         printf("Ingrese un número a buscar en la pila");
    //         printf("Ingrese un número a buscar: ");
    //         clave = ingreso_normalizado_enteros(-1000, 1000);
    //         if (p_buscar_clave(pila, clave))
    //         {
    //             printf("La clave se encuentra en la pila\n");
    //         }
    //         else
    //         {
    //             printf("La clave no se encuentra en la pila\n");
    //         }
    //         system("PAUSE");
    //     }
    //     if (eleccion==2)
    //     {
            // if (p_es_llena(pila))
            // {
            //     printf("La pila está llena, no se puede insertar elementos.");
            // }else{
            //     printf("Ingrese la posición del elemento a ingresar: ");
            //     posicion_1 = ingreso_normalizado_enteros(1, (p_contar_elementos(pila)+1));
            //     printf("Ingrese clave de elemento a insertar: ");
            //     clave=ingreso_normalizado_enteros(-1000,1000);
            //     x=te_crear(clave);
            //     p_insertar(pila,x,posicion_1);
            //     p_mostrar(pila);
            // }
    //         system("PAUSE");

    //     }
    //     if (eleccion==3)
    //     {
    //         if (p_es_vacia(pila))
    //         {
    //             printf("La pila está vacia, no hya elementos que eliminar.");
    //         }else{
    //             printf("Ingrese clave de elemento a insertar: ");
    //             clave=ingreso_normalizado_enteros(-1000,1000);
    //             p_eliminar_elemento(pila,clave);  
    //         }
    //         system("PAUSE");

    //     }
    //     if (eleccion==4)
    //     {
            // if(p_es_vacia(pila)){
            //     printf("La pila está vacia, no hya elementos que intercambiar.");

            // }else if ((p_contar_elementos(pila)==1))
            // {
            //     printf("La pila la pila solo tiene 1 elemento, no hay elementos que intercambiar");
            // }else{
            //     printf("Ingrese la posición del elemento a ingresar: ");
            //     posicion_1 = ingreso_normalizado_enteros(1, (p_contar_elementos(pila)+1));
            //     printf("Ingrese la posición del elemento a ingresar: ");
            //     posicion_2 = ingreso_normalizado_enteros(1, (p_contar_elementos(pila)+1));
            //     p_intercambiar(pila,posicion_1,posicion_2);
            //     p_mostrar(pila);
            // }
    //         system("PAUSE");

    //     }
    //     if (eleccion==5)
    //     {
            // if (p_es_vacia(pila))
            // {
            //     printf("No hay pila que duplicar.");
            // }else{
            //     duplicada=p_duplicar(pila);
            //     printf("Pila original:");
            //     p_mostrar(pila);
            //     printf("Pila duplicada:");
            //     p_mostrar(duplicada);
            // }
    //         system("PAUSE");

    //     }
    //     if (eleccion==6)
    //     {
    //         printf("La largo de la pila actualmente es de %i",p_contar_elementos(pila));
    //         system("PAUSE");

    //     }
    //     if (eleccion==0)
    //     {
    //         salir=true;
    //     }
    // }
    // system("PAUSE");
    // return 0;
}
