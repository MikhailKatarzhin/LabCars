#include <iostream>
#include "Car.h"
#include <string>
#include <stdlib.h>

using namespace std;

void showMenu()
{
    cout << "\t\t\t***Menu***" << endl;
    cout << "\t0)Menu up" << endl;
    cout << "\t1)Show all information about car" << endl;
    cout << "\t2)Set model of car" << endl;
    cout << "\t3)Set speed of car" << endl;
    cout << "\t4)Set color of car" << endl;
    cout << "\t5)Get model of car" << endl;
    cout << "\t6)Get speed of car" << endl;
    cout << "\t7)Get color of car" << endl;
    cout << "\t8)Copy this car" << endl;
    cout << "\t9)Delete this car" << endl;
    cout << "\t10)Add some cars" << endl;
    cout << "\t11)Upgrade car" << endl;
    cout << "\t12)Downgrade car" << endl;
    cout << "\t13)Battle between cars!!!" <<endl;
}

void showAllCars(short countOfCar, Car *Cars)
{
    for (short i = 0; i < countOfCar; i++)
    {
        cout << i+1 << ")";
        Cars[i].printInformationAboutCar();
    }
}

int main()
{
    string tmpModel, tmpColor;
    short var = 0, tmpspeed = 0, countOfCar = 1, i = 0, y = 0, addCount = 0;
    Car *Cars = new Car[1], *tmpCars;
    cout << "\t\t\t***Car's database***\n\n";
    while (1)
    {
        do{
            cout << "\nEntry number of car(to " << countOfCar << ") or close program(input 0)\n" << endl;
            showAllCars(countOfCar, Cars);
            cin >> i;
        }while((i < 0)||(i > countOfCar));
        if (i == 0)
        {
            delete Cars;
            return 0;
        }

        while (i != 0)
        {
            showMenu();
            cin >> var;
            switch (var)
            {
                case 0:
                    i = 0;
                    break;
                case 1:
                    //Cars[i-1].printInformationAboutCar();
                    cout << Cars[i-1] << endl;
                    break;
                case 2:
                    cout << "\nEntry model of car:" << endl;
                    cin >> tmpModel;
                    if((tmpModel == "Normal")||(tmpModel == "Rarity")||(tmpModel == "Epic")||(tmpModel == "Legendary")||(tmpModel == "Mythical"))
                    {
                        Cars[i-1].setModel(tmpModel);
                    }else{cout << "\nUncorrect model (Normal, Rarity, Epic, Legendary, Mythical)" << endl;}
                    break;
                case 3:
                    cout << "\nEntry speed of car:" << endl;
                    cin >> tmpspeed;
                    if (tmpspeed >= 0)
                    {
                        Cars[i-1].setSpeed(tmpspeed);
                    }else{
                        cout << "\nUncorrect speed set. Repeat." << endl;
                        }
                    break;
                case 4:
                    cout << "\nEntry color of car:" << endl;
                    cin >> tmpColor;
                    Cars[i-1].setColor(tmpColor);
                    break;
                case 5:
                    cout << "\nTaken model of car:\t" << (tmpModel = Cars[i-1].getModel()) << endl;
                    break;
                case 6:
                    cout << "\nTaken speed of car:\t" << (tmpspeed = Cars[i-1].getSpeed()) << endl;
                    break;
                case 7:
                    cout << "\nTaken color of car:\t" << (tmpColor = Cars[i-1].getColor()) << endl;
                    break;
                case 8:{
                    countOfCar++;
                    cout << "There";
                    tmpCars = new Car[countOfCar];
                    for (y = 0; y < countOfCar-1; y++)
                    {
                        tmpCars[y] = Cars[y];
                        delete &(Cars[y]);
                    }
                    delete Cars;
                    Cars = tmpCars;
                    Car newCar(Cars[i-1]);
                    cout << "\nCount of car: " << countOfCar;
                    Cars[countOfCar-1] = newCar;
                    break;}
                case 9:{
                    Cars[i-1] = Cars[countOfCar-1];
                    delete &(Cars[countOfCar-1]);
                    countOfCar --;
                    tmpCars = new Car[countOfCar];
                    for (y = 0; y < countOfCar; y++)
                    {
                        tmpCars[y] = Cars[y];
                        delete &(Cars[y]);
                    }
                    delete Cars;
                    Cars = tmpCars;
                    i = 0;
                    break;}
                case 10:{
                    while (addCount < 1)
                    {
                        cout << "How many car add in database?" << endl;
                        cin >> addCount;
                    }
                    countOfCar += addCount;
                    tmpCars = new Car[countOfCar];
                    for (y = 0; y < countOfCar-addCount; y++)
                    {
                        tmpCars[y] = Cars[y];
                        delete &(Cars[y]);
                    }
                    addCount = 0;
                    delete Cars;
                    Cars = tmpCars;
                    for (; y < countOfCar; y++)
                    {
                       /* cout << "\nCar #" << y << endl;
                        cout << "Entry model of car" << endl;
                        cin >> tmpModel;
                        cout << "Entry speed of car" << endl;
                        cin >> tmpspeed;
                        cout << "Entry color of car" << endl;
                        cin >> tmpColor;
                        Car newCar(tmpModel, tmpspeed, tmpColor);*/
                        Car newCar;
                        cout << "\nCar #" << y+1 << " \nModel\tSpeed\tColor" << endl;
                        cin >> newCar;
                        Cars[y] = newCar;
                    }
                }
                case 11:
                    //++ Cars[i-1];
                    Cars[i-1] ++;
                    break;
                case 12:
                    //-- Cars[i-1];
                    Cars[i-1] --;
                    break;
                case 13:
                    do{
                        cout << "\nSelect enemy for battle(to " << countOfCar <<"): ";
                        cin >> y;
                    }while ((y < 0)||(y > countOfCar));
                    if (Cars[i-1] < Cars[y-1])
                    {
                        cout << "\nWin car... IN LEFT CONNER!!!" << endl;
                        Cars[y-1] ++;

                        Cars[i-1] = Cars[countOfCar-1];
                        delete &(Cars[countOfCar-1]);
                        countOfCar --;
                        tmpCars = new Car[countOfCar];
                        for (y = 0; y < countOfCar; y++)
                        {
                            tmpCars[y] = Cars[y];
                            delete &(Cars[y]);
                        }
                        delete Cars;
                        Cars = tmpCars;
                    }else{
                        if (Cars[i-1] == Cars[y-1])
                        {
                            cout << "\nWin car... No, no winner... Both rivals fell.." << endl;
                            Cars[i-1] --;
                            Cars[y-1] --;
                        }else{
                            if (Cars[i-1] > Cars[y-1])
                            {
                                cout << "\nWin car... IN RIGHT CONNER!!!" << endl;
                                Cars[i-1] ++;

                                Cars[y-1] = Cars[countOfCar-1];
                                delete &(Cars[countOfCar-1]);
                                countOfCar --;
                                tmpCars = new Car[countOfCar];
                                for (y = 0; y < countOfCar; y++)
                                {
                                    tmpCars[y] = Cars[y];
                                    delete &(Cars[y]);
                                }
                                delete Cars;
                                Cars = tmpCars;
                            }
                        }
                    }
                    i = 0;
                    break;
            }
        }
    }
}
