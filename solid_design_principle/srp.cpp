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


class shoppingCartStorage{
    private:
        ShoppingCart* cart; // reference of ShoppingCart object

    public:
    // constructor to initialize the ShoppingCart object
        shoppingCartStorage(ShoppingCart* cart){
            this->cart = cart;
        }

        void saveToDatabase(){
            // code to save the cart to a database
            cout << "Saving cart to database..." << endl;
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

    shoppingCartStorage* storage = new shoppingCartStorage(cart);
    storage->saveToDatabase();

    // Clean up heap allocated memory

    delete product1;
    delete product2;
    delete cart;
    delete printer;
    delete storage;

    return 0;
};
