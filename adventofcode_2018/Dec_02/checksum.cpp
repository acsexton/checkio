#include <iostream>
#include <fstream> // input file stream
#include <string>
using namespace std;

bool hasRepeats(string line, int repeats){
    cout << line << endl;
    for (char c = 'a'; c <= 'z'; ++c){
        int count = 0;
        for (int i = 0; i < line.size(); ++i){
            if(line[i] == c){
                count++;
            }
        }
        cout << " has " << count << " instances of " << c << endl;
        if (count == repeats){
            cout << count << " repeats of " << repeats << "." << endl;
            return true;
        }
    }
    return false;
}

int main(){
    
    ifstream inFile; 

    inFile.open("input.txt");
    if (!inFile) {
        cerr << "Unable to open file input.txt";
        exit(1); 
    }

    string line;
    int foundTwo = 0;
    int foundThree = 0;
    while (getline (inFile,line)) {
        if (hasRepeats(line, 2)){
            foundTwo++;
            cout << "foundTwo increased by 1 to: " << foundTwo << endl;
        }
        if (hasRepeats(line, 3)){
            foundThree++;
            cout << "foundThree increased by 1 to: " << foundThree << endl;
        }
    }
    inFile.close();

    cout << "Two repeats: " << foundTwo << endl;
    cout << "Three repeats: " << foundThree << endl;
    int total = foundTwo * foundThree;
    cout << "Checksum: " << total << endl;

    return 0;

}


