#include "Plant.hpp"

int main(int argc, const char * argv[]) {
    // oak 123.3 222
    // dandelion 222.3 666
    // seaweed 432.77 999
    // willow 564.123 101
    // moss 567.55 902
//    Plant qwe("moss", 567.55, 902);
//    ofstream out;
//    out.open("textBin.txt", ios::app | ios::binary);
//    out.write((char*)&qwe, sizeof(Plant));
//    out.close();
//
//    ofstream out1;
//    out1.open("binBin.bin", ios::app | ios::binary);
//    out1.write((char*)&qwe, sizeof(Plant));
//    out1.close();
//
//    ofstream out2;
//    out2.open("textText.txt", ios::app );
//    out2 << qwe << '\n';
//    out2.close();
    
    // файлов нет, выбор типа файла, редактирование

//    cout << "file binBin.bin" << endl;
//    Plant::PrintAllBinFile("binBin.bin");
//
//    cout << endl << "file textBin.txt" << endl;
//    Plant::PrintAllBinFile("textBin.txt");
//
//    cout << endl << "file textText.txt" << endl;
//    Plant::PrintAllTextFile("textText.txt");
//
//
//
//
//    cout << endl << endl << endl <<  "Read and Write text file" << endl;
//    Plant textEx("moss", 333.3, 777);
//    textEx.WriteText("textFile.txt");
//
//    Plant secondTextEx;
//    secondTextEx.ReadText("textFile.txt");
//    secondTextEx.Display();
//    cout << endl << endl <<"Read and Write binary file" << endl;
//
//    Plant binEx("seaweed", 111.5, 444);
//    binEx.WriteBin("BinFile.bin");
//
//    Plant secondBinEx(Plant::ReadBin("BinFile.bin"));
//    secondBinEx.Display();
//
//    cout << endl << endl << "Function search in textText.txt" << endl;
//    Plant searchTextText(Plant::SearchInText("textText.txt"));
//    searchTextText.Display();
//
//    cout << endl << endl << "Function search in textBin.txt" << endl;
//    Plant searchTextBin(Plant::SearchInBin("textBin.txt"));
//    searchTextBin.Display();
//
//    cout << endl << endl << "Function search in binBin.bin" << endl;
//    Plant searchBinBin(Plant::SearchInBin("binBin.bin"));
//    searchBinBin.Display();
//
//    cout << endl << endl << "Function remove in textText.txt" << endl;
//    Plant::RemoveInText("textText.txt");
//
//    cout << endl << endl << "Function remove in textBin.txt" << endl;
//    Plant::RemoveInBin("textBin.txt");
//
//    cout << endl << endl << "Function remove in binBin.bin" << endl;
//    Plant::RemoveInBin("binBin.bin");
//
//
//
//    cout <<  endl <<  endl << "file binBin.bin" << endl;
//    Plant::PrintAllBinFile("binBin.bin");
//
//    cout << endl << "file textBin.txt" << endl;
//    Plant::PrintAllBinFile("textBin.txt");
//
//    cout << endl << "file textText.txt" << endl;
//    Plant::PrintAllTextFile("textText.txt");
    
    Plant::CreateFile("test1");
    cout << endl;
    Plant::CreateFile("test2");
    
    Plant::ChangeInTextFile("test1.txt");
    Plant::ChangeInBinFile("test2.bin");
    
    
    
    
    
    return 0;
}
