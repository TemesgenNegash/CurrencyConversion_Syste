// Currency_Conversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double conversionRates[4][4] = {
    {1.0, 0.96, 0.81, 155.18},   // USD to USD, EUR, GBP, JPY
    {1.04, 1.0, 0.84, 160.81},  // EUR to USD, EUR, GBP, JPY
    {1.24, 1.20, 1.0, 192.30},  // GBP to USD, EUR, GBP, JPY
    {0.0064, 0.0062, 0.0052, 1.0} // JPY to USD, EUR, GBP, JPY
};
int getCurrIndex(string currency) {
    if (currency == "USD") return 0;
    if (currency == "EUR") return 1;
    if (currency == "GBP") return 2;
    if (currency == "JPY") return 3;
    return -1;
}
double convertCurr(double amount, int fromIndex, int toIndex) {
    return amount * conversionRates[fromIndex][toIndex];
}

int main() {
    double amount;
    string fromCurrency, toCurrency;

    cout << "Enter amount you want to convert $: ";
    cin >> amount;

    cout << "Convert from (USD, EUR, GBP, JPY): ";
    cin >> fromCurrency;
    cout << "Convert to (USD, EUR, GBP, JPY): ";
    cin >> toCurrency;

    int fromIndex = getCurrIndex(fromCurrency);
    int toIndex = getCurrIndex(toCurrency);

    if (fromIndex == -1 || toIndex == -1) {
        cout << "Error, please use correct conversion selected." << endl;
        return 1;
    }
    double rate = conversionRates[fromIndex][toIndex];
    double convertedAmount = convertCurr(amount, fromIndex, toIndex);
    cout << fixed << setprecision(2) << amount << " " << fromCurrency << " is " << convertedAmount << " " << toCurrency << endl;

    cout << " Temporary adjusted conversion rate for black friday " << endl;
    if (fromCurrency == "USD" && toCurrency == "EUR") {
        conversionRates[0][1] = 0.80;
        rate = conversionRates[fromIndex][toIndex];
        convertedAmount = convertCurr(amount, fromIndex, toIndex);
        cout << "with promotional rate: " << amount << " " << fromCurrency << " is " << convertedAmount << " " << toCurrency << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
