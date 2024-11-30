
#include <iostream>
#include <iomanip>
#include <random>
#include <iostream>
using namespace std;
template <typename T>
class YarickBochock {
    int r;
    int c;
    T** arr;
public:
    YarickBochock() : r(0), c(0) ,arr(nullptr){
  
    }
    YarickBochock(int r, int c ): r(r), c(c){
        arr = new T*[r];
           for (int i = 0; i < r; i++)
           {
               arr[i] = new  T[c];

           }

    }
    ~YarickBochock() {
        if (arr != nullptr) {
            for (int i = 0; i < r; i++)
            {
                delete[] arr[i];
            }
            delete[]  arr;
           
        }
    }

    void get() {
        for (int i = 0; i < r; i++)
        {
            for (int y = 0; y < c; y++)
            {
                cout << i << "colonka" << y << "raidock" << "enter:";
                cin >> arr[i][y];
            }
  
        }





    }
    void show() {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    void random() {
        srand(time(NULL));
        for (int i = 0; i < r; i++)
        {
            for (int y = 0; y < c; y++)
            {
   
            arr[i][y] = rand() % 20;
            }

        }
    }
    void min() {
        int s = 100;
        for (int i = 0; i < r; i++)
        {
            for (int y = 0; y < c; y++)
            {
                if (s > arr[i][y])
                {
                    s = arr[i][y];
                }
            }
        }
        cout << "min:" << s;
    }
    void max() {

        int s = 0;
        for (int i = 0; i < r; i++)
        {
            for (int y = 0; y < c; y++)
            {
                if (s < arr[i][y])
                {
                    s = arr[i][y];
                }
            }
        }
        cout << "max:" << s;

    }

    YarickBochock operator+(const YarickBochock& other) {
    
        YarickBochock<T> varenyki(r, c);

        for (int i = 0; i < r; i++)
        {
            for (int y = 0; y < c; y++)
            {
                varenyki.arr[i][y] = this->arr[i][y] + other.arr[i][y] ;
            }
        }

        return varenyki;


}
    YarickBochock operator*(const YarickBochock& other) {

        YarickBochock<T> varenyki(r, c);

        for (int i = 0; i < r; i++)
        {
            for (int y = 0; y < c; y++)
            {
                varenyki.arr[i][y] = this->arr[i][y] * other.arr[i][y];
            }
        }

        return varenyki;


    }
    YarickBochock operator-(const YarickBochock& other) {

        YarickBochock<T> varenyki(r, c);

        for (int i = 0; i < r; i++)
        {
            for (int y = 0; y < c; y++)
            {
                varenyki.arr[i][y] = this->arr[i][y] - other.arr[i][y];
            }
        }

        return varenyki;


    }
    YarickBochock operator/(const YarickBochock& other) {

        YarickBochock<T> varenyki(r, c);

        for (int i = 0; i < r; i++)
        {
            for (int y = 0; y < c; y++)
            {
                varenyki.arr[i][y] = this->arr[i][y] / other.arr[i][y];
            }
        }

        return varenyki;


    }


};









int main()
{
    YarickBochock <double> sr(2,2);
    YarickBochock <double> sr2(2, 2);
    sr.random();
    sr.show();
    sr.max();
    cout << endl;
    sr2.random();
    sr2.show();
    sr2.min();
    cout << endl;
    YarickBochock <double> sd = sr + sr2;
    sd.show();
    
}


