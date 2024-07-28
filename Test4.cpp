#include <iostream>
#include "Movable.cpp"

using namespace std;

//Попытка сдвинуть объект, 
//у которого невозможно изменить 
//положение в пространстве, приводит к ошибке
int main() {
    Movable *still_obj = new Movable(true);
    
    Point startPos;
    startPos.x = 12;
    startPos.y = 5;
    still_obj->setPosition(startPos);

    Move moveObj(*still_obj);
    try {
        moveObj.execute();
    }
    catch (const std::exception& e) {
            std::cerr << "Невозможно передвинуть объект. Тест пройден. " << e.what() << std::endl;
            return 0;
        }

    std::cerr << "Тест провален." << std::endl;
    return 1;
    
}