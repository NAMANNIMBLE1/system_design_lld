#include<bits/stdc++.h>
using namespace std;

class Burger{
    public:
        virtual void prepare() = 0;
        virtual ~Burger() = default;
};


class BasicBurger:public Burger{
    public:
        void prepare() override{
            cout<<"preparing basic burger.."<<endl;
        }
};

class StandardBurger:public Burger{
    public:
        void prepare() override{
            cout<<"preparing standard burger.."<<endl;
        }
};

class PremiumBurger:public Burger{
    public:
        void prepare() override{
            cout<<"preparing premium burger.."<<endl;
        }
};


class BurgerFactory{
    public:
        BurgerFactory(){}

        Burger* create_burger(string burgerType){
            if(burgerType == "basic"){
                return new BasicBurger();
            }else if(burgerType == "standard"){
                return new StandardBurger();
            }else if(burgerType == "premium"){
                return new PremiumBurger();
            }else{
                throw logic_error("invalid burger type");
                return nullptr;
            }
        }
};

int main(){
    string burger_type = "standard";

    BurgerFactory* myBurgerFactory = new BurgerFactory();
    Burger* burger = myBurgerFactory->create_burger(burger_type);
    
    cout<<endl;
    burger->prepare();
    cout<<endl;
    
    delete myBurgerFactory;
    delete burger;

    return 0;
}