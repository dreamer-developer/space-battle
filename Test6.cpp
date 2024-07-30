#include <iostream>
#include "Rotable.cpp"

using namespace std;

//Попытка сдвинуть объект, 
//у которого невозможно прочитать направление,
//приводит к ошибке
int main() {
    Rotable *angv_obj = new Rotable(5,8);

    Rotate obj(*angv_obj);
    try {
        obj.execute();
    }
    catch (const std::exception& e) {
            std::cerr << "Невозможно прочитать значение направления. Тест пройден. " << e.what() << std::endl;
            return 0;
        }

    std::cerr << "Тест провален.";
    return 1;
    
}
