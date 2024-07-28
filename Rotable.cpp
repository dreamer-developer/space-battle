#include <iostream>

class RotableAbstract {
public:
    virtual int& getDirection() = 0; // Абстрактный метод
    virtual int& getAngularVelocity() = 0;
    virtual int& getDirectionsNumber() = 0;

    virtual void setDirection(const int& newV) = 0;
};

class Rotate{
    public:
    Rotate(RotableAbstract &r) : _r(r){}

    void execute(){
        _r.setDirection(
            (_r.getDirection() + _r.getAngularVelocity()) % _r.getDirectionsNumber()
        );
    }
    private:
        RotableAbstract& _r;
};

class Rotable : public RotableAbstract {
private:
    int direction;
    int angularVelocity;
    int directionsNumber;

public:
    Rotable(){}
    Rotable(int av, int dn) : angularVelocity(av), directionsNumber(dn) {}
    ~Rotable(){}

    int& getDirection() override { 
        if (!direction)
            throw std::invalid_argument("У объекта нет направления");
        return direction; 
    }
    int& getAngularVelocity() override {
        if (!angularVelocity)
            throw std::invalid_argument("У объекта нет угловой скорости");
        return angularVelocity; 
    }
    int& getDirectionsNumber() override { return directionsNumber; }

    void setDirection(const int& newV) override { direction = newV; }
};