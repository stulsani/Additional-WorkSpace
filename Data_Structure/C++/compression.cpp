#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

string decompressFunc(unordered_map<string,vector<int> > &mymap,int sizeofpara){
  string ans(sizeofpara, ' ');
  for(auto pair : mymap){
    for(int d : pair.second){
      for(int a=0;a < pair.first.size();a++)
        ans[d++] = pair.first[a];
    }
  }
  return ans;
}

unordered_map<string,vector<int> > compressFunc(string para){
  stringstream stream(para);
  unordered_map<string,vector<int> > mymap;
  int i = 0;
  while(i < para.size()){
    string words;
    stream >> words;
     mymap[words].push_back(i);
    i += words.size() + 1;
  }
  return mymap;
}

int main(){
  string para = "This is a good time to do this thing which is a good thing to do";
  unordered_map<string,vector<int> > mymapcompressed = compressFunc(para);
  cout << "Orignal Para: " << decompressFunc(mymapcompressed,para.size()) << endl;
  return 0;
}
