#include <iostream>
#include "BinarySearchTree.h"
#include "SequenceMap.h"
using namespace std;

int main(){

    string a = "red";
    string b = "blue";

    SequenceMap c{a,b};
    // string line = "AarI/CACCTGCNNNN'NNNN/'NNNNNNNNGCAGGTG//";

    // string&& acro = line.substr(0, line.find('/'));
    // line.erase(0, line.find('/')+1);
    // cout << "acro: " << acro << endl;
    // cout << "Seq: ";
    // while(line != "/"){
    //     //cout << "Line is now "<<line << endl;
    //   string&& sequence = line.substr(0,line.find('/'));
    //   line.erase(0, line.find('/')+1);

    //   cout << sequence << " ";
    // }
    // cout << endl;
    return 0;
}
    

