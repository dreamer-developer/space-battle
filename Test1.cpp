#include <iostream>
#include "Movable.cpp"

using namespace std;

//Тест, который проверяет, что для объекта, находящегося в точке (12, 5) 
//и движущегося со скоростью (-7, 3) движение меняет положение объекта на (5, 8)
int main() {

    Movable *object = new Movable();
    Point startPos;
    startPos.x = 12;
    startPos.y = 5;
    Point finishPos;
    finishPos.x = 5;
    finishPos.y = 8;
    object->setPosition(startPos);
    Move moveObj(*object);
    moveObj.execute();
    if (object->getPosition().x == finishPos.x && object->getPosition().y == finishPos.y){
        cout << "Тест пройден." << std::endl;
        } 
        else {
            std::cerr << "Тест провален!" << std::endl;
            return 1;
        }

    return 0;
}
