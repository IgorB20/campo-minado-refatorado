#include "../headers/libCampoMinado.h"
#include <iostream>
#include <time.h>

using namespace std;

void init(Game &game)
{
    cout << "Insira o numero de linhas e colunas" << endl;
    cin >> game.field.lines >> game.field.columns;

    cout << "Insira o numero de bombas" << endl;
    cin >> game.field.bombsAmount;

    generateField(game.field);
    generateBombs(game.field);
    setCoordinatesBombsAroundAmount(game.field);
    showField(game.field);
    startMainLoop(game);
}

void startMainLoop(Game &game){
    Position position;
    do
    {
        getUserInput(position, game);
        game.playsAmount++;

        if(checkGameOver(game.field, position)){
            cout << "PERDEU!!" << endl;
            game.endGame = true;
            break;
        }

        if(checkVictory(game)){
            cout << "GANHOU!!" << endl;
            game.endGame = true;
            break;
        }
        game.field.tiles[position.x][position.y].revealed = true;

        showField(game.field);
       

    }
    while(!game.endGame);

    showRevealedField(game.field);
}

void getUserInput(Position &position, Game game){
   cout<<"Insira as linhas e colunas que voce vai jogar"<<endl;
   cin>>position.x >> position.y; //entrada das coordenadas das jogadas
   while(validateUserInput(position, game) == false){
       cout<<"Insira novamente as linhas e colunas que voce vai jogar"<<endl;
       cin>>position.x >> position.y;
   }
}

bool validateUserInput(Position position, Game game){
    if(game.field.tiles[position.x][position.y].revealed){
        cout << "Coordenada ja jogada!! Tente novamente" << endl; 
        return false;
    }
   

    return true;
}

void generateField(Field &field)
{

    for (int i = 0; i < field.lines; i++)
    {
        for (int j = 0; j < field.columns; j++)
        {
            field.tiles[i][j] = {}; //intancia um Tile em cada posição da matriz
        }
    }
}

void generateBombs(Field &field)
{
    srand(time(NULL));
    for (int i = 0; i < field.bombsAmount; i++)
    {
        int random_row, random_col;

        random_row = rand() % field.lines;
        random_col = rand() % field.columns;

        //verificar se no campo já não possui uma bomba nessas coordenadas
        while (field.tiles[random_row][random_col].isBomb)
        {

            random_row = rand() % field.lines;
            random_col = rand() % field.columns;
        }

       field.tiles[random_row][random_col].isBomb = true;
    }
}

void setCoordinatesBombsAroundAmount( Field &field ){
    for (int i = 0; i < field.lines; i++)
    {
        for (int j = 0; j < field.columns; j++)
        {
            int currentCoordinateBombAmount = 0;
            if(field.tiles[i][j].isBomb == false){

                //CONTAGEM DAS BOMBAS AO REDOR DE UMA COORDENADA
                if( i>0 && j>0 && field.tiles[i-1][j-1].isBomb)currentCoordinateBombAmount++;
                if( j>0 && field.tiles[i][j-1].isBomb) currentCoordinateBombAmount++;
                if( i < (field.lines - 1)&& j > 0 && field.tiles[i+1][j-1].isBomb) currentCoordinateBombAmount++;
                if( i > 0 && field.tiles[i-1][j].isBomb) currentCoordinateBombAmount++;
                if( i < (field.lines-1) && field.tiles[i+1][j].isBomb) currentCoordinateBombAmount++;
                if( i > 0 && j < (field.columns -1) && field.tiles[i-1][j+1].isBomb) currentCoordinateBombAmount++;
                if( j < (field.columns - 1) && field.tiles[i][j+1].isBomb) currentCoordinateBombAmount++;
                if( i < (field.columns -1) && j < (field.columns -1) && field.tiles[i+1][j+1].isBomb) currentCoordinateBombAmount++;

                field.tiles[i][j].bombsAroundAmount = currentCoordinateBombAmount;
                currentCoordinateBombAmount = 0;
            }
        }
    }
}

void showField(Field field)
{

    for (int i = 0; i < field.lines; i++)
    {
        for (int j = 0; j < field.columns; j++)
        {
          if(field.tiles[i][j].revealed){
             
            cout << field.tiles[i][j].bombsAroundAmount << " ";
              
          }else{
              cout << "- ";
          }
          
        }
        cout << endl;
    }
}

 void showRevealedField( Field field ){
      for (int i = 0; i < field.lines; i++)
    {
        for (int j = 0; j < field.columns; j++)
        {
          if(field.tiles[i][j].isBomb){
            cout << "x ";
          }else{
            cout << field.tiles[i][j].bombsAroundAmount << " ";
          }
          
        }
        cout << endl;
    }
 }

bool checkGameOver( Field field, Position position ){
    if(field.tiles[position.x][position.y].isBomb) return true;
    return false;
} 

bool checkVictory(Game game){
    if(game.playsAmount == (game.field.lines * game.field.columns) - game.field.bombsAmount) return true;
    return false;
}
