#include <iostream>
#include <time.h>
#include <vector>
#include <cstdlib>


using namespace std;

int main()
{
    int linhas,colunas,bombs,jogadas = 0,x,y;
    bool endGame = false;
    srand(time(NULL));

    while(linhas<=1 || colunas<=1)
    {
        cout<<"Insira o numero de linhas e colunas"<<endl;
        cin>>linhas>>colunas;
        //entrada de linhas e colunas
        if (linhas>=2 && colunas>=2)
        {
            cout<<"Insira o numero de bombas"<<endl; //entrada de número de bombas
            cin>>bombs;
            while(bombs<2) //mínimo de tamanho e de bombas
            {

                cout<<"Insira o numero de bombas"<<endl; //entrada de número de bombas
                cin>>bombs;
            }
        }
    }
    char field[linhas][colunas];
    char bombs_positions[linhas][colunas];

    //GERAR O CAMPO
    cout << "  ";
    for(int j=0; j<colunas; j++)
    {
        cout << j << " ";
    }
    cout << endl;
    for(int i=0; i<linhas; i++)
    {
        for(int j=0; j<colunas; j++)
        {
            field[i][j] = '-';
            bombs_positions[i][j] = '0';
            if(j == 0)  //mostrar a numeração das linhas
            {
                cout << i << " ";
            }
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

    //gerar posições de bombas aleatórias
    for(int i=0; i<bombs; i++)
    {
        int random_row, random_col;

        random_row = rand()%linhas;
        random_col = rand()%colunas;

        //verificar se no campo já não possui uma bomba nessas coordenadas
        while(bombs_positions[random_row][random_col] == 'x')
        {
            random_row = rand()%linhas;
            random_col = rand()%colunas;
        }

        bombs_positions[random_row][random_col] = 'x';
    }

    //informar a quantidade de bombas ao redor de cada coordenada
    int currentCoordinateBombAmount = 0;

    for(int i=0; i<linhas; i++)
    {
        for(int j=0; j<colunas; j++)
        {
            if(bombs_positions[i][j] != 'x')
            {
                /*
                Nas linhas abaixo ocorre a contagem das bombas ao redor de cada coordenada,
                como no exemplo:
                    |x|x|x|
                    |x|o|x|
                    |x|x|x|
                */
                if( i>0 && j>0 && bombs_positions[i-1][j-1] == 'x')currentCoordinateBombAmount++;
                if( j>0 && bombs_positions[i][j-1] == 'x') currentCoordinateBombAmount++;
                if( i < (linhas - 1)&& j > 0 && bombs_positions[i+1][j-1] == 'x') currentCoordinateBombAmount++;
                if( i > 0 && bombs_positions[i-1][j] == 'x') currentCoordinateBombAmount++;
                if( i < (linhas-1) && bombs_positions[i+1][j] == 'x') currentCoordinateBombAmount++;
                if( i > 0 && j < (colunas -1) && bombs_positions[i-1][j+1] == 'x') currentCoordinateBombAmount++;
                if( j < (colunas - 1) && bombs_positions[i][j+1] == 'x') currentCoordinateBombAmount++;
                if( i < (linhas -1) && j < (colunas -1) && bombs_positions[i+1][j+1] == 'x') currentCoordinateBombAmount++;

                bombs_positions[i][j] = currentCoordinateBombAmount + '0';//"conversão" de int para pra char
                currentCoordinateBombAmount = 0;

            }


        }
    }
    do
    {
        cout<<"Insira as linhas e colunas que voce vai jogar"<<endl;
        cin>>x>>y; //entrada das coordenadas das jogadas
        jogadas++; //contador de jogadas
        field[x][y] = bombs_positions[x][y]; //posições da tela do jogador e tela das bombas

        //MOSTRAR CAMPO DO JOGADOR
        cout << "  ";
        for(int j=0; j<colunas; j++)
        {
            cout << j << " ";
        }
        cout << endl;
        for(int i=0; i<linhas; i++)
        {
            for(int j=0; j<colunas; j++)
            {
                if(j == 0)  //mostrar a numeração das linhas
                {
                    cout << i << " ";
                }
                cout << field[i][j] << " ";
            }
            cout << endl;
        }

        //CONFERIR DERROTA
        if(bombs_positions[x][y] == 'x')
        {
            endGame = true;
            cout << "PERDEU!" << endl << "Jogadas: " << jogadas<<endl;
        }

        //CONFERIR VITÓRIA
        if(jogadas == (linhas * colunas) - bombs)
        {
            endGame = true;
            cout << "GANHOU!" << endl << "Jogadas: " << jogadas<<endl;
        }

        //MOSTRAR CAMPO REVELADO
        if(endGame)
        {
            cout << "Campo revelado: " << endl;
            for(int i=0; i<linhas; i++)
            {
                for(int j=0; j<colunas; j++)
                {
                    cout << bombs_positions[i][j] << " ";
                }
                cout << endl;
            }
        }

    }
    while(!endGame);

    return 0;
}
