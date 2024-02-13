#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#include<vector>
vector<vector<char> > _board;
int Row, Col,command;
void menu() 
{
    cout << "**************************" << endl;
    cout << "******1.开始游戏**********" << endl;
    cout << "******0.退出游戏**********" << endl;
    cout << "**************************" << endl;
}
void menu2()
{
    cout << "************************" << endl;
    cout << "******1.三子棋**********" << endl;
    cout << "******2.五子棋**********" << endl;
    cout << "************************" << endl;
}
void menu3()
{
    cout << "************************" << endl;
    cout << "******1.人机对抗********" << endl;
    cout << "******2.双人对抗********" << endl;
    cout << "************************" << endl;
}
class Player
{
public:

    virtual void BoardPrint()
    {
        cout << "   "; // 额外空格用于列号对齐
        for (size_t j = 0; j < _board[0].size(); j++)
        {
            cout << j + 1 << "   "; // 改变这里保持列号宽度相同
        }
        cout << endl;
        for (size_t i = 0; i < _board.size(); i++)
        {
            cout << i + 1;
            if (i + 1 < 10) 
                cout << " "; // 对于一位数的行号，添加一个空格
            for (size_t j = 0; j < _board[i].size(); j++)
            {
                cout << " " << _board[i][j] << " ";
                if (j < _board[i].size() - 1)
                    cout << "|";
            }
            cout << endl;

            if (i != _board.size() - 1)
            {
                cout << "  "; // 对于一位数的行号，添加额外空格以对齐
                for (size_t j = 0; j < _board[i].size(); j++)
                {
                    cout << "---"; 
                    if (j < _board[i].size() - 1)
                        cout << "+";
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    virtual void Play() = 0;
};

class PeoplePlayer :public Player 
{
public:
    PeoplePlayer(char Mark = '*')
        : _Mark(Mark)
    {}
    void Play() override 
    {

        int x = 0, y = 0;
        BoardPrint();
       
        while (1)
        { 
            
            cout << "请输入坐标>>:";
            cin >> x >> y;

          if (x >= 0 && x <= _board.size() && y >= 0 && y <=_board[0].size()) 
          {
            if (_board[x - 1][y - 1] == ' ') 
            {
                _board[x - 1][y - 1] =_Mark;
                break;
            }
            else
                cout << "该坐标已输入，请重新输入";
          }
          else
             cout << "坐标非法，请重新输入" << endl;
        }
        
    }
protected:
    char _Mark;
};

class AIPlayer :public Player 
{
public:
    void Play() override 
    {
        BoardPrint();
        while (1) 
        {
            int x = rand() % _board.size();
            int y = rand() % _board[0].size();
            if (_board[x][y] == ' ') 
            {
                _board[x][y] = '#';
                break;
            }
        }
        
    }
};
class Game
{
public:
    //游戏选择
    enum Gametype
    {
        sanziqi=3,
        wuziqi=5
    };
    // 添加枚举定义游戏模式
    enum Mode 
    {
        Human_VS_AI,
        Human_VS_Human
    };

    Game(Player* p1, Player* p2, Mode mode,Gametype gametype)
        : _P1(p1), _P2(p2), _mode(mode), _currentPlayer(1),_wincount(gametype)
    {
        Row = Col = gametype == sanziqi ? 3 : 10;
        _board.clear();
        _board.resize(Row, vector<char>(Col, ' '));
    }
    virtual int Isfull()
    {
        for (auto e : _board)
        {
            for (auto e2 : e)
            {
                if (e2 == ' ')
                    return 0;
            }
        }
        return 1;
    }
    virtual char Iswin()
    {
        int count;
       
        //检查列
        for (auto e : _board)
        {
            count = 1;
            auto it = e.begin();
            while (it != e.end())
            {
                if (it + 1 != e.end() && *it == *(it + 1) && *it != ' ')
                {
                    count++;
                    if (count == _wincount)
                        return *it;
                }
                else
                    count = 1;
                it++;
            }
        }
        //检查行
        for (size_t j = 0; j< _board[0].size(); j++)
        {
            count = 1;
            for (int i = 0; i < _board.size()-1; i++)
            {
                if (_board[i][j] == _board[i + 1][j] && _board[i][j] != ' ')
                {
                    count++;
                    if (count == _wincount)
                    {
                        return _board[i][j];
                    }
                }
                else
                    count = 1;
            }
        }
        //检查主对角线
        for (size_t i = 0; i <= _board.size() - _wincount; i++)
        {
            for (size_t j = 0; j <= _board[0].size() - _wincount; j++)
            {
                for (size_t k = 0; k < _wincount -1; k++)
                {
                    if (_board[i + k][j + k] == _board[i + k + 1][j + k + 1] && _board[i][j] != ' ')
                    {
                        count++;
                        if (count == _wincount)
                        {
                            return _board[i][j];
                        }

                    }
                    else
                        count = 1;
                }
            }
        }
        //检查副对角线
        for (size_t i = 0; i <= _board.size() - _wincount; i++)
        {
            for (size_t j = _board[0].size() - 1; j >= _wincount-1; j--)
            {
                for (size_t k = 0; k < _wincount - 1; k++)
                {
                    if(_board[i + k][j - k] == _board[i + k + 1][j - k - 1] && _board[i][j] != ' ')
                    {
                        count++;
                        if (count == _wincount)
                        {
                            return _board[i][j];
                        }

                    }
                    else
                        count = 1;
                }
            }
        }
        if (Isfull())
        {
            return 'p';
        }
        return 'c';
    }
    void Gamework()
    {
        while (1)
        {
            if (_mode == Human_VS_Human)
            {
                cout << "玩家" << _currentPlayer << "的回合" << endl;
                if (_currentPlayer == 1)
                {
                    _P1->Play();
                }
                else
                {
                    _P2->Play();
                }
                // 切换玩家
                _currentPlayer = _currentPlayer == 1 ? 2 : 1;
            }
            else
            {
                // 人机对抗模式
                cout << "玩家的回合" << endl;
                _P1->Play();
                if (Iswin() != 'c')
                {
                    break;
                }
                cout << "电脑的回合" << endl;
                _P2->Play();
            }

            // 检查游戏是否胜利或平局
            if (Iswin() != 'c')
            {
                break;
            }
        }
        _P1->BoardPrint();
        if (_mode == Human_VS_AI)
        {
            if (Iswin() == '*')
                cout << "恭喜玩家赢得胜利" << endl;
            else if (Iswin() == '#')
                cout << "很遗憾，游戏失败" << endl;
            else
                cout << "平局" << endl;
        }
        else
        {
            if (Iswin() == '*')
                cout << "恭喜玩家1赢得胜利" << endl;
            else if (Iswin() == '$')
                cout << "恭喜玩家2赢得比赛" << endl;
            else
                cout << "平局" << endl;
        }
       
      
        
    }
    ~Game()
    {
        delete _P1;
        delete _P2;
    }
private:
    Player* _P1;
    Player* _P2;
    Gametype _gametype;//游戏类别
    Mode _mode; // 新增游戏模式变量
    int _currentPlayer; // 当前玩家
    int _wincount;
};

int main() 
{
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        cout << "请输入指令>>:";
        cin >> command;
        switch (command)
        {
        case 1:   
        {
            Game* game=nullptr;
            menu2();
            int gameTypeChoice;
            cout << "请选择游戏类型>>:";
            cin >> gameTypeChoice;
            cout << endl;

            Game::Gametype gametype = gameTypeChoice == 1 ? Game::sanziqi : Game::wuziqi;
            menu3();
            int choice;
            cout << "请选择模式>>:";
            cin >> choice;
            cout << endl;

            if (choice == 1)
            {
                 game=new Game(new PeoplePlayer, new AIPlayer,Game::Human_VS_AI,gametype);
            }
            else
                 game = new Game(new PeoplePlayer, new PeoplePlayer('$'),Game::Human_VS_Human,gametype);
            game->Gamework();
            break;
            delete game;
        }  
        case 0:
        {
           cout << "退出游戏" << endl;
           break;
        }
 
        default:
            cout << "输入错误，请重新选择"<<endl;
        }
    } while (command);
    return 0;
}