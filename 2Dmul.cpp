#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    // 1. initialize string variables for reading in text file lines 
    string line1;
    string line2;
    stringstream ss, sp;

    //2. initialize variables to hold the matrix
    vector<vector<float>> matrix1; //here matrix is 2D
    vector<vector<float>> matrix2; //2nd matrix
    // vector<vector<float>> result_matrix;
    vector<float> row1; //1D row
    vector<float> row2; 

    //3. counter for characters in a text file line
    float i, j;

    //4. read in the file
    ifstream matrixfile1 ("matrix1.txt");
    ifstream matrixfile2 ("matrix2.txt");
    ofstream outputfile;
    outputfile.open ("matrixoutput.txt");

    // read in the matrix file line by line
    // parse the file


    if (matrixfile1.is_open() && matrixfile2.is_open()) {
        while (getline (matrixfile1, line1) and getline(matrixfile2, line2 )) {

            // parse the text line with a stringstream
            // clear the string stream to hold the next line
            ss.clear();
            ss.str(""); //taking the line1 in a string
            ss.str(line1);
            sp.clear();
            sp.str(""); //taking the line2 in a string
            sp.str(line2);
            row1.clear();
            row2.clear();

            // parse each line and push to the end of the row vector
            // the ss variable holds a line of text
            // ss >> i puts the next character into the i variable. 
            // the >> syntax is like cin >> some_value or cout << some_value
            // ss >> i is false when the end of the line is reached

            while(ss >> i && sp >> j) { //pushing the first character into i and j
                row1.push_back(i);
                row2.push_back(j);

                if ((ss.peek() == ',' || ss.peek() == ' ') && (sp.peek() == ',' ||
                 sp.peek() == ' ')) {  //ignoring , and blankspace
                    ss.ignore();
                    sp.ignore();
                }
            }
            matrix1.push_back(row1);
            matrix2.push_back(row2);
        }

        matrixfile1.close();
        matrixfile2.close();

        // print out the matrix
        // for (int row = 0; row < matrix1.size(); row++) {
        //     for (int column = 0; column < matrix1[row].size(); column++) {
        //         cout << matrix1[row][column] << " " ;
        //     }
        //     cout << endl; 
        // }

        vector<vector<int>> result_matrix (matrix1.size(), 
                    vector<int>(matrix2[0].size(), 0));

        if(outputfile.is_open()){
            if(matrix1[0].size() == matrix2.size()){
                cout<<"Printing the multiplication of the two matrices and saving to output file"<<endl;
                

                for(int row = 0; row < matrix1.size(); row++){
                    for(int column = 0; column < matrix2[0].size(); column++){
                        for(int i = 0; i < matrix2.size(); i++){
                            result_matrix[row][column] += matrix1[row][i]*matrix2[i][column];
                        }
                        cout<<result_matrix[row][column]<<" ";
                        outputfile<<result_matrix[row][column]<<" ";
                         
                    }
                    cout<<endl;
                    outputfile<<endl;   
                    
                }
                
            }

            else{
                cout<<"Dimension error!!"<<endl;
            }

            outputfile.close();
        }
        

    }

    return 0;

}        




