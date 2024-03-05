#include <iostream>
#include <map>
#include <string>
#include <list>
#include <vector>

using namespace std;

class histogram{
    string values;
    vector<int> most_frequent_letter;
    vector<int> least_frequent_lettter;
    int frequency_most;
    int frequency_least;
    double mediana;
    map<int,string> chistogram; 
    string path_to_save = "out.txt";
    vector<string> input_file;
public:
    histogram(string arg = ""){
        this ->values = arg;
        this ->chistogram = chistogram;
        this ->most_frequent_letter = most_frequent_letter;
        this ->least_frequent_lettter = least_frequent_lettter;
        this ->frequency_most = frequency_most;
        this->frequency_least = frequency_least;
        this ->mediana = mediana;
        this ->path_to_save = path_to_save;
    }
    void start2();
    double return_mediana();
    map<int,string> take_values();
    void create_histogram();
    map<int,string> return_histogram();
    void create_mediana();
    void max_min();
    vector<int> return_most_frequent_letter();
    vector<int> return_least_frequent_letter();
    int return_frequency_most();
    int return_frequency_least();
    void start();
    void save_to_terminal();
    void save_to_file();
    void start4();
    void change_values(vector<string> arg);
    histogram operator+ (const histogram& arg) const;
    histogram operator- (const histogram& arg) const;
    histogram operator* (const histogram& arg) const;
    void change_path_to_save(string arg);
};