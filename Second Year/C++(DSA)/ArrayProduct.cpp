#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

class ArrayProduct {
private:
    struct Product {
        int proid, price;
        double rating;
    };
    Product pro[30];
    int n;

    void swap(Product &a, Product &b){
        Product temp = a;
        a = b;
        b = temp;
    }

public:
    ArrayProduct(){
        n = 0;
    }

    void getProduct(){
        cout<<"====== ENTER PRODUCTS ======\n";
        while(true){
            cout<<"Enter number of products (Max: 30): ";
            cin>>n;
            if(n > 0 && n <= 30){
                break;
            }
            cout<<"Invalid input! Maximum number of products is 30.\n";
        }
        for(int i = 0; i < n; i++){
            cout<<"\nEnter Product ID: ";
            cin>>pro[i].proid;
            cout<<"Enter Product Price: ";
            cin>>pro[i].price;
            cout<<"Enter Product Rating: ";
            cin>>pro[i].rating;
        }
    }

    void sortProduct(){
        bool isSorted;
        for(int i = 0; i < n - 1; i++){
            isSorted = true;
            for(int j = 0; j < n - i - 1; j++){
                if(pro[j].rating < pro[j + 1].rating){
                    swap(pro[j], pro[j + 1]);
                    isSorted = false;
                }
                else if(pro[j].rating == pro[j + 1].rating && pro[j].price > pro[j + 1].price){
                    swap(pro[j], pro[j + 1]);
                    isSorted = false;
                }
            }
            if(isSorted) break;
        }
    }

    void topFive(){
        cout<<"\n====== TOP RATED PRODUCTS ======\n";
        cout<<left<<setw(10)<<"Product ID"<<" || "<<setw(10)<<"Price"<<" || "<<setw(10)<<"Rating"<<endl;
        int limit = min(n, 5); 
        for(int i = 0; i < limit; i++)
            cout<<left<<setw(10)<<pro[i].proid<<" || "<<setw(10)<<pro[i].price<<" || "<<setw(10)<<pro[i].rating<<endl;
    }
};

int main() {
    ArrayProduct a;
    a.getProduct();
    a.sortProduct();
    a.topFive();
    return 0;
}