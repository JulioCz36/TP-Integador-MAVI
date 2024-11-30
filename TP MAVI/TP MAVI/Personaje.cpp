#include "Personaje.h"
#include <iostream>
#include <utility>
using namespace sf;
using namespace std;

Personaje::Personaje(Vector2f pos, bool esEnemigo)
    : posicion(pos), esEnemigo(esEnemigo), activo(true),duracion(3.0f) {
    if (esEnemigo) {
        texture.loadFromFile("assets/enemigo.png");
    }
    else {
        texture.loadFromFile("assets/inocente.png");
    }
    sprite.setTexture(texture);
    sprite.setPosition(posicion);
    sprite.setScale(0.2f, 0.2f);
}

void Personaje::dibujar(RenderWindow& ventana) {
    ventana.draw(sprite);
}
void Personaje::actualizar() {
    if (relojVida.getElapsedTime().asSeconds() > duracion) {
        activo = false;
    }
}

bool Personaje::esEnemigoFunc(){
    return esEnemigo;
}

bool Personaje::estaActivo() {
    return activo;
}

Vector2f Personaje::getPosicion() const {
    return posicion;
}

const Sprite& Personaje::getSprite() const {
    return sprite;
}

pair<float, float> Personaje::getTamanio() {
    FloatRect bounds = sprite.getGlobalBounds();

    return make_pair(bounds.width, bounds.height);
}

void Personaje::eliminar() {
    activo = false;
}

