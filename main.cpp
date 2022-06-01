#include <iostream>
#include <fstream>
#include <string>
#include <random>


using namespace std;

int random(int min, int max)
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) );
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

struct Vector2{

    public:
    int x;
    int y;

    Vector2(int aA, int aB){
        x = aA;
        y = aB;
        
    }

    int sum(){
        return x + y;
    }


};

Vector2 Position(int randA, int randB){

    Vector2 snake(randA, randB);

    return snake;
}

void Draw(){

    int randX = random(5, 13);
    int randY = random(5, 9);
    int height = 17;
    int full_length = 15;
    char upper = '-';
    char side = '|';
    char mid_char = ' ';
    char snake_char = '*';


    
    for (int i = 0; i < height; i++){
        cout << upper;
        if (i == (height-1)){
            cout << endl;
        }
    }
    
    for (int y = 0; y < height; y++){
        
        cout << side;
        for (int x = 0; x < full_length; x++){
            if (x == Position(12, 8).x){
                if (y == Position(9, 8).y){
                    cout << snake_char;
                }
                else{
                    cout << mid_char;
                }
            }
            else{
                cout << mid_char;
            }
        }
        cout << side << endl;
    }
    for (int i = 0; i < height; i++){
        cout << upper;
        if (i == (height-1)){
            cout << endl;
        }
    }
    



}


int main() {


  Draw();
  


    return 0;
}