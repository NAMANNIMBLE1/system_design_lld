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


//************kfc burgers */

class ChickenBurger:public Burger{
    public:
        void prepare(){
            cout<<"preparing kfc famous chicken burger";
        }
};

class MaharajaMacBurger:public Burger{
    public:
        void prepare(){
            cout<<"preparing kfc famous maharaja mac burger";
        }
};

class FriedChickenBurger:public Burger{
    public:
        void prepare(){
            cout<<"preparing kfc famous fried chicken burger";
        }
};


//****************** creating the factory and diff outlets********** */


class BurgerFactory{
    public:
        virtual Burger* createBurger(string burger_type) = 0;
        virtual ~BurgerFactory() = default;
};


class KFC:public BurgerFactory{
    public:
        Burger* createBurger(string burger_type){
            if(burger_type == "chickenburger"){
                return new ChickenBurger();
            }else if (burger_type == "maharaja"){
                return new MaharajaMacBurger();
            }else if(burger_type == "friedchicken"){
                return new FriedChickenBurger();
            }else{
                cout<<"we dont make this type of burger....";
                throw new logic_error("not in out outlet");
                return nullptr;
            }
        }
};


class BurgerKing:public BurgerFactory{
    public:
        Burger* createBurger(string burger_type){
            if(burger_type == "basic"){
                return new BasicBurger();
            }else if(burger_type == "standard"){
                return new StandardBurger();
            }else if(burger_type == "premium"){
                return new PremiumBurger();
            }else{
                cout<<"we dont make this type of burger....";
                throw new logic_error("not in out outlet");
                return nullptr;
            }
        }
};

int main(){
    string burger_type = "chickenburger";
    BurgerFactory* kfcBurgerFactory = new KFC();

    cout<<endl;
    Burger* kfcBurger = kfcBurgerFactory->createBurger(burger_type);
    kfcBurger->prepare();
    cout<<endl;

    BurgerFactory* burgerKingFactory = new BurgerKing();

    cout<<endl;
    Burger* burgerkingburger = burgerKingFactory->createBurger(burger_type);
    burgerkingburger->prepare();
    


    delete kfcBurger;
    delete kfcBurgerFactory;
    delete burgerkingburger;
    delete burgerKingFactory;

    return 0;
}