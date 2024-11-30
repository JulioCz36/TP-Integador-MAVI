#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <utility>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Personaje {
protected:
    Texture texture;
    Sprite sprite;
    Vector2f posicion;
    bool esEnemigo;
    bool activo;
    Clock relojVida;
    float duracion;


public:
    Personaje(Vector2f pos, bool esEnemigo);

    void actualizar();
    void dibujar(RenderWindow& ventana);
    bool estaActivo();
    bool esEnemigoFunc() ;
    void eliminar();

    Vector2f getPosicion() const;
    const Sprite& getSprite() const;
    pair<float, float> getTamanio();
};

#endif
