#include <iostream>
#include "histogram.h"
#include <map>
#include <string>
#include <list>
#include <vector>
#include "fstream"

using namespace std;

void histogram::change_values(vector<string> arg){
  for(long unsigned int i =0; i<arg.size();i++){
        ifstream  readdata;
        string temp_path = "/home/oliwi/pipr/cpp2/textfiles/" + arg[i];
        readdata.open(temp_path);
        string p;
        readdata >> p;
        values += p;
    }
}

map<int,string> histogram::take_values(){
    map<int,string> bighistogram;
    string dot = "*";
    for(int y=0;y<10;++y){
      bighistogram[y];
      if(values.size() == 0){
        bighistogram[y] ="";       
         }
        else{
      for(unsigned long int begin=0;begin<values.size()+1;++begin){
          int current_number = int(values[begin]);
          current_number = current_number -48;
          if(y == current_number){
            bighistogram[y] += dot;
          }
        }
      }
    }
    chistogram = bighistogram;
    return bighistogram;
}

void histogram::create_histogram(){
  system("clear");
  for(int i = 0; i < 10; i++){
      cout << i << " " <<  chistogram[i] << " " << '\n';
  }
  cout << '\n';
}


map<int,string> histogram::return_histogram(){
    return chistogram;
}


void histogram::create_mediana(){
    double mediana1;
    list<int> digits;
    if(values.size() == 0){
      mediana1 = 0;
    }
    else{
      for(unsigned long int i =0; i<values.size();i++){
        int o = int(values[i]);
        digits.push_front((o-48));
      }
      digits.sort();
      vector<double> some(digits.begin(),digits.end());
      if(values.size() % 2 != 0){
        int half = (values.size()/2) + 1/2;
        mediana1 = some[half];
      }
      else{
        double half1 = (values.size() + 1)/2;
        double half2 = (values.size() - 1)/2;
        mediana1 = (some[half1] + some[half2])/2;
        }
    }
    mediana = mediana1;
}

void histogram::max_min(){
    list <int> temp_letter_max;
    list <int>  temp_letter_min;
    unsigned long int temp_max = 0;
    unsigned long int temp_min = 163;
    if(values.size() == 0){
      temp_letter_max = {0};
      temp_letter_min = {0};
      temp_max = 0;
      temp_min = 0;
    }
    else{
      for(int i=0; i<10;i++){
        if(chistogram[i].size() >= temp_max){
          if(chistogram[i].size() == temp_max){
            temp_letter_max.push_back(i);
          }
          else{
            temp_max = chistogram[i].size();
            temp_letter_max = {i};
          }
        }
        if(chistogram[i].size() <= temp_min && chistogram[i].size() > 0){
          if(chistogram[i].size() == temp_min){
              temp_letter_min.push_back(i);
          }
          else{
            temp_min = chistogram[i].size();
            temp_letter_min = {i};
          }
        }
      }
    }
    vector<int> some1(temp_letter_min.begin(),temp_letter_min.end());
    least_frequent_lettter = some1;
    vector<int> some2(temp_letter_max.begin(),temp_letter_max.end());
    most_frequent_letter = some2;
    frequency_least = temp_min;
    frequency_most = temp_max;
}

void histogram::start2(){
  system("clear");
  create_histogram();
  create_mediana();
  max_min();
  save_to_terminal();
  save_to_file();

}


double histogram::return_mediana(){
  return mediana;
}

vector<int> histogram::return_least_frequent_letter(){
  return least_frequent_lettter;
}

vector<int> histogram::return_most_frequent_letter(){
  return most_frequent_letter;
}

int histogram::return_frequency_most(){
  return frequency_most;
}


int histogram::return_frequency_least(){
  return frequency_least;
}


void histogram::start(){
    system("clear");
    cout << "Enter your input_file: ";
    string input_path;
    cin >> input_path;
    vector<string> some3;
    some3.insert(some3.begin(),input_path);
    cout << "\n";
    cout << "Do you want to upload more files " << endl;
    cout << "1.Yes "<< endl;
    cout << "2.No" << endl;
    int input = 0;
    int variable = 0;
    cin >> input;
    while(variable == 0 ){
      if(input ==1){
          system("clear");
          cout << "Enter your next input_file: ";
          cin >> input_path;
          some3.push_back(input_path);
          cout << "\n";
          cout << "Do you want to upload more files " << endl;
          cout << "1.Yes "<< endl;
          cout << "2.No" << endl;
          cin >> input;
      }
      else if(input ==2){
        variable = 1;
        change_values(some3);
        start4();
      }
      else if(input =! 1 || input !=2){
        cout << " Wrong command.Try again"<< endl;
        cin >> input;
      }
    }
}

void histogram::save_to_terminal(){
  cout<< '\n';
  cout << "Median of this series of numbers is ";
  cout << return_mediana() << endl;
  cout << "The most frequent digit is ";
  vector<int> x = return_most_frequent_letter();
  vector<int> y = return_least_frequent_letter();
  for (auto v : x){
    std::cout << v << ",";
  }
  cout << '\n';
  cout << "It appears " << return_frequency_most() << " times" << endl;
  cout << "The least frequent digit is ";
    for (auto v : y){
    std::cout << v << ",";
  }
  cout << '\n';
  cout << "It appears " << return_frequency_least() << " times" << endl;
  cout << "Numbers of digit:" << values.size() << endl;

}

void histogram::save_to_file(){
  string path = "/home/oliwi/pipr/cpp2/textfiles/" + path_to_save;
  ofstream data;
  data.open(path);
   for(int i = 0; i < 10; i++){
      data << i << " " <<  chistogram[i] << " " << '\n';
  }
  cout << '\n';
  data << "Median of this series of numbers is ";
  data << return_mediana() << endl;
  vector<int> x = return_most_frequent_letter();
  vector<int> y = return_least_frequent_letter();
  data << "The most frequent digit is ";
  for (auto v : x){
    data << v << ",";
  }
  data << '\n';
  data << "It appears " << return_frequency_most() << " times" << endl;
  data << "The least frequent digit is ";
    for (auto v : y){
    data << v << ",";
  }
  data << '\n';
  data << "It appears " << return_frequency_least() << " times" << endl;
  data << "Numbers of digit:" << values.size() << endl;
  data.close();
}

void histogram::start4(){
  system("clear");
  cout << "Enter your output: ";
  cin >> path_to_save;
  take_values();
  start2();
}

 histogram histogram::operator+ (const histogram& arg) const{
    histogram result;
    result.values = (this->values + arg.values);
    return result;
}

histogram histogram::operator- (const histogram& arg) const{
    map<int,string> c = chistogram;
    map<int,string> d = arg.chistogram;
    histogram result;
    for(int i = 0 ;i <10;i++){
      long unsigned int j = c[i].size() - d[i].size();
      if(j == 0 || j <= 0){
        result.chistogram[i] = "";
      }
      result.chistogram[i] = c[i].substr(0,j);
      for(long unsigned int u =0 ; u<result.chistogram[i].size();u++){
        result.values = result.values + to_string(i);
      }
  }
  return result;
}

histogram histogram::operator* (const histogram& arg) const{
    histogram result;
    map<int,string> c1 = chistogram;
    map<int,string> c2 = arg.chistogram;
    for(int i = 0 ;i <10;i++){
      long unsigned int j = (c1[i].size() * c2[i].size());
      for(long unsigned int u =0;u<j;u++){
        result.values = result.values + to_string(i);
      }
    }
    return result;
}

void histogram::change_path_to_save(string arg){
  path_to_save = arg;
}