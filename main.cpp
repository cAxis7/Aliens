#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> numbers;

long long int sum(int n, int pos){
  long long int total = 0;
  if(n == 1){
    for(int i = pos; i < numbers.size(); i++){
      total += (long long int)numbers[i];
    }
  }

  else{
    for(int i = pos; i < numbers.size(); i++){
      total += (long long int)numbers[i] * sum(n-1, i+1);
    }
  }
  return total;
}

int main() {
  char lref;
  string info;
  int count = 0;

  cin >> info;
  
  lref = info[0];
  //cout << lref << endl;
  for(int i = 1; i < info.length(); i++){
    if(info[i] != lref){
      lref = info[i];
      count++;
      numbers.push_back(i*2 + 1);
    }
  }
  //for(int i = 0; i < numbers.size(); i++) cout << numbers[i] << endl;

  cout << numbers.size() << endl;

  if(lref == 'H'){ 
    cout << "1";
    for(int i = 1; i < numbers.size()+1; i++){
      cout << " ";
      if(i % 2 == 1) cout << "-";
      cout << sum(i, 0);
    }
  }
  
  
  else{ 
    cout << "-1";
    for(int i = 1; i < numbers.size()+1; i++){
      cout << " ";
      if(i % 2 == 0) cout << "-";
      cout << sum(i, 0);
    }
  }
  cout << endl;
}
