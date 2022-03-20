#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string LongestCommonSubsequence(string x, string y){
    int sizeX = x.size(); //setting two integers equal to string lengths
    int sizeY = y.size();
    vector<vector<int> >arr(sizeX+1, vector<int>(sizeY+1));
    //two dimensional vector to traverse both strings

    for (int i = 1; i <= sizeX; i++) {
        arr[i][0] = 0;
    }
    for(int j = 0; j <= sizeY; j++) {
        arr[0][j] = 0;
    }
    //calculates the length of the longest common subsequence
    for(int i = 1; i <= sizeX; i++){ //nested for loop to calculate the length
        for(int j = 1; j <= sizeY; j++){
            if(x[i-1] == y[j-1]){ //check if the last two characters in strings are same
                arr[i][j] = arr[i-1][j-1] + 1; //if yes, then add 1 to the result
            }
            else if (arr[i-1][j] >= arr[i][j-1]){ //check if last characters are not the same
                arr[i][j] = arr[i-1][j];
                //remove last character from first string and compare that string with the second one
            }
            else {
                //do the same thing again except this time compare first thing and second string with character removed
                arr[i][j] = arr[i][j-1];
            }
        }
    }


    string strLCS = ""; //begin with empty string
    while(sizeX > 0 && sizeY > 0) {
        if (x[sizeX-1] == y[sizeY-1]) { //check if last character in both strings are same
            //add the last character to the LCS string
            strLCS += x[sizeX-1];
            //delete that character from both strings
            sizeX--;
            sizeY--;
        }
        else {
            if (arr[sizeX-1][sizeY] > arr[sizeX][sizeY-1]) {
                //check if the cell above current cell is greater
                // than the cell to the left of it
                sizeX--; //delete character from string x
            }
            else if(arr[sizeX][sizeY-1] > arr[sizeX-1][sizeY]) {
                //checks if the cell on the left side of current cell
                // is greater than the one above it
                sizeY--; //delete character from string y
            }
            else if (arr[sizeX][sizeY-1] == arr[sizeX-1][sizeY]){
                //checks if the cell above and to the left of the current cell
                // are equal to each other
                sizeX--; //delete character from string x
            }
        }
    }
    reverse(strLCS.begin(), strLCS.end());
    //string is reversed so the output is displayed properly
    return strLCS;
    //initial subsequence was stored in backwards order so reverse function is used

}

int main() {
    string word1;
    string word2;
    cout << "Enter first string: " << endl;
    cin >> word1;
    cout << "Enter second string: " << endl;
    cin >> word2;
    cout << "the longest common subsequence is: " << LongestCommonSubsequence(word1, word2) << endl;
    return 0;
}
