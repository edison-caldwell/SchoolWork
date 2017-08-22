#include "gm.h"

GameMaster* GameMaster::gm = NULL;

Board* GameMaster::board = NULL;

bool GameMaster::gm_loaded = false;

bool GameMaster::Elgeon = false;

const int GameMaster::PARTY_SIZE = 4;


GameMaster::GameMaster( )
{
  
}


GameMaster::~GameMaster( )
{
  //cout << "destructor\n\n";
  Creature* temp = NULL;
  
  for(int i = 0; i < PARTY_SIZE; i++)
  {
    temp = fiesta.front();
    fiesta.pop( );
    delete temp;
  }
  
  while(!armament.empty( ))
  {
    delete armament.back( );
    armament.pop_back( );
  }
 
  board->DeleteBoard( );
  
  //SkillRules::DeleteSkillRules( );
}


GameMaster* GameMaster::GetGM( )
{
  if(!gm)
    gm = new GameMaster;
  
  return gm;
}


void GameMaster::DeleteGM( )
{
  delete gm;
}


queue< Creature* > GameMaster::SearchParty( ) const
{
  return fiesta;
}


set<string> GameMaster::ActivePlayers( ) const
{
  return active_players;
}


map< string, int > GameMaster::Inventory( ) const
{
  return inventory;
}


vector< EquipClass* > GameMaster::Armament( ) const
{
  return armament;
}


void GameMaster::InitBoard(int row, int column)
{
  Board::CreateBoard(row, column);
  board = Board::GetBoard( );
}


void GameMaster::InitSearchParty( )
{
  Creature* temp = new Creature("JAMIAN", Creature::HUMAN);
  temp->FindEquipment(new ArmorClass("large wooden shield"));
  temp->FindEquipment(new WpnClass("sword"));
  
  fiesta.push(temp);

  
  temp = new Creature("ADEAK", Creature::ELF);
  temp->FindEquipment(new WpnClass("quarter staff"));
  temp->FindEquipment(new WpnClass("short bow"));
  
  fiesta.push(temp);

  
  temp = new Creature("PANROS", Creature::HALFELF, VocRules::CLR);
  temp->FindEquipment(new ArmorClass("small wooden shield"));
  temp->FindEquipment(new WpnClass("long sword"));
  
  fiesta.push(temp);

  
  temp = new Creature("KEVKUL", Creature::ORC, VocRules::ROG);
  temp->FindEquipment(new WpnClass("short bow"));
  temp->FindEquipment(new ArmorClass("leather"));
  temp->FindEquipment(new WpnClass("rapier"));
  
  fiesta.push(temp);

  for(int i = 0; i < PARTY_SIZE; i++)
  {
    temp = fiesta.front( );
    temp->UpdateXP(76000);
    temp->UpdateGP(25);   
    fiesta.pop( );
    fiesta.push(temp);
  }
  
  InitActivePlayers( );
}


void GameMaster::WriteParty( )
{
  queue<Creature*> party = SearchParty( );
  
  Creature* temp = NULL;
  
  for(int i = 0; i < PARTY_SIZE; i++)
  {
    temp = party.front( );
    temp->Write(cout); 
    cout << " ";
    party.pop( );
    party.push(temp);
  }
  
  cout << endl;
}

void GameMaster::InitArmament( ) 
{
  string item;
  string temp;
  int amount = 0;
  fstream shrek; //Shrek hold no meaning to the file. I like shrek :D
  
  shrek.open(GameSpace::ARMAMENT_FILE.c_str( ));
  
  getline(shrek,item,'#'); //Prime read
  
  while(shrek)
  {
    getline(shrek, temp);
    amount = atoi(temp.c_str( ));
    
    inventory.insert((make_pair(item,amount)));
    
    if(ArmorClass::IsEquipment(item))
    {
      for(int i = 0; i < amount; i++)
	armament.push_back(new ArmorClass(item));
    }
    else if(WpnClass::IsEquipment(item))
    {
      for(int i = 0; i < amount; i++)
	armament.push_back(new WpnClass(item));
    }
    
    getline(shrek,item,'#'); 
  }
  shrek.close( );
  
}



void GameMaster::Deployment( )
{
  Creature* lead = fiesta.front( );
  EquipClass* found = NULL;
  EquipClass* swap = NULL;
  string item;
  
  item = Interface::GetEquipment(cout,cin);
  
  vector<EquipClass*>::iterator erase_me;

  bool find = false;
  
  for(vector<EquipClass*>::iterator it = armament.begin( ); it != armament.end( ) && !find; it++)
  { 
    if((*it)->Name( ) == item)
    {
      found = *it;
      erase_me = it;
      find = true;
    }
  }
 
  if(find)
  {    
    armament.erase(erase_me);
  
    if(dynamic_cast<WpnClass*>(found))
    {
      swap = lead->LoseWeapon( );
      lead->FindEquipment(found);
      armament.push_back(swap);
    }
    else if(dynamic_cast<ArmorClass*>(found))
    {
      swap = lead->LoseArmor( );
      lead->FindEquipment(found);
      armament.push_back(swap);
    }
  
    inventory.find(item)->second -= 1;
  
    if(inventory.find(item)->second <= 0)
      inventory.erase(item);
  
    if(inventory.find(swap->Name( )) == inventory.end( ))
      inventory.insert(make_pair(swap->Name( ), 1));
    else
      inventory.find(swap->Name( ))->second += 1;
  }
  
  
  
}


void GameMaster::InitActivePlayers( )
{
  Creature* temp;
  for(int i = 0; i < PARTY_SIZE; i++)
  {
    temp = fiesta.front( );
    fiesta.pop( );
    
    active_players.insert(temp->Name( ));
    
    fiesta.push(temp);
  }
}


void GameMaster::MoveSearchParty()
{
  pair<int, int> move;
  if(fiesta.front( )->Row( ) == -1)
  {
    move = Interface::GetFirstMove(cout, cin);
    board->PlaceCreatures(fiesta, move);
  }
  else
  {
    move = Interface::GetMove(cout, cin);
    board->MoveCreatures(fiesta, move);
  }
}


void GameMaster::Healing( )
{
//   WriteParty( );
//   cout << endl << endl;
  
  Creature* target = fiesta.front( );
  int healcheck = 0;
  
  if(!target->Dead( ) && !target->Active( ))
  {
    healcheck = target->SkillCheck("heal");

    target->UpdateHP(healcheck);
  }
  
  if(!target->Active( ) && !target->Dead( ) && healcheck == 0)
  {
    fiesta.pop( );
    fiesta.push(target);
    
    for(int j = 0; j < (PARTY_SIZE - 1); j++)
    {
      Creature* healer = fiesta.front( );
      fiesta.pop( );
      
      if(healer->Active( ) && !target->Active( ))
	target->UpdateHP(healer->SkillCheck("heal"));
      
      fiesta.push(healer);
    }
    
    
  }
  
  if(!target->Active( ))
      active_players.erase(target->Name( ));
}




void GameMaster::UpdateLeader( )
{
  int count = 0;
  
//   WriteParty( );
//   cout << endl << endl;
  
  Creature* temp = fiesta.front( );
  fiesta.pop( );
  fiesta.push(temp);
  
  while(!fiesta.front( )->Active() && count < 3)
  {
    temp = fiesta.front( );
    fiesta.pop( );
    fiesta.push(temp);
    count++;
  }
/*  
  WriteParty( );
  cout << endl << endl;*/
}


bool GameMaster::GameOver()
{ 
  if(ActivePlayers().size( ) == 0 || Encounter::IsRescued( ))
    return true;
  else
    return false;
}
