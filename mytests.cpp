#include "histogram.h"
#include "gtest/gtest.h"
#include <map>
#include <string>
#include <list>
#include <vector>
#include "fstream"


using namespace std;


TEST(mytests,histogram1){
    histogram histogram1;
    vector <string> cos = {"text1.txt","text2.txt"};
    histogram1.change_values(cos);
    histogram1.take_values();
    map<int,string> chistogram = histogram1.return_histogram();
    int value0 = chistogram[0].size();
    int value1 = chistogram[1].size();
    int value2 = chistogram[2].size();
    EXPECT_EQ(value0,0);
    EXPECT_EQ(value1,2);
    EXPECT_EQ(value2,2);
    EXPECT_EQ(chistogram[1],"**");

}

TEST(mytests,mediana1){
    histogram histogram2;
    histogram2.change_values({"text1.txt","text2.txt"});
    histogram2.take_values();
    histogram2.create_mediana();
    histogram2.max_min();
    vector <int> c= {4};
    vector <int> y= {7};
    EXPECT_EQ(histogram2.return_mediana(),7);
    EXPECT_EQ(histogram2.return_least_frequent_letter(),c);
    EXPECT_EQ(histogram2.return_most_frequent_letter(),y);
    EXPECT_EQ(histogram2.return_frequency_most(),37);
    EXPECT_EQ(histogram2.return_frequency_least(),1);

}

TEST(mytests,save_to_file1){
    histogram histogram3;
    histogram3.change_values({"text1.txt","text2.txt"});
    histogram3.take_values();
    histogram3.create_mediana();
    histogram3.max_min();
    histogram3.save_to_file();
    ifstream file1;
    file1.open("/home/oliwi/pipr/cpp2/textfiles/out.txt");
    EXPECT_TRUE(file1);
}

TEST(mytests,save_to_file2){
    histogram histogram4;
    histogram4.change_values({"text.txt1","text2.txt"});
    histogram4.take_values();
    histogram4.create_mediana();
    histogram4.max_min();
    histogram4.change_path_to_save("out2.txt");
    histogram4.save_to_file();
    ifstream file2;
    file2.open("/home/oliwi/pipr/cpp2/textfiles/out2.txt");
    EXPECT_TRUE(file2);
}

TEST(mytests,add1){
    histogram histogram5;
    histogram histogram6;
    histogram5.change_values({"text1.txt"});
    histogram6.change_values({"text2.txt"});
    histogram5.take_values();
    histogram6.take_values();
    histogram histogram7 = histogram5 + histogram6;
    histogram7.take_values();
    histogram7.max_min();
    histogram7.create_mediana();
    vector <int> c= {4};
    vector <int> y= {7};
    EXPECT_EQ(histogram7.return_mediana(),7);
    EXPECT_EQ(histogram7.return_least_frequent_letter(),c);
    EXPECT_EQ(histogram7.return_most_frequent_letter(),y);
    EXPECT_EQ(histogram7.return_frequency_most(),37);
    EXPECT_EQ(histogram7.return_frequency_least(),1);
    histogram7.change_path_to_save("out3.txt");
    histogram7.save_to_file();
    ifstream file1;
    file1.open("/home/oliwi/pipr/cpp2/textfiles/out3.txt");
    EXPECT_TRUE(file1);
}


TEST(mytests,sub1){
    histogram histogram8;
    histogram histogram9;
    histogram8.change_values({"text1.txt"});
    histogram9.change_values({"text3.txt"});
    histogram8.take_values();
    histogram9.take_values();
    histogram histogram10 = histogram8 - histogram9;
    histogram10.take_values();
    histogram10.max_min();
    histogram10.create_mediana();
    vector <int> c= {2};
    vector <int> y= {5};
    EXPECT_EQ(histogram10.return_mediana(),5);
    EXPECT_EQ(histogram10.return_least_frequent_letter(),c);
    EXPECT_EQ(histogram10.return_most_frequent_letter(),y);
    EXPECT_EQ(histogram10.return_frequency_most(),2);
    EXPECT_EQ(histogram10.return_frequency_least(),1);
    histogram10.change_path_to_save("out4.txt");
    histogram10.save_to_file();
    ifstream file2;
    file2.open("/home/oliwi/pipr/cpp2/textfiles/out4.txt");
    EXPECT_TRUE(file2);
}

TEST(mytests,mul1){
    histogram histogram11;
    histogram histogram12;
    histogram11.change_values({"text1.txt"});
    histogram12.change_values({"text3.txt"});
    histogram11.take_values();
    histogram12.take_values();
    histogram histogram13 = histogram11 * histogram12;
    histogram13.take_values();
    histogram13.max_min();
    histogram13.create_mediana();
    vector <int> c= {4};
    vector <int> y= {1};
    EXPECT_EQ(histogram13.return_mediana(),1);
    EXPECT_EQ(histogram13.return_least_frequent_letter(),c);
    EXPECT_EQ(histogram13.return_most_frequent_letter(),y);
    EXPECT_EQ(histogram13.return_frequency_most(),4);
    EXPECT_EQ(histogram13.return_frequency_least(),1);
    histogram13.change_path_to_save("out5.txt");
    histogram13.save_to_file();
    ifstream file3;
    file3.open("/home/oliwi/pipr/cpp2/textfiles/out5.txt");
    EXPECT_TRUE(file3);
}

TEST(mytests,sub2){
    histogram histogram14;
    histogram histogram15;
    histogram14.change_values({"text4.txt"});
    histogram15.change_values({"text5.txt"});
    histogram14.take_values();
    histogram15.take_values();
    histogram histogram16 = histogram14 - histogram15;
    histogram16.take_values();
    histogram16.max_min();
    histogram16.create_mediana();
    vector <int> c= {0};
    vector <int> y= {0};
    EXPECT_EQ(histogram16.return_mediana(),0);
    EXPECT_EQ(histogram16.return_least_frequent_letter(),c);
    EXPECT_EQ(histogram16.return_most_frequent_letter(),y);
    EXPECT_EQ(histogram16.return_frequency_most(),0);
    EXPECT_EQ(histogram16.return_frequency_least(),0);
    histogram16.change_path_to_save("out5.txt");
    histogram16.save_to_file();
    ifstream file4;
    file4.open("/home/oliwi/pipr/cpp2/textfiles/out5.txt");
    EXPECT_TRUE(file4);
}


int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}