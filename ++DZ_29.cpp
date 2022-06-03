#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Car
{
    string name;
    size_t year;
    double engine;
    double price;

public:
    Car(const string& name, const size_t year, const double engine, const double price)
        :
        name{ name },
        year{ year },
        engine{ engine },
        price{ price }
    { }

    void setName(string& name)
    {
        this->name = name;
    }
    void setYear(size_t year)
    {
        this->year = year;
    }
    void setEngine(double engine)
    {
        this->engine = engine;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    const string& getName()
    {
        return name;
    }
    const size_t getYear()
    {
        return year;
    }
    const double getEngine()
    {
        return engine;
    }
    const double getPrice()
    {
        return price;
    }

    friend class dataBase;

    struct compareByYear
    {
        bool operator()(const Car& a, const Car& b)
        {
            return a.year < b.year;
        }
    };

    struct compareByName
    {
        bool operator()(const Car& a, const Car& b)
        {
            return a.name < b.name;
        }
    };

};

class dataBase
{
    vector<Car>item;

public:


    void addCar(const Car& car)
    {
        item.push_back(car);
    }

    void deleteCar(int number)
    {
        item.erase(item.begin() + number - 1);
    }

    void showItem()
    {
        int number = 1;
        for (auto i = item.begin(); i != item.end(); ++i)
        {
            cout << number++ << " " << i->name << " " << i->year << " "
                << i->engine << " " << i->price << endl;

        }
    }

    void sortByName()
    {
        cout << " sorting by name: " << endl;

        Car::compareByName name;
        sort(item.begin(), item.end(), name);
        showItem();

        cout << endl;

    }

    void sortByYear()
    {
        cout << " sorting by year: " << endl;

        Car::compareByYear year;
        sort(item.begin(), item.end(), year);
        showItem();

        cout << endl;
    }
    void searchByName(const string& search)
    {
        for (auto i = item.begin(); i != item.end(); ++i)
        {
            if (i->name == search)
            {
                cout << " " << i->name << " " << i->year << " "
                    << i->engine << " " << i->price << endl;
            }

        }
    }

    void searchByYear(size_t y)
    {
        for (auto i = item.begin(); i != item.end(); ++i)
        {
            if (i->year == y)
            {
                cout << " " << i->name << " " << i->year << " "
                    << i->engine << " " << i->price << endl;
            }

        }
    }


};

int main()
{

    Car car_1("Opel vivaro ", 2004, 1.9, 120.500);
    Car car_2("Mersedes-Benz vito", 2001, 2.5, 170.100);
    Car car_3("Audi RS6", 2021, 4.0, 205.000);
    Car car_4("Lada Sidan", 2014, 1.6, 321.340);
    Car car_5("Opel Vectra", 2000, 1.8, 3400);
    Car car_6("TESLA", 2021, 5.0, 10000);

    dataBase db;
    db.addCar(car_1);
    db.addCar(car_2);
    db.addCar(car_3);
    db.addCar(car_4);
    db.addCar(car_5);
    db.addCar(car_6);

    db.showItem();
    db.sortByName();
    db.sortByYear();

    cout << "Enter Car name " << endl;
    string str = "BMW M5";

    db.searchByName(str);

    cout << "Enter Year Car: " << endl;
    size_t y = 2022;

    db.searchByYear(y);

    db.deleteCar(3);
    db.showItem();

    return 0;
}