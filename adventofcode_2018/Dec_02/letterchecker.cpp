#include <iostream>
#include <fstream> // input file stream
#include <string>
#include <vector> // dynamic array, modifiable length
using namespace std;

string checkAndPrintAnswer(string line1, string line2){
    string answer;
    int diff = 0;
    cout << "Line1: " << line1 << endl;
    cout << "Line2: " << line2 << endl;
    for (int i = 0; i < line1.size(); i++){
        if (line1[i] != line2[i]){
           diff++; 
        }
        if (diff > 1){
            cout << "More than 1 diff." << endl;
            break;
        }
    }
    if (diff == 1){
        for (int i = 0; i < line1.size(); i++){
            if (line1[i] == line2[i]){
                answer += line1[i];
            }
        }
        return answer;
    }
} //end checkAndAnswer()

int main(){
    
    ifstream inFile; 

    inFile.open("input.txt");
    if (!inFile) {
        cerr << "Unable to open file input.txt";
        exit(1); 
    }

    string line;
    vector<string> lines;
    bool found = false;

    while (!inFile.eof()){
        getline(inFile, line);
        lines.push_back(line);
    }
    
    while(!found){
        for (int i = 0; i < lines.size(); i++){
            for (int j = 0; j < lines.size(); j++){
                if (lines[i] != lines[j]){
                    if (!lines[i].empty() && !lines[j].empty()){
                        string answer = checkAndPrintAnswer(lines[i], lines[j]);
                        if (!answer.empty()){
                            cout << "Answer: " << answer << endl;
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (found){
                break;
            }
        }
    }

    inFile.close();
    return 0;
}


