#include <iostream>
#include "bank_account.hpp"
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <cmath>


int main() 
{
    return 0;
}


void deposit(double &balance, double amount){
    balance+=amount;
}

bool withdraw(double &balance, double amount){
    if(amount>balance){
    return false;
}
    else{
        balance-=amount;
        return true;
    }
}

void overdraft(double &balance, double amount){

    balance-=35+amount;
}

double interest_for_month(double balance, double apr){
    apr = apr/12;
    int balance1 = balance *100*apr/100;
    return balance1/100.0;

}

void string_date_to_int_ptrs(std::string date,int *year, int *month, int *day){
    *year=std::stoi(date.substr(0,4));
    *month=std::stoi(date.substr(5,2));
    *day=std::stoi(date.substr(8,2));

}

void string_date_to_ints(std::string date,int &year, int &month, int &day){
    string_date_to_int_ptrs(date,&year,&month,&day);
    

}

int number_of_first_of_months(std::string start, std::string end){
    int year1=0;
    int month1=0;
    int day1=0;
    string_date_to_ints(start,year1,month1,day1);
    int year2=0;
    int month2=0;
    int day2=0;
    string_date_to_ints(end,year2,month2,day2);
    return (year2*12+month2)-(year1*12+month1);
    
}
double interest_earned(double balance,double apr, std::string start, std::string end){
    int b = number_of_first_of_months(start,end);

    /*double x=balance*pow((1+apr/12/100),b)-balance;
    std::cout<<"x = "<<x<<std::endl;
    return ((int) (x*100))/100.0;*/
    double totalbal=balance;
    for(int i=0; i<b ; i++){
        totalbal+=interest_for_month(totalbal,apr);
    }
    return totalbal-balance;
}


