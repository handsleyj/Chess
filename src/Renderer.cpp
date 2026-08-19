#include "..\include\Renderer.h"

void Renderer::run() {
    /* Create new window (800x800 pixels) with title 'Chess'*/
    sf::RenderWindow window(
        sf::VideoMode({800, 800}),
        "Chess"
    );

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            /* If the window is closed, exit the program */
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
} 


void Renderer::drawBoard(const Board &board) {
    return;
}