#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;
int Duracion; // entre 10 – 100
}typedef tarea;

tarea buscarTarea(tarea *tarea);

int main (){
    int cantTareas,bool,busc;
    printf("ingrese cuantas tareas debe cargar: ");
    scanf("%d", &cantTareas);

    struct Tarea **punt = (struct Tarea **)malloc(sizeof(struct Tarea *)*cantTareas);
    struct Tarea **TareasPendientes = (struct Tarea **)malloc(sizeof(struct Tarea *)*cantTareas);
    struct Tarea **TareasRealizadas = (struct Tarea **)malloc(sizeof(struct Tarea *)*cantTareas);


    for (int j = 0; j < cantTareas; j++) //inicializo la matriz en null
    {
        punt[j]=NULL;
        TareasPendientes[j]=NULL;
        TareasRealizadas[j]=NULL;
    }
    

    for (int i = 0; i < cantTareas; i++)
    {
        punt[i]=malloc(sizeof(struct Tarea));
        // TareasPendientes[i]=malloc(sizeof(struct Tarea));
        // TareasRealizadas[i]=malloc(sizeof(struct Tarea));
        
        punt[i]->TareaID = i;
        printf("\nTAREA N° %d", punt[i]->TareaID);
        
        char auxi[50];
        printf("\nIngrese descripcion de la tarea: ");
        scanf("%s", &auxi);
        fflush;
        punt[i]->Descripcion = malloc(sizeof(char)*strlen(auxi+1));
        strcpy(punt[i]->Descripcion,auxi);
        printf("\nDescripcion: %s", punt[i]->Descripcion);

        punt[i]->Duracion = 10+rand()%110;
        printf("\nDuracion: %d", punt[i]->Duracion);

        printf("\n¿se realizo esta tarea?(1 para si,0 para no): ");
        scanf("%d", &bool);
        
        TareasPendientes[i]=punt[i];
        if (bool==1)
        {
            TareasRealizadas[i]=punt[i];
            TareasPendientes[i]=NULL;
        }
    
        // free(punt[i]->Descripcion);
        // free(punt[i]);
    }
    

    printf("\n-------Tareas Realizadas-------");
    for (int z = 0; z < cantTareas; z++)
    {
        if (TareasRealizadas[z]!=NULL)
        {
            printf("\nTarea N°%d", TareasRealizadas[z]->TareaID);
            printf("\nDescripcion: %s", TareasRealizadas[z]->Descripcion);
            printf("\nDuracion: %d", TareasRealizadas[z]->Duracion);
        }
        
    }
    free(TareasRealizadas);
    
    printf("\n-------Tareas Pendientes-------");
    for (int y = 0; y < cantTareas; y++)
    {
        if (TareasPendientes[y]!=NULL)
        {
            printf("\nTarea N°%d", TareasPendientes[y]->TareaID);
            printf("\nDescripcion: %s", TareasPendientes[y]->Descripcion);
            printf("\nDuracion: %d", TareasPendientes[y]->Duracion);
        }
        
    }
    free(TareasPendientes);

   

    tarea tareabus = buscarTarea(*punt);
    printf("\n------tarea buscada--------");
    printf("\ntarea N°%d", tareabus.TareaID);
    printf("\ndescripcion: %s", tareabus.Descripcion);
    printf("\nduracion: %d", tareabus.Duracion);

    for (int u = 0; u < cantTareas; u++)
    {
        free(punt[u]->Descripcion);
        free(punt[u]);
    }
    free(punt);
    
    return 0;
}

tarea buscarTarea(tarea *tarea){
    int i;
    printf("ingrese el numero de tarea (ID): ");
    scanf("%d", &i);

    return tarea[i];
}