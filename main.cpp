#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include "Collection.h"

using json = nlohmann::json;

int main() {
/*
    {
        json movies = json::array();
        std::ifstream in("movie_titles.txt");
        std::string s;
        if (in.is_open()) {
            int number, tmp;

            std::getline(in, s);
            number = std::stoi(s);
            json j;
            for (int i = 0; i < number; i++) {
                std::getline(in, s);
                j["name"] = s;

                std::getline(in, s);
                tmp = std::stoi(s);
                j["year"] = tmp;

                std::getline(in, s);
                j["type"] = s;

                std::getline(in, s);
                j["genre"] = s;

                movies.push_back(j);
            }
        }
        std::ofstream out("my.json");
        out<<std::setw(4)<< movies << std::endl;
    }*/
    std::string fileName = "my.json";

    Collection myCol;
    myCol.createContent(fileName);
    myCol.print();

//    std::cout<<std::setw(4)<< my << std::endl;

    return 0;
}
