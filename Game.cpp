#include <cstdlib>
#include <iostream>
#include <string>
#include "Game.h"

Game::Game() {
    player1 = new Player(true, "Computador");
    player2 = new Player(false, "Jogador1");
}

Game::~Game() {
    delete player1;
    delete player2;
}

void Game::startGame() {
    int play, play_player1, play_player2;
    Player *first_player, *second_player;

    std::cout
        << "------------------------------------\n"
        << "Iniciando Jogo\n\n"
        << "Digite seu nome: "
    ;

    // armazenando nome do jogador
    std::getline(std::cin, player2->name);

    do {
        play_player1 = player1->requireNewPlay();
        play_player2 = player2->requireNewPlay();

        std::cout 
            << player1->name << " vs " << player2->name << std::endl
            << "\nJogada " << player1->name << ": " << getPlayName(play_player1) << std::endl
            << "Jogada " << player2->name << ": " << getPlayName(play_player2) << std::endl
            << std::endl
        ;

        switch(checkWinner(play_player1, play_player2))
        {
        case 1:
            std::cout << "Jogador " << player1->name << " eh o vencedor!\n";
            break;
        
        case 2:
            std::cout << "Jogador " << player2->name << " eh o vencedor!\n";
            break;
        
        case 0:
            std::cout << "Empate!\n";
            break;
        }

    } while(askPlayAgain());

    std::cout << "------------------------------------\n";
}

bool Game::askPlayAgain() {
    char play_again;
    std::cout << "\nDeseja jogar novamente (S|N)? ";
    std::cin >> play_again;

    return play_again == 'S' || play_again == 's';
}

int Game::checkWinner(int play1, int play2) {
    if((play1 == PLAY_PEDRA && play2 == PLAY_TESOURA) || (play1 == PLAY_PAPEL && play2 == PLAY_PEDRA) || (play1 == PLAY_TESOURA && play2 == PLAY_PAPEL)) {
        return 1;
    }

    if((play2 == PLAY_PEDRA && play1 == PLAY_TESOURA) || (play2 == PLAY_PAPEL && play1 == PLAY_PEDRA) || (play2 == PLAY_TESOURA && play1 == PLAY_PAPEL)) {
        return 2;
    }

    return 0;
}

std::string Game::getPlayName(int play) {
    switch (play)
    {
    case PLAY_PAPEL:
        return "papel";
    
    case PLAY_TESOURA:
        return "tesoura";
    
    case PLAY_PEDRA:
        return "pedra";
    
    default:
        return "INVALIDA";
    }
}

Player::Player(bool is_computer, std::string name): is_computer(is_computer), name(name) {}

int Player::requireNewPlay() {
    int play;

    if(is_computer) {
        play = rand() % 3;
    } else {
        std::string op;

        std::cout << "Digite sua jogada [pedra, papel, tesoura]: ";
        std::cin >> op;

        if(op == "pedra") {
            play = PLAY_PEDRA;
        } else if(op == "papel") {
            play = PLAY_PAPEL;
        } else if(op == "tesoura") {
            play = PLAY_TESOURA;
        } else {
            std::cout << "opcao invalida!" << std::endl;
            return -1;
        }
    }

    return play;
}
