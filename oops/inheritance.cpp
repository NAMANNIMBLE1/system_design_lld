#include<bits/stdc++.h>
using namespace std;

class Cars{
    public:
        string name;
        int price;
        int model;

        Cars(string n, int p, int m){
            this->name = n;
            this->price = p;
            this->model = m;
        }

        void startEngine(){
            cout << "Engine started" << endl;
        }

        void stopEngine(){
            cout << "Engine stopped" << endl;
        }
};

class manualCar : public Cars{
    private: 
        int currentGear;

    public:
        manualCar(string n, int p, int m, int g) : Cars(n, p, m){
            this->currentGear = g;
        }

        void changeGear(int g){
            this->currentGear = g;
            cout << "Gear changed to: " << this->currentGear << endl;
        }
};


class electricCar : public Cars{
    private:
        int batteryLevel = 0;

    public:
        electricCar(string n, int p, int m, int b) : Cars(n, p, m){
            this->batteryLevel = b;
        }

        void chargeBattery(int b){
            this->batteryLevel += b;
            cout << "Battery charged to: " << this->batteryLevel << "%" << endl;
        }
};

int main(){
    
    manualCar myManualCar("Toyota", 20000, 2020, 1);
    myManualCar.startEngine();
    myManualCar.changeGear(2);

    electricCar myElectricCar("Tesla", 50000, 2021, 0);
    myElectricCar.startEngine();
    myElectricCar.chargeBattery(56);

    return 0;
}