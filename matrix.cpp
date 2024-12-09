#include <iostream>
using namespace std;
int main(){
    int N, M;
    cin >> N;
    cin >> M;
    int** matrix = new int*[N];
    for (int i = 0; i < N; ++i){
        matrix[i] = new int[M];
    }
    for (int i = 0; i < N; ++i){
        for (int j = 0 ; j < M; ++j){
            cin>> matrix[i][j];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j){
           cout <<  matrix[i][j] << " ";
        }
        cout << "\n";
    }
    int *arr = new int[N];
    for (int i = 0; i < N; ++i){
        bool fl = true;
        
            int j  = M /2 - 1;
            int p = matrix[i][0];
            int h = matrix[i][M-1];
            //cout<< " =========" << h <<" "<< p << endl;
            for (int k = 0; k <= j; ++k){
                if (h == p){
              //      cout <<"!" << h << " "<< p << endl;
                    h = matrix[i][M-1-k];
                    p = matrix[i][k];
                    continue;
                } else {
                //    cout <<"@" << h << " "<< p<< " " << endl;
                    fl = false;
                    break;
                }
            }    
         
        // else {
        //     int j  = M /2 - 1;
        //     int p = matrix[i][0];
        //     int h = matrix[i][M-1];
        //   //  cout << " /////////" << *p << " " << *h<< " "<< j <<  endl;
        //     for (int k = 0; k <= j; ++k){
        //         if (h == p){
        //             //cout <<"!" << *h << " "<< *p<< endl;
        //             h = matrix[i][M-1-k];
        //             p = matrix[i][k];
        //              continue;
        //         } else {
        //             //cout <<"@" << *h << " "<< *p<< endl;
        //             fl = false;
        //             break;
        //         }
        //     }   

        // }
        if (fl == true){
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    }
    cout << endl;
    for (int i = 0; i < N; ++i){
        cout << arr[i] << " ";
    }
   
    delete[] arr; 
    for (int i = 0; i < N; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
    cout <<"\n" << "Yipe!!!";
}