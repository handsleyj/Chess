#include "..\include\Renderer.h"

Renderer::Renderer(unsigned int windowSize)
    : window(sf::VideoMode({windowSize, windowSize}), "Chess"),
      bgColour(78, 135, 83),
      lightSquareColour(200, 200, 200),
      darkSquareColour(20, 20, 20)
{
}

void Renderer::run(const Board &board) {
    this->window.setVerticalSyncEnabled(true);

    while (this->window.isOpen()) {
        while (const std::optional event = this->window.pollEvent()) {
            /* If the window is closed, exit the program */
            if (event->is<sf::Event::Closed>()) {
                this->window.close();
            }
        }

        this->window.clear(this->bgColour);
        this->drawBoard();
        this->window.display();
    }
} 

void Renderer::drawBoard() {
    sf::RectangleShape square;
    square.setSize({SQUARE_SIZE, SQUARE_SIZE});

    float xPadding = (this->window.getSize().x - (BOARD_DIMENSION * SQUARE_SIZE)) / 2.0f;
    float yPadding = (this->window.getSize().y - (BOARD_DIMENSION * SQUARE_SIZE)) / 2.0f;

    for (int row = 0; row < BOARD_DIMENSION; row++) {
        for (int col = 0; col < BOARD_DIMENSION; col++) {
            if ((row + col) % 2 == 0) {
                square.setFillColor(this->lightSquareColour);
            }
            else {
                square.setFillColor(this->darkSquareColour);
            }

            square.setPosition({
                xPadding + (col * SQUARE_SIZE),
                yPadding + (row * SQUARE_SIZE)
            });

            this->window.draw(square);
        }
    }
}