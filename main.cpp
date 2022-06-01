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
 

char insert;
int randX = random(5, 13);
int randY = random(5, 9);


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

Vector2 snake(randX, randY);
vector<Vector2> snakeParts;

void Position(Vector2 &snake){
    
    cin >> insert;
    switch(insert){

        case 'd':
        snake.x += 1;
        break;

        case 'a':
        snake.x -= 1;
        break;

        case 'w':
        snake.y -= 1;
        break;

        case 's':
        snake.y += 1;
        break;

        default:
        cout << "Enter a valid direction" << endl;
        break;

    }

    

}

void Draw(){

    
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
            if (x == snake.x){
                if (y == snake.y){
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
    bool game = true;
    while (game){
        Draw();
        Position(snake);
    }
  
  


    return 0;
}