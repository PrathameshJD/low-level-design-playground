#include <iostream>
#include <vector>
using namespace std;

class Database {
public:
    virtual void save(string data) = 0;
    virtual ~Database() = default;
};

class SQLDatabase : public Database {
public:
    void save(string data) override {
        cout << "Saving to SQL Database: " << data << endl;
    }
};

class MongoDatabase : public Database {
public:
    void save(string data) override {
        cout << "Saving to MongoDB: " << data << endl;
    }
};

class UserService {
private:
    vector<Database*> databases;

public:
    UserService(vector<Database*> dbs) {
        this->databases = dbs;
    }

    void saveUser(string data) {
        for (Database* db : databases) {
            db->save(data);
        }
    }
};

int main() {
    SQLDatabase sql;
    MongoDatabase mongo;

    vector<Database*> dbs = { &sql, &mongo };

    UserService user(dbs);
    user.saveUser("USERNAME");
}