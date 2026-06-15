#include<iostream>
#include<vector>

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

    string getName(){
        return this->name;
    }

    void setName(string name){
        this->name = name;
    }

    double getPrice(){
        return this->price;
    }

    void setPrice(){
        this->price = price;
    }
};

class ShoppingCart{
private:
    vector<Product*> products;

public:

    void addProduct(Product *p){
        products.push_back(p);
    }

    const vector<Product*> getProducts(){
        return products;
    }

    double calculateTotal(){
        double total = 0;

        for(auto product:products){
            total += product->getPrice();
        }
        return total;
    }

};

class ShoppingCartPrinter{
private:
    ShoppingCart *cart;

public:

    ShoppingCartPrinter(ShoppingCart *cart){
        this->cart = cart;
    }
    
    void printCartInvoice(){
        cout << "Shopping cart Invoice :\n" ;        
        for(auto product:cart->getProducts()){
            cout << product->getName() << " - Rs" << product->getPrice() << endl;
        }

        cout << "Total : Rs " << cart->calculateTotal() << endl;
    }

};

class ShoppingCartStorage{
private:
    ShoppingCart *cart;

public: 
    ShoppingCartStorage(ShoppingCart *cart){
        this->cart = cart;
    }

    void saveToDatabase(){
        cout << "Saving shopping cart to database..." << endl;
    }
};


int main(){
    ShoppingCart *cart = new ShoppingCart();

    cart->addProduct(new Product("Book", 20));
    cart->addProduct(new Product("Laptop",50000));
    cart->addProduct(new Product("Mouse", 500));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printCartInvoice();

    ShoppingCartStorage *storage = new ShoppingCartStorage(cart);
    storage->saveToDatabase();

}
