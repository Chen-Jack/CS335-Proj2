#include "SequenceMap.h"

SequenceMap::SequenceMap(const string &a_rec_seq, const string &an_enz_acro){
  recognition_sequence_ = a_rec_seq;
  enzyme_acronyms_.push_back(an_enz_acro);
}

// SequenceMap(const string &&a_rec_seq, const string &&an_enz_acro){
//   recognition_sequence_
//   enzyme_acronyms_.push_b
// }
// void SequenceMap:: operator = (SequenceMap map){
//   recognition_sequence_ = map.recognition_sequence_;
//   enzyme_acronyms_ = map.enzyme_acronyms_;
// }

bool SequenceMap::operator < (const SequenceMap &rhs){
  if (recognition_sequence_ < rhs.recognition_sequence_){
    return true;
  }
  else{
    return false;
  }
}

void SequenceMap::Merge(const SequenceMap& other_sequence){
  if(recognition_sequence_ == other_sequence.recognition_sequence_){
    //Insert all contents from other seq into the end of caller's sequence.
    enzyme_acronyms_.insert(enzyme_acronyms_.end(), 
      other_sequence.enzyme_acronyms_.begin(), 
      other_sequence.enzyme_acronyms_.end());
  } 
}

int main(){
  string test = "wor3";
  string testacro = "wwhatever";

  SequenceMap mapf{"z","cow"};

  SequenceMap mapx{move(test), move(testacro)};
  SequenceMap mapz{};
  mapz = mapx;
  mapz.Merge(mapx);

  cout << (mapz < mapf) << endl;


  
  return 0;
}