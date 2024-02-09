//58352

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;




class Pokemon                                                     //base class(Pokemon)
{
	protected:
		string name;
		string type;
	
	
	public:
		int level;
		int HP;
		int attackPoints;
		
		string getName() {return name;}		                    //getter for Pokemon name
		string getType() {return type;}		                    //getter for Pokemon type
		
		void setName(string onoma) {name=onoma;}                //setter for Pokemon name   
		void setType(string typos) {type=typos;}                //setter for Pokemon type


		Pokemon operator++();                                   //class' ++ overload declaration as prefix
		Pokemon operator++(int);                                //class' ++ overload declaration as postfix
		Pokemon operator-(Pokemon const&);                      //class' - overload declaration
		Pokemon operator=(Pokemon);                             //class' = overload declaration so new HP value can be assigned thru updated  class  
};



class grassPokemon : public Pokemon                             //1st derived class(Grass Type)
{
	public:
		string move;
		
		//grassPokemon operator=(Pokemon);                                                     //class' = overload declaration so new HP value can be assigned thru updated grass class
		
};



class waterPokemon : public Pokemon                             //2nd derived class(Water Type)
{
 	public:
		string move;  
		
		//waterPokemon operator=(Pokemon);                                                     //class' = overload declaration so new HP value can be assigned thru updated water class
			
};



class firePokemon : public Pokemon                              //3rd derived class(Fire Type)
{
	public:
		string move;	
		
		//firePokemon operator=(Pokemon);                                                      //class' = overload declaration so new HP value can be assigned thru updated fire class
		 
};



Pokemon Pokemon::operator++(int dummy)                          //++ overloading code(postfix)
{
	Pokemon temp=*this;
	(this->level)++;
	return temp;
}


 
Pokemon Pokemon::operator++()                                   //++ overloading code(prefix)
{
    this->level++; //or level++ or (*this)
    return *this;
}



Pokemon Pokemon::operator-(Pokemon const& pokemon_2)            // - overloading code / const& not mandatory-obligatory
{
	Pokemon temp;
	temp.HP=HP - pokemon_2.attackPoints;
	return temp;
}



Pokemon Pokemon::operator=(Pokemon pokemon_1)                   // = overloading code to return updated class
{
	HP=pokemon_1.HP;
	return *this;
}


void showInfo(Pokemon Ditto)                                                                      
{
	cout<<"Name: "<<Ditto.getName()<<endl;
	cout<<"Type: "<<Ditto.getType()<<endl;
	cout<<"Level: "<<Ditto.level<<endl;
	cout<<"Hit points: "<<Ditto.HP<<endl;
	cout<<"Attack points: "<<Ditto.attackPoints<<endl;
}



void battle (Pokemon one,Pokemon two)                           //5o erwthma
{
	
	
	two=two-one;
	
	if(two.HP<=0)                                     //round 1
	   {
	   	one++;
	   	cout<<one.getName()<<" won the battle"<<endl;
	   }
	   
	else                                             //round 2 in case the battle didn't end in round 1
	   {
	    one=one-two;
		if(one.HP<two.HP)                            //it comes down to the one with highest HP
		  { 
			two++;
			cout<<two.getName()<<" won the battle"<<endl;
		  } 	
		  
		else if(one.HP>two.HP)
		  {
		  	one++;
	   	    cout<<one.getName()<<" won the battle"<<endl;
		  }  
	   }   

}



int main()                                                         //tester
{
	   grassPokemon Pikachu;
	   grassPokemon Bulbasaur;
	   
	   Pikachu.setName("Pikachu");
	   Bulbasaur.setName("Bulbasaur");
	   
	   cout<<Bulbasaur.getName()<<endl;
	   
	   Pikachu.HP=30;
	   Bulbasaur.HP=30;
	   
	   Pikachu.attackPoints=10;
	   Bulbasaur.attackPoints=20;
	   
	   //Bulbasaur=Bulbasaur-Pikachu;       //classes completed->1st and 2nd task completed  
	   cout<<Bulbasaur.HP<<endl     ;       //- ++ and = work for all combos ->3rd task completed 	
		                                    //4th task completed 
	   Pikachu.level=5;                     //5th task completed
	   
	   Pikachu++;
	   cout<<Pikachu.level<<endl;
	   
	   ++Pikachu;
	   cout<<Pikachu.level<<endl; 
	   
	   cout<<Bulbasaur.getName()<<endl;
	   
	   showInfo(Pikachu);
	   battle(Pikachu,Bulbasaur);   
	   showInfo(Pikachu);  
	                                        
	                       
}


