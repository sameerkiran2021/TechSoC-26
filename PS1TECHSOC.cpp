 #include<iostream>
 #include<string>
 #include<vector>
 #include<cmath>
 #include <cstdlib>
#include <ctime> 
 using namespace std;
struct Moves{
    string move;
    int power;
};
class Bender{
    public :
    string name;
    string type;
    int HP; 
    int Attack;
    int Defense;
    int Speed;
    vector<Moves> move;
    Bender(string n,string t,int health,int A,int D,int S,vector<Moves> m){
      name=n;
      type=t;
      HP=health;
      Attack=A;
      Defense=D;
      Speed=S;
      move=m;
      cout<<n<< " (" <<t<< ") HP: "<<health<<"/"<<health<< " | Attack: " <<A<<" | Defense: "<<D<< " | Speed: " <<S<<"\n";
      for(int i=0;i<4;i++){
        cout<<move[i].move<<" ("<< move[i].power<<") ";
      }
      cout<<"\n";
    }
   int dama(int a,int p,int d){
     int damage;
     damage=round((double)(a*p)/d);
     return damage;}
     int nhealth(int health,int damage){
int newhealth=0;
newhealth=health-damage;
if(newhealth<0){
    newhealth=0;
}
return newhealth;}
void display_stats(int currenthp){
     cout << name << " (" << type << ") HP: " << currenthp << "/" << HP 
             << " | Attack: " << Attack << " | Defense: " << Defense << " | Speed: " << Speed << "\n";
        for (int i = 0; i < 4; i++) {
            cout << " - " << move[i].move << " (" << move[i].power << ")";
        }
        cout << "\n"<<"\n";
    }
};
int main(){
    srand(time(0)); 
   
vector<Bender> selection= {Bender{"Zephyr", "Air", 28, 12, 50, 95,
               {{"Gust", 0}, {"Wind Slap", 18}, {"Tumble", 12}, {"Cyclone", 22}}},
    // Create strong Doran 
 Bender("Doran", "Earth", 145, 80, 75, 40,
                 {{"Boulder Throw", 75}, {"Rock Fist", 42}, {"Tremor", 48}, {"Mountain Crush", 85}}),
   
 Bender("Nadia", "Water", 85, 48, 60, 72,
              {{"Wave Crash", 35}, {"Splash Kick", 25}, {"Guard", 0}, {"Riptide", 50}}),

 Bender("Talon", "Air", 90, 52, 55, 72,
              {{"Gale Strike", 38}, {"Wind Cutter", 28}, {"Updraft", 0}, {"Cyclone Blast", 48}})};
 int p1;
 int p2;
 Bender *ptr1;
 Bender *ptr2;
 cout<<"Choose the first player 1/2/3/4\n";
 cin>>p1;
 cout<<"Choose the second player 1/2/3/4\n";
 cin>>p2;
 ptr1=&selection[p1-1];
 ptr2=&selection[p2-1];

 cout<<"Batlle is between "<<(*ptr1).name<<" and "<<(*ptr2).name<<"\n";
  cout<<"===Duel Begins===\n";

 Bender *first_player ;
    Bender *second_player ;
if((*ptr1).Speed>(*ptr2).Speed){
   first_player = ptr2;
        second_player = ptr1;
}else if((*ptr2).Speed>(*ptr1).Speed){
   first_player = ptr2;
        second_player = ptr1;
}else {
    if (rand() % 2 == 0) {
       first_player = ptr1;
        second_player = ptr2;
    } else {
       first_player = ptr1;
        second_player = ptr2;
    }
}
 int first_player_choose=0;
 int first_player_editchoice=0;
 int second_player_choose=0;
 int second_player_editchoice=0;
 int second_player_power=0;
int first_player_power=0;
int damage_to_first_player=0;
int damage_to_second_player=0;
int first_player_hp = (*first_player).HP;
int second_player_hp = (*second_player).HP;
 int ptr1_hp = (*ptr1).HP;
    int ptr2_hp = (*ptr2).HP;
    double multiplier=0;
if((*first_player).type=="Water" && (*second_player).type=="Fire" ){
    multiplier=2;
    cout<<"Fire is weak against Water\n";
}else if((*first_player).type=="Air" && (*second_player).type=="Earth"){
    multiplier=2;
    cout<<"Earth is weak against Air\n";
}else if((*first_player).type=="Fire" && (*second_player).type=="Air"){
    multiplier=2;
    cout<<"Air is weak against Fire\n";
}else if((*first_player).type=="Earth" && (*second_player).type=="Water"){
    multiplier=2;
    cout<<"Water is weak against Earth\n";
}else if((*first_player).type=="Fire" && (*second_player).type=="Water" ){
    multiplier=0.5;
    cout<<"Fire is weak against Water\n";
}else if((*first_player).type=="Earth" && (*second_player).type=="Air"){
    multiplier=0.5;
    cout<<"Earth is weak against Air\n";
}else if((*first_player).type=="Air" && (*second_player).type=="Fire"){
    multiplier=0.5;
    cout<<"Air is weak against Fire\n";
}else if((*first_player).type=="Water" && (*second_player).type=="Earth"){
    multiplier=0.5;
    cout<<"Water is weak against Earth\n";
}else{multiplier=1;}
while(ptr1_hp>0 && ptr2_hp>0){
    for(int i=0;i<4;i++){
        if(i%2==0){
    cout<<"Which attack number do you want to use by " <<(*first_player).name<<": 1/2/3/4?\n";
 cin>>first_player_choose;
 first_player_editchoice=first_player_choose-1;
 cout<<(*first_player).name<<" choose "<<(*first_player).move[first_player_editchoice].move<<"\n";
 first_player_power=(*first_player).move[first_player_editchoice].power;
  first_player_hp=(*first_player).nhealth(first_player_hp, damage_to_first_player);
damage_to_second_player=multiplier*(*first_player).dama((*first_player).Attack,first_player_power, (*second_player).Defense);
  if (rand() % 10 == 0) {
    damage_to_second_player *= 2; 
    cout << " CRITICAL HIT!\n";
}
second_player_hp=(*second_player).nhealth(second_player_hp, damage_to_second_player);
if(first_player == ptr1) {
    ptr1_hp = first_player_hp;
    ptr2_hp = second_player_hp;
} else {
  ptr2_hp = first_player_hp;
  ptr1_hp = second_player_hp;}
   cout<<(*second_player).name<<" took "<<damage_to_second_player<<" damage.\n";
  cout<<(*second_player).name<<" HP: "<<second_player_hp<<"/"<<(*second_player).HP<<"\n";
 
}if(first_player_hp<=0 ){
 cout<<(*first_player).name<<" fainted \n"<<"Winner is "<<(*second_player).name<<"\n";

 return 0;
 }
 else if(second_player_hp<=0){
     cout<<(*second_player).name<<" fainted \n"<<"Winner is "<<(*first_player).name<<"\n";
    return 0;}
   
else if(i%2!=0){ cout<<"Which attack number do you want to use by "<<(*second_player).name<<": 1/2/3/4?\n";
 cin>>second_player_choose;
 second_player_editchoice=second_player_choose-1;
  cout<<(*second_player).name<<" choose "<<(*second_player).move[second_player_editchoice].move<<"\n";
  second_player_power=(*second_player).move[second_player_editchoice].power;
damage_to_first_player=(*second_player).dama((*second_player).Attack,second_player_power, (*first_player).Defense);
if (rand() % 10 == 0) {
    damage_to_first_player *= 2; 
    cout << " CRITICAL HIT!\n";}

first_player_hp=(*first_player).nhealth(first_player_hp, damage_to_first_player);
if(first_player == ptr2) {
    ptr2_hp = first_player_hp;
     ptr1_hp = second_player_hp;
} else {
   ptr1_hp = first_player_hp;
  ptr2_hp = second_player_hp;}
   cout<<(*first_player).name<<" took "<<damage_to_first_player<<" damage."<<"\n";
  cout<<(*first_player).name<<" HP: "<<first_player_hp<<"/"<<(*first_player).HP<<"\n";
 
}if(first_player_hp<=0 ){
 cout<<(*first_player).name<<" fainted \n"<<"Winner is "<<(*second_player).name<<"\n";

 return 0;
 }
 else if(second_player_hp<=0){
     cout<<(*second_player).name<<" fainted \n"<<"Winner is "<<(*first_player).name<<"\n";
    return 0;}
 

}

 }
 return 0;

}
 

 
    
