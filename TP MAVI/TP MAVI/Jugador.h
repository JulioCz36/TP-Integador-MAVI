#ifndef JUGADOR_H
#define JUGADOR_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;


class Jugador {
    Texture textura;
    Sprite sprite;
    Vector2f posicion;
    RenderWindow& ventana;
    int vidas;

public:
    Jugador(RenderWindow& v);

    void actualizar();
    void dibujar(RenderWindow& ventana);
    Vector2f getPosicion() const;
    const Sprite& getSprite() const;

    void restarVida();
    int getVidas();
};

#endif
