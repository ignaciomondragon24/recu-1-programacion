#include <stdio.h>

// funcion calcular recaudación
float calcularRecaudacion(int pasajeros, float precio);
int main() {
    int vehiculo, seccion, tarjeta, operacion, conductor;
    float precio, totalSeccion1=0, totalSeccion2=0, totalSeccion3=0;
    float totalDia=0;
    
    //lo uso para la salida de el bucle
    int fin=0;

    printf("Sistema de Cierre de Caja\n");

    //Bucle do while
    do {
        printf("\nIngrese numero de vehiculo (con 0 finaliza): ");
        scanf("%d",&vehiculo);

        if (vehiculo==0) {
            fin=1; // Finaliza el día
        } else {
            printf("Ingrese seccion (1, 2 o 3): ");
            scanf("%d",&seccion);

            //Validar sección
            if (seccion<1||seccion>3) {
                printf("Error: Seccion invalida. Intente nuevamente.\n");
                continue;
            }

            printf("Ingrese numero de tarjeta:");
            scanf("%d",&tarjeta);
            printf("Ingrese numero de operacion:");
            scanf("%d",&operacion);
           printf("Ingrese identificador de conductor:");
            scanf("%d",&conductor);

            //Asignar precio según sección
            switch (seccion) {
                case 1: precio=484.0; break;
                case 2: precio=520.0; break;
                case 3: precio=950.0; break;
            }
            // recaudación por sección usando funcion
           if (seccion == 1) {
                totalSeccion1 = calcularRecaudacion(1, precio);
            } else if (seccion == 2) {
                totalSeccion2 = calcularRecaudacion(1, precio);
            } else {
                totalSeccion3 = calcularRecaudacion(1, precio);
            }
            totalDia += precio;
        }
    } while (!fin);
// Resultados
    printf("\nCierre de caja\n");
    printf("1. Recaudacion Seccion 1: $%.2f\n", totalSeccion1);
    printf("2. Recaudacion Seccion 2: $%.2f\n", totalSeccion2);
    printf("3. Recaudacion Seccion 3: $%.2f\n", totalSeccion3);
// Determinar sección con mayor recaudación
    if (totalSeccion1 > totalSeccion2 && totalSeccion1 > totalSeccion3) {
        printf("La Seccion 1 tuvo la mayor recaudacion.\n");
    } else if (totalSeccion2 > totalSeccion3) {
        printf("La Seccion 2 tuvo la mayor recaudacion.\n");
    } else {
        printf("La Seccion 3 tuvo la mayor recaudacion.\n");
    }
 printf("Total recaudado en el dia:$%.2f\n", totalDia);

    return 0;
}
//Multiplica cantidad de pasajeros × precio del boleto.
float calcularRecaudacion(int pasajeros, float precio) {
    return pasajeros * precio;
}

