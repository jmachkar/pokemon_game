#include "gamecommand.h"
#include "input_handling.h"
#include <iostream>
using namespace std;

int main(){

    cout<<endl<<"EC327: Introduction to Software Engineering\n"<<"Fall 2019\n"<<"Programming Assignment 3"<<endl;
    cout<<endl<<"Welcome to Jean Marc Achkar's Pokemon Game!\n\n";
    cout<<"Instructions: \n"<<"- Enter a valid command when prompted, and depending on your command, you will be prompted for additional input!\n";
    cout<<"- To win the game, you must beat all the Pokemon Gyms available before your Pokemon run out of stamina!\n";
    cout<<"- To leave the game at anytime, enter the command 'q'.\n";
    cout<<"Good Luck!"<<endl<<endl;
    cout<<"Game starting in 3...2...1..."<<endl<<endl<<endl;

    const string POKEMON_BANNER = "                                  ,'\\\n"
                              "    _.----.        ____         ,'  _\\   ___    ___     ____\n"
                              "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n"
                              "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n"
                              " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n"
                              "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n"
                              "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n"
                              "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n"
                              "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n"
                              "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n"
                              "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n"
                              "                                `'                            '-._|";

    
    cout << POKEMON_BANNER << endl;
    Model model = Model();
    View view = View();
    char command, TYPE;
    int id, id1, id2;
    double x, y;
    unsigned int stamina, units;

    model.ShowStatus();
    model.Display(view);


    cout<<"Enter command: ";
    cin>>command;

    while(command != 'q'){
        try{
        switch(command){
            case 'm':{
                cout<<"Pokemon id: ";
                cin>>id;
                cout<<"Coordinates: ";
                cin>>x>>y;
                DoMoveCommand(model, id, Point2D(x,y));
                break;
            }
            case 'g':{
                cout<<"Pokemon id: ";
                cin>>id1;
                cout<<"Pokemon Gym id: ";
                cin>>id2;
                DoMoveToGymCommand(model, id1, id2);
                break;
            }
            case 'c':{
                cout<<"Pokemon id: ";
                cin>>id1;
                cout<<"Pokemon Center id: ";
                cin>>id2;
                DoMoveToCenterCommand(model, id1, id2);
                break;
            }
            case 's':{
                cout<<"Pokemon id: ";
                cin>>id;
                DoStopCommand(model, id);
                break;
            }
            case 'r':{
                cout<<"Pokemon id: ";
                cin>>id1;
                cout<<"Stamina amount to recover: ";
                cin>>stamina;
                DoRecoverInCenterCommand(model, id1, stamina);
                break;
            }
            case 't':{
                cout<<"Pokemon id: ";
                cin>>id1;
                cout<<"Amount of units to train: ";
                cin>>units;
                DoTrainInGymCommand(model, id1, units);
                break;
            }
            case 'v':{
                DoGoCommand(model, view);
                model.ShowStatus();
                break;
            }
            case 'x':{
                DoRunCommand(model, view);
                model.ShowStatus();
                break;
            }
            case 'q':{
                model.~Model();
                break;
            }
               case 'b':{
                cout<<"Pokemon id: ";
                cin>>id1;
                cout<<"Rival id: ";
                cin>>id2;
                DoBattleCommand(model, id1, id2);
                break;
            }
            case 'a':{
                cout<<"Pokemon id: ";
                cin>>id1;
                cout<<"Battle Arena id: ";
                cin>>id2;
                DoMoveToArenaCommand(model, id1, id2);
                break;
            }
            case 'n':{
                cout<<"Type: ";
                cin>>TYPE;
                cout<<"Id: ";
                cin>>id;
                cout<<"Coordinates: ";
                cin>>x>>y;
                model.NewCommand(TYPE, id, x, y);
                break;
            }
            default:
                throw Invalid_Input("Invalid command!");
            break;
        }
        }
        catch(Invalid_Input& except){
            cout<<"Error message - "<< except.msg_ptr<<endl;
        }

        cout<<endl<<"Enter command: ";
        cin>>command;
     }
 
    return 0;
}
