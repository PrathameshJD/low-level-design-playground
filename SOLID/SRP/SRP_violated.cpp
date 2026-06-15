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

    void printInvoice(){
        cout<<"Shopping cart Invoice :\n";
        for(auto product:products){
            cout << product->getName() << " - Rs" << product->getPrice() << endl;
        }

        cout << "Total - Rs" << calculateTotal() << endl;
    }

    void saveToDB(){
        cout << "Saving to database...." << endl;
    }
};


int main(){

    ShoppingCart *cart = new ShoppingCart();

    cart->addProduct(new Product("Pen",10));
    cart->addProduct(new Product("Pencil",5));

    cart->printInvoice();

    cart->saveToDB();
}

