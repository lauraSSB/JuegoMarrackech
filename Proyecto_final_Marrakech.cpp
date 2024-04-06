#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct alfombra{
    int coor_uno[2];
    int coor_dos[2];
};

void tablero2(string movimientos2[][7]){ //lo unico que hace es imprimr la matriz de copia
    for (int i=0; i<7; i++){
        cout<<" ---  ---  ---  ---  ---  ---  --- "<<endl;
        for(int j=0; j<7; j++){

            cout<<"| "<<movimientos2[i][j]<<" |";
        }
        cout<<endl;
    }
    cout<<" ---  ---  ---  ---  ---  ---  --- "<<endl;
}

void tablero(int fila, int columna,string movimientos[][7],string movimientos2[][7], alfombra alfombras, string tipo, int jugador1[], int jugador2[]){
    if(tipo=="X"){
        jugador1[0] -= 1;
    }
    else if (tipo=="Y"){
        jugador2[0] -= 1;
    }
    movimientos2[alfombras.coor_uno[0]][alfombras.coor_uno[1]] = tipo;
    movimientos2[alfombras.coor_dos[0]][alfombras.coor_dos[1]] = tipo;
    movimientos[alfombras.coor_uno[0]][alfombras.coor_uno[1]] = tipo;
    movimientos[alfombras.coor_dos[0]][alfombras.coor_dos[1]] = tipo;

    for (int i=0; i<7; i++){
        cout<<" ---  ---  ---  ---  ---  ---  --- "<<endl;
        for(int j=0; j<7; j++){
                cout<<"| "<<movimientos2[i][j]<<" |";
        }
        cout<<endl;
    }
    cout<<" ---  ---  ---  ---  ---  ---  --- "<<endl;

}

alfombra tablero_opciones(string movimientos2[][7], int coordenadasxy[], alfombra Alfombra){
    string movimientos3[7][7]; //para que el jugador decida en que direccion pone la alfombra
    int opcion, direccion;
    int coordenadasx = coordenadasxy[0]; //columna
    int coordenadasy = coordenadasxy [1]; //fila

    for (int i=0; i<7;i++){
        for (int j=0;j<7; j++){
            movimientos3[i][j] = movimientos2[i][j];
        }
    }

    if (coordenadasy-1>=0 && coordenadasy<7){
        movimientos3[coordenadasy-1][coordenadasx] = "1";
    }
    if(coordenadasy+1<=6 && coordenadasy+1>=0){
        movimientos3[coordenadasy+1][coordenadasx] = "3";
    }
    if (coordenadasx-1>=0 && coordenadasx<7){
        movimientos3[coordenadasy][coordenadasx-1] = "2";
    }
    if(coordenadasx+1<=6 && coordenadasx+1>=0){
        movimientos3[coordenadasy][coordenadasx+1] = "4";
    }

    tablero2(movimientos3);

    cout<<"Ingrese la opcion (1, 2, 3 o 4) en donde desea poner la alfombra: ";
    cin>>opcion;
    cout<<"Ingrese la direccion. "<<endl;
    switch (opcion){
        case 1:
            Alfombra.coor_uno[0] = coordenadasy-1;
            Alfombra.coor_uno[1] = coordenadasx;
            cout<<"1. Norte"<<endl<<"2. Este"<<endl<<"3. Oeste"<<endl;
            cin>>direccion;
            switch(direccion){
                case 1:
                    Alfombra.coor_dos[0] = coordenadasy-2;
                    Alfombra.coor_dos[1] = coordenadasx;
                    break;
                case 2:
                    Alfombra.coor_dos[0] = coordenadasy-1;
                    Alfombra.coor_dos[1] = coordenadasx+1;
                    break;
                case 3:
                    Alfombra.coor_dos[0] = coordenadasy-1;
                    Alfombra.coor_dos[1] = coordenadasx-1;
                    break;
            }
            break;
        case 2:
            Alfombra.coor_uno[0] = coordenadasy;
            Alfombra.coor_uno[1] = coordenadasx-1;
            cout<<"1. Norte"<<endl<<"2. Oeste"<<endl<<"3. Sur"<<endl;
            cin>>direccion;
            switch(direccion){
                case 1:
                    Alfombra.coor_dos[0] = coordenadasy-1;
                    Alfombra.coor_dos[1] = coordenadasx-1;
                    break;
                case 2:
                    Alfombra.coor_dos[0] = coordenadasy;
                    Alfombra.coor_dos[1] = coordenadasx-2;
                    break;
                case 3:
                    Alfombra.coor_dos[0] = coordenadasy+1;
                    Alfombra.coor_dos[1] = coordenadasx-1;
                    break;
            }
            break;

        case 3:
            Alfombra.coor_uno[0] = coordenadasy+1;
            Alfombra.coor_uno[1] = coordenadasx;
            cout<<"1. Sur"<<endl<<"2. Este"<<endl<<"3. Oeste"<<endl;
            cin>>direccion;
            switch(direccion){
                case 1:
                    Alfombra.coor_dos[0] = coordenadasy+2;
                    Alfombra.coor_dos[1] = coordenadasx;
                    break;
                case 2:
                    Alfombra.coor_dos[0] = coordenadasy+1;
                    Alfombra.coor_dos[1] = coordenadasx+1;
                    break;
                case 3:
                    Alfombra.coor_dos[0] = coordenadasy+1;
                    Alfombra.coor_dos[1] = coordenadasx-1;
                    break;
            }
            break;

        case 4:
            Alfombra.coor_uno[0] = coordenadasy;
            Alfombra.coor_uno[1] = coordenadasx+1;
            cout<<"1. Norte"<<endl<<"2. Este"<<endl<<"3. Sur"<<endl;
            cin>>direccion;
            switch(direccion){
                case 1:
                    Alfombra.coor_dos[0] = coordenadasy-1;
                    Alfombra.coor_dos[1] = coordenadasx+1;
                    break;
                case 2:
                    Alfombra.coor_dos[0] = coordenadasy;
                    Alfombra.coor_dos[1] = coordenadasx+2;
                    break;
                case 3:
                    Alfombra.coor_dos[0] = coordenadasy+1;
                    Alfombra.coor_dos[1] = coordenadasx+1;
                    break;
            }
            break;

        default:
            break;
    }
    return Alfombra;
}

void monedas2(int fila,int columna, string movimientos[][7],string contrario, int contador_monedas[],char direccion){
    char copia_direccion;
    if(movimientos[fila][columna] == contrario){
        contador_monedas[0]++;
        if (movimientos[fila-1][columna] == contrario && direccion!='b'){
            copia_direccion = 'a';
            monedas2(fila-1,columna,movimientos,contrario,contador_monedas,copia_direccion);
        }
        if (movimientos[fila+1][columna] == contrario && direccion!='a'){
            copia_direccion = 'b';
            monedas2(fila+1,columna,movimientos,contrario,contador_monedas,copia_direccion);
        }
        if (movimientos[fila][columna-1] == contrario && direccion!='d'){
            copia_direccion = 'i';
            monedas2(fila,columna-1,movimientos,contrario,contador_monedas,copia_direccion);
        }
        if (movimientos[fila][columna+1] == contrario && direccion!='i'){
            copia_direccion = 'd';
            monedas2(fila,columna+1,movimientos,contrario,contador_monedas,copia_direccion);
        }
    }
}

void arriba(string flecha_direccion[], int coordenadasxy[], int movimiento){
    int movimiento_resultante;
    coordenadasxy[1] -= movimiento;
    if(coordenadasxy[1]<0){
        movimiento_resultante = coordenadasxy[1]*(-1) - 1;
        if(coordenadasxy[0]==6 || coordenadasxy[0]==2 || coordenadasxy[0]==4){
            coordenadasxy[1] = movimiento_resultante;
            coordenadasxy[0] -= 1;
            flecha_direccion[0] = "V";
        }
        else if (coordenadasxy[0]==1 || coordenadasxy[0]==3 || coordenadasxy[0]==5){
            coordenadasxy[1] = movimiento_resultante;
            coordenadasxy[0] += 1;
            flecha_direccion[0] = "V";
        }
        else if (coordenadasxy[0] == 0){
            coordenadasxy[1] = 0;
            coordenadasxy[0] = movimiento_resultante;
            flecha_direccion[0] = ">";
        }
    }
    else{
        flecha_direccion[0] = "^";
    }
}

void abajo(string flecha_direccion[], int coordenadasxy[], int movimiento){
    int movimiento_resultante;
    coordenadasxy[1] += movimiento;
    if(coordenadasxy[1]>6){
        movimiento_resultante = 6 - (coordenadasxy[1] - 6) + 1;
        if(coordenadasxy[0]==0 || coordenadasxy[0]==2 || coordenadasxy[0]==4){
            coordenadasxy[1] = movimiento_resultante;
            coordenadasxy[0] += 1;
            flecha_direccion[0] = "^";
        }
        else if (coordenadasxy[0]==1 || coordenadasxy[0]==3 || coordenadasxy[0]==5){
            coordenadasxy[1] = movimiento_resultante;
            coordenadasxy[0] -= 1;
            flecha_direccion[0] = "^";
        }
        else if (coordenadasxy[0] == 6){
            coordenadasxy[1] = 6;
            coordenadasxy[0] = movimiento_resultante;
            flecha_direccion[0] = "<";
        }
    }
    else{
        flecha_direccion[0] = "V";
    }
}

void derecha(string flecha_direccion[], int coordenadasxy[], int movimiento){
    int movimiento_resultante;
    coordenadasxy[0] += movimiento;
    if(coordenadasxy[0]>6){
        movimiento_resultante = 6 - (coordenadasxy[0] - 6) + 1;
        if(coordenadasxy[1]==0 || coordenadasxy[1]==2 || coordenadasxy[1]==4){
            coordenadasxy[0] = movimiento_resultante;
            coordenadasxy[1] += 1;
            flecha_direccion[0] = "<";
        }
        else if (coordenadasxy[1]==1 || coordenadasxy[1]==3 || coordenadasxy[1]==5){
            coordenadasxy[0] = movimiento_resultante;
            coordenadasxy[1] -= 1;
            flecha_direccion[0] = "<";
        }
        else if (coordenadasxy[1] == 6){
            coordenadasxy[0] = 6;
            coordenadasxy[1] = movimiento_resultante;
            flecha_direccion[0] = "^";
        }
    }
    else{
        flecha_direccion[0] = ">";
    }
}

void izquierda(string flecha_direccion[], int coordenadasxy[], int movimiento){
    int movimiento_resultante;
    coordenadasxy[0] -= movimiento;
    if(coordenadasxy[0]<0){
        movimiento_resultante = coordenadasxy[0]*(-1) - 1;
        if(coordenadasxy[1]==6 || coordenadasxy[1]==4 || coordenadasxy[1]==2){
            coordenadasxy[0] = movimiento_resultante;
            coordenadasxy[1] -= 1;
            flecha_direccion[0] = ">";
        }
        else if (coordenadasxy[1]==1 || coordenadasxy[1]==3 || coordenadasxy[1]==5){
            coordenadasxy[0] = movimiento_resultante;
            coordenadasxy[1] += 1;
            flecha_direccion[0] = ">";
        }
        else if (coordenadasxy[1] == 0){
            coordenadasxy[0] = 0;
            coordenadasxy[1] = movimiento_resultante;
            flecha_direccion[0] = "V";
        }
    }
    else{
        flecha_direccion[0] = "<";
    }
}

bool salida (int jugador1[], int jugador2[],string movimientos[][7]){
    bool juego = true;
    int total_jugador1=0, total_jugador2=0;
    int monedas1 = jugador1[1] + jugador1[2]*5;
    int monedas2 = jugador2[1] + jugador2[2]*5;
    if (jugador1[0]==0 && jugador2[0] == 0){
        for (int i=0; i<7; i++){
            for (int j=0; j<7; j++){
                if (movimientos[i][j] == "X"){
                    total_jugador1++;
                }
                else if (movimientos[i][j] == "Y"){
                    total_jugador2++;
                }
            }
        }

        total_jugador1+=monedas1;
        total_jugador2+=monedas2;

        if(total_jugador1>total_jugador2){
            cout<<endl<<"JUGADOR 1, FELICIDADES. ���HA GANADO LA PARTIDA!!!"<<endl;
        }
        else if(total_jugador1<total_jugador2){
            cout<<endl<<"JUGADOR 2, FELICIDADES. ���HA GANADO LA PARTIDA!!!"<<endl;
        }
        else{
            cout<<endl<<"JUGADORES 1 Y 2, HAN QUEDADO EMPATADOS. BUEN JUEGO."<<endl;
        }
        juego = false;
        return juego;
    }
    else if (monedas1<= 0 || monedas2<=0){
        juego = false;
        return juego;
    }
    return juego;
}

int main(){
    bool juego = true; //nos da la pauta de seguir o terminar el juego
    int fila, columna; // posicion del Assam, segun el movimiento
    int contador =0,jugador; //contador=rondas del juego
    int movimiento,direccion; //movimiento -> lo que saca en el dado - direccion -> una opcion que ingresa el usuario
    int coordenadax,coordenaday; //posicion del Assam
    int coordenadasxy[2]={3,3}; //vector de posiciones del Assam  (en vector para que se cambie en todo el programa al llamar funciones)
    int mon5,mon1; //calculo de monedas de 1 y de 5
    int contador_monedas[1] = {0}; //contador monedas en cada jugada
    alfombra Alfombra, alfombras; //coordenadas de la alfombra (se divide en dos)
    int jugador1[3] = {15,5,5}; //alfombras, monedas1, monedas 5 del jugador 1
    int jugador2[3] = {15,5,5}; //alfombras, monedas1, monedas5 del jugador 2
    string alfombra_tipo,flecha_direccion[1]={"^"}; //alfombra tipo -> segun el jugador, flecha direccion -> a donde mira el Assam
    string movimientos[7][7]={{" "," "," "," "," "," "," "},
                              {" "," "," "," "," "," "," "},
                              {" "," "," "," "," "," "," "},
                              {" "," "," "," "," "," "," "},
                              {" "," "," "," "," "," "," "},
                              {" "," "," "," "," "," "," "},
                              {" "," "," "," "," "," "," "}}; //matriz principal que contiene las alfombras y el Assam
    string movimientos2[7][7]; //copia matriz principal
    string contrario; //tipo de alfombra contraria a la del jugador actual

    srand(time(0)); //aleatoreidad del dado
    cout<<"Jugador 1: X"<<endl;
    cout<<"Jugador 2: Y"<<endl;
    for (int i=0; i<7;i++){ //para llenar copia matriz principal
        for (int j=0;j<7; j++){
            movimientos2[i][j] = movimientos[i][j];
        }
    }
    coordenadax = coordenadasxy [0]; //columna
    coordenaday = coordenadasxy [1]; //fila
    movimientos2[coordenaday][coordenadax] = flecha_direccion[0]; //Vector (x,y), matrix (y,x)
    tablero2(movimientos2);

    while (juego){
        contador_monedas[0] = 0;
        for (int i=0; i<7;i++){
            for (int j=0;j<7; j++){
                movimientos2[i][j] = movimientos[i][j];
            }
        }
        if (contador%2==0){
            jugador = 1;
            cout<<"Jugador "<<jugador<<" es su turno: "<<endl;
            alfombra_tipo = "X";
        }
        else if (contador%2!=0){
            jugador = 2;
            cout<<"Jugador "<<jugador<<" es su turno: "<<endl;
            alfombra_tipo = "Y";
        }
        cout<<"Jugador "<<jugador<<" escoja la direccion. "<<endl<<"1. Al frente"<<endl<<"2. Girar a la derecha"<<endl<<"3. Girar a la izquierda"<<endl;
        cout<<"Direccion: ";
        cin>>direccion;
        movimiento = rand()%4 +1;
        cout<<"Numero: ";
        cout<<movimiento<<endl;
        switch(direccion){
            case 1:
                if (flecha_direccion[0]=="^"){
                    arriba(flecha_direccion,coordenadasxy,movimiento);
                }
                else if (flecha_direccion[0]=="<"){
                    izquierda(flecha_direccion,coordenadasxy,movimiento);
                }
                else if (flecha_direccion[0]==">"){
                    derecha(flecha_direccion,coordenadasxy,movimiento);
                }
                else if(flecha_direccion[0]=="V"){
                    abajo(flecha_direccion,coordenadasxy,movimiento);
                }
                contador++;
                break;
            case 2:
                if (flecha_direccion[0]=="^"){
                    derecha(flecha_direccion,coordenadasxy,movimiento);
                }
                else if (flecha_direccion[0]=="<"){
                    arriba(flecha_direccion,coordenadasxy,movimiento);
                }
                else if (flecha_direccion[0]==">"){
                    abajo(flecha_direccion,coordenadasxy,movimiento);
                }
                else if(flecha_direccion[0]=="V"){
                    izquierda(flecha_direccion,coordenadasxy,movimiento);
                }
                contador++;
                break;
            case 3:
                if (flecha_direccion[0]=="^"){
                    izquierda(flecha_direccion,coordenadasxy,movimiento);
                }
                else if (flecha_direccion[0]=="<"){
                    abajo(flecha_direccion,coordenadasxy,movimiento);
                }
                else if (flecha_direccion[0]==">"){
                    arriba(flecha_direccion,coordenadasxy,movimiento);
                }
                else if(flecha_direccion[0]=="V"){
                    derecha(flecha_direccion,coordenadasxy,movimiento);
                }
                contador++;
                break;
            default:
                cout<<"Opcion no valida."<<endl;
                break;

        }

        coordenadax = coordenadasxy[0]; //columnas
        coordenaday = coordenadasxy[1]; //filas
        movimientos2[coordenaday][coordenadax] = flecha_direccion[0];
        columna = coordenadasxy[0];
        fila = coordenadasxy[1];
        if (alfombra_tipo=="X"){
            contrario = "Y";
        }
        else{
            contrario = "X";
        }
        direccion = 'n';
        monedas2(fila,columna,movimientos,contrario,contador_monedas,direccion);
        mon5 = contador_monedas[0]/5;
        mon1 = contador_monedas[0]%5;
        alfombras = tablero_opciones(movimientos2,coordenadasxy,Alfombra);
        tablero(coordenadasxy[1], coordenadasxy[0],movimientos,movimientos2,alfombras,alfombra_tipo,jugador1,jugador2);
        if(alfombra_tipo=="X"){
            cout<<"El jugador 1 debe pagar "<<contador_monedas[0]<<" monedas"<<endl;
            jugador1[2] -= mon5;
            jugador1[1] -= mon1;
        }
        else if(alfombra_tipo=="Y"){
            cout<<"El jugador 2 debe pagar "<<contador_monedas[0]<<" monedas"<<endl;
            jugador2[2] -= mon5;
            jugador2[1] -= mon1;
        }
        cout<<"JUGADOR 1:"<<endl<<"Alfombras: "<<jugador1[0]<<endl<<"Monedas:"<<jugador1[1] + jugador1[2]*5<<endl;
        cout<<"JUGADOR 2:"<<endl<<"Alfombras: "<<jugador2[0]<<endl<<"Monedas:"<<jugador2[1] + jugador2[2]*5<<endl;
        juego = salida(jugador1,jugador2,movimientos);
    }
}
