#include "Rectangulo.h"
#include <SFML/Graphics/Rect.hpp>

Rectangulo::Rectangulo(Vector2f pos, float escala, int rotacion, Color col) {
	// Configurar el rectángulo
	rectangulo.setSize(Vector2f(90 * escala, 30 * escala));
	rectangulo.setPosition(pos);
	rectangulo.setRotation(rotacion);
	rectangulo.setFillColor(col);
}


FloatRect Rectangulo::verGlobalBounds() {
	return rectangulo.getGlobalBounds();
}

void Rectangulo::dibujar(RenderWindow& w) {
	w.draw(rectangulo);
}
