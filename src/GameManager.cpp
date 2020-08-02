#include <iostream>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <functional>
#include <set>
#include "GameManager.h"
#include "DataManager.h"
#include <bits/stdc++.h>

bool GameManager::quit_game_flag = false;

bool GameManager::InitManager() {
    std::cout << " --- SNAKE GAME ---" << std::endl;
    std::cout << "   " << std::endl;
    std::cout << " 1. Start New Game" << std::endl;
    std::cout << " 2. Top Scores" << std::endl;
    std::cout << " 3. Quit Game" << std::endl;
    std::cout << "Please choose between 1-3: ";

    int key_pressed;

    while (!(std::cin >> key_pressed)) {

        std::cin.clear();

        while (std::cin.get() != '\n')
            continue;

        std::cout << "FAILED. You must put a number(1-3). Please enter correct number: ";
    }
    if ((key_pressed < 1) || (key_pressed > 3)) {
        std::cout << "You pressed : " << key_pressed << std::endl;
        std::cout << "FAILED. Please enter correct number!"
                  << "\n\n";
        return false;
    }

    switch (key_pressed)
    {

    case 1:
    {
        return true;
    };
    break;

    case 2:
    {
        DataManager dm;
        std::map<string, int> recorded_players;
        recorded_players = dm.ReadGameHistoryMap();
        if (recorded_players.size() > 0) {
            dm.DisplaySortedPlayers(recorded_players);
        }
        else {
            std::cout << "There is no recent history for these game!" << std::endl;
        }
        return false;
    };
    break;
    case 3:
    {
        std::cout << "Quiting the game ... Thanks" << std::endl;
        quit_game_flag = true;
    };

        return false;
    }
}

void GameManager::ManageNewPlayer(Player *p) {
    p->SetPlayerName();
}

void GameManager::DumpDataToFile(Player *p) {
    std::cout << "Call the function " << __FUNCTION__ << std::endl;
    std::cout << "Player:  " << p->GetPlayerName() << " :: " << p->GetPlayerScore() << " : " << p->GetPlayerGameTime() << std::endl;
}

void GameManager::temp_print_vector_of_object_pointers(vector<Player *> v_player) {
    int v_player_size = v_player.size();
    for (int i = 0; i < v_player_size; i++) {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Player vector::  " << v_player[i]->GetPlayerName() << std::endl;
    }
}