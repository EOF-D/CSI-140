/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Assignment Week Six- Investment
Date Assigned:           10/1/23
Due Date:                11/19/23

Description:
Investment calculator for stocks

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
and consequences of plagiarism and acknowledge that the assessor of this
assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic
staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which
may then retain a copy of this assignment on its database for the purpose of
future plagiarism checking)
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string in, out;
  string stock_name = "";

  double buy_cost, buy_commission;
  double sell_cost, sell_commission;
  int bought_shares, sold_shares;

  double total_buying_amount, total_buying_commission, total_selling_amount,
      total_selling_commission, grand_profit = 0.0;

  cout << "Enter input file: ";
  cin >> in;

  ifstream input(in, ios::out);
  if (!input) {
    cout << "Failed to open: " << in << endl;
    return 1;
  }

  cout << "Enter output file: ";
  cin >> out;

  ofstream output(out, ios::out);
  if (!output) {
    cout << "Failed to open: " << out << endl;
    return 1;
  }

  do {
    getline(input, stock_name);

    if (input.eof()) {
      break;
    }

    input >> buy_cost >> buy_commission >> bought_shares;
    input >> sell_cost >> sell_commission >> sold_shares;

    double profit;
    profit = sold_shares * sell_cost - sell_commission;
    profit = profit - bought_shares * buy_cost + buy_commission;

    total_buying_amount += buy_cost * bought_shares;
    total_buying_commission += buy_commission;
    total_selling_amount += sell_cost * sold_shares;
    total_selling_commission += sell_commission;
    grand_profit += profit;

    output << left << setw(20) << stock_name << right << setw(15) << buy_cost
           << setw(15) << buy_commission << setw(15)
           << (sell_cost * sold_shares) << setw(15) << sell_commission
           << setw(15) << profit << endl;

    input.ignore();
  } while (!input.eof());

  cout << right << setw(15) << "Total buying amount: " << total_buying_amount
       << endl;

  cout << right << setw(15)
       << "Total buying commission: " << total_buying_commission << endl;

  cout << right << setw(15) << "Total selling amount: " << total_selling_amount
       << endl;

  cout << right << setw(15)
       << "Total selling commission: " << total_selling_commission;

  cout << right << setw(15) << "\nGrand profit: " << grand_profit << endl;

  input.close();
  output.close();
}