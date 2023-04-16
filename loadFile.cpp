#include"loadFile.h"
#include<fstream>
#include<cstring>
// #include<sstream>
#include<iostream>


std::vector<int> tokenize(std::string line){
    std::vector<int> row;
    char * token = std::strtok(const_cast<char *>(line.c_str(), " "));
    while(token != nullptr){
        row.push_back(atoi(token[0]));
        token = std::strtok(nullptr, " ");
    }
    return row
}


void readFromFile(const char * fileName){
    std::ifstream file;
    file.open(fileName);
    std::string line;
    if(file.is_open()){
        while ((file))
        {    
            std::getline(file, line);
            // std::cout<<line<<"\n\n";
            std::vector<int> row = tokenize(line);
            for(auto it = row.begin(); it != row.end(); it++){
                std::cout<<*it<<"\t";
            }
            std::cout<<std::endl;
        }
    }
}