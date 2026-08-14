// abstraction is a method  Where we hide the data and allow only methods to use 
// hide unnessary detaiols from a client and showcase only what is necessary

#include<bits/stdc++.h>
using namespace std;


class Cars{

    public:
        virtual void startEngine() = 0; // pure virtual function
        virtual void stopEngine() = 0; // pure virtual function
};

class BMW : public Cars{
    public:
        void startEngine(){
            cout<<"BMW engine started"<<endl;
        }
        void stopEngine(){
            cout<<"BMW engine stopped"<<endl;
        }
};

int main(){
    
    Cars* car = new BMW(); 

    car->startEngine();
    car->stopEngine();

    return 0;
}