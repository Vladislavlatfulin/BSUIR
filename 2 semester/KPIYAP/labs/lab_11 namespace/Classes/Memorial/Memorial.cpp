#include "Memorial.h"

namespace memorial {
void Memorial:: Display() {
    cout << "Name and surname author: " << authorObg -> GetName() << " " << authorObg -> GetSurname() << endl;
    cout << "Opening Date memorial: " << desObg -> GetOpeningDate() << endl;
    cout << "expended Resources memorial: " << desObg -> GetExpendedResources() << endl;
    cout << "Coordinate(latitude/longitude) memorial: " << coorObg->GetLatitude() << "/" << coorObg->GetLongitude() << endl;
    cout << "Name of material memorial: " << matObj -> GetNameOfMaterial() << endl;
    cout << "Price material: " << matObj -> GetPrice() << endl;
    cout << "Memorial height/square: " << archObj -> GetHeight() << "/" << archObj->GetSquare() << endl;
    cout << "Whom Is The Memorial: " << whomIsTheMemorial << endl;
    cout << "In Honor Of What: " << inHonorOfWhat << endl;
}

void Memorial:: SetInHonorOfWhat(std::string inHonorOfWhat) {
    this -> inHonorOfWhat = inHonorOfWhat;
}

void Memorial:: SetWhomIsTheMemorial(std::string whomIsTheMemorial) {
    this -> whomIsTheMemorial = whomIsTheMemorial;
}

std::string Memorial:: GetInHonorOfWhat() {
    return inHonorOfWhat;
}

std::string Memorial:: GetWhomIsTheMemorial() {
    return whomIsTheMemorial;
}

Memorial:: Memorial (Material *matObg, Coordinate *coorObj, Author *authorObj): ArchitecturalObject() {
    
    this->matObj = matObg;
    this->coorObg = coorObj;
    this->authorObg = authorObj;
    
    this -> desObg = new Description("23.10.2002", 650);
    this -> archObj = new ArchitecturalObject(20, 500);

    
    SetInHonorOfWhat(" ");
    SetWhomIsTheMemorial(" ");
}

Memorial:: Memorial(Material *matObg, Coordinate *coorObj, Author *authorObj, float height, float square, std::string whomIsTheMemorial, std::string inHonorOfWhat): ArchitecturalObject(height, square) {
    
    this->matObj = matObg;
    this->coorObg = coorObj;
    this->authorObg = authorObj;
    
    this -> archObj = new ArchitecturalObject(height, square);
    this -> desObg = new Description("23.10.2002", 650);
    SetInHonorOfWhat(inHonorOfWhat);
    SetWhomIsTheMemorial(whomIsTheMemorial);
}

Memorial:: ~Memorial() {
    delete archObj;
    delete desObg;
}

Memorial::Memorial(Memorial &temp) {
    // выделение памяти
    matObj = new Material();
    this -> matObj -> SetPrice(temp.matObj ->GetPrice());
    this -> matObj -> SetNameOfMaterial(temp.matObj -> GetNameOfMaterial());
    coorObg = new Coordinate();
    this->coorObg -> SetLatitude(temp.coorObg->GetLatitude());
    this->coorObg -> SetLongitude(temp.coorObg->GetLongitude());
    authorObg = new Author();
    this->authorObg->SetName(temp.authorObg->GetName());
    this->authorObg->SetSurName(temp.authorObg->GetSurname());
    archObj = new ArchitecturalObject();
    this->archObj->SetHeight(temp.archObj->GetHeight());
    this->archObj->SetSquare(temp.archObj->GetSquare());
    desObg = new Description();
    this->desObg->SetOpeningDate(temp.desObg->GetOpeningDate());
    this->desObg->SetExpendedResources(temp.desObg->GetExpendedResources());
    SetInHonorOfWhat(temp.GetInHonorOfWhat());
    SetWhomIsTheMemorial(temp.GetWhomIsTheMemorial());
}

void Memorial:: SetInformation(Material *matObg, Coordinate *coorObj, Author *authorObj, float height, float square, std::string whomIsTheMemorial, std::string inHonorOfWhat) {
    this -> SetSquare(square);
    this -> SetHeight(height);
    
    this->matObj = matObg;
    this->coorObg = coorObj;
    this->authorObg = authorObj;
    
    
    this -> archObj = new ArchitecturalObject(height, square);
    std::string temp;
    std::cout << "Enter a opening data" << std::endl;
    std::cin >> temp;
    
    std::cout << "Enter a expended Resources" << std::endl;
    this -> desObg = new Description(temp, enteringANumber());
    SetInHonorOfWhat(inHonorOfWhat);
    SetWhomIsTheMemorial(whomIsTheMemorial);
    
}


Memorial& Memorial:: operator=(Memorial &temp) {
    this -> matObj -> SetPrice(temp.matObj ->GetPrice());
    this -> matObj -> SetNameOfMaterial(temp.matObj -> GetNameOfMaterial());
    this->coorObg -> SetLatitude(temp.coorObg->GetLatitude());
    this->coorObg -> SetLongitude(temp.coorObg->GetLongitude());
    this->authorObg->SetName(temp.authorObg->GetName());
    this->authorObg->SetSurName(temp.authorObg->GetSurname());
    this->archObj->SetHeight(temp.archObj->GetHeight());
    this->archObj->SetSquare(temp.archObj->GetSquare());
    this->desObg->SetOpeningDate(temp.desObg->GetOpeningDate());
    this->desObg->SetExpendedResources(temp.desObg->GetExpendedResources());
    SetInHonorOfWhat(temp.GetInHonorOfWhat());
    SetWhomIsTheMemorial(temp.GetWhomIsTheMemorial());
    
    
//    delete matObj;
//    delete coorObg;
//    delete authorObg;
//    matObj = temp.matObj;
//    coorObg = temp.coorObg;
//    authorObg = temp.authorObg;
//    SetSquare(temp.GetSquare());
//    SetHeight(temp.GetHeight());
//
//    delete archObj;
//    delete desObg;
//    archObj = new ArchitecturalObject(temp.archObj -> GetHeight(), temp.archObj -> GetSquare());
//    desObg = new Description(temp.desObg -> GetOpeningDate(), temp.desObg -> GetExpendedResources());
//
//    SetInHonorOfWhat(temp.GetInHonorOfWhat());
//    SetWhomIsTheMemorial(temp.GetWhomIsTheMemorial());
    
    
    
    
    return *this;
}
}
