/**
 * Author: Bryan P. Saavedra
 * Section: BSCS 1B
 * Created: 2026-02-20
 */

#include <iostream>
#include <cctype>
#include <vector>
#include <iomanip> // I used this library to show the .00 for each number
using namespace std;


// Function to Handle Out of Bounds Inputs
int getValidInputs(string str, int min, int max){
    int value;
    do {
        cout << str;
        cin >> value;
        if (value < min || value > max)
            cout << "Invalid Input! Please enter a number between " << min << " and " << max << ".\n";
    } while (value < min || value > max);
    return value;
}

// Function to Handle Invalid Input (Y/N)
char getValidYesOrNo(string str, char y, char n){
    char value;
    do {
        cout << str;
        cin >> value;
        if (value != y && value != n)
            cout << "Invalid Input! Please enter a letter between " << y << " and " << n << ".\n";
    } while (value != n && value != y);
    return value;
}

// Function to Calculate and Output Total Sales Per Person, Total Sales Per Product and Grand Total 
void tableOutput(vector<vector<double>> salesTable, int noOfRows, int noOfCols){
    vector<double> totalSalesPerProduct;
    vector<double> totalSalesPerSalesPerson;

    // Total Sales Per Product
    for(int i = 0; i < noOfCols; i++){
        double total = 0;
        for(int j = 0; j < noOfRows; j++){
            total += salesTable[j][i];
        }
        totalSalesPerSalesPerson.push_back(total);
    }
    // Total Sales Per Salesperson
    for(int i = 0; i < noOfRows; i++){
        double total = 0;
        for(int j = 0; j < noOfCols; j++){
            total += salesTable[i][j];
        }
        totalSalesPerProduct.push_back(total);
    }
    // Overall Total for Totals of Sales Per Product
    double GrandTotal = 0;
    for(int i = 0; i < totalSalesPerProduct.size(); i++){
        GrandTotal += totalSalesPerProduct[i];
    }
    // This is where will be the output shown
    cout << "\t\t\t\t\tSalesperson\t\t" <<endl;
    cout << "Product\t\t1\t\t2\t\t3\t\t4\t\tTotal"<<endl;
    cout << "-------------------------------------------------------------------------------------"<<endl;
    for(int i = 0; i < noOfRows; i++){
        cout << i+1<<"\t\t";
        for(int j = 0; j < noOfCols; j++){
            cout<<fixed<<setprecision(2)<<salesTable[i][j]<<"\t\t";
        }
        cout <<fixed<<setprecision(2)<<totalSalesPerProduct[i]<<endl;
    }

    cout << "-------------------------------------------------------------------------------------"<<endl;
    cout << "Total\t\t";
    for(int i = 0; i < noOfCols; i++){
        cout <<fixed<<setprecision(2)<<totalSalesPerSalesPerson[i]<<"\t\t";
    }
    cout <<fixed<<setprecision(2)<<GrandTotal<<endl;

}


int main() {
    const int NO_OF_PRODUCTS = 5; //Rows
    const int NO_OF_SALESPEOPLE = 4; // Columns
    char choice;
    
    do{
        char option;
        system("cls");
        vector sales(NO_OF_PRODUCTS,vector<double>(NO_OF_SALESPEOPLE, 0)); 
        do{
            int salesperson, product;
            double amount;
            cout <<endl;
            salesperson = getValidInputs("Select Salesperson [1-4]: ", 1, 4);           
            product = getValidInputs("Select Product [1-5]: ", 1, 5);
            cout << "Enter Amount: ";
            cin >> amount;
            cout << endl;

            sales[product-1][salesperson-1] += amount;

            option = getValidYesOrNo("Do you want to add another entry [y/n]? : ", 'y', 'n');
            


        }while(tolower(option) == 'y');

        cout <<endl;
        tableOutput(sales, NO_OF_PRODUCTS, NO_OF_SALESPEOPLE);

        choice = getValidYesOrNo("\nDo you want to run the program again? :" , 'y', 'n');

    }while(tolower(choice) == 'y');



    return 0;
}

