#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

// Funcion para ordenar los turnos por fecha
void ordenar(Lista *l, Turno T){
Turno Buscar;
if(isEmpty(*l)==1){
    push(l,T);}
else{
reset(l);
Buscar=copys(*l);
while(getFechaMes(T)>getFechaMes(Buscar) && (isOos(*l)==0)){
    forwards(l);
    if(isOos(*l)==0)Buscar=copys(*l);}
    if(getFechaMes(T)>=getFechaMes(Buscar)){
    while(getFechaDia(T)>getFechaDia(Buscar) && (isOos(*l)==0)){
        forwards(l);
        if(isOos(*l)==0)Buscar=copys(*l);}
        if(getFechaDia(T)>=getFechaDia(Buscar)){
        while(getFechaHora(T)>getFechaHora(Buscar) && (isOos(*l)==0) && getFechaDia(T)>=getFechaDia(Buscar)){
            forwards(l);
            if(isOos(*l)==0)Buscar=copys(*l);}
            if(getFechaHora(T)>=getFechaHora(Buscar)){
                push(l,T);}
            else{push(l,T);}}
        else{push(l,T);}}
    else{push(l,T);}}
    }

// a)
void insertar_un_turno(Lista *l, Servicio se[]) {
    int mes, dia, hora, semana, i, ser, metodo,control;
    char nombre[50];
    Turno t;
    initServicio(s);
    float precio = 0, total = 0;
do{
    control=0;
    do {
        printf("¿Que mes desea?\n");
        scanf("%d", &mes);
        if(mes < 1 || mes > 12) {
            printf("Semana invalida. Por favor, ingrese un valor entre 1 y 12.\n");
        }
    } while(mes < 1 || mes > 12);


    do {
        printf("Que semana desea? (1-4)\n");
        scanf("%d", &semana);
        if (semana < 1 || semana > 4) {
            printf("Semana invalida. Por favor, ingrese un valor entre 1 y 4.\n");
        }
    } while (semana < 1 || semana > 4);

    int inicio_semana = (semana - 1) * 7 + 1;
    int fin_semana = inicio_semana + 4;

    reset(l);

    // Mostrar turnos disponibles
    printf("Turnos disponibles para el mes %d, semana %d:\n", mes, semana);
    for (i = inicio_semana; i <= fin_semana; i++) {
        int turnoOcupado[5] = {0, 0, 0, 0, 0}; // Para las horas 8, 10, 14, 16 (saltando 12)

        while (!isOos(*l) && getFechaMes(copys(*l)) == mes && getFechaDia(copys(*l)) == i) {
            int turno_hora = getFechaHora(copys(*l));
            if (turno_hora == 8) turnoOcupado[0] = 1;
            else if (turno_hora == 10) turnoOcupado[1] = 1;
            else if (turno_hora == 14) turnoOcupado[2] = 1;
            else if (turno_hora == 16) turnoOcupado[3] = 1;
            forwards(l);
        }

        for (hora = 8; hora <= 16; hora += 2) {
            if (hora == 12) continue;
            if (hora == 8 && turnoOcupado[0] == 1) printf("Mes %d, dia %d, hora %d: ocupado\n", mes, i, hora);
            else if (hora == 10 && turnoOcupado[1] == 1) printf("Mes %d, dia %d, hora %d: ocupado\n", mes, i, hora);
            else if (hora == 14 && turnoOcupado[2] == 1) printf("Mes %d, dia %d, hora %d: ocupado\n", mes, i, hora);
            else if (hora == 16 && turnoOcupado[3] == 1) printf("Mes %d, dia %d, hora %d: ocupado\n", mes, i, hora);
            else printf("Mes %d, dia %d, hora %d: disponible\n", mes, i, hora);
        }
    }

    // Solicitar al usuario la fecha y hora del turno
    do {
        printf("Que dia desea?\n");
        scanf("%d", &dia);
        if(dia < inicio_semana || dia > fin_semana) {
            printf("\nIngrese un dia de la semana elegida\n");
        }
    } while(dia < inicio_semana || dia > fin_semana);

    do {
        printf("Que hora desea? (8, 10, 14, 16)\n");
        scanf("%d", &hora);
        if(hora != 8 && hora != 10 && hora != 14 && hora != 16) {
            printf("\nHora invalida. Ingrese nuevamente\n");
        }
    } while(hora != 8 && hora != 10 && hora != 14 && hora != 16);

    Fecha f = {hora, dia, mes};
    setFecha(&t, f);
    reset(l);
while(!isOos(*l)){
    if(mes==getFechaMes(copys(*l)) && dia==getFechaDia(copys(*l)) && hora==getFechaHora(copys(*l))){
        control=1;
        printf("\nLa fecha ingresada ya esta ocupada\n");}
    forwards(l);}
}while(control!=0);
    printf("\nIngrese el nombre del cliente:\n");
    scanf(" %[^\n]s", nombre);
    setNombreCliente(&t, nombre);

    int agregarOtroServicio = 1;
    while (agregarOtroServicio == 1) {
        printf("\nQue servicio desea?\n");
        printf("1:Cambio de bujias\n2:Cambio de aceite y filtro\n3:Cambio del filtro de nafta y aire\n4:Cambio del refrigerante\n5:Cambio de la faja del alternador\n6:Ajuste del tiempo de encendido\n7:Revision de las luces y los faros\n8:Inspeccion del tubo del alternador y del tubo de vacio\n9:Inspeccion de las zapatas del freno de estacionamiento\n10:Desmontaje y rotacion de ruedas\n11:Alineacion de ruedas\n12:Cambio de pastillas de freno\n13:Lavado de Motor\n14:Lavado de Carroceria e interior\n15:Pulido de Carroceria\n");
        scanf("%d", &ser);
        if (ser >= 1 && ser <= 15) {
            setServicio(&t, ser - 1);
        } else {
            printf("\nServicio incorrecto\n");
        }
        printf("\nDesea agregar otro servicio? 1=si 0=no\n");
        scanf("%d", &agregarOtroServicio);
    }

    printf("\nIngrese metodo de pago 1: Debito. 2: Credito. 3: QR. 4: Efectivo\n");
    scanf("%d", &metodo);
    setMetodoPago(&t, metodo);

    int y;
   char x[10];
   for(y=0;y<5;y++){
    x[y]=(rand()%26)+65;
   }
   for(y=5;y<10;y++){
    x[y]=(rand()%10)+48;
   }
    setIdTurno(&t, x);

    for (i = 0; i < 15; i++) {
        if (getServicio(t, i) == 1) {
            precio += getPrecio(se[i]);
            total += getPrecio(se[i]) - (getDescuento(se[i]) * getPrecio(se[i])) / 100;
        }
    }
    setSubtotal(&t, precio);
    setEstado(&t, 0);

    printf("\nNombre del Cliente: %s\n", getNombreCliente(t));
    printf("ID del Turno: %s\n", getIdTurno(t));
    printf("Fecha: %02d/%02d %02d:00 hs\n", getFechaDia(t), getFechaMes(t), getFechaHora(t));
    printf("Metodo de Pago: %d\n", getMetodoPago(t));
    printf("Subtotal: $%.2f\n", getSubtotal(t));
    printf("Total: $%.2f\n", total);
    printf("Estado: %d\n", getEstado(t));
    ordenar(l, t);
}

// b)
Turno buscar_turno(Lista *l, char id_buscado[10]) {
    reset(l);
    while(!isOos(*l)) {
        Turno t = copys(*l);
        if(strcmp(getIdTurno(t), id_buscado) == 0) {
            return t;
        }
        forwards(l);
    }
    Turno nulo;
    setIdTurno(&nulo, "Nulo");
    return nulo;
}

// c)
void mostrar_turno(Lista *l, char id_buscado[10]) {
    Turno t = buscar_turno(l, id_buscado);
    if(strcmp(getIdTurno(t), "Nulo") != 0) {
        printf("Nombre del Cliente: %s\n", getNombreCliente(t));
        printf("ID del Turno: %s\n", getIdTurno(t));
        printf("Fecha: %02d/%02d %02d:00 hs\n", getFechaDia(t), getFechaMes(t), getFechaHora(t));
        printf("Metodo de Pago: %d\n", getMetodoPago(t));
        printf("Subtotal: $%.2f\n", getSubtotal(t));
        if(getEstado(t) == 1) {
            printf("Pedido Entregado!\n\n");
        } else {
            printf("Pedido NO entregado\n\n");
        }
    } else {
        printf("No se encontro ningun turno con el ID buscado\n");
    }
}

// d)
void mostrar_turnos_semana(Lista *l, int mes, int semana) {
    int inicio_semana = (semana - 1) * 7 + 1;
    int fin_semana = inicio_semana + 4;
    int contador = 0;

    printf("\nTurnos de la semana %d del mes %d: \n", semana, mes);

    reset(l);
    while(!isOos(*l)) {
        Turno t = copys(*l);
        if(getFechaMes(t) == mes && getFechaDia(t) >= inicio_semana && getFechaDia(t) <= fin_semana) {
            printf("Nombre del Cliente: %s\n", getNombreCliente(t));
            printf("ID del Turno: %s\n", getIdTurno(t));
            printf("Fecha: %02d/%02d %02d:00 hs\n", getFechaDia(t), getFechaMes(t), getFechaHora(t));
            printf("Metodo de Pago: %d\n", getMetodoPago(t));
            printf("Subtotal: $%.2f\n", getSubtotal(t));
            if(getEstado(t) == 1) {
                printf("Pedido Entregado!\n\n");
            } else {
                printf("Pedido NO entregado\n\n");
            }
            contador++;
        }
        forwards(l);
    }

    if(contador == 0) {
        printf("No se encontraron turnos en la semana buscada\n");
    }
}

// e)
void paginar(Lista *l, int items) {
    int pagina = 0;
    int i = 0;
    int opcion;

    do {
        int contador = 0;
        system("cls");
        printf("Pagina: %d\n", pagina + 1);
        reset(l);

        // Avanzar a la página correspondiente
        for (i; i < pagina * items; i++) {
            if (!isOos(*l)) {
                forwards(l);
            }
        }

        // Mostrar los items de la página actual
        while (!isOos(*l) && contador < items) {
            Turno t = copys(*l);
            printf("Nombre del Cliente: %s\n", getNombreCliente(t));
            printf("ID del Turno: %s\n", getIdTurno(t));
            printf("Fecha: %02d/%02d %02d:00 hs\n", getFechaDia(t), getFechaMes(t), getFechaHora(t));
            printf("Metodo de Pago: %d\n", getMetodoPago(t));
            printf("Subtotal: $%.2f\n", getSubtotal(t));
            if (getEstado(t) == 1) {
                printf("Pedido Entregado!\n\n");
            } else {
                printf("Pedido NO entregado\n\n");
            }
            forwards(l);
            contador++;
        }

        if (contador == 0) {
            printf("No hay mas turnos para mostrar\n");
        }

        printf("Opciones: [1] Siguiente, [2] Anterior, [3] Salir: ");
        scanf("%d", &opcion);

        if (opcion == 1 && contador == items) {
            pagina++;
        } else if (opcion == 2 && pagina > 0) {
            pagina--;
        }

    } while (opcion != 3);
}

// i)
void modificarestado(Lista *l){
    char id[10];
    Turno t;
    printf("Ingrese el ID del turno que desea modificar:\n");
    scanf("%s",id);
    t = buscar_turno(l,id);
    suppress(l);
    setEstado(&t,1);
    ordenar(l,t);
}

// j)
void modificarformadepago(Lista *l){
    char id[10];
    int metodo;
    Turno t;
    printf("Ingrese el ID del turno que desea modificar:\n");
    scanf("%s",id);
    t = buscar_turno(l,id);
    suppress(l);
    printf("Ingrese el nuevo metodo de pago 1: Débito. 2: Crédito. 3: QR. 4: Efectivo\n");
    scanf("%d",&metodo);
    setMetodoPago(&t, metodo);
    ordenar(l,t);
}

// k)
void anular_turno(Lista *l, char id_turno[]) {
    reset(l);
    FILE *archivo = fopen("turnoscancelados.txt", "a");
    if(archivo == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    int contador = 0;
    while(!isOos(*l)) {
        Turno t = copys(*l);
        if(strcmp(getIdTurno(t), id_turno) == 0) {
            if(getEstado(t) == 1) {
                printf("El turno ya se concreto, no se puede anular\n");
            } else {
                fprintf(archivo, "Nombre del cliente: %s\n", getNombreCliente(t));
                fprintf(archivo, "ID del turno: %s\n", getIdTurno(t));
                fprintf(archivo, "Fecha: %d/%d %d:00 hs\n", getFechaDia(t), getFechaMes(t), getFechaHora(t));
                fprintf(archivo, "Metodo de Pago: %d\n", getMetodoPago(t));
                fprintf(archivo, "Subtotal: $%.2f\n", getSubtotal(t));
                fprintf(archivo, "-------------------\n");

                suppress(l);
                contador++;
            }
            break;
        }
        forwards(l);
    }
    if(contador == 0) {
        printf("No se anulo ningun turno\n");
    } else {
        printf("Turno con ID %s anulado y guardado en el archivo.\n", id_turno);
    }
    fclose(archivo);
}

// l)
void almacenar_turnos_metodo_pago(Lista l, int metodo){
    FILE *fp;
    int i=0;
    fp=fopen("backup.txt","w");
    if(fp==NULL)
        printf("error\n");
    else{
        reset(&l);
        while(!isOos(l)){
            if(getMetodoPago(copys(l))==metodo){
                fprintf(fp,"Nombre: %s\n",getNombreCliente(copys(l)));
                fprintf(fp,"ID: %s\n",getIdTurno(copys(l)));
                fprintf(fp,"Fecha: %d/",getFechaMes(copys(l)));
                fprintf(fp,"%d/",getFechaDia(copys(l)));
                fprintf(fp,"%dhs\n",getFechaHora(copys(l)));
                switch(getMetodoPago(copys(l))){
                    case 1:(fprintf(fp,"Debito\n"));break;
                    case 2:(fprintf(fp,"Credito\n"));break;
                    case 3:(fprintf(fp,"QR\n"));break;
                    case 4:(fprintf(fp,"Efectivo\n"));break;
                }
                if(getEstado(copys(l))==0)
                    fprintf(fp,"Estado: pendiente\n");
                else{fprintf(fp,"Estado: realizado\n");}
                fprintf(fp,"subtotal: $%.2f\n",getSubtotal(copys(l)));
                fprintf(fp, "-------------------\n");
                i++;}
        forwards(&l);
    }}
    fclose(fp);
    printf("Se copiaron %d turnos\n",i);
}

// m)
void precargadeturnos(Lista *l){
    FILE *fp;
    int i,mes,dia,hora,servis,metodo,estado;
    float subtotal;
    char id[10],nombre[50];
    Turno t;
    fp = fopen("precarga.txt","r");
    if (fp==NULL)
        printf ("error");
    else{
        do{
            fscanf (fp,"%s",nombre);
            setNombreCliente(&t,nombre);
            fscanf (fp,"%s",id);
            setIdTurno(&t,id);
            fscanf (fp,"%d",&servis);
            setServicio(&t,servis);
            fscanf (fp,"%d",&mes);
            fscanf (fp,"%d",&dia);
            fscanf (fp,"%d",&hora);
            Fecha f={hora,dia,mes};
            setFecha(&t,f);
            fscanf (fp,"%d",&metodo);
            setMetodoPago(&t,metodo);
            fscanf (fp,"%f",&subtotal);
            setSubtotal(&t,subtotal);
            fscanf (fp,"%d",&estado);
            setEstado(&t,estado);
            ordenar(l,t);}
        while(!feof(fp));}
    fclose(fp);
}

// ñ)
void precargaServicios(Servicio s[]) {
    FILE *fp = fopen("servicios.txt", "r");
    if(fp == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    int id_servicio, descuento;
    char descripcion[100];
    float precio;
    int x = 0;

    for(x = 0; x < 15; x++){
        fscanf(fp,"%d",&id_servicio);
        setId(&s[x],id_servicio);
        fscanf(fp,"  %[^\n]s",descripcion);
        setDescripcion(&s[x],descripcion);
        fscanf(fp,"%f",&precio);
        setPrecio(&s[x],precio);
        fscanf(fp,"%d",&descuento);
        setDescuento(&s[x],descuento);
    }
    fclose(fp);
}

// n)
void modificaPrecioYDescripcion(Servicio s[], int idServicio) {
    int i = 0;
    int opcion;
    float precio;
    char descripcion[50];

    for(i; i < 15; i++) {
        if(getIdServicio(s[i]) == idServicio) {
            do {
                printf("Desea modificar el precio del servicio? (0 para NO; 1 para SI): \n");
                scanf("%d", &opcion);
                switch(opcion) {
                    case 1: printf("Ingrese el nuevo precio para el servicio: \n");
                            scanf("%f", &precio);
                            setPrecio(&s[i], precio);
                            printf("Modificacion exitosa!\n");
                }
            } while(opcion < 0 || opcion > 1);

            do {
                printf("Desea modificar la descripcion del servicio? (0 para NO; 1 para SI): \n");
                scanf("%d", &opcion);
                switch(opcion) {
                    case 1: printf("Ingrese la nueva descripcion para el servicio: \n");
                    scanf(" %[^\n]s", descripcion);
                    setDescripcion(&s[i], descripcion);
                    printf("Modificacion exitosa!\n");
                }
            } while(opcion < 0 || opcion > 1);
        }
    }
}

// o
void mostrarServicios(Servicio s[]) {
    int i = 0;
    for (i; i < 15; i++) {
        printf("ID del servicio: %d\n", getIdServicio(s[i]));
        printf("Descripcion del servicio: %s\n", getDescripcion(s[i]));
        printf("Precio del servicio: $%.2f\n", getPrecio(s[i]));
        if (getDescuento(s[i]) > 0) {
            printf("El servicio tiene descuento: %d%%\n", getDescuento(s[i]));
        } else {
            printf("El servicio NO tiene descuento\n");
        }
        printf("------------------------------------\n");
    }
}

void menu_principal() {
    system("cls");
    printf(" _______________________________________________________________________________________\n");
    printf(" |                                SERVICIOS Y TURNOS                                   |\n");
    printf(" |                                                                                     |\n");
    printf(" |                                1........GESTIONAR TURNOS                            |\n");
    printf(" |                                2........GESTIONAR SERVICIOS                         |\n");
    printf(" |                                3........SALIR                                       |\n");
    printf(" |_____________________________________________________________________________________|\n");
}

void menu_turnos(Lista *l, Servicio s[]) {
    char id[10];
    char nombre[50];
    int opcion, mes, semana, metodo_pago;

    do {
        system("cls");
        printf("1. Cargar un turno\n");
        printf("2. Mostrar los datos de un turno segun su ID\n");
        printf("3. Mostrar los turnos de una semana en especifico\n");
        printf("4. Mostrar todos los turnos\n");
        printf("5. Modificar el estado de un turno\n");
        printf("6. Modificar el metodo de pago de un turno\n");
        printf("7. Anular un turno segun su ID\n");
        printf("8. Almacenar en un archivo los turnos segun su metodo de pago\n");
        printf("9. Salir\n");

        printf("\nIngrese una opcion: \n");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                system("cls");
                insertar_un_turno(l, s);
                break;
            case 2:
                system("cls");
                printf("Ingrese el ID del turno que desea buscar: \n");
                scanf(" %[^\n]s", id);
                mostrar_turno(l, id);
                break;
            case 3:
                system("cls");
                do {
                    printf("Ingrese el mes en el que desea buscar (1 al 12): \n");
                    scanf("%d", &mes);
                } while(mes <= 0 || mes > 12);
                do {
                    printf("Ingrese la semana en la que desea buscar (1 al 4): \n");
                    scanf("%d", &semana);
                } while(semana <= 0 || semana > 4);
                mostrar_turnos_semana(l, mes, semana);
                break;
            case 4:
                system("cls");
                paginar(l, 3);
                break;
            case 5:
                system("cls");
                modificarestado(l);
                break;
            case 6:
                system("cls");
                modificarformadepago(l);
                break;
            case 7:
                system("cls");
                printf("Ingrese el ID del turno que desea eliminar: \n");
                scanf(" %[^\n]s", id);
                anular_turno(l, id);
                break;
            case 8:
                system("cls");
                printf("Ingrese el metodo de pago para almacenar (1: Debito, 2: Credito, 3: QR, 4: Efectivo): \n");
                scanf("%d", &metodo_pago);
                almacenar_turnos_metodo_pago(*l, metodo_pago);
                break;
            case 9:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion incorrecta, intente nuevamente\n");
                system("cls");
        }

        printf("Presione Enter para continuar...\n");
        getchar();
        getchar();

    } while(opcion != 9);
}

void menu_servicios(Servicio s[]) {
    int opcion, opcionServicio;

    do {
        system("cls");
        printf("1. Modificar precio y descripcion de algun servicio\n");
        printf("2. Mostrar todos los servicios disponibles\n");
        printf("3. Salir\n");

        printf("\nIngrese una opcion: \n");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                system("cls");
                mostrarServicios(s);
                printf("\nElija el ID del servicio que desea modificar: \n");
                scanf("%d", &opcionServicio);
                modificaPrecioYDescripcion(s, opcionServicio);
                break;
            case 2:
                system("cls");
                mostrarServicios(s);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion incorrecta, intente nuevamente\n");
        }

        if (opcion != 3) {
            printf("\nPresione Enter para continuar...\n");
            getchar(); // Para capturar el '\n' sobrante del buffer
            getchar(); // Para esperar que el usuario presione Enter
        }
    } while(opcion != 3);
}

int main()
{
    Lista l;
    init(&l);
    precargadeturnos(&l);
    Servicio servicios[15];
    precargaServicios(servicios);
    int opcion;

    do {
        menu_principal();
        printf("Ingrese una opcion: \n");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                menu_turnos(&l, servicios);
                break;
            case 2:
                menu_servicios(servicios);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion incorrecta, intente nuevamente\n");
        }

        if (opcion != 3) {
            printf("\nPresione Enter para continuar...\n");
            getchar(); // Para capturar el '\n' sobrante del buffer
            getchar(); // Para esperar que el usuario presione Enter
        }
    } while(opcion != 3);
    return 0;
}
