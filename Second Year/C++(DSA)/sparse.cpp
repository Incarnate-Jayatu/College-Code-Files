#include <iostream>
using namespace std;

#define MAX 100

// Structure to store one non-zero element
struct Element
{
    int row;
    int col;
    int value;
};

class SparseMatrix
{
private:
    int rows, cols;
    int nonZero;
    Element data[MAX];

public:

    // Create Sparse Matrix
    void create()
    {
        cout << "Enter number of rows: ";
        cin >> rows;

        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "Enter number of non-zero elements: ";
        cin >> nonZero;

        cout << "\nEnter Row Column Value\n";

        for(int i = 0; i < nonZero; i++)
        {
            cin >> data[i].row
                >> data[i].col
                >> data[i].value;
        }
    }

    // Display Triplet Representation
    void displayTriplet()
    {
        cout << "\nTriplet Representation\n";
        cout << "Row\tCol\tValue\n";

        for(int i = 0; i < nonZero; i++)
        {
            cout << data[i].row << "\t"
                 << data[i].col << "\t"
                 << data[i].value << endl;
        }
    }

    // Display Original Matrix
    void displayMatrix()
    {
        int k = 0;

        cout << "\nOriginal Matrix\n";

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(k < nonZero &&
                   data[k].row == i &&
                   data[k].col == j)
                {
                    cout << data[k].value << "\t";
                    k++;
                }
                else
                {
                    cout << "0\t";
                }
            }
            cout << endl;
        }
    }

    // Search Element
    void search()
    {
        int r, c;

        cout << "\nEnter row and column to search: ";
        cin >> r >> c;

        for(int i = 0; i < nonZero; i++)
        {
            if(data[i].row == r &&
               data[i].col == c)
            {
                cout << "Value = "
                     << data[i].value << endl;
                return;
            }
        }

        cout << "Value = 0" << endl;
    }

    // Count Non-Zero Elements
    void count()
    {
        cout << "\nNumber of Non-Zero Elements = "
             << nonZero << endl;
    }

    // Transpose Matrix
    void transpose()
    {
        cout << "\nTranspose (Triplet Representation)\n";
        cout << "Row\tCol\tValue\n";

        for(int c = 0; c < cols; c++)
        {
            for(int i = 0; i < nonZero; i++)
            {
                if(data[i].col == c)
                {
                    cout << data[i].col << "\t"
                         << data[i].row << "\t"
                         << data[i].value << endl;
                }
            }
        }
    }
};

int main()
{
    SparseMatrix sm;

    sm.create();

    sm.displayTriplet();

    sm.displayMatrix();

    sm.search();

    sm.count();

    sm.transpose();

    return 0;
}