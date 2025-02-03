#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void inicio_juego();
void menu();
void Registro();
struct return_values matrizlogica(char i1, char j1);

struct return_values
{
    int iout, jout;
};

struct valores_Jugador
{
    string nombre;
    long int puntos;
};
valores_Jugador *piezas = new valores_Jugador[10];


void toString() {
    string result = ""; 
    for (int i = 0; i < 2; i++) {
        result += "\tJugador " + to_string(i + 1) + ": " + piezas[i].nombre + "\t||\t" + to_string(piezas[i].puntos) + "\n";
    }
    cout<<result;
}

int main()
{
    menu();
    return 0;
}

void menu()
{
    int opcion;
    do
    {

        cout << "\t\t\t\t\t TORTUNTITOS" << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;
        cout << "\t 1. Jugar" << endl;
        cout << "\t 2. Tabla de Puntuaciones" << endl;
        cout << "\t 3. Creditos" << endl;
        cout << "\t 4. Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {

            cout << "\t\t\t\t\t TORTUNTITOS" << endl;
            cout << "--------------------------------------------------------------------------------------------" << endl;
            cout << "\t\tRegistro de valores_Jugador" << endl;
            cout << "Ingresar los nombres de los jugadores" << endl;
            Registro();
            inicio_juego();

            break;
        }
        case 2:
        {
            cout << "\t\tTabla de Puntuaciones" << endl;
            cout << "\t--------------------------------------" << endl;
            cout << "\tNombre\t\t||\tPuntuacion" << endl;
            toString();

            break;
        }
        case 3:
        {

            cout << "\t\t\tCreditos" << endl;
            cout << "\t-----------------------------------------------------" << endl;
            cout << "Méndez Johan & Moreta Luis\n";
            break;
        }
     
        case 4:
        {

            cout << "Saliste del juego....." << endl;
            break;
        }
        default:
            cout << "Opcion no valida" << endl;

            break;
        }
    } while (opcion != 4);
}

void Registro()
{
    string nombre;

    for (int i = 0; i < 2; i++)
    {
        cout << "Jugador " << i + 1 << ": ";
        cin >> piezas[i].nombre;
    }
}

struct return_values matrizlogica(char i1, char j1)
{
    int matriz[21][21] = {};
    char posicionletra[11] = {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char posicionnumero[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    return_values valores;
    int iout, jout, confirm;

    do
    {
        for (jout = 0; jout <= 10; jout++)
        {
            for (iout = 0; iout <= 10; iout++)
            {
                if ((i1 == posicionletra[jout] && j1 == posicionnumero[iout]) || (i1 == posicionnumero[jout] && j1 == posicionletra[iout]))
                {
                    if (i1 == posicionletra[jout])
                    {
                        matriz[iout * 2][jout * 2 - 1] = 1;
                        valores.iout = iout;
                        valores.jout = jout;
                        confirm = 1;
                    }
                    else
                    {
                        matriz[iout * 2 - 1][jout * 2] = 1;
                        valores.iout = iout;
                        valores.jout = jout;
                        confirm = 1;
                    }
                }
            }
        }
    } while (confirm = 0);
    return valores;
}

void inicio_juego()
{
    char matriz[84][42] = {};
    for (int j = 0; j <= 20; j++)
    {
        for (int i = 0; i <= 39; i++)
        {
            matriz[i][j] = ' ';
        }
    }

    char numeracion[20] = {'0', 'a', '1', 'b', '2', 'c', '3', 'd', '4', 'e', '5', 'f', '6', 'g', '7', 'h', '8', 'i', '9', 'j'};
    char posicionletra[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char posicionnumero[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char posicionletral[11] = {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char i1, j1;
    return_values valores, v;
    int matrizl[21][21] = {};
    int puntaje1 = 0, puntaje2 = 0;

    for (int j = 0; j <= 18; j++)
    {
        for (int i = 0; i <= 39; i++)
        {
          
            if (i % 8 == 0 && j % 4 == 0 && i < 80 && j < 39)
            {
                matriz[i][j + 2] = posicionletra[j / 4];
            }
            if (i % 8 == 1 && j % 4 == 0 && i < 80 && j < 39)
            {
                matriz[i][j + 2] = posicionnumero[i / 8];
            }
            if (i % 8 == 0 && j % 4 == 0 && i < 80 && j < 39)
            {
                matriz[i + 4][j] = posicionnumero[j / 4];
            }
            if (i % 8 == 1 && j % 4 == 0 && i < 80 && j < 39)
            {
                matriz[i + 4][j] = posicionletra[i / 8];
            }
        }
    }

    for (int k = 0; k < 20; k++)
    {
        for (int j = 0; j <= 19; j++)
        {
            for (int i = 0; i <= 41; i++)
            {
                if (matriz[i][j] == '\0')
                {
                    matriz[i][j] = ' ';
                }
                // lineas horizontales superior e inferior
                matriz[i][0] = 219;
                matriz[i][20] = 219;
                // lineas verticales (1)(2) izquierda (3)(4) derecha
                matriz[0][j] = 219;  //(1)
                matriz[1][j] = 219;  //(2)
                matriz[41][j] = 219; //(3)
                matriz[40][j] = 219; //(4)
                // cuadros o puntos del tablero
                if (i % 8 == 0 && j % 4 == 0 && i < 80 && j < 39)
                {
                    matriz[i][j] = 219;
                }
                if (i % 8 == 1 && j % 4 == 0 && i < 80 && j < 39)
                {
                    matriz[i][j] = 219;
                }
                // lineas de juego (hechas por jugador)
                int vertical = 0, horizontal = 0;
                for (int k = 0; k < 10; k++)
                {
                    if (i1 == posicionletra[k])
                    {
                        vertical = 1;
                    }
                }
                for (int k = 0; k < 10; k++)
                {
                    if (i1 == posicionnumero[k])
                    {
                        horizontal = 1;
                    }
                }
                if ((i == valores.iout * 8 || i == valores.iout * 8 + 1) && j == valores.jout * 4 - 2 && vertical == 1)
                {
                    matriz[i][j - 1] = 176;
                    matriz[i][j] = 176;
                    matriz[i][j + 1] = 176;
                }
                if ((i == valores.iout * 8 - 4 || i == valores.iout * 8 - 3) && j == valores.jout * 4 && horizontal == 1)
                {
                    matriz[i - 2][j] = 176;
                    matriz[i][j] = 176;
                    matriz[i + 2][j] = 176;
                }
                // Rellenador de x y o
                if (matrizl[(i + 2) / 4][(j + 1) / 2] == 2 && i % 8 != 0 && j % 4 != 0)
                {
                    matriz[i][j] = 88;
                    matriz[i + 2][j] = 88;
                    matriz[i][j + 1] = 88;
                    matriz[i + 2][j + 1] = 88;
                }
                if (matrizl[(i + 2) / 4][(j + 1) / 2] == 3 && i % 8 != 0 && j % 4 != 0)
                {
                    matriz[i][j] = 79;
                    matriz[i + 2][j] = 79;
                    matriz[i][j + 1] = 79;
                    matriz[i + 2][j + 1] = 79;
                }
            }
            cout << endl;
        }
        // graficador del tablero

        cout << "\t\t\t\t\t\t\t TORTUNTITOS" << endl;
        cout << "\t--------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Es el turno del jugador " << k % 2 + 1 << "      ";
        for (int i = 0; i <= 41; i++)
        {
            printf("%c", matriz[i][0]);
        }
        cout << "\t\tSCORE: " << "  X = " << puntaje1 << "    O = " << puntaje2 << endl;
        for (int j = 1; j <= 20; j++)
        {
            cout << "                 ";
            for (int i = 0; i <= 41; i++)
            {
                printf("%c", matriz[i][j]);
            }
            cout << endl;
        }
        cout << "Ingrese 00 para salir" << endl;
        ;

        int posicion_invalida = 1;
        int confirmar_salir = 0;
        do
        {
            cin.ignore();
            cin >> i1;
            cin >> j1;
        
            v = matrizlogica(i1, j1);
            for (int jb = 0; jb <= 11; jb++)
            {
                for (int ib = 0; ib <= 11; ib++)
                {
                    if (((i1 == posicionletral[jb] && j1 == posicionnumero[ib]) || (i1 == posicionnumero[jb] && j1 == posicionletral[ib])))
                    {
                        posicion_invalida = 0;
                    }
                }
            }
            if (posicion_invalida == 1)
            {
                cout << "Ingrese una posicion valida" << endl;
            }
            for (int jb = 0; jb <= 20; jb++)
            {
                for (int ib = 0; ib <= 20; ib++)
                {
                    if ((i1 == posicionletral[jb] && j1 == posicionnumero[ib]) || (i1 == posicionnumero[jb] && j1 == posicionletral[ib]))
                    {
                        if (i1 == posicionletral[jb])
                        {
                            if (matrizl[ib * 2][jb * 2 - 1] == 1)
                            {
                                posicion_invalida = 2;
                            }
                        }
                        else
                        {
                            if (matrizl[ib * 2 - 1][jb * 2] == 1)
                            {
                                posicion_invalida = 2;
                            }
                        }
                    }
                }
            }
            if (posicion_invalida == 2)
            {
                cout << "Posicion ya jugada, ingrese otra posicion" << endl;
            }
            if (i1 == '0' && j1 == '0')
            {
                k = k + 100;
                posicion_invalida = 0;
            }
        } while (posicion_invalida != 0);
        valores = matrizlogica(i1, j1);

        // lineas de tabla logica
        int confirm = 0;
        do
        {
            for (int jb = 0; jb <= 20; jb++)
            {
                for (int ib = 0; ib <= 20; ib++)
                {
                    if ((i1 == posicionletral[jb] && j1 == posicionnumero[ib]) || (i1 == posicionnumero[jb] && j1 == posicionletral[ib]))
                    {
                        if (i1 == posicionletral[jb])
                        {
                            matrizl[ib * 2][jb * 2 - 1] = 1;
                            confirm = 1;
                        }
                        else
                        {
                            matrizl[ib * 2 - 1][jb * 2] = 1;
                            confirm = 1;
                        }
                    }
                }
            }
        } while (confirm = 0);

        int pasounicob;

        if (pasounicob != 1)
        {
            // bordes de la tabla valor=1
            for (int jb = 0; jb <= 20; jb++)
            {
                for (int ib = 0; ib <= 20; ib++)
                {
                    if (ib == 0 || jb == 0 || ib == 10 || jb == 10)
                    {
                        matrizl[ib][jb] = 1;
                    }
                }
            }
            // puntos de la tabla logica
            for (int jb = 0; jb <= 20; jb++)
            {
                for (int ib = 0; ib <= 20; ib++)
                {
                    if (ib % 2 == 0 && jb % 2 == 0)
                    {
                        matrizl[ib][jb] = 8;
                    }
                }
            }
            pasounicob = 1;
        }

        // confirmador de 4 lineas completadas
        int ka = k;
        for (int jb = 1; jb <= 20; jb += 2)
        {
            for (int ib = 1; ib <= 20; ib += 2)
            {
                if (matrizl[ib - 1][jb] == 1 && matrizl[ib + 1][jb] == 1 && matrizl[ib][jb - 1] == 1 && matrizl[ib][jb + 1] == 1 && matrizl[ib][jb] == 0 && k % 2 == 1)
                {
                    matrizl[ib][jb] = 2;
                    ka = ka - 1;
                }
                if (matrizl[ib - 1][jb] == 1 && matrizl[ib + 1][jb] == 1 && matrizl[ib][jb - 1] == 1 && matrizl[ib][jb + 1] == 1 && matrizl[ib][jb] == 0 && k % 2 == 0)
                {
                    matrizl[ib][jb] = 3;
                    ka = ka - 1;
                }
            }
        }
        k = ka;

        // Puntajes
        int c1 = 0, c2 = 0;
        for (int jb = 1; jb <= 20; jb += 2)
        {
            for (int ib = 1; ib <= 20; ib += 2)
            {
                if (matrizl[ib][jb] == 2)
                {
                    c1 += 1;
                    puntaje1 = c1;
                    piezas[0].puntos = puntaje1;
                }
                if (matrizl[ib][jb] == 3)
                {
                    c2 += 1;
                    puntaje2 = c2;
                    piezas[1].puntos = puntaje2;
                }
            }
        }
    }
}


