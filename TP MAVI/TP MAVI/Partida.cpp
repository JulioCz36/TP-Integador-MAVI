#include "Partida.h"
#include <numeric>
#include "Menu.h"
#include "Personaje.h"
#include "Resultado.h"
#include <random>
#include <iostream>
using namespace std;

Partida::Partida(RenderWindow& w)
	:jugador(w),puntos(0), enemigosMatados(0), inocentesMatados(0),ventana(w) {

	pt.loadFromFile("assets/fondoPartida.png");
	ps.setTexture(pt);
	fuente.loadFromFile("assets/Starborn.ttf");

	textoPuntos.setFont(fuente);
	textoPuntos.setCharacterSize(24);
	textoPuntos.setFillColor(sf::Color::White);
	textoPuntos.setPosition(10, 10);  

	textoVidas.setFont(fuente);
	textoVidas.setCharacterSize(24);
	textoVidas.setFillColor(sf::Color::White);
	textoVidas.setPosition(10, 40);  

	textoEnemigos.setFont(fuente);
	textoEnemigos.setCharacterSize(24);
	textoEnemigos.setFillColor(sf::Color::White);
	textoEnemigos.setPosition(10, 70); 
}


Partida::~Partida() {
}

void Partida::comprobarColisiones() {
	if (personaje != nullptr) {
		if (personaje->getSprite().getGlobalBounds().contains(jugador.getPosicion())) {
			if (personaje->esEnemigoFunc()) {
				enemigosMatados++;
				puntos++;
			}
			else {
				inocentesMatados++;
				puntos--;
				jugador.restarVida();
			}
			delete personaje;
			personaje = nullptr; 
		}
	}
}


//metodo hecho por chtGPT
void Partida::generarPersonaje() {
	float ancho = 700;
	float alto = 500;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distTipo(0, 1);
	bool esEnemigo = distTipo(gen) == 1;

	Personaje temp(Vector2f(0, 0), esEnemigo);
	auto tamanio = temp.getTamanio();
	float anchoSprite = tamanio.first;
	float altoSprite = tamanio.second;

	uniform_real_distribution<> distX(anchoSprite / 2, ancho - anchoSprite / 2);
	uniform_real_distribution<> distY(altoSprite / 2, alto - altoSprite / 2);

	Vector2f posicionAleatoria(distX(gen), distY(gen));

	personaje = new Personaje(posicionAleatoria, esEnemigo);
}



void Partida::actualizar(Juego& j) {
	if (jugador.getVidas() == 0) {
		j.CambiarScena(new Resultado(ventana, false, enemigosMatados, inocentesMatados));
	}
	if (jugador.getVidas() > 0 && enemigosMatados == 10) {
		j.CambiarScena(new Resultado(ventana, true, enemigosMatados, inocentesMatados));
	}

	jugador.actualizar();

	textoPuntos.setString("Puntos: " + to_string(puntos));
	textoVidas.setString("Vidas: " + to_string(jugador.getVidas()));
	textoEnemigos.setString("Enemigos Matados: " + to_string(enemigosMatados));

	if (personaje != nullptr) {
		personaje->actualizar();
		if (personaje->esEnemigoFunc() && relojGeneracion.getElapsedTime().asSeconds() > 1.3f) {
			jugador.restarVida();
			delete personaje; 
			personaje = nullptr; 
		}
	}

	if (personaje == nullptr || relojGeneracion.getElapsedTime().asSeconds() > 1.3f) {
		generarPersonaje(); 
		relojGeneracion.restart();
	}

	if (Mouse::isButtonPressed(Mouse::Left)) {
		comprobarColisiones(); 
	}
}


void Partida::dibujar(RenderWindow& w) {
	w.clear();
	w.draw(ps);
	if (personaje != nullptr) {
		personaje->dibujar(w);
	}
	w.draw(textoPuntos);
	w.draw(textoVidas);
	w.draw(textoEnemigos);

	jugador.dibujar(w);

}

void Partida::ProcesoEventos(Juego& j, Event& event) {
}

