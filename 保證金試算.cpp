#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int initial_value_a = 34000;
int initial_value_b = 17000;
int maintain_value_a = 26000;
int maintain_value_b = 13000;
int liquidation_value_a = 25000;
int liquidation_value_b = 13000;

int init_sell_call(int premium, int strike, int pow) {
    int OTM_value = max((strike - pow) * 50, 0);
    if(strike - pow >= 500 && strike - pow < 1000)
        return (premium * 50 + max(initial_value_a - OTM_value, initial_value_b)) * 1.2;
    else if(strike - pow >= 1000)
        return (premium * 50 + max(initial_value_a - OTM_value, initial_value_b)) * 1.5;
    return premium * 50 + max(initial_value_a - OTM_value, initial_value_b);
}

int maintain_sell_call(int premium, int strike, int pow) {
    int OTM_value = max((strike - pow) * 50, 0);
    if(strike - pow >= 500 && strike - pow < 1000)
        return (premium * 50 + max(maintain_value_a - OTM_value, maintain_value_b)) * 1.2;
    else if(strike - pow >= 1000)
        return (premium * 50 + max(maintain_value_a - OTM_value, maintain_value_b)) * 1.5;
    return premium * 50 + max(maintain_value_a - OTM_value, maintain_value_b);
}

int liquidation_sell_call(int premium, int strike, int pow) {
    int OTM_value = max((strike - pow) * 50, 0);
    if(strike - pow >= 500 && strike - pow < 1000)
        return (premium * 50 + max(liquidation_value_a - OTM_value, liquidation_value_b)) * 1.2;
    else if(strike - pow >= 1000)
        return (premium * 50 + max(liquidation_value_a - OTM_value, liquidation_value_b)) * 1.5;
    return premium * 50 + max(liquidation_value_a - OTM_value, liquidation_value_b);
}

int init_sell_put(int premium, int strike, int pow) {
    int OTM_value = max((pow - strike) * 50, 0);
    if(pow - strike >= 500 && pow - strike < 1000)
        return (premium * 50 + max(initial_value_a - OTM_value, initial_value_b)) * 1.2;
    else if(pow - strike >= 1000)
        return (premium * 50 + max(initial_value_a - OTM_value, initial_value_b)) * 1.5;
    return premium * 50 + max(initial_value_a - OTM_value, initial_value_b);
}

int maintain_sell_put(int premium, int strike, int pow) {
    int OTM_value = max((pow - strike) * 50, 0);
    if(pow - strike >= 500 && pow - strike < 1000)
        return (premium * 50 + max(maintain_value_a - OTM_value, maintain_value_b)) * 1.2;
    else if(pow - strike >= 1000)
        return (premium * 50 + max(maintain_value_a - OTM_value, maintain_value_b)) * 1.5;
    return premium * 50 + max(maintain_value_a - OTM_value, maintain_value_b);
}

int liquidation_sell_put(int premium, int strike, int pow) {
    int OTM_value = max((pow - strike) * 50, 0);
    if(pow - strike >= 500 && pow - strike < 1000)
        return (premium * 50 + max(liquidation_value_a - OTM_value, liquidation_value_b)) * 1.2;
    else if(pow - strike >= 1000)
        return (premium * 50 + max(liquidation_value_a - OTM_value, liquidation_value_b)) * 1.5;
    return premium * 50 + max(liquidation_value_a - OTM_value, liquidation_value_b);
}

int init_stock_futures(double stock_price, int margin_type) {
    double init_type1 = 0.135, init_type2 = 0.162, init_type3 = 0.2025;
    switch(margin_type) {
        case 1:
            return round(stock_price * 2 * 1000 * init_type1);
        case 2:
            return round(stock_price * 2 * 1000 * init_type2);
        case 3:
            return round(stock_price * 2 * 1000 * init_type3);
    }
}

int maintain_stock_futures(double stock_price, int margin_type) {
    double maintain_type1 = 0.1035, maintain_type2 = 0.1242, maintain_type3 = 0.1553;
    switch(margin_type) {
        case 1:
            return round(stock_price * 2 * 1000 * maintain_type1);
        case 2:
            return round(stock_price * 2 * 1000 * maintain_type2);
        case 3:
            return round(stock_price * 2 * 1000 * maintain_type3);
    }
}

int liquidation_stock_futures(double stock_price, int margin_type) {
    double liquidation_type1 = 0.1, liquidation_type2 = 0.12, liquidation_type3 = 0.15;
    switch(margin_type) {
        case 1:
            return round(stock_price * 2 * 1000 * liquidation_type1);
        case 2:
            return round(stock_price * 2 * 1000 * liquidation_type2);
        case 3:
            return round(stock_price * 2 * 1000 * liquidation_type3);
    }
}

int main() {
    int n = 1;
    while(n) {
        cout << "*************" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Sell Call" << endl;
        cout << "2. Sell Put" << endl;
        cout << "3. Stock futures" << endl;
        cout << "*************" << endl;
        cout << "Enter your option: ";
        cin >> n;
        int premium, strike, pow, margin_type;
        double stock_price;
        switch(n) {
            case 0:
                break;
            case 1:
                cout << endl;
                cout << "Enter Pow index: ";
                cin >> pow;
                cout << "Enter premium: ";
                cin >> premium;
                cout << "Enter strike price: ";
                cin >> strike;
                Sleep(300);
                cout << endl;
                cout << "---------------------------" << endl;
                cout << "Initial margin: " << init_sell_call(premium, strike, pow) << endl;
                cout << "Maintainance margin: " << maintain_sell_call(premium, strike, pow) << endl;
                cout << "Liquidation margin: " << liquidation_sell_call(premium, strike, pow) << endl;
                cout << "---------------------------" << endl;
                cout << endl;
                Sleep(500);
                break;
            case 2:
                cout << endl;
                cout << "Enter Pow index: ";
                cin >> pow;
                cout << "Enter premium: ";
                cin >> premium;
                cout << "Enter strike price: ";
                cin >> strike;
                Sleep(300);
                cout << endl;
                cout << "---------------------------" << endl;
                cout << "Initial margin: " << init_sell_put(premium, strike, pow) << endl;
                cout << "Maintainance margin: " << maintain_sell_put(premium, strike, pow) << endl;
                cout << "Liquidation margin: " << liquidation_sell_put(premium, strike, pow) << endl;
                cout << "---------------------------" << endl;
                cout << endl;
                Sleep(500);
                break;
            case 3:
                cout << endl;
                cout << "Enter stock futures price: ";
                cin >> stock_price;
                cout << "Enter margin type (1, 2 or 3): ";
                cin >> margin_type;
                Sleep(300);
                cout << endl;
                cout << "---------------------------" << endl;
                cout << "Initial margin: " << init_stock_futures(stock_price, margin_type) << endl;
                cout << "Maintainance margin: " << maintain_stock_futures(stock_price, margin_type) << endl;
                cout << "Liquidation margin: " << liquidation_stock_futures(stock_price, margin_type) << endl;
                cout << "---------------------------" << endl;
                cout << endl;
                Sleep(500);
                break;
        }
    }
    Sleep(300);
    cout << endl;
    cout << "Exit..." << endl;
    cout << endl;
    Sleep(1000);
    return 0;
}