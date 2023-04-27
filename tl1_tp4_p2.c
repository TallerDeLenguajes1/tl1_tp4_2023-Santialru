#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*----------ESTRUCTURAS---------*/
struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;
int Duracion; // entre 10 – 100
}typedef tarea;

struct Nodo{
    tarea T;
    struct Nodo *Siguiente;
};

/*---------FUNCIONES-------------*/
struct Nodo *CrearListaVacia();
struct Nodo *CrearNodo(tarea t);
void InsertarNodo(struct Nodo ** Start, tarea t);
void EliminarNodo(struct Nodo **Start, tarea t);
struct Nodo *buscarNodo(struct Nodo * Start);
void MostrarDatos (struct Nodo * Start);


int main (){ 
    srand(time(NULL));
    int tareabool,estado, i, busbool,list;
    printf("¿Desea cargar una tarea?(1 para si, 0 para no): ");
    scanf("%d", &tareabool);

    struct Tarea **punt = (struct Tarea **)malloc(sizeof(struct Tarea *));
    
    struct Nodo *tareasRealizadas = NULL;
    struct Nodo *tareasPendientes = NULL;
    struct Nodo *todasTareas = NULL;
    struct Nodo *tareasEnProceso = NULL;
    
    tareasRealizadas = CrearListaVacia();
    tareasPendientes = CrearListaVacia();
    todasTareas = CrearListaVacia();
    tareasEnProceso = CrearListaVacia();
    

    while(tareabool != 0)
    {
        punt[i]=NULL;
        punt[i]=malloc(sizeof(struct Tarea));
        
        punt[i]->TareaID = i;
        printf("\nTAREA N° %d", punt[i]->TareaID);
        
        char auxili[50];
        printf("\nIngrese descripcion de la tarea: ");
        scanf("%s", &auxili);
        fflush(stdin);
        punt[i]->Descripcion = malloc(sizeof(char)*strlen(auxili+1));
        strcpy(punt[i]->Descripcion,auxili);
        printf("\nDescripcion: %s", punt[i]->Descripcion);
        

        punt[i]->Duracion = 10+rand()%110;
        printf("\nDuracion: %d", punt[i]->Duracion);

        printf("\n¿Se realizo esta tarea?(2:en proceso, 1: si,0: no): ");
        scanf("%d", &estado);
        
        InsertarNodo(&tareasPendientes, *punt[i]);
        InsertarNodo(&todasTareas, *punt[i]);


        if (estado == 1)
        {
            InsertarNodo(&tareasRealizadas, *punt[i]);
            EliminarNodo(&tareasPendientes, *punt[i]);
        }else if (estado == 2)
        {
            InsertarNodo(&tareasEnProceso, *punt[i]);
            EliminarNodo(&tareasPendientes, *punt[i]);
        }
        
        printf("\ndesea cargar una tarea?(1 para si, 0 para no): ");
        scanf("%d", &tareabool);
        i++;
    }
    struct Nodo *auxi = tareasRealizadas;
    struct Nodo *auxi2 = tareasPendientes;
    struct Nodo *auxi3 = tareasEnProceso;
    
    while (auxi != NULL)
    {
        printf("\n------TAREAS REALIZADAS-------");
        printf("\nTarea N°%d", auxi->T.TareaID);
        printf("\nDescripcion: %s", auxi->T.Descripcion);
        printf("\nDuracion: %d", auxi->T.Duracion);
        auxi = auxi->Siguiente;
    }
    while (auxi2 != NULL)
    {
        printf("\n------TAREAS PENDIENTES-------");
        printf("\nTarea N°%d", auxi2->T.TareaID);
        printf("\nDescripcion: %s", auxi2->T.Descripcion);
        printf("\nDuracion: %d", auxi2->T.Duracion);
        auxi2 = auxi2->Siguiente;
    }
    
    while (auxi3 != NULL)
    {
        printf("\n------TAREAS EN PROCESO-------");
        printf("\nTarea N°%d", auxi3->T.TareaID);
        printf("\nDescripcion: %s", auxi3->T.Descripcion);
        printf("\nDuracion: %d", auxi3->T.Duracion);
        auxi3 = auxi3->Siguiente;
    }

    
    printf("\nDesea realizar una busqueda? (1:si, 0:no): ");
    scanf("%d", &busbool);
    if (busbool == 1)
    {
        struct Nodo * busqueda = buscarNodo(todasTareas);

        printf("\n------TAREA BUSCADA-------");
        printf("\nTarea N°%d", busqueda->T.TareaID);
        printf("\nDescripcion: %s", busqueda->T.Descripcion);
        printf("\nDuracion: %d", busqueda->T.Duracion);
        busqueda = busqueda->Siguiente;
    }
    
    printf("\nDesea mostrar la cantidad de tareas y el tiempo que tomaran o tomaron?(1:si, 0:no): ");
    scanf("%d", &busbool);

    if (busbool == 1)
    {
        printf("elije que lista quieres mostrar: (1:Tarea Realizada, 2:Tarea pendiente, 3:Tarea en proceso)");
        scanf("%d", &list);

        switch (list)
        {
        case 1:
            MostrarDatos(tareasRealizadas);
            break;
        case:2
            MostrarDatos(tareasPendientes);
            break;
        case 3:
            MostrarDatos(tareasEnProceso);
        default:
            break;
        }
    }
    
    
    /*-------------------liberar memoria---------------*/
    for (int u = 0; u < i+1; u++)
    {
        free(punt[u]->Descripcion);
        free(punt[u]);
    }
    free(punt);

    return 0;
}

struct Nodo *CrearListaVacia(){
    return NULL;
}

struct Nodo *CrearNodo(tarea t){
    struct Nodo *Nnodo =(struct Nodo*)malloc(sizeof(struct Nodo));
    Nnodo->T = t;
    Nnodo->Siguiente= NULL;
    return Nnodo;
}

void InsertarNodo(struct Nodo ** Start, tarea t){
    struct Nodo * NuevoNodo= CrearNodo(t);
    NuevoNodo->Siguiente = *Start;
    *Start = NuevoNodo;
}


void EliminarNodo(struct Nodo **Start, tarea tare){
    struct Nodo *Aux = *Start;
    struct Nodo *AuxAnterior = NULL;

    while (Aux && Aux->T.TareaID != tare.TareaID){
        AuxAnterior = Aux;
        Aux = Aux->Siguiente;
    }

    if(Aux){
        if(Aux == *Start){
            *Start = Aux->Siguiente;
        }
        else{
            AuxAnterior->Siguiente = Aux->Siguiente;
        }
        free(Aux);
    }
}


struct Nodo *buscarNodo(struct Nodo * Start){
    int tipo;
    printf("\ningrese el tipo de busqueda (1:por palabra, 0:por id): ");
    scanf("%d", &tipo);

    if (tipo == 1)
    {
        char busque[50];
        printf("\nIngrese la palabra buscada: ");
        gets(busque);

        struct Nodo * aux = Start;
        while (aux && aux->T.Descripcion != busque)
        {
            aux = aux->Siguiente;
        }
        return aux;
    }else
    {
        int id;
        printf("ingrse el id buscado: ");
        scanf("%d", &id);
        struct Nodo * aux = Start;
        while (aux && aux->T.TareaID != id)
        {
            aux = aux->Siguiente;
        }
        return aux;
    }
}

void MostrarDatos (struct Nodo * Start){
    int cont, time;

    while (Start != NULL)
    {
        cont+=1;
        time += Start->T.Duracion
    }
    printf("cantidad de tareas: %d", &cont);
    printf("tiempo total: %d minutos", &time);
    
}