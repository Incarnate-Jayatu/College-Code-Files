// Program 8
/* Store only occupied squares of a chessboard using a Sparse Matrix ADT. */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class ChessBoardSparseMatrix
{
private:
    static const int MAX_PIECES = 32;
    const int ROWS = 8;
    const int COLS = 8;
    int row_indices[MAX_PIECES];
    int col_indices[MAX_PIECES];
    string pieces[MAX_PIECES];
    int piece_count;
    bool is_valid(int row, int col) const
    {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }
    int find_piece_index(int row, int col) const
    {
        for (int i = 0; i < piece_count; i++)
        {
            if (row_indices[i] == row && col_indices[i] == col)
                return i;
        }
        return -1;
    }
public:
    ChessBoardSparseMatrix()
    {
        piece_count = 0;
    }
    bool set_piece(int row, int col, const string& piece)
    {
        if (!is_valid(row, col))
        {
            cout << "Error: Row and column must be between 0 and 7.\n";
            return false;
        }
        int index = find_piece_index(row, col);
        if (piece.empty() || piece == "--")
        {
            if (index == -1)
            {
                cout << "Square is already empty.\n";
                return false;
            }
            for (int i = index; i < piece_count - 1; i++)
            {
                row_indices[i] = row_indices[i + 1];
                col_indices[i] = col_indices[i + 1];
                pieces[i] = pieces[i + 1];
            }
            piece_count--;
            cout << "Piece removed successfully.\n";
            return true;
        }
        if (index != -1)
        {
            pieces[index] = piece;
            cout << "Piece updated successfully.\n";
            return true;
        }
        if (piece_count >= MAX_PIECES)
        {
            cout << "Error: Maximum 32 pieces are allowed.\n";
            return false;
        }
        row_indices[piece_count] = row;
        col_indices[piece_count] = col;
        pieces[piece_count] = piece;
        piece_count++;
        cout << "Piece placed successfully.\n";
        return true;
    }
    string get_piece(int row, int col) const
    {
        if (!is_valid(row, col))
            return "";
        int index = find_piece_index(row, col);
        if (index != -1)
            return pieces[index];
        return "";
    }
    void remove_piece(int row, int col)
    {
        if (!is_valid(row, col))
        {
            cout << "Error: Row and column must be between 0 and 7.\n";
            return;
        }
        int index = find_piece_index(row, col);
        if (index == -1)
        {
            cout << "Square is already empty.\n";
            return;
        }
        for (int i = index; i < piece_count - 1; i++)
        {
            row_indices[i] = row_indices[i + 1];
            col_indices[i] = col_indices[i + 1];
            pieces[i] = pieces[i + 1];
        }
        piece_count--;
        cout << "Piece removed successfully.\n";
    }
    void display_board() const
    {
        cout << "\n\t\t\tCHESSBOARD\n\n";
        cout << setw(6) << " ";
        for (int c = 0; c < COLS; c++)
            cout << setw(5) << c;
        cout << "\n";
        for (int r = 0; r < ROWS; r++)
        {
            cout << setw(6) << r;
            for (int c = 0; c < COLS; c++)
            {
                int index = find_piece_index(r, c);
                if (index != -1)
                    cout << setw(5) << pieces[index];
                else
                    cout << setw(5) << "--";
            }
            cout << "\n";
        }
    }
    void print_internal_arrays() const
    {
        cout << "\n--- SPARSE MATRIX COO ARRAY ---\n";
        cout << "Active Piece Count: " << piece_count << "/" << MAX_PIECES << "\n";
        if (piece_count == 0)
        {
            cout << "Arrays are empty.\n";
            return;
        }
        cout << setw(8) << "Index"
             << setw(8) << "Row"
             << setw(8) << "Col"
             << setw(12) << "Piece" << "\n";
        cout << "------------------------------------\n";
        for (int i = 0; i < piece_count; i++)
        {
            cout << setw(8) << i
                 << setw(8) << row_indices[i]
                 << setw(8) << col_indices[i]
                 << setw(12) << pieces[i] << "\n";
        }
    }
};
int main()
{
    ChessBoardSparseMatrix board;
    int choice, row, col;
    string piece;
    do
    {
        cout << "\n===============================\n";
        cout << "    CHESSBOARD SPARSE MATRIX\n";
        cout << "===============================\n";
        cout << "1. Place / Update Piece\n";
        cout << "2. Get Piece at Coordinate\n";
        cout << "3. Remove Piece\n";
        cout << "4. Display Full Chessboard Grid\n";
        cout << "5. View Sparse Array Elements\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter row (0-7): ";
                cin >> row;
                cout << "Enter column (0-7): ";
                cin >> col;
                cout << "Enter piece label (e.g., wK, bP, wR): ";
                cin >> piece;
                board.set_piece(row, col, piece);
                break;
            case 2:
                cout << "Enter row (0-7): ";
                cin >> row;
                cout << "Enter column (0-7): ";
                cin >> col;
                if (row < 0 || row > 7 || col < 0 || col > 7)
                    cout << "Error: Row and column must be between 0 and 7.\n";
                else
                {
                    string found_piece = board.get_piece(row, col);
                    if (found_piece.empty())
                        cout << "Square (" << row << ", " << col << ") is empty.\n";
                    else
                        cout << "Piece at (" << row << ", " << col << ") is: " << found_piece << "\n";
                }
                break;
            case 3:
                cout << "Enter row (0-7) to remove: ";
                cin >> row;
                cout << "Enter column (0-7) to remove: ";
                cin >> col;
                board.remove_piece(row, col);
                break;
            case 4:
                board.display_board();
                break;
            case 5:
                board.print_internal_arrays();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
                cout << "Please select a valid option from 1 to 6.\n";
        }
    } while (choice != 6);
    return 0;
}