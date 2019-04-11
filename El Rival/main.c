#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define numPreguntas 1

struct Persona
{
    char nombre[10];
    int respCorrectas;   //Para determinar el rival mas fuerte
    bool participando = true;   //Sabremos si sigue participando en el juego
}typedef Persona;

struct Pregunta
{
    char pregunta[40];    //guarda la pregunta
    char opciones[20][4];    //guarda las 4 opciones
    int opcCorrecta;   //para saber que opcion es la correcta
}typedef Pregunta;

bool RealizarPregunta(/*(pregunta[aleatorio])*/);    //selecciona una pregunta random del vector pregunta
void LlenarPersonas(struct *persona,int numJugadores);   //Almacena los participantes
void LlenarPreguntas(struct *Pregunta);    //llena el vector de preguntas con el archivo preguntas.txt

int main()
{
int numJugadores, ronda = 1, aleatorio, i, j, turnos, opc;     //aleatorio = rand() % numPreguntas
int vectorPuntos = {5,10,20,50,100,150,200,250};
int /*vectorAcumulado[7] = {0}*/, total=0;
bool salir = false, correcta;
struct Persona *persona;
struct Pregunta *pregunta;

    printf("Bienvenido a Quinask!\n");
    do{
        printf("¿Cuantos jugadores participaran?\nJugadores:   ");
        scanf("%d",&numJugadores);
    }while(numJugadores<1 || numJugadores>7);

    persona = (Persona*)malloc(numJugadores*sizeof(Persona));  //crea un vector de personas
    pregunta = (Pregunta*)malloc(numPreguntas*sizeof(Pregunta));  //crea un vector de preguntas definida por numPreguntas que sesta en define

    LlenarPersonas(*persona, numJugadores);  //manda a llenar de datos el vector
    LlenarPreguntas(*pregunta);   //llena el vector de pregunas con el archivo

        //persona[0].

    do{    //seguira con el ciclo hasta que acabe el juego o decidan salir

        turnos = 0;
        i = 0;
        printf("Iniciaremos con la ronda %d",ronda);
        while((vectorAcumulado[i] <= 250) && (turnos < 10)){    //la ronda acaba cuando consiguen el dinero maximo o acaban los turnos

            if(i>1){
                printf("¿Quieres guardar en banco?\n1. Si\n2. No\nOpcion:  ");
                scanf("%d");
                if(opc==1){
                    total += vectorPuntos[i];    //añade los puntos acumulados de eso momento
                    i=0;      //resetea la cantidad acumulada
                }
            }

            correcta = RealizarPregunta(/*(pregunta[aleatorio])*/);  //recibe  para  imprimir la pregunta y opciones, y tambien regresa si acerto
            if (correcta == true) {                         //si regresa un true significa que la tuvo bien
                i++;       //aumenta la posicion en el vector de dinero acumulado
            }
            else
            {
                i=0;   //pierden lo acumulado
            }
            turnos++;
        }
        ronda++;

        printf("¿Quieres salir del juego?\n1. Si\n2. No\nOpcion:  ");
        scanf("%d");
        if(opc==1){salir = true;}
        system("cls");

    }while(ronda != 7 && salir == false);

    return 0;
}



bool RealizarPregunta(/*(pregunta[aleatorio])*/){
    int opc
    /*printf("%s\n\n%s\n%s\n%s\n%s\nOpcion:  "pregunta.pregunta,pregunta.opciones[][0],pregunta.opciones[][1],pregunta.opciones[][2],pregunta.opciones[][3]);
    scanf("%d",&opc);
    if(opc == preguna.opcCorrecta){
        return true;
    }
    return false;
    */
}

void LlenarPersonas(struct *persona, int numJugadores){
    for(int i = 0; i < numJugadores; i++)
    {
        printf("Dame el nombre del participante %d",i+1);
        scanf("%s",persona[i].nombre);
        system("cls");
    }
}

void LlenarPreguntas(struct *Pregunta){
	FILE *fp;
	fp = fopen ( "preguntas.txt", "r" );
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
	fclose ( fp );
}
