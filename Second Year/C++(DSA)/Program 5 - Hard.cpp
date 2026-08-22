//Program 5
/* Represent a grayscale image as a Matrix ADT and perform transpose, rotation, and 
brightness adjustment. */

#include <iostream>
using namespace std;

// Maximum dimensions for the image matrix
const int MAX_ROWS = 100;
const int MAX_COLS = 100;

class ImageMatrix 	// Matrix ADT for Grayscale Image
{
	private:
    	int pixels[MAX_ROWS][MAX_COLS];
    	int rows;
    	int cols;

	public:
    	ImageMatrix() 	// Constructor
		{
        	rows = 0;
        	cols = 0;
    	}
    
    	void loadImage() 	// Function to initialize and input image pixels
		{
        	cout << "Enter number of rows (max " << MAX_ROWS << "): ";
        	cin >> rows;
        	cout << "Enter number of columns (max " << MAX_COLS << "): ";
        	cin >> cols;
        	if (rows > MAX_ROWS || cols > MAX_COLS || rows <= 0 || cols <= 0) 
			{
	            cout << "Invalid dimensions!\n";
    	        rows = 0;
        	    cols = 0;
	            return;
    	    }
        	cout << "Enter pixel values (0-255):\n";
        	for (int i = 0; i < rows; i++) {
            	for (int j = 0; j < cols; j++) 
				{
                	cin >> pixels[i][j];
                	// Clamp input values to valid grayscale range
                	if (pixels[i][j] < 0) pixels[i][j] = 0;
                	if (pixels[i][j] > 255) pixels[i][j] = 255;
            	}
        	}
    	}

   
    	void displayImage() const 	 // Function to display the image matrix
		{
        	if (rows == 0 || cols == 0) 
			{
            	cout << "Image is empty!\n";
            	return;
        	}
        	cout << "\nCurrent Image Matrix (" << rows << "x" << cols << "):\n";
        	for (int i = 0; i < rows; i++) 
			{
	            for (int j = 0; j < cols; j++) 
				{
    	            cout << pixels[i][j] << "\t";
	            }
    	        cout << "\n";
	        }
    	}

    
    	void transpose() 	// 1. Transpose Operation
		{
        	if (rows == 0 || cols == 0) return;
        	int temp[MAX_ROWS][MAX_COLS];
	        
        // Copy transposed elements to a temporary array
    	    for (int i = 0; i < rows; i++) 
			{
        	    for (int j = 0; j < cols; j++) 
				{
            	    temp[j][i] = pixels[i][j];
            	}
        	}

        	// Swap row and column dimensions
        	int t = rows;
        	rows = cols;
        	cols = t;

        	// Copy back to original pixel array
        	for (int i = 0; i < rows; i++) 
			{
            	for (int j = 0; j < cols; j++) 
				{
	                pixels[i][j] = temp[i][j];
    	        }
        	}
        	cout << "Image transposed successfully.\n";
    	}

    
    	void rotateClockwise(int degrees)	// 2. Rotation Operation (90, 180, 270 degrees clockwise)
		{
        	if (rows == 0 || cols == 0) return;
        	if (degrees != 90 || degrees != 180 || degrees != 270) 
			{
            	cout << "Invalid rotation angle! Choose 90, 180, or 270.\n";
            	return;
        	}
        	int passes = degrees / 90;
        	for (int p = 0; p < passes; p++) 
			{
            	int temp[MAX_ROWS][MAX_COLS];
	            	
    	        // 90-degree clockwise rotation logic using raw loops
        	    for (int i = 0; i < rows; i++) 
				{
            	    for (int j = 0; j < cols; j++) 
					{
                	    temp[j][rows - 1 - i] = pixels[i][j];
                	}
            	}

            	// Swap dimensions
            	int t = rows;
            	rows = cols;
            	cols = t;

            	// Copy back
            	for (int i = 0; i < rows; i++) 
				{
                	for (int j = 0; j < cols; j++) 
					{
	                    pixels[i][j] = temp[i][j];
    	            }
	            }
	        }
    	    cout << "Image rotated by " << degrees << " degrees clockwise.\n";
    	}

    	void adjustBrightness(int offset)	// 3. Brightness Adjustment Operation 
		{
        	if (rows == 0 || cols == 0) return;
        	for (int i = 0; i < rows; i++) 
			{
            	for (int j = 0; j < cols; j++) 
				{
                	int newValue = pixels[i][j] + offset;
                
                	// Manual Clamping (0 - 255) without using std::clamp, std::min, or std::max
                	if (newValue < 0) {
                    	pixels[i][j] = 0;
                	} 
					else if (newValue > 255)
					{
                    	pixels[i][j] = 255;
                	} 
					else 
					{
                    	pixels[i][j] = newValue;
                	}
            	}
        	}
        	cout << "Brightness adjusted.\n";
    	}
};

int main() {
    ImageMatrix img;
    int choice;
    do 
	{
        cout << "\n===============================\n";
        cout << "   GRAYSCALE IMAGE MATRIX ADT  \n";
        cout << "===============================\n";
        cout << "1. Load/Input Image\n";
        cout << "2. Display Image Matrix\n";
        cout << "3. Transpose Image\n";
        cout << "4. Rotate Image Clockwise\n";
        cout << "5. Adjust Brightness\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
		{
            case 1:
                img.loadImage();
                img.displayImage();
                break;
            case 2:
                img.displayImage();
                break;
            case 3:
                img.transpose();
                img.displayImage();
                break;
            case 4: {
                int angle;
                cout << "Enter angle to rotate (90, 180, 270): ";
                cin >> angle;
                img.rotateClockwise(angle);
                img.displayImage();
                break;
            }
            case 5: {
                int offset;
                cout << "Enter brightness offset (positive to brighten, negative to darken): ";
                cin >> offset;
                img.adjustBrightness(offset);
                img.displayImage();
                break;
            }
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);
    return 0;
}
