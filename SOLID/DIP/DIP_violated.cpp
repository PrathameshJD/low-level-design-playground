#include <iostream>
using namespace std;

class SQLDatabase {
public:
    void save(string data) {
        cout << "Saving to SQL Database: " << data << endl;
    }
};

class MongoDatabase {
public:
    void save(string data) {
        cout << "Saving to MongoDB: " << data << endl;
    }
};

class UserService {
private:
    SQLDatabase sqlDB;
    MongoDatabase mongoDB;

public:
    void saveToSQL(string data) {
        sqlDB.save(data);
    }

    void saveToMongo(string data) {
        mongoDB.save(data);
    }
};

int main() {
    UserService user;
    user.saveToSQL("User1");
    user.saveToMongo("User2");
}