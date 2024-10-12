#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main() {

    // step 1. initialize string variables for reading in text file lines
    std::string line1, line2;
    std::stringstream ss1, ss2;

    // step 2. initialize two variables to hold the matrices
    std::vector < std::vector <float> > matrix1;
    std::vector < std::vector <float> > matrix2;

    std::vector<float> row_mtx1;
    std::vector<float> row_mtx2;

    // step 3. counter for characters in a text file line
    float i;

    // step 4. read in the file
    std::ifstream input_file1 ("input1.txt");
    std::ifstream input_file2 ("input2.txt");


    if (input_file1.is_open() && input_file2.is_open()) {
        while (std::getline(input_file1, line1)) {
            // parse the text line with a string_stream
            // clear the string stream to hold the next line

            ss1.clear();
            ss1.str("");
            ss1.str(line1);
            row_mtx1.clear();

            while(ss1 >> i) {
                row_mtx1.push_back(i);

                if (ss1.peek() == ',' || ss1.peek() == ' ') {
                    ss1.ignore();
                }
            }
            matrix1.push_back(row_mtx1);

        while(std::getline(input_file2, line2)) {
            ss2.clear();
            ss2.str("");
            ss2.str(line2);
            row_mtx2.clear();

            while(ss2 >> i) {
                row_mtx2.push_back(i);

                if (ss2.peek() == ',' || ss2.peek() == ' ') {
                    ss2.ignore();
                    }
                }
                matrix2.push_back(row_mtx2);
            }

        }
        input_file1.close();
        input_file2.close();

        std::cout << matrix1[0].size() << std::endl;
        std::cout << matrix2.size() << std::endl;

        std::cout <<"Matrix 1"<< std::endl;
        for (int row = 0; row < matrix1.size(); row++) {
            for (int column = 0; column < matrix1[0].size(); column++) {
                std::cout << matrix1[row][column] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;

        std::cout <<"Matrix 2"<< std::endl;
        for (int row = 0; row < matrix2.size(); row++) {
            for (int column = 0; column < matrix2[0].size(); column++) {
                std::cout << matrix2[row][column] << " ";
            }
            std::cout << std::endl;
        }

        //doing matrix multiplication
        if (matrix1[0].size() == matrix2.size()) {
            std::vector < std::vector <float> > result_matrix(matrix1.size(),
                std::vector<float>(matrix2[0].size(), 0.0));

            for (int row = 0; row < matrix1.size(); row++) {
                for (int column = 0; column < matrix2[row].size(); column++) {
                    for(int i = 0; i < matrix1[0].size()-1; i++) {
                        result_matrix[row][column] += matrix1[row][i] * matrix2[i][column];
                    }
                }
            }

            std::cout<<"\nResult"<<std::endl;
            for (int row = 0; row < result_matrix.size(); row++) {
                for (int column = 0; column < result_matrix[0].size(); column++) {
                    std::cout << result_matrix[row][column] << " ";
                }
                std::cout << std::endl;
            }
        }
        else {
            std::cout << "Dimension error" << std::endl;
        }

    } else {
        std::cout << "Unable to open file";
    }
    return 0;
}
