#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <set>
#include <dirent.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include "DataManager.h"

using std::string;
using std::vector;


DataManager::DataManager(){};
DataManager::~DataManager(){};
std::map<string, int> DataManager::ReadGameHistoryMap()
{

  string line;
  string player_name;
  int player_score;
  std::map<string, int> players_map;
  std::map<string, int>::iterator it;
  const std::string gameDataDirectory{"../data"};

  std::ifstream filestream(gameDataDirectory + "/" + "game_statistics.txt");

  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {

      std::istringstream linestream(line);
      while (linestream >> player_name >> player_score)
      {

        players_map.insert(std::make_pair(player_name, player_score));
      }
    }
    filestream.close();
    return players_map;
  }
  else
  {
    std::ofstream outfile("game_Statistics.txt");
    std::cout << "game_statistics.txt does not exist. New is created." << std::endl;
  }
}


void DataManager::WriteGameHistoryMapSorted(std::map<string, int> aux_map)
{

  std::ofstream dataFile;

  dataFile.open("game_statistics.txt", std::ios::in | std::ios::out | std::ios::app);
  if (!dataFile.is_open())
  {
    std::cout << " can't open file" << std::endl;
  }
  else
  {
    std::map<string, int> sorted_aux_map;

    typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;

    Comparator compFunctor =
        [](std::pair<std::string, int> elem1, std::pair<std::string, int> elem2) {
          return elem1.second > elem2.second;
        };
    std::set<std::pair<std::string, int>, Comparator> sorted_map(
        aux_map.begin(), aux_map.end(), compFunctor);

    int ii = 1;
    for (std::pair<std::string, int> element : sorted_map)
    {
      dataFile << ii << ". player : " << element.first << ", score : " << element.second << "\n";
      ii++;
    }

    dataFile.close();
  }
}


void DataManager::WriteGameHistoryMap(std::map<string, int> players_map)
{

  std::map<string, int>::iterator it;

  std::ofstream dataFile;

  dataFile.open("game_statistics.txt", std::ios::in | std::ios::out | std::ios::app);
  if (!dataFile.is_open())
  {
    std::cout << " can't open file" << std::endl;
  }
  else
  {

    for (it = players_map.begin(); it != players_map.end(); it++)
    {

      dataFile << (*it).first << " " << (*it).second << "\n";
    }

    dataFile.close();
  }
}


void DataManager::DisplaySortedPlayers(std::map<string, int> aux_map)
{

  std::cout << "called :: " << __FUNCTION__ << "   size  ::" << aux_map.size() << std::endl;
  std::map<string, int> sorted_aux_map;

  typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;

  Comparator compFunctor =
      [](std::pair<std::string, int> elem1, std::pair<std::string, int> elem2) {
        return elem1.second > elem2.second;
      };
  std::set<std::pair<std::string, int>, Comparator> sorted_map(
      aux_map.begin(), aux_map.end(), compFunctor);
  int ii = 1;
  for (std::pair<std::string, int> element : sorted_map)
  {
    std::cout << ii << ". player : " << element.first << ", score : " << element.second << std::endl;
    ii++;
    if (ii > 10)
      break;
  }
}

