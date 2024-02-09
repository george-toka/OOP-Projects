//58352

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
using namespace std;


class Pokemon
{
	private:                                                //private Pokemon members
	
		string type;
		int level;
	 
	 
	public:                                                 //public Pokemon members
	
		string name;
		
		Pokemon(string c_name,string c_type,int c_level)    //Pokemon constructor
		{
			name=c_name;
			type=c_type;
			level=c_level;
			
		  cout<<name<<" is ready and its level is: "<<level<<endl;
		  	
		}
		
		
		void setType(string typos) {type=typos;}            //Pokemon setters      
		void setLevel(int epipedo) {level=epipedo;}    
		
		
		string getType() {return type;}                     //Pokemon getters
		int getLevel() {return level;}
		
};



class Team
{
	private:                                               //private Team members
	
		vector<string> members_types;
		vector<int> members_levels;
	
		
	public:                                                //public Team members  
		vector<string> members_names;
		string team_name;
		
		Team(string onoma_omadas)                          //Team constructor
		{
			team_name=onoma_omadas;
		}
		
		
		void setTypes(string typoi_melwn) {members_types.push_back(typoi_melwn);}                //Team setters
		void setLevels(int epipeda_melwn) {members_levels.push_back(epipeda_melwn);}
		
		
		vector<string> getTypes() {return members_types;}                                       //Team getters
		vector<int> getLevels() {return members_levels;}
		
		 
		void addNewPokemon(Pokemon n_pokemon);                           //3.1 function declaration    
	    friend void isMember(Team &f_team,Pokemon f_pokemon); 	         //3.2 function declaration 
};




void Team::addNewPokemon(Pokemon n_pokemon)                              //3.1 function's code
{
 
  int temp_level;                             //temp variables to help
  string temp_type;                           //with private Pokemon members  
	
	temp_level=n_pokemon.getLevel();
	temp_type=n_pokemon.getType();	
	
	
	members_names.push_back(n_pokemon.name);  //stores name (linearly to the vector)	
	members_types.push_back(temp_type);       //stores type (linearly to the vector)
	members_levels.push_back(temp_level);     //stores level(linearly to the vector)
 }



void isMember(Team &f_team,Pokemon f_pokemon)                            //3.2 function's code
{
	
	int size=(f_team.members_names).size(); //size of vector helps to
                                            //define loop's number of reps  	
	
	
	for(int i=0; i<size ; i++) 
	{
	   	if(f_pokemon.name!=f_team.members_names[i])  //if names don't match, pokemon is added
	   	{
	   		f_team.addNewPokemon(f_pokemon);
	   		cout<<f_pokemon.name<<" added to the "<<f_team.team_name<<" team"<<endl;
		}
		
		else cout<<f_pokemon.name<<" already exists in the "<<f_team.team_name<<" team"<<endl; //else bla bla bla
	}
	
}



void battle(Team first,Team second)                                     //3.3 function code
{
	vector<int> level_first,level_second;   //helps with private members
	
level_first=first.getLevels();           
level_second=second.getLevels();
	
	
	
	int size_first,size_second;             //size of vectors helps 
	int sum_first,sum_second;                //define loops' number of reps 
	                                        //sum_first-second are sums of the respective teams
	
	sum_first=0;
	sum_second=0;
	
	size_first=level_first.size();
	size_second=level_second.size();
	
	
	
	
	for(int i=0; i<size_first ; i++)       //loop for the first team
	{
		sum_first=sum_first + level_first[i];
	}
	
	
	
	for(int j=0; j<size_second ; j++)       //loop for the second team
	{
		sum_second=sum_second + level_second[j];
	}
	
	
	
	if(sum_first>sum_second) cout<<"Team "<<first.team_name<<" wins having a total level: "<<sum_first;
	else if(sum_first<sum_second) cout<<"Team "<<second.team_name<<" wins having a total level: "<<sum_second;
	else cout<<"Teams are equal";
}





int main()
{
	Team one("1");                                    //declare Teams
	Team two("2");
	                   
	Pokemon Pikachu("Pikachu","Electric",20);        //declare Pokemon 
	Pokemon Charmander("Charmander","Fire",20);
	Pokemon Squirtle("Squirtle","Water",20);
	Pokemon Bulbasaur("Bulbasaur","Grass",30);
	
	one.addNewPokemon(Pikachu);                 //function calls
	isMember(one,Pikachu);
	isMember(one,Charmander);
	
	two.addNewPokemon(Squirtle);
	isMember(two,Squirtle);
	isMember(two,Bulbasaur);
	
	cout<<one.members_names[0]<<endl;               //test that call-by reference and other shit worked
    cout<<one.members_names[1]<<endl;  
	cout<<two.members_names[0]<<endl;               
    cout<<two.members_names[1]<<endl;
    
    
    
    vector<int> level_first,level_second;          
    vector<string> type_first,type_second;
    
    level_first=one.getLevels();           
	level_second=two.getLevels();
	
	type_first=one.getTypes();           
	type_second=two.getTypes();
   
    
    cout<<type_first[0]<<endl;              
    cout<<type_first[1]<<endl;  
	cout<<type_second[0]<<endl;               
    cout<<type_second[1]<<endl;
    	
	cout<<level_first[0]<<endl;               
    cout<<level_first[1]<<endl;  
	cout<<level_second[0]<<endl;               
    cout<<level_second[1]<<endl;
    
	
	int size=(one.members_names).size(); 
	cout<<size<<endl;
	
	battle(one,two);
}                             






