#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <regex>
using namespace std;

// #[ID] @ x,y: wxl 
// #123 @ 3,2: 5x4

int main(){

    ifstream inFile;
    vector<vector<pair<int, int>>> claimedPairs;
    map<pair<int,int>,int> useCounts;

    inFile.open("input.txt");
    if (!inFile){
        cerr << "Unable to open input.txt";
        exit(1);
    }

    for (string line; getline(inFile, line);){
        // smatch = string match
        smatch claim; regex_match(line, claim, regex(R"(#(\d+) @ (\d+),(\d+): (\d+)x(\d+))"));
        claimedPairs.push_back({});
        // stoi = string to int
        int xLoc=stoi(claim[2]), yLoc=stoi(claim[3]), xClaim=stoi(claim[4]), yClaim=stoi(claim[5]);
        for(int x = xLoc; x < (xLoc + xClaim); x++){
           for(int y = yLoc; y < (yLoc + yClaim); y++){
                claimedPairs.back().push_back({x, y});
                useCounts[{x, y}]++;
           }
        }
    }

    cout << "More than two claims on " << count_if(useCounts.begin(), useCounts.end(), [](auto& coord){
        return (coord.second > 1);
    }); 
    cout << " spaces." << endl;
    //cout << "Claim with no overlaps is Claim # " << find_if(claimedPairs.begin(), claimedPairs.end(), [](auto& coord){
       // TODO: This. 
    //});

    return 0;
}
