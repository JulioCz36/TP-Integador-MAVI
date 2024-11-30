#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Objeto.h"

class Rectangulo : public Objeto {
public:
	Rectangulo(Vector2f pos, float escala, int rotacion, Color col);
	void dibujar(RenderWindow& w) override;
	FloatRect verGlobalBounds() override;
	void Actulizar(Color col)override {
		rectangulo.setFillColor(col);
	};
private:
	RectangleShape rectangulo;
};

#endif