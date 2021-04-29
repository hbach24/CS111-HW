#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int Decode (int mesg, int n1, int d1) { 
  int temp = 1;
  mesg = mesg % n1; //calculate the modulus 
  while (d1 > 0) {
    if (d1 % 2 == 1) { 
      temp = (temp * mesg) % n1;
      mesg = (mesg * mesg) % n1;
      d1 = d1 / 2;
    }
    else {
      mesg = (mesg * mesg) % n1;
      d1 = d1 / 2;
    }
  }
  return temp;
}

int Convert (int element) {
  int letter;
  if(element == 29) {
    letter = 32;
  }

  else if (element == 30) {
    letter = 34;
  }

  else if (element == 31) {
    letter = 46;
  }

  else if (element >= 3 && element < 29) {
    element += 62;
    letter = element;
  } 
  return letter;
}

int main() {
  vector<int> arr;
  vector<int> decodedMesg;
  vector<int> convMesg;

  int num;
  int msg = 0, d = 89, n = 187;

  ifstream inFS;    
  inFS.open("Cmessage.txt"); //open CMessage.txt file containing Bob's encoded message

  if (!inFS.is_open()) {
    cout << "Unable to open file" << endl;
  }

  //store letters into array
  while (inFS >> num) { 
    if (num != 0) {
      arr.push_back(num);
    }
  }
  inFS.close();

  //store decoded letters into new/different array
  cout << "Bob's decoded message: ";
  for (int i = 0; i < arr.size(); i++) {
    decodedMesg.push_back(Decode(arr[i], n, d));
    cout << decodedMesg[i] << " ";
  }
  
  cout << endl << endl << "Bob's message in plaintext: ";
  for (int i = 0; i < decodedMesg.size(); i++) {
    convMesg.push_back(Convert(decodedMesg[i]));
  }

  for (int i = 0; i < convMesg.size(); i++) {
    cout << (char)convMesg[i] << " ";
  }
  
  return 0;
}
