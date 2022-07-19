/*
 CS530
 Jaylan Pierce
 RedID: 822644713
 cssc3652
 Disassembler
 Professor Ben Shen 
 April 1, 2021
 */

#include <iostream>

using namespace std;

//Converts Hex to Decimal
int hexToDecimal(string num);

//Converts Decimal to Hex
string decimalToHex(int num);


//Symbol Table data structure
class Symbol{
    private:
        string name;
        char flag;
        string value;
        int decValue;

    public:
    	Symbol *next;
        Symbol(string nam, string val, char flg, Symbol *nextSym){
            this->name = nam;
            this->flag = flg;
            this->value = val;
            this->decValue = hexToDecimal(val);
            this->next = nextSym;
        }

        char getFlag(){
            return this->flag;
        }

        string getValue(){
            return this->value;
        }

        int getDecValue(){
            return this->decValue;
        }

        void setNext(Symbol *nextSym){
            this->next = nextSym;
        }

        string getName(){
            return this->name;
        }
};


//Literal Table data structure
class Literal{
    private:
        string name;
        string address;
        string length;
        int decAddress;
        int decLength;

    public:
        Literal *next;
        Literal(string nam, string addy, string len, Literal *nextLit){
            this->name = nam;
            this->address = addy;
            this->length = len;
            this->decAddress = hexToDecimal(addy);
            this->decLength = hexToDecimal(len);
            this->next = nextLit;
        }

        string getAddress(){
            return this->address;
        }

        string getLength(){
            return this->length;
        }

        int getDecAddress(){
            return this-> decAddress;
        }

        int getDecLength(){
            return this-> decLength;
        }

        void setNext(Literal *nextLit){
            this->next = nextLit;
        }

        string getName(){
            return this->name;
        }
};




