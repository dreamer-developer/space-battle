#include <iostream>
#include "Movable.cpp"

using namespace std;

//Попытка сдвинуть объект, 
//у которого невозможно прочитать положение в пространстве, приводит к ошибке
int main() {
    Point velocity;
    velocity.x = -7;
    velocity.y = 3;

    Movable *object = new Movable(velocity);

    Move moveObj(*object);
    try {
        moveObj.execute();
    }
    catch (const std::exception& e) {
            std::cerr << "Невозможно прочитать положение в пространстве. Тест пройден. " << e.what() << std::endl;
            return 0;
        }

    std::cerr << "Тест провален." << std::endl;
    return 1;
    
}
