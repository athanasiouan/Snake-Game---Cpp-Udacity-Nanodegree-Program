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


using std::string;
using std::vector;

class DataManager {
public:
    DataManager();
    ~DataManager();
    std::map<string, int> ReadGameHistoryMap();
    void WriteGameHistoryMapSorted(std::map<string, int> aux_map);
    void WriteGameHistoryMap(std::map<string, int> players_map);
    void DisplaySortedPlayers(std::map<string, int> aux_map);
};