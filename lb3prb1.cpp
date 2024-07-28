#include <iostream>
using namespace std;

#define CONVERSION_RATE 98.51

class exchange_money {
    int rupees;
    int paisa;

public:
    void setCurrency() {
        cout << "Enter money in Nepali rupees and paisa:" << endl;
        cin >> rupees >> paisa;
    }

    float toTotalRupees()  {
        return rupees + (paisa / 100.0);
    }

    float toUSD()  {
        float totalRupees = toTotalRupees();
        return totalRupees / CONVERSION_RATE;
    }

    void displayUSD()  {
        float totalUSD = toUSD();
        int dollars = static_cast<int>(totalUSD);
        int cents = static_cast<int>((totalUSD - dollars) * 100);
        cout << "Equivalent US currency: " << dollars << " dollars and " << cents << " cents." << endl;
    }
};

int main() {
    exchange_money exchange;
    exchange.setCurrency();
    exchange.displayUSD();
    return 0;
}
