#include "Set/Set.hpp"
int main(int argc, const char * argv[]) {
    // заполнение с клавиатуры
    // размер не больше 10   поиск подможества с клавиатуры(если не подряд - не подмножество)
    std::cout << "Enter your mySet:" << std::endl;
    
    Set<int, 10> mySet;
    mySet.EnterSet();
    
    std::cout << "Enter your subSet:" << std::endl;
    Set<int, 3> subSet;
    subSet.EnterSet();
    
    std::cout  << mySet.isSubset(subSet) << " MySet" << std:: endl << std:: endl;
    
    print(mySet);
    print(subSet);
    
    
    
    
    
    
    
    
    
    
    
//    Set<float, 5> firstSet;
//    firstSet.Add(3.3);
//    firstSet.Add(11.1);
//    firstSet.Add(33.3);
//    firstSet.Add(44.4);
//    firstSet.Add(66.6);
//
//    std::cout << "First Set:" << std::endl;
//    print(firstSet);
//    std::cout << "Element index 33.3: " << firstSet.Find(33.3) << std::endl;
//
//    firstSet.Remove();
//    firstSet.Remove();
//
//    std::cout << std::endl << "After 2 remove:" << std::endl;
//    print(firstSet);
//
//    Set<float, 5> secondSet;
//    secondSet.Add(3.3);
//    secondSet.Add(11.1);
//
//    std::cout << std:: endl << "Second Set:" << std::endl;
//    print(secondSet);
//
//    std::cout << std::endl <<"first set == second set: " << std::boolalpha << (firstSet == secondSet) << std::endl
//    << "first set != second set: " << std::boolalpha << (firstSet != secondSet) << std::endl;
//
//    secondSet.Add(33.3);
//
//    std::cout << std::endl << "33.3 add in second set" << std::endl;
//
//    std::cout << "first set == second set: " << std::boolalpha << (firstSet == secondSet) << std::endl
//    << "first set != second set: " << std::boolalpha << (firstSet != secondSet) << std::endl;
//    firstSet.Remove();
//    secondSet.Remove();
//    secondSet.Remove();
//    secondSet.Add(55.5);
//
//    std::cout << std::endl << "New first Set:" << std::endl;
//    print(firstSet);
//    std::cout << std::endl << "New second Set:" << std::endl;
//    print(secondSet);
//    std::cout << std::endl << "firstSet + secondSet:" << std::endl;
//    auto thirdSet = firstSet + secondSet;
//    print(thirdSet);
//
//
//    std::cout << std::endl;
//    Set<char*, 3> stringsSet;
//    char str1[] = "Venom";
//    char str2[] = "Carnage";
//    char str3[] = "Spider-man";
//    stringsSet.Add(str1);
//    stringsSet.Add(str2);
//    stringsSet.Add(str3);
//
//    std::cout << "Strings set:" << std::endl;
//    print(stringsSet);
    
    return 0;
}
