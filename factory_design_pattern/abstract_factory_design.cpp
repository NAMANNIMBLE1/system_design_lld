#include <bits/stdc++.h>
using namespace std;

// Abstract Burger
class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

// Abstract Bread
class Bread {
public:
    virtual void prepare() = 0;
    virtual ~Bread() = default;
};

// KFC Burgers
class ChickenBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing KFC famous chicken burger.." << endl;
    }
};

class MaharajaMacBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing KFC famous maharaja burger.." << endl;
    }
};

class FriedChickenBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing KFC famous fried chicken burger.." << endl;
    }
};

// BurgerKing Burgers
class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing BurgerKing basic burger.." << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing BurgerKing standard burger.." << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing BurgerKing premium burger.." << endl;
    }
};

// KFC Garlic Bread
class KFCGarlicBread : public Bread {
public:
    void prepare() override {
        cout << "Preparing KFC special garlic bread.." << endl;
    }
};

// BurgerKing Garlic Bread
class BurgerKingGarlicBread : public Bread {
public:
    void prepare() override {
        cout << "Preparing BurgerKing special garlic bread.." << endl;
    }
};

// Abstract Factory
class RestaurantFactory {
public:
    virtual Burger* createBurger(string burger_type) = 0;
    virtual Bread* createBread() = 0;

    virtual ~RestaurantFactory() = default;
};

// KFC Factory
class KFC : public RestaurantFactory {
public:
    Burger* createBurger(string burger_type) override {

        if (burger_type == "chickenburger") {
            return new ChickenBurger();
        }
        else if (burger_type == "maharaja") {
            return new MaharajaMacBurger();
        }
        else if (burger_type == "friedchicken") {
            return new FriedChickenBurger();
        }
        else {
            throw logic_error("KFC does not make this burger");
        }
    }

    Bread* createBread() override {
        return new KFCGarlicBread();
    }
};

// BurgerKing Factory
class BurgerKing : public RestaurantFactory {
public:
    Burger* createBurger(string burger_type) override {

        if (burger_type == "basic") {
            return new BasicBurger();
        }
        else if (burger_type == "standard") {
            return new StandardBurger();
        }
        else if (burger_type == "premium") {
            return new PremiumBurger();
        }
        else {
            throw logic_error("BurgerKing does not make this burger");
        }
    }

    Bread* createBread() override {
        return new BurgerKingGarlicBread();
    }
};

int main() {

    RestaurantFactory* kfcFactory = new KFC();

    Burger* kfcBurger =
        kfcFactory->createBurger("chickenburger");

    Bread* kfcBread =
        kfcFactory->createBread();

    cout << "\n--- KFC Order ---" << endl;

    kfcBurger->prepare();
    kfcBread->prepare();


    RestaurantFactory* burgerKingFactory =
        new BurgerKing();

    Burger* burgerKingBurger =
        burgerKingFactory->createBurger("standard");

    Bread* burgerKingBread =
        burgerKingFactory->createBread();

    cout << "\n--- Burger King Order ---" << endl;

    burgerKingBurger->prepare();
    burgerKingBread->prepare();


    delete kfcBurger;
    delete kfcBread;
    delete kfcFactory;

    delete burgerKingBurger;
    delete burgerKingBread;
    delete burgerKingFactory;

    return 0;
}