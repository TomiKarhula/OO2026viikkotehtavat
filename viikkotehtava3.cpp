#include <iostream>
#include <string>
#include <algorithm>    

using namespace std;

class Chef
{
private:
    string chefName;

protected:
    void printNameAndMessage(const string& message) const {
        cout << chefName << " " << message << endl;
    }

public:
    Chef(const string& name) : chefName(name) {
        cout << "Chef " << chefName << " constructor" << endl;
    }

    virtual ~Chef() {
        cout << "Chef " << chefName << " destructor" << endl;
    }

    int makeSalad(int ingredients) {
        int portions = ingredients / 5;
        cout << "Chef " << chefName << " makes salad: " 
             << portions << " portions (uses " << portions*5 << " ingredients)" << endl;
        return portions;
    }

    int makeSoup(int ingredients) {
        int portions = ingredients / 3;
        cout << "Chef " << chefName << " makes soup: " 
             << portions << " portions (uses " << portions*3 << " ingredients)" << endl;
        return portions;
    }

    string getName() const {
        return chefName;
    }
};


class ItalianChef : public Chef
{
private:
    string password;
    
    int makePizza(int flour, int water) {
        int portions_by_flour = flour / 5;
        int portions_by_water = water / 5;
        
        int portions = min(portions_by_flour, portions_by_water);
        
        cout << "ItalianChef " << getName() << " makes pizza: " 
             << portions << " portions (uses " << portions*5 << " flour + " 
             << portions*5 << " water)" << endl;
             
        return portions;
    }

public:
    ItalianChef(const string& name) 
        : Chef(name), password("pizza")
    {
        cout << "ItalianChef " << getName() << " constructor" << endl;
    }

    ~ItalianChef() override {
        cout << "ItalianChef " << getName() << " destructor" << endl;
    }

    bool askSecret(const string& givenPassword, int flour, int water) {
        cout << "ItalianChef " << getName() 
             << " checks password... ";

        if (givenPassword.compare(password) == 0) {
            cout << "OK!" << endl;
            makePizza(flour, water);
            return true;
        } else {
            cout << "WRONG!" << endl;
            return false;
        }
    }
};


int main()
{
    cout << "=== Creating normal Chef ===\n";
    Chef chefMario("Mario");
    
    cout << "\n=== Making food with normal chef ===\n";
    chefMario.makeSalad(18);
    chefMario.makeSoup(11);

    cout << "\n=== Creating ItalianChef ===\n";
    ItalianChef chefLuigi("Luigi");

    cout << "\n=== Trying secret pizza - wrong password ===\n";
    chefLuigi.askSecret("pitsa", 25, 30);

    cout << "\n=== Trying secret pizza - correct password ===\n";
    chefLuigi.askSecret("pizza", 23, 17);

    cout << "\n=== Normal food with Italian chef ===\n";
    chefLuigi.makeSalad(14);
    chefLuigi.makeSoup(10);

    cout << "\n=== Program ending - destructors will be called ===\n";

    return 0;
}
