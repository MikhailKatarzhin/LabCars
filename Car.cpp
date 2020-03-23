#include <iostream>
#include "Car.h"
#include <string>
#include <cstring>

using namespace std;
    Car :: Car()
    {
        setModel("Normal");
        setSpeed(10);
        cout << "\nConstruction... " << this;
    }

    Car :: Car(string model_in, short speed_in, string color_in)
    {
        this -> model = model_in;
        this -> speed = speed_in;
        this -> color = color_in;
        cout << "\nConstruction... " << this;
    }

    Car :: Car(const Car &otherCar)
    {
        this -> model = otherCar.model;
        this -> speed = otherCar.speed;
        this -> color = otherCar.color;
        cout << "\nConstruction copy... " << this;
    }
    void Car :: printInformationAboutCar()
    {   cout << "Model: " << model << "\tSpeed: " << speed << "\tColor: " << color << endl;    }

    void Car :: setModel(string model_in)
    {   this -> model = model_in;  }

    void Car :: setSpeed(short speed_in)
    {   this -> speed = speed_in;  }

    void Car :: setColor(string color_in)
    {   this -> color = color_in;  }

    string Car :: getModel()
    {
        return model;
    }

    short Car :: getSpeed()
    {
        return speed;
    }

    string Car :: getColor()
    {
        return color;
    }

    Car :: ~Car()
    {
        cout << "\nDestruction... " << this;
    }

    Car& Car :: operator ++()
    {
        if (this->model == "Legendary") this->model = "Mythical";
        if (this->model == "Epic") this->model = "Legendary";
        if (this->model == "Rarity") this->model = "Epic";
        if (this->model == "Normal") this->model = "Rarity";
        this->speed += 20;
        return *this;
    }

    Car Car:: operator ++(int)
    {
        //**
        return ++(*this);
    }

    Car& Car :: operator --()
    {
        if (this->model == "Rarity") this->model = "Normal";
        if (this->model == "Epic") this->model = "Rarity";
        if (this->model == "Legendary") this->model = "Epic";
        if (this->model == "Mythical") this->model = "Legendary";
        if (this->speed > 20) this->speed -= 20;
        return *this;
    }

    Car Car:: operator --(int)
    {
        //**
        return --(*this);
    }

    short Car :: operator == (Car car_in)
    {
        if ((this -> model == car_in.model)/*&&(this -> speed == car_in.speed)&&(this -> color == car_in.color)*/)
            return 1;
        return 0;
    }

    short Car :: operator != (Car car_in)
    {
        //if ((this -> model != car_in.model)/*||(this -> speed != car_in.speed)||(this -> color != car_in.color)*/)
        //return 1;
        if (*(this) == car_in)
        return 0;
        return 1;
    }

    short Car :: operator > (Car car_in)
    {
        if ((this -> model == "Mythical")&&(car_in.model != "Mythical"))
            {return 1;}
        if ((this -> model == "Legendary")&&(car_in.model != "Mythical")&&(car_in.model != "Legendary"))
            {return 1;}
        if ((this -> model == "Epic")&&((car_in.model == "Normal")||(car_in.model == "Rarity")))
            {return 1;}
        if ((this -> model == "Rarity")&&(car_in.model == "Normal"))
            {return 1;}
        return 0;
    }

    short Car :: operator < (Car car_in)
    {
        /*if ((this -> model == "Normal")&&(car_in.model != "Normal"))
            {return 1;}
        if ((this -> model == "Rarity")&&(car_in.model != "Normal")&&(car_in.model != "Rarity"))
            {return 1;}
        if ((this -> model == "Epic")&&((car_in.model == "Legendary")||(car_in.model == "Mythical")))
            {return 1;}
        if ((this -> model == "Legendary")&&(car_in.model == "Mythical"))
            {return 1;}
        return 0;
        */
        if ((*(this) == car_in)||(*(this)> car_in))
            {return 0;}
        return 1;
    }

    short Car :: operator <= (Car car_in)
    {
        if ((*(this) == car_in) || (*(this) < car_in))
            {return 1;}
        return 0;
    }

    short Car :: operator >= (Car car_in)
    {
        if ((*(this) == car_in) || (*(this) > car_in))
            {return 1;}
        return 0;
    }

    Car& Car :: operator = (Car car_in)
    {
        this -> model = car_in.model;
        this -> speed = car_in.speed;
        this -> color = car_in.color;
        return *this;
    }

    ostream& operator << (ostream &out, const Car &car_in)
    {
        out << "Model: " << car_in.model << " Speed: " << car_in.speed << " Color: " << car_in.color << ";";
        return out;
    }

    istream& operator >> (istream &in, Car &car_in)
    {
        in >> car_in.model;
        in >> car_in.speed;
        in >> car_in.color;
        return in;
    }

