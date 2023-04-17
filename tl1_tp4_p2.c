#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;
int Duracion; // entre 10 – 10
struct Tarea *tareaPendiente;
struct Tarea *tareaRealizada;

}typedef tarea;

tarea buscarTarea(tarea **tarea);


int main (){

    int cantTareas,bool;
    printf("ingrese cuantas tareas debe cargar: ");
    scanf("%d", &cantTareas);

    struct Tarea **punt = (struct Tarea **)malloc(sizeof(struct Tarea *)*cantTareas);

    for (int i = 0; i < cantTareas; i++)
    {
        punt[i]=NULL;
    }
    

    for (int i = 0; i < cantTareas; i++)
    {
        tarea[i]=malloc(sizeof(struct Tarea));
        punt[i].TareaID = i;

        char auxi[50];

        printf("ingrese descripcion de la tarea: ");
        scanf("%s", &auxi);
        fflush;

        punt[i]->Descripcion = malloc(sizeof(char)*strlen(auxi+1));
        strcpy(punt[i]->Descripcion,auxi);

        punt[i].Duracion = 10+rand()%110;
        
        printf("\nTAREA N° %d", punt[i]->TareaID);
        printf("\nDescripcion: %s", punt[i]->Descripcion);
        printf("\nDuracion: %d", punt[i]->Duracion);
        printf("\n¿se realizo esta tarea?(1 para si,0 para no)");
        scanf("%d", &bool);
        
        struct tarea tareaPendiente[i]=tarea[i];

        if (bool==1)
        {
            tareaRealizada[i]=tareaPendiente[i];
            tareaPendiente[i]=NULL;
        }
        
    }
    
    return 0;
}

tarea buscarTarea(tarea **tarea){
    int i;
    printf("ingrese el numero de tarea (ID): ");
    scanf("%d", &i);

    return tarea[i];
}