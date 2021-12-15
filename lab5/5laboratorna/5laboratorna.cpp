#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

class Smartphone
{
public:
    string phoneName;
    int price;
    string model;
    string phoneNumber;
    vector <string> phoneNumbers;
    int memoryGb;
    int batteryMah;


    void addPhoneNumber(string phoneNumber) {
        this->phoneNumbers.push_back(phoneNumber);
    }




    Smartphone(string phoneName, int priceUAH, string model, string phoneNumber, int memoryGb, int batteryMah) {
        this->phoneName = phoneName;
        this->price = priceUAH;
        this->model = model;
        this->phoneNumber = phoneNumber;
        this->memoryGb = memoryGb;
        this->batteryMah = batteryMah;
    }


};



class PhoneStore
{
public:
    vector<Smartphone> allPhones;
    void addPhone(Smartphone newPhone)
    {
        this->allPhones.push_back(newPhone);
    }

    void sales_sort()
    {
        int i, j;
        int sales = 0;
        for (i = 1; i < allPhones.size(); i++)
        {
            sales = allPhones[i].price;
            for (j = i - 1; j >= 0 && allPhones[j].price < sales; j--)
            {
                allPhones[j + 1] = allPhones[j];

            }
            allPhones[j + 1].price = sales;
        }
        cout << "\t phone have been sorted by price " << endl;
    }
    void advicePhone(int price) {
        vector<Smartphone> chosenPhones;
        sales_sort();
        for (int i = 0; i < allPhones.size(); i++) {
            if (allPhones[i].price < price) {
                if (i > 1) {

                    cout << allPhones[i - 1].model << endl;
                    cout << allPhones[i - 1].batteryMah << endl;
                    cout << allPhones[i - 1].phoneName << endl;
                    cout << allPhones[i - 1].memoryGb << endl;

                }
            }
        }
    }
};

int main() {
    PhoneStore appleStore;

    Smartphone iphone12 = Smartphone("Iphone ", 6000, "12", "+380974545007", 256, 4500);
    appleStore.addPhone(iphone12);

    Smartphone iphone10 = Smartphone("Iphone ", 3000, "10", "+380978492322", 128, 4200);
    appleStore.addPhone(iphone10);

    Smartphone iphone11 = Smartphone("Iphone ", 4500, "11", "+380978492228", 64, 4400);
    appleStore.addPhone(iphone11);

    appleStore.sales_sort();
    for (int i = 0; i < appleStore.allPhones.size();i++) {
        cout << appleStore.allPhones[i].price << endl;
    }

    appleStore.advicePhone(7000);

}