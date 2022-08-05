#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;
using std::string;



int compare(string a1, string  b1) {

    stringstream geeka(a1);
    stringstream geekb(b1);

    int a = 0;
    geeka >> a;
    int b = 0;
    geekb >> b;

    return(a>b)?(1):(2);
    
}




string largest_number(vector<string> a) {

    vector<string> a2 = a;
    int n = a.size();
    char max = (char)5;
    int maxIn = 0;
    vector<string> res;

    
    while (a.size() != 0) {

        for (int i = 0; i < n; i++) {
            if (a[i][0] == max) {

                string a1 = a[i]     +    a[maxIn];
                string b1 = a[maxIn] +    a[i];


                max = (compare(a1,b1)==1)?(a[i][0]):(max);
                maxIn = (compare(a1, b1) == 1) ? (i) : (maxIn);;
            }
            //////////////////////////////////////////////////////////
            if (a[i][0] > max) {
                max = a[i][0];
                maxIn = i;               
            }
        }



        res.push_back(a2[maxIn]);
        a.erase(a.begin() + maxIn);
        a2.erase(a2.begin() + maxIn);
        max = '0';
        maxIn = 0;
        n = a.size();
    }
    std::stringstream ret;
    for (size_t i = 0; i < res.size(); i++) {
        ret << res[i];
    }
    string result;
    ret >> result;
    return result;
}



int main() {

    //while (true) {

        int n;
        std::cin >> n;
        vector<string> a(n);
        for (size_t i = 0; i < a.size(); i++) {
            std::cin >> a[i];
        }
        std::cout << largest_number(a);






     //   cout << endl << endl;
    //}
}
