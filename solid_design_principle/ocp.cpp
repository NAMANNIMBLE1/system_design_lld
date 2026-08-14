#include<bits/stdc++.h>
using namespace std;


class Product{
    private:
        string name;
        double price;
    
    public:

        Product(string name, double price){
            this->name = name;
            this->price = price;
        }

        // method to get the price and make the variable price private to adhere to the Single Responsibility Principle
        double getPrice() const {
            return price;
        }
        // method to get the name and make the variable name private to adhere to the Single Responsibility Principle
        string getName() const {
            return name;
        }
};

class ShoppingCart{
    private:
        vector<Product*> products; // store heap allocated products

    public:
        // setter 
        void addProduct(Product* product){
            products.push_back(product);
        }

        // getter 
        vector<Product*> getProducts(){
            return products;
        }

        // calculate total price of products in the cart
        double calculateTotalPrice(){
            double total = 0.0;
            for(auto product : products){
                total += product->getPrice();
            }
            return total;
        }
};

class ShoppingCartprinter{
    private:
        ShoppingCart* cart; // reference of ShoppingCart object

    public:
        ShoppingCartprinter(ShoppingCart* cart){
            this->cart = cart;
        }

        void printInvoice(){
            cout << "Invoice:" << endl;
            for(auto product : cart->getProducts()){
                cout << "Product: " << product->getName() << ", Price: " << product->getPrice() << endl;
            }
            cout << "Total Price: " << cart->calculateTotalPrice() << endl;
        }
};

// making diff inherit class to save the diff data in diff database to adhere to the Open/Closed Principle
class Db_persistance{
    private:
        // cart reference to save the data in database
        ShoppingCart* cart;
    public:
    // constructor to initialize the cart reference
        Db_persistance(ShoppingCart* cart) {
            this->cart = cart;
        }
    // pure virtual function to save data in database
        virtual void saveData() = 0; // pure virtual function to save data in database
};

// inheterited class to save data in diff database to adhere to the Open/Closed Principle
// using inheritance to create diff class to save data 

class SQLpersistance : public Db_persistance {
    public:
        SQLpersistance(ShoppingCart* cart) : Db_persistance(cart) {}

        void saveData() override {
            // code to save the cart to a SQL database
            cout << "Saving data to SQL database..." << endl;
        }
};

class MongoDBpersistance : public Db_persistance {
    public:
        MongoDBpersistance(ShoppingCart* cart) : Db_persistance(cart) {}

        void saveData() override {
            // code to save the cart to a MongoDB database
            cout << "Saving data to MongoDB database..." << endl;
        }
};

class FilePersistance : public Db_persistance {
    public:
        FilePersistance(ShoppingCart* cart) : Db_persistance(cart) {}

        void saveData() override {
            // code to save the cart to a file
            cout << "Saving data to file..." << endl;
        }
};




int main() {
    // Create products and add them to the shopping cart
    Product* product1 = new Product("Laptop", 999.99);
    Product* product2 = new Product("Mouse", 29.99);


    // Create a shopping cart and add products to it
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(product1);
    cart->addProduct(product2);
    
    // Create a printer and print the invoice
    ShoppingCartprinter* printer = new ShoppingCartprinter(cart);
    printer->printInvoice();
    
    // save the cart to a SQL database
    Db_persistance* sqlPersistance = new SQLpersistance(cart);
    sqlPersistance->saveData();
    // save the cart to a MongoDB database
    Db_persistance* mongoPersistance = new MongoDBpersistance(cart);
    mongoPersistance->saveData();
    // save the cart to a file
    Db_persistance* filePersistance = new FilePersistance(cart);
    filePersistance->saveData();


    // Clean up heap allocated memory
    delete product1;
    delete product2;
    delete cart;
    delete printer;
    
    delete sqlPersistance;
    delete mongoPersistance;    
    delete filePersistance;

    return 0;
};
