#include <iostream>
#include <string>
#include <cstdlib>  // Función rand().
#include <ctime>    // Función time() para generar una nueva seed aleatoria.
using namespace std;

#define log(x) cout << x << endl;

class Jugador{
    /*
        Agrega propiedades para guardar la vida(número entero), ataque(número entero) y nombre del jugador.
        Agrega una propiedad para guardar el jugador que lo atacó por última vez.
    */
    int hp;
    int ataque;
    string nombre;
    string uAtacante;
    public:
    Jugador();
    Jugador(int hp, int ataque, string nombre/* agrega parámetros para asignar hp, ataque y nombre */);

    void atacar(Jugador &objetivo/* agregar parámetros para atacar a otro jugador*/);
    int getHp(){
        return this->hp;
    }
    string getName(){
        return this->nombre;
    }
};

int main()
{
    srand(time(0));  // Seed para generar valores aleatorios
    Jugador abraham{100,5,"Abraham"};
    Jugador eleonor{200,20,"Eleonor"};
    while(eleonor.getHp()>0&&abraham.getHp()>0){
        if(eleonor.getHp()>0){
            eleonor.atacar(abraham);
        }
        if(abraham.getHp()>0){
            abraham.atacar(eleonor);
        }
        ;
    }
    if(eleonor.getHp()>abraham.getHp()){
        cout<<eleonor.getName()<<" fue la vencedora"<<endl;
    }else{
        cout<<abraham.getName()<<" fue el vencedor"<<endl;
    }

    /*
        Crear al menos 2 jugadores con diferentes nombres, vida y ataque.
        Los jugadores deben atacarse entre sí, tomando turnos, hasta que uno pierda toda su vida.
        En cuanto la vida del jugador se reduzca a 0 el programa muestra al ganador y se termina.
        No importa quien ataca primero.
    */

    return 0;
}

Jugador::Jugador(){
    this->hp=100;
    this->ataque=5;
    this->nombre="no definido";

    /*
        Asignar 100 a hp y 5 a attack como valores default.
        Asignar 'No definido' al nombre como default.
    */
}

Jugador::Jugador(int hp, int ataque, string nombre/* Agrega parámetros para asignar hp, ataque y nombre*/){
    if(hp>0){
        if(hp>=200){
            this->hp=200;
        }else{
            this->hp=hp;
        }
    }else{
        this->hp=1;
    }

if(ataque>0){
    if(ataque>=20){
        this->ataque=20;
    }else{
        this->ataque=ataque;
    }
}else{
        this->ataque=1;
}

    this->nombre=nombre;
    /*
        Asignar los parámetros recibidos a las propiedades del objeto.
        No se pueden asignar valores negativos a hp y attack.
        Máximo 200 hp y 20 attack
    */
}

void Jugador::atacar(Jugador &objetivo/* Agregar parámetros para atacar a otro Jugador */){

    int x=rand()%5;
    if(x!=0){
        objetivo.hp=objetivo.hp-this->ataque;
        cout<<this->nombre<<" ataco a "<<objetivo.nombre<<" he hizo "<<this->ataque<<" de danio, la vida restante de "<<objetivo.nombre<<"= "<<objetivo.hp<<endl;
        objetivo.uAtacante=this->nombre;
    }else{
        cout<<this->nombre<<" ataco a "<<objetivo.nombre<<" pero fallo, la vida restante de "<<objetivo.nombre<<"= "<<objetivo.hp<<endl;
        objetivo.uAtacante=this->nombre;
    }

    /*
        El jugador atacado(el que recibes como parámetro) pierde HP igual al ataque del jugador que ataca.
        Existe un 20% de probabilidad de que el ataque falle y no haga daño.
        Se debe mostrar lo que pasó en cada ataque:
        nombre1 atacó a nombre2 e hizo 5 de daño, vida restante de nombre2 = 95
        nombre2 atacó a nombre1 pero fallo, vida restante de nombre1 = 100
        El jugador que atacó debe quedar guardar en la propiedad atacadoPor del jugador atacado.
    */
    /*
    Nota:
        int x = rand() % 1000; asigna un valor aleatorio entre 0 y 999 a x;
        Puedes usar esto para la probabilidad del ataque.
    */
}
