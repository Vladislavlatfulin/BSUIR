
#ifndef Plant_hpp
#define Plant_hpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Plant {
private:
    std::string title;
    int lifespan;
    float plantHeight;
public:
    Plant(std::string, float, int);
    Plant();
    Plant (const Plant &value);
    void SetTitle(std::string);
    void SetLifeSpan(int);
    void SetPlantHeight(float);
    std::string GetTitle();
    int GetLifeSpan();
    float GetPlantHeight();
    void Display();
    
    void ReadText(std::string);
    void WriteText(std::string);
    
    Plant& operator= (Plant &value);
    
    static void RemoveInText(std::string);
    static void RemoveInBin(std::string);

    
    static Plant ReadBin(std::string);
    void WriteBin(std::string);
        
    static Plant SearchInBin(std::string);
    static Plant SearchInText(std::string);
    
    static void CreateFile(std::string);
    
    static void PrintAllBinFile(std::string);
    static void PrintAllTextFile(std::string);
    
    static void ChangeInTextFile(std::string);
    static void ChangeInBinFile(std::string);
    
    friend std::ostream& operator<< (std::ostream &out, const Plant &);
    friend std::istream& operator>> (std::istream &in, Plant &);
};

#endif
