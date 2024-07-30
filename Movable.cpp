#include <iostream>

struct Point{
    int x;
    int y;
};

Point sumPoints(const Point& p1, const Point& p2) {
    Point result;
    result.x = p1.x + p2.x;
    result.y = p1.y + p2.y;
    return result;
};

class MovableAbstract {
public:
    virtual Point& getPosition() = 0; // Абстрактный метод
    virtual Point& getVelocity() = 0;
    virtual void setPosition(const Point& newV) = 0;
};

// Класс, реализующий интерфейс MovableAbstract
class Movable : public MovableAbstract {
private:
    Point _position;
    Point _velocity;
    bool _isStill;//признак неподвижности объекта

public://Реализуем несколько конструкторов вместо нескольких наследуемых классов, чтобы не дублировать код
    //Конструктор по умолчанию не задает никаких начальных настроек
    Movable(){
        _isStill = false;
    }
    //Конструктор задает только начальную скорость
    Movable(Point& velocity){ 
        _velocity = velocity;
        _isStill = false;
    }
    //Конструктор принимает признак неподвижности объекта
    Movable(bool isStill) : _isStill(isStill) {}
    ~Movable(){}

    Point& getPosition() override {
        if (!_position.x && !_position.y)
            throw std::invalid_argument("У объекта нет положения в пространстве");
        return _position;
        //std::cout << "Position: (" << position.x << ", " << position.y << ")" << std::endl;
    }

    Point& getVelocity() override {
        if (!_velocity.x && !_velocity.y)
            throw std::invalid_argument("У объекта нет мгновенной скорости");
        return _velocity;
        std::cout << "Velocity: (" << _velocity.x << ", " << _velocity.y << ")" << std::endl;
    }

    void setPosition(const Point& newV) override {
        if (_position.x && _position.y && _isStill)
            throw std::invalid_argument("Объект нельзя передвинуть, он неподвижен");
        _position = newV;
    }
};

class Move {
    public:
    Move(MovableAbstract &m) : _m(m){}

    void execute(){
        _m.setPosition(sumPoints(_m.getPosition(),_m.getVelocity()));
    }
    private:
        MovableAbstract& _m;
};
