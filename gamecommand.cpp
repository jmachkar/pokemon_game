#include "gamecommand.h"
#include <iostream>
using namespace std;

void DoMoveCommand(Model & model ,int pokemon_id, Point2D p1){
    Pokemon * pokemon_ptr = model.GetPokemonPtr(pokemon_id);
    if(pokemon_ptr == 0){ //if NULL pointer 
        // cout<<"Error: Please enter a valid command!"<<endl;
        throw Invalid_Input("Not valid Id");
    }
    else{
        cout<<"Moving "<<pokemon_ptr->GetName()<<" to "<<p1<<endl;
        pokemon_ptr->StartMoving(p1);
    }
}

void DoMoveToCenterCommand(Model & model, int pokemon_id, int center_id){
    Pokemon * pokemon_ptr = model.GetPokemonPtr(pokemon_id);
    PokemonCenter * center_ptr = model.GetPokemonCenterPtr(center_id);
    if(pokemon_ptr == 0 || center_ptr == 0){
        // cout<<"Error: Please enter a valid command!"<<endl;
        throw Invalid_Input("Not valid Id");
    }
    else{
        cout<<"Moving "<<pokemon_ptr->GetName()<<" to center "<<center_ptr->GetId()<<endl;
        pokemon_ptr->StartMovingToCenter(center_ptr);
    }  
}

void DoMoveToGymCommand(Model & model, int pokemon_id, int gym_id){
    Pokemon * pokemon_ptr = model.GetPokemonPtr(pokemon_id);    
    PokemonGym * gym_ptr = model.GetPokemonGymPtr(gym_id);
    if(pokemon_ptr == 0 || gym_ptr == 0){
        // cout<<"Error: Please enter a valid command!"<<endl;
        throw Invalid_Input("Not valid Id");
    }
    else{
        cout<<"Moving "<<pokemon_ptr->GetName()<<" to gym "<<gym_ptr->GetId()<<endl;
        pokemon_ptr->StartMovingToGym(gym_ptr);
    }
}

void DoStopCommand(Model & model, int pokemon_id){
    Pokemon * pokemon_ptr = model.GetPokemonPtr(pokemon_id);    
    if(pokemon_ptr == 0){
        // cout<<"Error: Please enter a valid command!"<<endl;
        throw Invalid_Input("Not valid Id");
    }
    else{
        cout<<"Stopping "<<pokemon_ptr->GetName()<<" "<<pokemon_ptr->GetCode()<<pokemon_ptr->GetId()<<endl;
        pokemon_ptr->Stop();
    }  
}

void DoTrainInGymCommand(Model & model, int pokemon_id, unsigned int training_units){
    Pokemon * pokemon_ptr = model.GetPokemonPtr(pokemon_id); 
    if(pokemon_ptr == NULL){
        // cout<<"Error: Please enter a valid command!"<<endl;
        throw Invalid_Input("Not valid Id");
    }
    else{
        cout<<"Training "<<pokemon_ptr->GetName()<<endl;
        pokemon_ptr->StartTraining(training_units);
    }  
}

void DoRecoverInCenterCommand(Model & model, int pokemon_id, unsigned int stamina_points){
    Pokemon * pokemon_ptr = model.GetPokemonPtr(pokemon_id); 
    if(pokemon_ptr == 0){
        // cout<<"Error: Please enter a valid command!"<<endl;
        throw Invalid_Input("Not valid Id");
    }
    else{
        cout<<"Recovering "<<pokemon_ptr->GetName()<<"'s stamina"<<endl;
        pokemon_ptr->StartRecoveringStamina(stamina_points);
    }  
}


void DoGoCommand(Model & model, View & view){
    cout<<"Advancing one tick."<<endl;
    model.Update();
    model.Display(view);
}

void DoRunCommand(Model & model, View & view){
    bool u;
    for(int i=0; i<5; i++){ //Advancing 5 ticks or until update returns true;
        cout<<"Advancing one tick."<<endl;
        u = model.Update();
        model.Display(view);
        if(u){
            return;
        }
    }
    return;
}

void DoBattleCommand(Model &model, int pokemon_id, int rival_id){
    Pokemon * pokemon_ptr = model.GetPokemonPtr(pokemon_id);
    Rival * rival_ptr = model.GetRivalPtr(rival_id); 
    if(pokemon_ptr == 0){
        // cout<<"Error: Please enter a valid command!"<<endl;
        throw Invalid_Input("Not valid Id");
    }
    else{
        // cout<<"Training "<<pokemon_ptr->GetName()<<endl;
        pokemon_ptr->ReadyBattle(rival_ptr);
    }  
}

void DoMoveToArenaCommand(Model &model, int pokemon_id, int arena_id){
    Pokemon * pokemon_ptr = model.GetPokemonPtr(pokemon_id);    
    BattleArena * arena_ptr = model.GetBattleArenaPtr(arena_id);
    if(pokemon_ptr == 0 || arena_ptr == 0){
        // cout<<"Error: Please enter a valid command!"<<endl;
        throw Invalid_Input("Not valid Id");
    }
    else{
        cout<<"Moving "<<pokemon_ptr->GetName()<<" to battle arena "<<arena_ptr->GetId()<<endl;
        pokemon_ptr->StartMovingToArena(arena_ptr);
    }
}
