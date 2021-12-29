#ifndef Memorial_hpp
#define Memorial_hpp

#include "author.h"
#include "Description.h"
#include "Coordinate.h"
#include "Material.h"
#include "Architectural Object.h"
#include "Library.hpp"
//#include "/Users/vladislavlatfulin/Desktop/GitHub/KPIYAP/Library/Library/Library.hpp"

namespace memorial {
class Memorial: public ArchitecturalObject {
private:
    std::string whomIsTheMemorial;
    std::string inHonorOfWhat;
    
public:
    
    ArchitecturalObject *archObj;
    Material *matObj;
    Coordinate *coorObg;
    Description *desObg;
    Author *authorObg;
    Memorial(){};
    Memorial(Memorial &temp);
    Memorial(Material *matObg, Coordinate *coorObj, Author *authorObj);
    Memorial(Material *matObg, Coordinate *coorObj, Author *authorObj, float height, float square, std::string whomIsTheMemorial, std::string inHonorOfWhat);
    ~Memorial();
    void SetWhomIsTheMemorial(std::string whomIsTheMemorial);
    void SetInHonorOfWhat(std::string inHonorOfWhat);
    std::string GetWhomIsTheMemorial();
    std::string GetInHonorOfWhat();
    void Display();
   
    void SetInformation(Material *matObg, Coordinate *coorObj, Author *authorObj, float height, float square, std::string whomIsTheMemorial, std::string inHonorOfWhat);
    Memorial& operator =(Memorial &temp);
    string GetAuthorName() { return authorObg->GetName(); }
    string GetSurname() { return authorObg->GetSurname(); }
};
}

#endif
