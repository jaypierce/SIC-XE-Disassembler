/*
 CS530
 Jaylan Pierce
 RedID: 822644713
 cssc3652
 Disassembler
 Professor Ben Shen 
 April 1, 2021
 */

//Includes
#include <cstdlib>
#include <string>
#include <exception>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <vector>
#include <algorithm>
#include "dissem.hpp"

//Creates a file to write to
FILE* createFile(string filename){
    FILE* fp;

    fp = fopen(filename.c_str(), "w");

    return fp;
}

//Converts hexadecimal to decimal
int hexToDecimal(string num){
    int x;
    stringstream ss;

    ss << hex << "0"+num;
    ss >> x;

    return x;
}

int signedHexToDecimal(string num){
    string leadF = "";

    if(num.substr(0,1) == "8" || num.substr(0,1) == "9" || num.substr(0,1) == "A" ||
        num.substr(0,1) == "B" || num.substr(0,1) == "C" || num.substr(0,1) == "D" ||
        num.substr(0,1) == "E" || num.substr(0,1) == "F")
            for(int i = num.length(); i < 9; i++) leadF += "F";

    leadF += num;

    int x = (int)strtol(leadF.c_str(), 0, 16);

    return x;
}

//Converts decimal to hexadecimal
string decimalToHex(int num){
    stringstream ss;

    ss << hex << num;

    string s (ss.str());

    transform(s.begin(), s.end(), s.begin(), ::toupper);

    while(s.length() < 6) s = "0"+s;
    if(s.length() > 6) s = s.substr(s.length()-6,6);
    return s;
}

//Converts an integer to its string representation
 string intToString(int num){
	stringstream ss;
	ss << num;
	return ss.str();
}

//Checks nixbpe bits
string bitChecker(string hex){
    int x = hexToDecimal(hex.substr(0,2));
    int y = hexToDecimal(hex.substr(2,1));
    string tmpStr = "";

    x %= 4;
    if(x==3)tmpStr += "11";
    if(x==2)tmpStr += "10";
    if(x==1)tmpStr += "01";

    if(y>=8){
        y-=8;
        tmpStr += "1";
    }
    else tmpStr += "0";
    if(y>=4){
        y-=4;
        tmpStr += "1";
    }
    else tmpStr += "0";
    if(y>=2){
        y-=2;
        tmpStr += "1";
    }
    else tmpStr += "0";
    if(y>=1){
        y-=1;
        tmpStr += "1";
    }
    else tmpStr += "0";

    return tmpStr;
}

//Checks to see if the input opcode is valid
bool validOpcode(string hex){

    string nixbpe = bitChecker(hex);

    if(nixbpe.substr(0,2)=="00") return false;
    if(nixbpe.substr(0,1)=="0" || nixbpe.substr(1,1)=="0")
        if(nixbpe.substr(2,1)=="1")return false;
    if(nixbpe.substr(3,1)=="1" && (nixbpe.substr(4,1)=="1" || nixbpe.substr(5,1)=="1")) return false;
    if(nixbpe.substr(4,1)=="1" && nixbpe.substr(5,1)=="1") return false;

    return true;
}

//Checks the format from the opcode
int checkFormat(string hex){
    int x = hexToDecimal(hex);
    x /= 4;

    //Commands
    switch(x){
        case 0://00
            return 3;
            break;
        case 1://04
            return 3;
            break;
        case 2://08
            return 3;
            break;
        case 3://0C
            return 3;
            break;
        case 4://10
            return 3;
            break;
        case 5://14
            return 3;
            break;
        case 6://18
            return 3;
            break;
        case 7://1C
            return 3;
            break;
        case 8://20
            return 3;
            break;
        case 9://24
            return 3;
            break;
        case 10://28
            return 3;
            break;
        case 11://2C
            return 3;
            break;
        case 12://30
            return 3;
            break;
        case 13://34
            return 3;
            break;
        case 14://38
            return 3;
            break;
        case 15://3C
            return 3;
            break;
        case 16://40
            return 3;
            break;
        case 17://44
            return 3;
            break;
        case 18://48
            return 3;
            break;
        case 19://4C
            return 3;
            break;
        case 20://50
            return 3;
            break;
        case 21://54
            return 3;
            break;
        case 22://58
            return 3;
            break;
        case 23://5C
            return 3;
            break;
        case 24://60
            return 3;
            break;
        case 25://64
            return 3;
            break;
        case 26://68
            return 3;
            break;
        case 27://6C
            return 3;
            break;
        case 28://70
            return 3;
            break;
        case 29://74
            return 3;
            break;
        case 30://78
            return 3;
            break;
        case 31://7C
            return 3;
            break;
        case 32://80
            return 3;
            break;
        case 33://84
            return 3;
            break;
        case 34://88
            return 3;
            break;
        case 35://8C
            return 0;
            break;
        case 36://90
            return 2;
            break;
        case 37://94
            return 2;
            break;
        case 38://98
            return 2;
            break;
        case 39://9C
            return 2;
            break;
        case 40://A0
            return 2;
            break;
        case 41://A4
            return 2;
            break;
        case 42://A8
            return 2;
            break;
        case 43://AC
            return 2;
            break;
        case 44://B0
            return 2;
            break;
        case 45://B4
            return 2;
            break;
        case 46://B8
            return 2;
            break;
        case 47://BC
            return 0;
            break;
        case 48://C0
            return 1;
            break;
        case 49://C4
            return 1;
            break;
        case 50://C8
            return 1;
            break;
        case 51://CC
            return 0;
            break;
        case 52://D0
            return 3;
            break;
        case 53://D4
            return 3;
            break;
        case 54://D8
            return 3;
            break;
        case 55://DC
            return 3;
            break;
        case 56://E0
            return 3;
            break;
        case 57://E4
            return 0;
            break;
        case 58://E8
            return 3;
            break;
        case 59://EC
            return 3;
            break;
        case 60://F0
            return 1;
            break;
        case 61://F4
            return 1;
            break;
        case 62://F8
            return 1;
            break;
    }

    return 0;
}

//Converts hex opcode to its command
string hexToCommand(string hex){
    int x = hexToDecimal(hex);
    x /= 4;

    //Commands
    switch(x){
        case 0://00
            return "LDA   ";
            break;
        case 1://04
            return "LDX   ";
            break;
        case 2://08
            return "LDL   ";
            break;
        case 3://0C
            return "STA   ";
            break;
        case 4://10
            return "STX   ";
            break;
        case 5://14
            return "STL   ";
            break;
        case 6://18
            return "ADD   ";
            break;
        case 7://1C
            return "SUB   ";
            break;
        case 8://20
            return "MUL   ";
            break;
        case 9://24
            return "DIV   ";
            break;
        case 10://28
            return "COMP  ";
            break;
        case 11://2C
            return "TIX   ";
            break;
        case 12://30
            return "JEQ   ";
            break;
        case 13://34
            return "JGT   ";
            break;
        case 14://38
            return "JLT   ";
            break;
        case 15://3C
            return "J     ";
            break;
        case 16://40
            return "AND   ";
            break;
        case 17://44
            return "OR    ";
            break;
        case 18://48
            return "JSUB  ";
            break;
        case 19://4C
            return "RSUB  ";
            break;
        case 20://50
            return "LDCH  ";
            break;
        case 21://54
            return "STCH  ";
            break;
        case 22://58
            return "ADDF  ";
            break;
        case 23://5C
            return "SUBF  ";
            break;
        case 24://60
            return "MULF  ";
            break;
        case 25://64
            return "DIVF  ";
            break;
        case 26://68
            return "LDB   ";
            break;
        case 27://6C
            return "LDS   ";
            break;
        case 28://70
            return "LDF   ";
            break;
        case 29://74
            return "LDT   ";
            break;
        case 30://78
            return "STB   ";
            break;
        case 31://7C
            return "STS   ";
            break;
        case 32://80
            return "STF   ";
            break;
        case 33://84
            return "STT   ";
            break;
        case 34://88
            return "COMPF ";
            break;
        case 35://8C
            return "ERROR ";
            break;
        case 36://90
            return "ADDR  ";
            break;
        case 37://94
            return "SUBR  ";
            break;
        case 38://98
            return "MULR  ";
            break;
        case 39://9C
            return "DIVR  ";
            break;
        case 40://A0
            return "COMPR ";
            break;
        case 41://A4
            return "SHIFTL";
            break;
        case 42://A8
            return "SHIFTR";
            break;
        case 43://AC
            return "RMO   ";
            break;
        case 44://B0
            return "SVC   ";
            break;
        case 45://B4
            return "CLEAR ";
            break;
        case 46://B8
            return "TIXR  ";
            break;
        case 47://BC
            return "ERROR ";
            break;
        case 48://C0
            return "FLOAT ";
            break;
        case 49://C4
            return "FIX   ";
            break;
        case 50://C8
            return "NORM  ";
            break;
        case 51://CC
            return "ERROR ";
            break;
        case 52://D0
            return "LPS   ";
            break;
        case 53://D4
            return "STI   ";
            break;
        case 54://D8
            return "RD    ";
            break;
        case 55://DC
            return "WD    ";
            break;
        case 56://E0
            return "TD    ";
            break;
        case 57://E4
            return "ERROR ";
            break;
        case 58://E8
            return "STSW  ";
            break;
        case 59://EC
            return "SSK   ";
            break;
        case 60://F0
            return "SIO   ";
            break;
        case 61://F4
            return "HIO   ";
            break;
        case 62://F8
            return "TIO   ";
            break;
    }

    return "ERROR";
}

//Finds address in symbol table
Symbol* findAddressInSym(Symbol *symPtr, string address){
    while(symPtr!=nullptr){
        if(symPtr->getValue() == address)return symPtr;
        symPtr = symPtr->next;
    }
    return symPtr;
}

//Finds address in literal table
Literal* findAddressinLit(Literal *litPtr, string address){
    while(litPtr!=nullptr){
        if(litPtr->getAddress() == address)return litPtr;
        litPtr = litPtr->next;
    }
    return litPtr;
}

//Reads in from symbol table
Symbol* toSymbol(Symbol* head, FILE *fp){
    int c = 0;
    string tmpName = "";
    string tmpValue = "";
    char tmpFlag;

    if(feof(fp))return head;
    for(int i = 0; i<2; i++){
        c = fgetc(fp);
        if(c != 10) i--;
    }

    while(!feof(fp)){
        for(int i = 0; i<6; i++){
            c =fgetc(fp);
            if(i==0 && c == 10)return head;
            char s = static_cast<char>(c);
            tmpName += s;
        }

        c =fgetc(fp);
        c =fgetc(fp);

        for(int i = 0; i<6; i++){
            c =fgetc(fp);
            char s = static_cast<char>(c);
            tmpValue += s;
        }

        c =fgetc(fp);
        c =fgetc(fp);

        c = fgetc(fp);
        tmpFlag = static_cast<char>(c);

        Symbol *tmpSym = new Symbol(tmpName, tmpValue, tmpFlag, nullptr);
        if(head == nullptr) head = tmpSym;
        else{
            Symbol *symPtr = head;
            while(symPtr->next !=nullptr) symPtr = symPtr->next;
            symPtr->next = tmpSym;
        }
        tmpName = "";
        tmpValue = "";

        c = fgetc(fp);
    }

    return head;
}

//Reads in from literal table
Literal* toLiteral(Literal* &head, FILE *fp){
    int c = 0;
    string tmpName = "";
    string tmpAddr = "";
    string tmpLen = "";

    if(feof(fp))return head;
    for(int i = 0; i<2; i++){
         c = fgetc(fp);
        if(c != 10) i--;
    }

    while(!feof(fp)){
        c = fgetc(fp);

        if(c == -1)return head;

        while(c == 32)c = fgetc(fp);

        while(c != 32){
            char s = static_cast<char>(c);
            tmpName += s;
            c = fgetc(fp);
        }

        while(c == 32)c = fgetc(fp);

        while(c != 32){
            char s = static_cast<char>(c);
            tmpLen += s;
            c = fgetc(fp);
        }

        while(c == 32)c = fgetc(fp);

        for(int i = 0; i<6; i++){
            char s = static_cast<char>(c);
            tmpAddr += s;
            c =fgetc(fp);
        }

        // Save to literal
        Literal *tmpLit = new Literal(tmpName, tmpAddr, tmpLen, nullptr);
        if(head == nullptr) head = tmpLit;
        else{
            Literal *litPtr = head;
            while(litPtr->next !=nullptr) litPtr = litPtr->next;
            litPtr->next = tmpLit;
        }
        head = tmpLit;
        tmpName = "";
        tmpAddr = "";
        tmpLen = "";

        while (c==32)c = fgetc(fp);

    }

    return head;
}

//Reads .obj file
vector<string> readObj(FILE *fp, Symbol *symHead, Literal *litHead){

    vector<string> tmpVector;
    string tmpVar = "";
    int tmpFormat = 0;
    int address = 0;

    int c = fgetc(fp);

    tmpVector.push_back("H");
    for(int i=0; i<18; i++){
        c= fgetc(fp);
        char s = static_cast<char>(c);
        tmpVar += s;
    }

    address = hexToDecimal(tmpVar.substr(6,6));

    tmpVector.push_back(tmpVar);
    tmpVar = "";

    while(c!=10)c=fgetc(fp);
    c = fgetc(fp);

    //Text Record
    tmpVector.push_back("T");
    while(c == 84){

        for(int i=0;i<9;i++)c=fgetc(fp);

        while(c!=10){

            if(litHead!=nullptr && litHead->getDecAddress() <= address){//LTORG
                for(int i=0; i < litHead->getDecLength();i++){
                    char s = static_cast<char>(c);
                    tmpVar += s;
                    c=fgetc(fp);
                }

                tmpVector.push_back(tmpVar);
                tmpVar="";
                address += litHead->getDecLength()/2;
                litHead = litHead->next;
                continue;
            }

            for(int i=0;i<2;i++){
                char s = static_cast<char>(c);
                tmpVar += s;
                c=fgetc(fp);
            }

            tmpFormat = checkFormat(tmpVar);


            if(tmpFormat == 3){//Format 3/4
                int j = 3;

                char s = static_cast<char>(c);
                tmpVar += s;
                c=fgetc(fp);

                if(s == '1'||s == '3'||s == '5'||s == '7'||s == '9'||s == 'B'||s == 'D'||s == 'F'){//Format 4
                    j=5;
                    address+=1;
                }

                for(int i=0; i<j; i++){
                    s= static_cast<char>(c);
                    tmpVar += s;
                    c=fgetc(fp);
                }
                tmpVector.push_back(tmpVar);
                tmpVar = "";
                address+=3;
            }
            else if(tmpFormat == 2){// Format 2
                char s = static_cast<char>(c);
                tmpVar += s;
                c=fgetc(fp);

                s = static_cast<char>(c);
                tmpVar += s;
                c=fgetc(fp);

                tmpVector.push_back(tmpVar);
                tmpVar = "";
                address+=2;
            }
            else if(tmpFormat == 1){
                tmpVector.push_back(tmpVar);
                tmpVar = "";
                address+=1;
            }
        }
        c=fgetc(fp);
    }

    // Modification Record
    tmpVector.push_back("M");
    while(c==77){
        fprintf(fp, "%d", c);
        c= fgetc(fp);
        while(c!=10){
            char s = static_cast<char>(c);
            tmpVar += s;
            c= fgetc(fp);
        }
        tmpVector.push_back(tmpVar);
        tmpVar = "";
        c= fgetc(fp);
    }

    //End Record
    tmpVector.push_back("E");
    for(int i=0; i<6; i++){
        c= fgetc(fp);
        char s = static_cast<char>(c);
        tmpVar += s;
    }

    tmpVector.push_back(tmpVar);
    tmpVar = "";

    return tmpVector;
}

//Gets rid of extra spaces
 string extraSpaces(string s){

     while(s.substr(s.length()-1,1) == " ") s = s.substr(0, s.length()-1);

     return s;
}

//Converts decimal address to hex address
void decToHexAddress(FILE *fp, int address){

    string s = decimalToHex(address);

    fprintf(fp, "%s  ", s.substr(s.length()-4,4).c_str());
}

//Writes opcode
void writeOpcode(FILE *fp, string opcode, int column){

    while(column < 26){
        fputc(32, fp);
        column++;
    }

    fprintf(fp, "%s", opcode.c_str());
}

//Writes .lst file
void outputWrite(FILE *fp, vector<string> objVector, Symbol *symHead, Literal *litHead){

    // Inserts 1st line of SIC program
    fprintf(fp, "%s  ", objVector[1].substr(8,4).c_str());
    fprintf(fp, "%s", objVector[1].substr(0,6).c_str());
    fprintf(fp, "   START   ");
    fprintf(fp, "%s", objVector[1].substr(6,1).c_str());
    fputc(10, fp);

    // Text records
    int index = 3;
    int address = hexToDecimal(objVector[1].substr(6,6));;
    int baseAddress = 0;
    int column = 0;
    bool baseBool = false;
    Symbol *symPtr = symHead;
    Literal *litPtr = litHead;
    string nixbpeStr = "";
    while(objVector[index] != "M"){

        decToHexAddress(fp, address);

        //First 8 columns
        if(symPtr != nullptr && symPtr->getDecValue() == address){
            fprintf(fp, "%s  ", symPtr->getName().c_str());
            symPtr = symPtr->next;
        }
        else fprintf(fp, "        ");
        column += 8;

        //Column 9
        if(checkFormat(objVector[index].substr(0,2))==3 && validOpcode(objVector[index].substr(0,3))){
            nixbpeStr = bitChecker(objVector[index].substr(0,3));
            if(nixbpeStr.substr(5,1) == "1") fprintf(fp, "+");
            else fprintf(fp," ");
        }else fprintf(fp, " ");
        column ++;

        //Columns 10-16
        if(litPtr!=nullptr && litPtr->getDecAddress()==address){
            fprintf(fp, "LTORG  ");
            fputc(10, fp);
            column = 0;
            while(litPtr!=nullptr && litPtr->getDecAddress()==address){
                decToHexAddress(fp, address);

                fprintf(fp, "*       %s", litPtr->getName().c_str());
                column += 7 + litPtr->getName().length();

                writeOpcode(fp, objVector[index], column);

                fputc(10, fp);
                column = 0;

                address += objVector[index++].length()/2;
                litPtr = litPtr->next;
            }
            continue;
        }
        fprintf(fp, "%s ", hexToCommand(objVector[index].substr(0,2)).c_str());
        column += hexToCommand(objVector[index].substr(0,2)).length();

        //Column 17
        if(checkFormat(objVector[index].substr(0,2))==3){
            nixbpeStr = bitChecker(objVector[index].substr(0,3));
            if(nixbpeStr.substr(0,1)=="0") fputc(35, fp);
            else if(nixbpeStr.substr(1,1)=="0") fputc(64, fp);
            else fputc(32, fp);
            column++;
        }

        // Base Register checker
        if(hexToCommand(objVector[index].substr(0,2))=="LDB   "){
            int checkNibbles = 3;
            int checkAddress = 0;
            if(nixbpeStr.substr(5,1)=="1") checkNibbles = 5;
            else if(nixbpeStr.substr(4,1)=="1") checkAddress = address;
            else if(nixbpeStr.substr(3,1)=="1") checkAddress = baseAddress;

            if(nixbpeStr.substr(1,1)=="1") baseAddress = checkAddress + hexToDecimal(objVector[index].substr(3,checkNibbles));

        }

        //Columns 18-35
        if(objVector[index].substr(0,2)=="4F"){
            writeOpcode(fp, objVector[index], column);
            fputc(10, fp);
        }
        else if(checkFormat(objVector[index].substr(0,2))==3){ // Format 3/4
            if(nixbpeStr.substr(4,1)=="0"){ 
                int tmpAddress = -1;

                if(nixbpeStr.substr(4,1)=="1") tmpAddress = address + 3 + signedHexToDecimal(objVector[index].substr(3,3)); //pc
                else if(nixbpeStr.substr(3,1)=="1") tmpAddress = baseAddress + hexToDecimal(objVector[index].substr(3,3)); //base 
                else tmpAddress = hexToDecimal(objVector[index].substr(3,3)); //neither

                Symbol *tmpSymPtr = findAddressInSym(symHead, decimalToHex(tmpAddress));
                Literal *tmpLitPtr = findAddressinLit(litHead, decimalToHex(tmpAddress-3));

                if(tmpSymPtr != nullptr){
                    string s = extraSpaces(tmpSymPtr->getName());
                    column -= tmpSymPtr->getName().length() - s.length();
                    fprintf(fp, "%s", s.c_str());
                    column += tmpSymPtr->getName().length();
                }
                else if(tmpLitPtr != nullptr){
                    string s = extraSpaces(tmpLitPtr->getName());
                    column -= tmpLitPtr->getName().length() - s.length();
                    fprintf(fp, "%s", s.c_str());
                    column += tmpLitPtr->getName().length();
                }
                else{
                    fprintf(fp, "%s", objVector[index].substr(3,3).c_str());
                    column += objVector[index].substr(3,3).length();
                }

            }
            else { // if not relative
                Symbol *tmpSymPtr = findAddressInSym(symHead, "0"+objVector[index].substr(3,5));
                Literal *tmpLitPtr = findAddressinLit(litHead, "0"+objVector[index].substr(3,5));

                if(tmpSymPtr != nullptr){
                    string s = extraSpaces(tmpSymPtr->getName());
                    column -= tmpSymPtr->getName().length() - s.length();
                    fprintf(fp, "%s", s.c_str());
                    column += tmpSymPtr->getName().length();
                }
                else if(tmpLitPtr != nullptr){
                    string s = extraSpaces(tmpLitPtr->getName());
                    column -= tmpLitPtr->getName().length() - s.length();
                    fprintf(fp, "%s", s.c_str());
                    column += tmpLitPtr->getName().length();
                }
                else{
                    fprintf(fp, "%s", objVector[index].substr(3,5).c_str());
                    column += objVector[index].substr(3,5).length();
                }
            }

            //Checking if indexed
            if(nixbpeStr.substr(2,1)=="1"){
                fprintf(fp, ",X");
                column+=2;
            }

            writeOpcode(fp, objVector[index], column);

            fputc(10, fp);
            column = 0;
        }
        //Format 2
        else if(checkFormat(objVector[index].substr(0,2))==2){
            column ++;
            int x = hexToDecimal(objVector[index].substr(2,1));
            switch(x){
                case 0:
                    fprintf(fp, "A");
                    break;
                case 1:
                    fprintf(fp, "X");
                    break;
                case 2:
                    fprintf(fp, "L");
                    break;
                case 3:
                    fprintf(fp, "B");
                    break;
                case 4:
                    fprintf(fp, "S");
                    break;
                case 5:
                    fprintf(fp, "T");
                    break;
                case 6:
                    fprintf(fp, "F");
                    break;
                case 8:
                    fprintf(fp, "PC");
                    break;
                case 9:
                    fprintf(fp, "SW");
                    break;
            }
            if(objVector[index].substr(0,2)!="B0"&&objVector[index].substr(0,2)!="B4"&&objVector[index].substr(0,2)!="B8"){
                column += 2;
                x = hexToDecimal(objVector[index].substr(3,1));
                switch(x){
                    case 0:
                        fprintf(fp, ",A");
                        break;
                    case 1:
                        fprintf(fp, ",X");
                        break;
                    case 2:
                        fprintf(fp, ",L");
                        break;
                    case 3:
                        fprintf(fp, ",B");
                        break;
                    case 4:
                        fprintf(fp, ",S");
                        break;
                    case 5:
                        fprintf(fp, ",T");
                        break;
                    case 6:
                        fprintf(fp, ",F");
                        break;
                    case 8:
                        fprintf(fp, ",PC");
                        break;
                    case 9:
                        fprintf(fp, ",SW");
                        break;
                }
            }
            writeOpcode(fp, objVector[index], column);
            fputc(10, fp);
            column = 0;
        }
        else if(checkFormat(objVector[index].substr(0,2))==1){
            writeOpcode(fp, objVector[index], column);
            fputc(10, fp);
            column = 0;
        }

        //Check to see if next command is base relative or PC relative
        if(objVector[index+1] != "M" && checkFormat(objVector[index+1].substr(0,2))==3 && checkFormat(objVector[index].substr(0,2))==3){
            if(bitChecker(objVector[index+1].substr(0,3)).substr(3,1)=="1" && !baseBool){
                decToHexAddress(fp, address);
                string name = findAddressInSym(symHead, decimalToHex(baseAddress))->getName();
                fprintf(fp, "         BASE    %s", name.c_str());
                fputc(10, fp);
                column = 0;
                baseBool = true;
            }
            else if(bitChecker(objVector[index+1].substr(0,3)).substr(4,1)=="1" && baseBool){
                decToHexAddress(fp, address);
                fprintf(fp, "         NOBASE");
                fputc(10, fp);
                column = 0;
                baseBool = false;
            }

        }
        address += objVector[index++].length()/2;
    }

    Symbol *tmpSym = symHead;

    while(tmpSym!=nullptr){

        if(tmpSym->getDecValue() == address){

            int RESBlength = 0;
            int RESWlength = 0;

            if(tmpSym->next != nullptr) RESBlength = tmpSym->next->getDecValue() - tmpSym->getDecValue();
            else RESBlength = hexToDecimal(objVector[1].substr(12,6)) - tmpSym->getDecValue();
            if(RESBlength % 3 == 0) RESWlength = RESBlength / 3;
            string RESBstring = intToString(RESBlength);
            string RESWstring = intToString(RESWlength);

            decToHexAddress(fp, address);
            if((RESBlength) % 3 == 0) fprintf(fp, "%s   RESW    %s", tmpSym->getName().c_str() ,RESWstring.c_str());
            else fprintf(fp, "%s   RESB    %s", tmpSym->getName().c_str() ,RESBstring.c_str());
            fputc(10, fp);
            address += RESBlength;
        }

        tmpSym = tmpSym->next;
    }

    //End
    tmpSym = findAddressInSym(symHead, objVector[objVector.size()-1]);

    fprintf(fp, "      ");

    if(tmpSym != nullptr) fprintf(fp, "         END     %s", tmpSym->getName().c_str());
    else fprintf(fp, "         END   %s", objVector[objVector.size()-1].c_str());
    fputc(10, fp);

}

//Main function
int main(int argc, char* argv[]){

    //Reads in .obj and .sym files
    string objFile (argv[1]);
    string symFile (argv[2]);
    string lstFile = "out.lst";

    Symbol *symHead = nullptr;
    Literal *litHead = nullptr;
    FILE *fp = fopen(symFile.c_str(), "r");
    symHead = toSymbol(symHead, fp);
    litHead = toLiteral(litHead, fp);
    fclose(fp);

    //Read in .obj file
    FILE *fpObj = fopen(objFile.c_str(), "r");
    vector<string> objectVector = readObj(fpObj, symHead, litHead);
    fclose(fpObj);

    //Writing to output(.lst) file
    FILE* lstFp = createFile(lstFile);
    outputWrite(lstFp, objectVector, symHead, litHead);
    fclose(lstFp);

    return 0;
}
