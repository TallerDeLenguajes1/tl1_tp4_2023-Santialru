#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;
int Duracion; // entre 10 – 100
}typedef tarea;

struct Nodo{
    tarea T;
    struct Nodo *Siguiente;
};

struct Nodo *CrearListaVacia();
struct Nodo *CrearNodo(tarea t);
void InsertarNodo(struct Nodo ** Start, tarea t);
void EliminarNodo(struct Nodo **Start, tarea t);
struct Nodo *buscarNodo(struct Nodo * Start, tarea t);


int main (){ 
    srand(time(NULL));
    int tareabool,bool, i;
    printf("¿Desea cargar una tarea?(1 para si, 0 para no): ");
    scanf("%d", &tareabool);

    struct Tarea **punt = (struct Tarea **)malloc(sizeof(struct Tarea *));
    
    struct Nodo *tareasRealizadas = NULL;
    struct Nodo *tareasPendientes = NULL;
    
    tareasRealizadas = CrearListaVacia();
    tareasPendientes = CrearListaVacia();


    // for (int j = 0; j < cantTareas; j++) //inicializo la matriz en null
    // {
    //     
    // }
    

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

        printf("\n¿Se realizo esta tarea?(1 para si,0 para no): ");
        scanf("%d", &bool);
        
        InsertarNodo(&tareasPendientes, *punt[i]);


        if (bool == 1)
        {
           InsertarNodo(&tareasRealizadas, *punt[i]);
           EliminarNodo(&tareasPendientes, *punt[i]);
        }

        printf("\ndesea cargar una tarea?(1 para si, 0 para no): ");
        scanf("%d", &tareabool);
        i++;
    }
    struct Nodo *auxi = tareasRealizadas;
    struct Nodo *auxi2 = tareasPendientes;
    
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

