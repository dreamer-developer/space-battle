#include <iostream>
#include <vector>

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

// Класс, реализующий интерфейс Movable
class Movable : public MovableAbstract {
private:
    Point position;
    Point velocity;

public:
    Movable(){
        velocity.x = -7;
        velocity.y = 3;
    };

    Point& getPosition() override {
        return position;
        //std::cout << "Position: (" << position.x << ", " << position.y << ")" << std::endl;
    }

    Point& getVelocity() override {
        return velocity;
        //std::cout << "Velocity: (" << velocity.x << ", " << velocity.y << ")" << std::endl;
    }

    void setPosition(const Point& newV) override {
        position = newV;
    }
};

class Move {
    public:
    Move(Movable &m) : _m(m){}

    void execute(){
        _m.setPosition(sumPoints(_m.getPosition(),_m.getVelocity()));
    }
    private:
        Movable& _m;
};
