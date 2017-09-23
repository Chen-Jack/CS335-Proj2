#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H

#include<iostream>
#include<vector>
using namespace std;

class SequenceMap{
  public:
    //Rule of 5
    SequenceMap() = default; //Empty Constructor

    SequenceMap(const string &a_rec_seq, const string &an_enz_acro);  //Copy constructor
    // SequenceMap(const string &&a_rec_seq, const string &&an_enz_acro); //Move constructor

    SequenceMap& operator = (SequenceMap& map) = default; //Copy assignment
    SequenceMap& operator = (SequenceMap&& map) = default;  //Move assignment

    ~SequenceMap() = default;
    //End rule of 5

    bool operator < (const SequenceMap &rhs); //Compares recognition sequences

    void Merge(const SequenceMap& other_sequence);
    void PrintSequence(){
      cout << recognition_sequence_ << endl;
    }
    void PrintAcronyms(){
      for(string& acro : enzyme_acronyms_){
        cout << acro << " ";
      }
      cout << endl;
    }


  private:
    string	recognition_sequence_	;
    vector<string>	enzyme_acronyms_;
};

#endif