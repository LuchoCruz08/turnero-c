#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED
#include "servicio.h"

typedef struct {
    int hora; // (8hs, 10hs, 14hs y 16 hs)
    int dia;
    int mes;
} Fecha;

typedef struct {
    char nombreCliente[50];
    char idTurno[10];
    int servicio[15];
    Fecha fecha;
    int metodoPago; // 1: Debito. 2: Credito. 3: QR. 4: Efectivo
    float subtotal;
    int estado; // 0: pendiente 1: realizado
} Turno;

// Setters
void setNombreCliente(Turno *t, char nombreCliente[]) {
    strcpy(t->nombreCliente, nombreCliente);
}

void setIdTurno(Turno *t, char idTurno[]) {
    strcpy(t->idTurno, idTurno);
}

void setServicio(Turno *t, int idServicio) {
    if(idServicio >= 0 && idServicio < 15) {
        t->servicio[idServicio] = 1;
    }
}

void setFecha(Turno *t, Fecha f) {
    t->fecha = f;
}

void setMetodoPago(Turno *t, int metodoPago) {
    t->metodoPago = metodoPago;
}

void setSubtotal(Turno *t, float subtotal) {
    t->subtotal = subtotal;
}

void setEstado(Turno *t, int estado){
    t->estado=estado;
}

// Getters
char *getNombreCliente(Turno t) {
    char *aux = (char*)malloc(sizeof(strlen(t.nombreCliente) + 1));
    strcpy(aux, t.nombreCliente);
    return aux;
}

char *getIdTurno(Turno t) {
    char *aux = (char*)malloc(sizeof(char)*10 + 1);
    strcpy(aux, t.idTurno);
    return aux;
}

int getServicio(Turno t, int id_servicio) {
    if (id_servicio >= 0 && id_servicio < 15) {
        return t.servicio[id_servicio];
    }
}

int getFechaHora(Turno t) {
    return t.fecha.hora;
}

int getFechaDia(Turno t) {
    return t.fecha.dia;
}

int getFechaMes(Turno t) {
    return t.fecha.mes;
}

int getMetodoPago(Turno t) {
    return t.metodoPago;
}

float getSubtotal(Turno t) {
    return t.subtotal;
}

int getEstado(Turno t){
    return t.estado;
}


#endif // TURNO_H_INCLUDED
