#include <string>

using namespace std;
class Car
{
private:
    string model;
    short speed;
    string color;
public:
    Car();
    Car(string model_in, short speed_in, string color_in);
    Car(const Car &car);
    void printInformationAboutCar();
    void setModel(string model_in);
    void setSpeed(short speed_in);
    void setColor(string color_in);
    string getModel();
    short getSpeed();
    string getColor();
    ~Car();

    Car& operator ++();
    Car operator ++(int);
    Car& operator --();
    Car operator --(int);
    short operator == (Car car_in);
    short operator != (Car car_in);
    short operator > (Car car_in);
    short operator < (Car car_in);
    short operator <= (Car car_in);
    short operator >= (Car car_in);
    Car& operator = (Car car_in);
    friend ostream& operator << (ostream &out, const Car &car_in);
    friend istream& operator >> (istream &in, Car &car_in);
};
