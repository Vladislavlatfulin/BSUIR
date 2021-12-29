#include "Plant.hpp"

void Plant:: SetTitle(std::string title) {
    this->title = title;
}

Plant:: Plant(const Plant &value) {
    this -> title = value.title;
    this -> plantHeight = value.plantHeight;
    this -> lifespan = value.lifespan;
}

void Plant:: SetLifeSpan(int lifespan) {
    this->lifespan = lifespan;
}

void Plant:: SetPlantHeight(float plantHeight) {
    this->plantHeight = plantHeight;
}

std::string Plant:: GetTitle() {
    return title;
}

int Plant:: GetLifeSpan() {
    return lifespan;
}

float Plant:: GetPlantHeight() {
    return plantHeight;
}

Plant:: Plant(std::string title, float plantHeight, int lifeSpan) {
    SetTitle(title);
    SetPlantHeight(plantHeight);
    SetLifeSpan(lifeSpan);
}

void Plant:: Display() {
    std::cout << title << "   " << plantHeight << "   " << lifespan;
}

Plant::Plant () {
    SetTitle("");
    SetPlantHeight(0.0);
    SetLifeSpan(0);
}

std::ostream& operator<< (std::ostream &out, const Plant &plant)
{
    out << plant.title << " " << plant.plantHeight << " " << plant.lifespan;
    
    return out;
}

std::istream& operator>> (std::istream &in, Plant &plant)
{
    in >> plant.title;
    in >> plant.plantHeight;
    in >> plant.lifespan;
    
    return in;
}

void Plant:: ReadText(std::string fileName) {
    fstream ifs;
    
    
    try {
        cout << "block try in function ReadText" << endl;
        ifs.open(fileName, ios::in | ios::out);
        ifs >> (*this);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch in function ReadText" << endl;
        return;
    }
    ifs.close();
}

Plant& Plant:: operator=(Plant& value) {
    this -> title = value.title;
    this -> plantHeight = value.plantHeight;
    this -> lifespan = value.lifespan;
    
    return *this;
}


void Plant:: WriteText(std::string fileName) {
    fstream ofs;
    
    try {
        cout << "block try in function WriteText" << endl;
        ofs.open(fileName, ios::out|ios::in);
        ofs << (*this);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch in function WriteText" << endl;
        return;
    }
    ofs.close();
}



Plant Plant:: ReadBin(std::string fileName) {
    ifstream ifs;
    Plant temp;
    try {
        cout << "block try in function ReadBin" << endl;
        ifs.open(fileName, ios::binary);
        ifs.read((char*)&temp, sizeof(Plant));
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch function ReadBin" << endl;
        return temp;
    }
    ifs.close();
    return temp;
}

void Plant:: WriteBin(std::string fileName) {
    ofstream ofs;
    try {
        cout << "block try in function WriteBin" << endl;
        ofs.open(fileName, ios::binary);
        ofs.write((char*)this, sizeof(Plant));
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch function WriteBin" << endl;
        return;
    }
    ofs.close();
}

Plant Plant:: SearchInBin(std::string fileName) {
    Plant test;
    string world;
    cout << endl << "Enter a world pattern: ";
    cin >> world;
    ifstream ifl;
    bool isFound = false;
    try {
        cout << "block try in function SearchInBin" << endl;
        ifl.open(fileName, ios::binary);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch function SearchInBin" << endl;
        return test;
    }
    
    while (ifl.read((char*)&test, sizeof(Plant))) {
        if (test.title == world) { isFound = true;  break; }
    }
    Plant temp;
    if (!isFound) { return temp;}
    ifl.close();
    return test;
}

Plant Plant:: SearchInText(std::string fileName) {
    
    Plant test;
    string world;
    cout << endl << "Enter a world pattern: ";
    cin >> world;
    ifstream ifl;
    bool isFound = false;
    try {
        cout << "block try in function SearchInText" << endl;
        ifl.open(fileName);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch function SearchInText" << endl;
        return test;
    }
    
    while (ifl >> test) {
        if (test.title == world) { isFound = true; break; }
    }
    Plant temp;
    if (!isFound) {return temp;}
    ifl.close();
    return test;
}

void Plant:: RemoveInText(std::string fileName) {
    Plant temp[5];
    string world;
    int i = 0, j = 0;
    bool flag = false;
    cout << endl << "Enter the name for deleting: ";
    cin >> world;
    ifstream in;
    try {
        cout << "block try in function RemoveInText" << endl;
        in.open(fileName);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch function RemoveInText" << endl;
        return;
    }
    
    while (in >> temp[i]) i++;
    in.close();
    ofstream out;
    try {
        cout << "block try in function RemoveInText" << endl;
        out.open(fileName, ios::out | ios::trunc);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch function RemoveInText" << endl;
        return;
    }
    
    while (j<i) {
        if (world != temp[j].GetTitle()) {
            out << temp[j] << endl;
            flag = true;
        }
        else { cout << temp[j]; }
        j++;
    }
    if (!flag) { cout << "\n\nNot found for delete!"; }
    out.close();
   
}

void Plant:: RemoveInBin(std::string fileName) {
    Plant temp[5];
    string world;
    int i = 0, j = 0;
    bool flag = false;
    cout << endl << "Enter the name for deleting: ";
    cin >> world;
    ifstream in;
    try {
        cout << "block try in function RemoveInBin" << endl;
        in.open(fileName, ios::binary);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch function RemoveInBin" << endl;
        return;
    }
    
    while (in.read((char*)&(temp[i]), sizeof(Plant))) i++;
    in.close();
    ofstream out;
    
    try {
        cout << "block try in function RemoveInBin" << endl;
        out.open(fileName, ios::out | ios::trunc | ios::binary);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch function RemoveInBin" << endl;
        return;
    }
    
    while (j<i) {
        if (world != temp[j].GetTitle()) {
            out.write((char*)&(temp[j]), sizeof(Plant));
            flag = true;
        }
        else { cout << temp[j]; }
        j++;
    }
    if (!flag) { cout << "\n\nNot found for delete!"; }
    out.close();
    
}

void Plant:: PrintAllBinFile(std::string fileName) {
    Plant temp[5];
    int i = 0;
    ifstream in;
    try {
        cout << "block try in function PrintAllBinFile" << endl;
        in.open(fileName, ios::binary);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch function RemoveInBin" << endl;
        return;
    }
    while (in.read((char*)&(temp[i]), sizeof(Plant))) i++;
    in.close();
    cout << endl;
    for (int j = 0; j < i; j++) {
        cout << temp[j].title << "   ";
        cout << fixed << setprecision(5) << temp[j].plantHeight << "   ";
        cout.setf(ios::showpos);
        cout << temp[j].lifespan << endl;
    }
}


void Plant:: PrintAllTextFile(std::string fileName) {
    Plant temp[5];
    int i = 0;
    ifstream in;
    try {
        cout << "block try in function PrintAllBinFile" << endl;
        in.open(fileName);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
        cout << "work completed in block catch function RemoveInBin" << endl;
        return;
    }
    while (in >> temp[i]) i++;
    in.close();
    cout << endl;
    for (int j = 0; j < i; j++) {
        cout << temp[j].title << "   ";
        cout << fixed << setprecision(5) << temp[j].plantHeight << "   ";
        cout.setf(ios::showpos);
        cout << temp[j].lifespan << endl;
    }
}



void Plant:: CreateFile(std::string fileName) {
    int choice;
    cout << "What type of file do you want to create?" << endl;
    cout << "1 - Text." << endl;
    cout << "2 - Binary." << endl;
    cin >> choice;
    Plant firstEx("moss", 567.55, 902);
    Plant secondEx("oak", 123.55, 101);
    Plant thirdEx("willow", 999.223, 987);

    ofstream file;
    switch (choice) {
        case 1:
            try {
                file.open(fileName + ".txt");
                file << firstEx << '\n';
                file << secondEx << '\n';
                file << thirdEx << '\n';
                file.close();
                cout << "Your file: " << endl;
                Plant::PrintAllTextFile(fileName + ".txt");
                
            } catch (const exception &ex) {
                cout << ex.what() << endl;
                cout << "work completed in block catch function CreateFile" << endl;
                return;
            }
            
            break;
            
        case 2:
            try {
                file.open(fileName + ".bin");
                file.write((char*)&firstEx, sizeof(Plant));
                file.write((char*)&secondEx, sizeof(Plant));
                file.write((char*)&thirdEx, sizeof(Plant));
                file.close();
                cout << "Your file: " << endl;
                Plant::PrintAllBinFile(fileName + ".bin");
            } catch (const exception &ex) {
                cout << ex.what() << endl;
                cout << "work completed in block catch function CreateFile" << endl;
            }
            
            break;
            
        default:
            break;
    }
}



void Plant:: ChangeInTextFile(string fileName) {
    int choice;
    Plant temp[3];
    int i = 0;
    ifstream in;
    in.open(fileName);
    while (in >> temp[i]) { i++; }
    
    cout << endl << endl << "Change function work - " << fileName << endl;
    for (int i = 0; i < 3; i++) {
        cout << temp[i] << " (" << i << " index)" << endl;
    }
    cout << endl << endl;
    cout << "Enter element index change element" << endl;
    cin >> choice;
    Plant userTemp;
    
    cout << "Enter element title: " << endl;
    std::string tempString;
    cin >> tempString;
    userTemp.SetTitle(tempString);
    
    cout << "Enter element plantHeight: " << endl;
    float tempPlantHeight;
    cin >> tempPlantHeight;
    userTemp.SetPlantHeight(tempPlantHeight);
    
    cout << "Enter element lifespan: " << endl;
    int tempLifespan;
    cin >> tempLifespan;
    userTemp.SetLifeSpan(tempLifespan);
    temp[choice] = userTemp;
    in.close();
    
    ofstream out;
    out.open(fileName);
    for (i = 0; i < 3; i++) {
        out << temp[i] << '\n';
    }
    out.close();
    cout << endl;
    Plant::PrintAllTextFile(fileName);
}

void Plant:: ChangeInBinFile(string fileName) {
    int choice;
    Plant temp[3];
    int i = 0;
    ifstream in;
    in.open(fileName, ios::binary);
    while (in.read((char*)&temp[i], sizeof(Plant))) { i++; }
    
    cout << endl << endl << "Change function work - " << fileName << endl;
    for (int i = 0; i < 3; i++) {
        cout << temp[i] << " (" << i << " index)" << endl;
    }
    
    cout << "Enter element index change element" << endl;
    cin >> choice;
    Plant userTemp;
    rewind(stdin);
    cout << "Enter element title: " << endl;
    std::string tempString;
    cin >> tempString;
    userTemp.SetTitle(tempString);
    
    cout << "Enter element plantHeight: " << endl;
    float tempPlantHeight;
    cin >> tempPlantHeight;
    userTemp.SetPlantHeight(tempPlantHeight);
    
    cout << "Enter element lifespan: " << endl;
    int tempLifespan;
    cin >> tempLifespan;
    userTemp.SetLifeSpan(tempLifespan);
    temp[choice] = userTemp;
    in.close();
    
    ofstream out;
    out.open(fileName, ios::binary);
    for (i = 0; i < 3; i++) {
        out.write((char*)&temp[i], sizeof(Plant));
    }
    out.close();
    cout << endl;
    Plant::PrintAllBinFile(fileName);
}
