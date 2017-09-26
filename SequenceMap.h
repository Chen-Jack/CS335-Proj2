#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H

#include<iostream>
#include<vector>
using namespace std;

class SequenceMap{
  public:
    //Rule of 5
    SequenceMap() = default; //Empty Constructor
    SequenceMap(const string& a_rec_seq): recognition_sequence_{a_rec_seq}{};
    SequenceMap(const string &a_rec_seq, const string &an_enz_acro){  //Argument constructor
      recognition_sequence_ = a_rec_seq;
      enzyme_acronyms_.push_back(an_enz_acro);
    } 

    SequenceMap(const SequenceMap& map) = default; //Copy constructor
    SequenceMap(SequenceMap&& map) = default;//Move constructor
    SequenceMap& operator = (SequenceMap& map) = default; //Copy assignment
    SequenceMap& operator = (SequenceMap&& map) = default;  //Move assignment

    ~SequenceMap() = default;
    //End rule of 5

    bool operator < (const SequenceMap &rhs){//Compares recognition sequences
      if (recognition_sequence_ < rhs.recognition_sequence_){
        return true;
      }
      else{
        return false;
      }
    }
    const bool operator < (SequenceMap &rhs) const{
      if (recognition_sequence_ < rhs.recognition_sequence_){
        return true;
      }
      else{
        return false;
      }
    } 

    //Overloaded stream operator.
    friend void operator<<( ostream &output, const SequenceMap& someMap) { 
      cout << "Sequence: "<< someMap.recognition_sequence_ << endl;
      cout << "Acronym: ";
      for(const string& acro : someMap.enzyme_acronyms_){
        cout << acro << " ";
      }  
      output << endl;
    }

    /*Assuming that two sequence map's have the same recognition sequences, 
    the acronym vector of other_sequence is copied and added into the caller's 
    acronym vector*/
    void Merge(const SequenceMap& other_sequence){
      if(recognition_sequence_ == other_sequence.recognition_sequence_){
      //   //Insert all contents from other seq into the end of caller's vector.
      //   enzyme_acronyms_.insert(enzyme_acronyms_.end(), 
      //     other_sequence.enzyme_acronyms_.begin(), 
      //     other_sequence.enzyme_acronyms_.end());
        for(int i=0; i< other_sequence.enzyme_acronyms_.size(); i++){
          enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);
        }
      } 

    }

    void PrintRecognitionSequence()const{
      cout << recognition_sequence_ << endl;
    }
    void PrintEnzSequence() const{
      for(string acro: enzyme_acronyms_){
        cout << acro << " ";
      }
      cout << endl;
    }
    

  private:
    string	recognition_sequence_	;
    vector<string>	enzyme_acronyms_;
};

#endif