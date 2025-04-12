#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct {
    int idServicio;
    char descripcion[100];
    float precio;
    int descuento;
} Servicio;

Servicio s[15];
void initServicio(Servicio s[]) {
    int i;
    for(i=0;i<15;i++){
    s[i].idServicio=0;
    strcpy(s[i].descripcion,"nulo\n");
    s[i].precio=0;
    s[i].descuento=0;}
}

// Setters
void setId(Servicio *s, int idServicio) {
    s->idServicio = idServicio;
}

void setDescripcion(Servicio *s, char descripcion[]) {
    strcpy(s->descripcion, descripcion);
}

void setPrecio(Servicio *s, float precio) {
    s->precio = precio;
}

void setDescuento(Servicio *s, int descuento) {
    s->descuento = descuento;
}

// Getters
int getIdServicio(Servicio s) {
    return s.idServicio;
}

char *getDescripcion(Servicio s) {
    char *aux = (char*)malloc(sizeof(Servicio) + 1);
    strcpy(aux, s.descripcion);
    return aux;
}

float getPrecio(Servicio s) {
    return s.precio;
}

int getDescuento(Servicio s) {
    return s.descuento;
}

#endif // SERVICIO_H_INCLUDED
