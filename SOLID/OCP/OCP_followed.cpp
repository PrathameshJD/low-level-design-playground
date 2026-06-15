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

    void setPrice(double price){
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

class Persistence{

public: 
    virtual void save(ShoppingCart *cart)=0;
    virtual ~Persistence() = default;
};

class SQLPersistence : public Persistence{
public:
    void save(ShoppingCart *cart) override{
        cout << "Saving shopping cart to SQL database..." << endl;
    }
};

class MongoPersistence : public Persistence{
public:
    void save(ShoppingCart *cart) override{
        cout << "Saving shopping cart to MongoDB..." << endl;
    }
};

class FilePersistence : public Persistence{
public:
    void save(ShoppingCart *cart) override{
        cout << "Saving shopping cart to File..." << endl;
    }
};


int main(){
    ShoppingCart *cart = new ShoppingCart();

    cart->addProduct(new Product("Book", 20));
    cart->addProduct(new Product("Laptop",50000));
    cart->addProduct(new Product("Mouse", 500));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printCartInvoice();

    Persistence *db = new SQLPersistence();
    db->save(cart);

    Persistence *mongo = new MongoPersistence();
    mongo->save(cart);

    Persistence *file = new FilePersistence();
    file->save(cart);

    return 0;
}
