#include "Jugador.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Jugador::Jugador(RenderWindow& v):ventana(v){
    textura.loadFromFile("assets/crosshair.png");
    sprite.setTexture(textura);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    vidas = 3;
    ventana.setMouseCursorVisible(false);
}

void Jugador::actualizar() {

    Vector2i posicionMouse = sf::Mouse::getPosition(ventana);
    sprite.setPosition(static_cast<float>(posicionMouse.x), static_cast<float>(posicionMouse.y));

}

void Jugador::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(sprite);
}

Vector2f Jugador::getPosicion() const {
    return sprite.getPosition();
}

const Sprite& Jugador::getSprite() const {
    return sprite;
}

void Jugador::restarVida() {
    if (vidas > 0) {
        vidas--;
    }
}

int Jugador::getVidas() {
    return vidas;
}
