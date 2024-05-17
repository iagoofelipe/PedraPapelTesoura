#include <string>

#define PLAY_PEDRA 0
#define PLAY_PAPEL 1
#define PLAY_TESOURA 2

class Player {

public:
    Player(bool is_computer, std::string name);
    int requireNewPlay();
    std::string name;

private:
    bool is_computer;

};

class Game {

public:
    Game();
    ~Game();
    void startGame();
    bool askPlayAgain();
    int checkWinner(int play1, int play2); // verifica entre as duas jogadas qual é a vencedora, retorna 1 para a primeira, 2 para a segunda ou 0 para nenhum dos dois
    std::string getPlayName(int play);

private:
    Player *player1;
    Player *player2;
};