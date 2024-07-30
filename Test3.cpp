#include <iostream>
#include "Movable.cpp"

using namespace std;

//Попытка сдвинуть объект, 
//у которого невозможно прочитать значение 
//мгновенной скорости, приводит к ошибке
int main() {
    Movable *obj = new Movable();
    
    Point startPos;
    startPos.x = 12;
    startPos.y = 5;
    obj->setPosition(startPos);

    Move moveObj(*obj);
    try {
        moveObj.execute();
    }
    catch (const std::exception& e) {
            std::cerr << "Невозможно прочитать значение мгновенной скорости. Тест пройден. " << e.what() << std::endl;
            return 0;
        }

    std::cerr << "Тест провален." << obj->getVelocity().x << " " << obj->getVelocity().y << std::endl;
    return 1;
    
}
