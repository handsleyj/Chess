#include "..\include\Renderer.h"

Renderer::Renderer(unsigned int windowSize)
    : window(sf::VideoMode({windowSize, windowSize}), "Chess"),
      bgColour(78, 135, 83),
      lightSquareColour(200, 200, 200),
      darkSquareColour(20, 20, 20)
{
    /* Load SQUARES .pngs ------------------------------------------------ */
    if (!whiteSquareTexture.loadFromFile("assets/white/square.png")) {
        throw std::runtime_error("Failed to load assets/white/square.png");
    }

    if(!blackSquareTexture.loadFromFile("assets/black/square.png")) {
        throw std::runtime_error("Failed to load assets/black/sqaure.png");
    }

    /* Load PAWNS .pngs ------------------------------------------------ */
    if (!whitePawnTexture.loadFromFile("assets/white/pawn.png")) {
        throw std::runtime_error("Failed to load assets/white/pawn.png");
    }

    if (!blackPawnTexture.loadFromFile("assets/black/pawn.png")) {
        throw std::runtime_error("Failed to load assets/black/pawn.png");
    }

    /* Load ROOKS .pngs ------------------------------------------------ */
    if (!whiteRookTexture.loadFromFile("assets/white/rook.png")) {
        throw std::runtime_error("Failed to load assets/white/rook.png");
    }

    if (!blackRookTexture.loadFromFile("assets/black/rook.png")) {
        throw std::runtime_error("Failed to load assets/black/rook.png");
    }

    /* Load KNIGHTS .pngs ------------------------------------------------ */
    if (!whiteKnightTexture.loadFromFile("assets/white/knight.png")) {
        throw std::runtime_error("Failed to load assets/white/knight.png");
    }

    if (!blackKnightTexture.loadFromFile("assets/black/knight.png")) {
        throw std::runtime_error("Failed to load assets/black/knight.png");
    }
}

void Renderer::run(Board &board) {
    this->window.setVerticalSyncEnabled(true);

    while (this->window.isOpen()) {
        while (const std::optional event = this->window.pollEvent()) {
            /* If the window is closed, exit the program */
            if (event->is<sf::Event::Closed>()) {
                this->window.close();
            }

            /* If the window is resized, reposition visual elements */
            if (event->is<sf::Event::Resized>()) {
                const auto &resized = event->getIf<sf::Event::Resized>();
                sf::View view {
                    sf::FloatRect(
                        {0.0f, 0.0f},
                        {
                            static_cast<float>(resized->size.x),
                            static_cast<float>(resized->size.y)
                        }
                    )
                };

                this->window.setView(view);
            }
        }

        this->window.clear(this->bgColour);
        this->drawBoard();
        this->drawPieces(board);
        this->window.display();
    }
} 

void Renderer::drawBoard() {
    sf::RectangleShape square;
    square.setSize({SQUARE_SIZE, SQUARE_SIZE});

    for (int row = 0; row < BOARD_DIMENSION; row++) {
        for (int col = 0; col < BOARD_DIMENSION; col++) {
            sf::Texture texture;
            if ((row + col) % 2 == 0) {
                square.setTexture(&this->whiteSquareTexture);
            }
            else {
                square.setTexture(&this->blackSquareTexture);
            }

            square.setPosition(this->boardToScreen(row, col));

            this->window.draw(square);
        }
    }
}

void Renderer::drawPieces(Board &board) {
    for (int row = 0; row < BOARD_DIMENSION; row++) {
        for (int col = 0; col < BOARD_DIMENSION; col++) {
            Piece *pieceToDraw = board.getPieceFromCoordinate({row, col});

            if (pieceToDraw == nullptr) {
                continue;
            }

            switch (pieceToDraw->getType()) {
                case PieceType::PAWN: {
                    sf::Sprite pawn(
                        (pieceToDraw->getColour() == PieceColour::WHITE) ? this->whitePawnTexture : this->blackPawnTexture
                    );
                    pawn.setPosition(this->boardToScreen(row, col));
                    this->window.draw(pawn);
                    break;
                }
                case PieceType::ROOK: {
                    sf::Sprite rook(
                        (pieceToDraw->getColour() == PieceColour::WHITE) ? this->whiteRookTexture : this->blackRookTexture
                    );
                    rook.setPosition(this->boardToScreen(row, col));
                    this->window.draw(rook);
                    break;
                }
                case PieceType::KNIGHT: {
                    sf::Sprite knight(
                        (pieceToDraw->getColour() == PieceColour::WHITE) ? this->whiteKnightTexture : this->blackKnightTexture
                    );
                    knight.setPosition(this->boardToScreen(row, col));
                    this->window.draw(knight);
                    break;
                }
                default:
                    break;
            }
        }
    }
}

sf::Vector2f Renderer::boardToScreen(int row, int col) const {
    float xPadding = (this->window.getSize().x - (BOARD_DIMENSION * SQUARE_SIZE)) / 2.0f;
    float yPadding = (this->window.getSize().y - (BOARD_DIMENSION * SQUARE_SIZE)) / 2.0f;
    
    return {
        xPadding + (col * SQUARE_SIZE),
        yPadding + (row * SQUARE_SIZE)
    };
}