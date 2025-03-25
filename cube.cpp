#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>
#include <cmath>
#include <windows.h>


using namespace std;
using namespace chrono;   


//Declaração de variaveis.
float X, Y, Z;
float A = 0, B = 0, C = 0;
const int altura = 44;
const int largura = 160;
const int area = largura * altura;
float zBuffer[area];
float cubeSize = 20;
char buffer[area];
int XP, YP;
int IDX;
char background = ' ';
float OZZ;
float incrementSpeed = 0.5;
float angleRotation = 0.005;
const int distanciaCamera = 100;
float fatorEscala = 60;






//Prototipagem de funções.
float calcularX(float i, float j, float k);
float calcularY(float i, float j, float k);
float calcularZ(float i, float j, float k);
void calcularSuperficie(float cubeX, float cubeY, float cubeZ, int ch);
int corCaractere(char ch);
void setColor(int color);




int main(){


while(1){
    fill(buffer, buffer + area, background);
    memset(zBuffer, 0, area * 4);


for(float cubeX = - cubeSize; cubeX < cubeSize; cubeX += incrementSpeed){
    for(float cubeY = - cubeSize; cubeY < cubeSize; cubeY += incrementSpeed){

        //Implementação de todas as faces do cubo.
        calcularSuperficie(cubeX, cubeY, -cubeSize, '@');
        calcularSuperficie(cubeSize, cubeY, cubeX, '$');
        calcularSuperficie(-cubeSize, cubeY, -cubeX, '~');
        calcularSuperficie(-cubeX, cubeY, cubeSize, '#');
        calcularSuperficie(cubeX, -cubeSize, -cubeY, ';');
        calcularSuperficie(cubeX, cubeSize, cubeY, '+');

    }
}

printf("\x1b[H");
for(int K = 0; K < area; K++){
   if(K % largura == 0) cout << '\n';
    //Definir cor pra cada caractere do buffer.
   setColor(corCaractere(buffer[K])); 
   cout << buffer[K];
 
   }
   setColor(15);
    //Rotação em angulo.
     A += 0.1f;
     B += 0.1f;
     C += 0.02f;
     //Delay de cada frame.
     this_thread::sleep_for(milliseconds(7));
}
    return 0;
}






//Setagem de cor baseada no comando windows.
void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}




//Definir cor pra cada caractere.
int corCaractere(char ch) {
    switch (ch) {
        case '@': return 12;
        case '$': return 10; 
        case '~': return 14;
        case '#': return 9;  
        case ';': return 11; 
        case '+': return 13;
        default: return 15;
    }
}



//Funções de calculo dos exiso X Y Z utilizando matriz de rotação
float calcularX(float i, float j, float k){
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
         j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}



float calcularY(float i, float j, float k){
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
    j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
    i * cos(B) * sin(C);


}



float calcularZ(float i, float j, float k){
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}




//Calcular a superfice e profundidade.
void calcularSuperficie(float cubeX, float cubeY, float cubeZ, int ch){


X = calcularX(cubeX, cubeY, cubeZ);
Y = calcularY(cubeX, cubeY, cubeZ);
Z = calcularZ(cubeX, cubeY, cubeZ) + distanciaCamera;


OZZ = 1/Z;


XP = (int)(largura / 2 + fatorEscala * OZZ * X + 2);
YP = (int)(altura / 2 + fatorEscala * OZZ * Y);


IDX = XP + YP * largura;


//Atualizar pontos.
if(IDX >= 0 && IDX < area){
    if(OZZ > zBuffer[IDX]){
        zBuffer[IDX] = OZZ;
        buffer[IDX] = ch;



        
    }
  }
}

