#include <iostream>
#include "Rotable.cpp"

using namespace std;

//Попытка сдвинуть объект, 
//у которого невозможно прочитать значение 
//угловой скорости, приводит к ошибке
int main() {
    Rotable *dir_obj = new Rotable();
    
    dir_obj->setDirection(5);

    Rotate rotateObj(*dir_obj);
    try {
        rotateObj.execute();
    }
    catch (const std::exception& e) {
            std::cerr << "Невозможно прочитать значение угловой скорости. Тест пройден. " << e.what() << std::endl;
            return 0;
        }

    std::cerr << "Тест провален.";
    return 1;
    
}
