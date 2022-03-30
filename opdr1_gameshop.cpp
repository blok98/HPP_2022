// Your First C++ Program

#include <iostream>
#include <string>
#include <list>

class Game {  
  public:
    std::string name;  
    // default constructor to avoid error. It makes sure AutoHuur can declare an object of type Klant  
    Game(){             
        name = "";
    }     
    Game(std::string n){             
        name = n;
    }    
};

class Persoon {
  public:
    std::string name;
    double budget;
    std::list<Game> games;

    // default constructor to avoid error. It makes sure AutoHuur can declare an object of type Auto
    Persoon(){
        name="";
    }

    Persoon(std::string t, double b){
        name=t;
        budget=b;
    }

    void koop(Game g){
        games.push_back(g);
    }

    void showTheContent(std::list<Game> l){
        std::list<int>::iterator it;
        for(it=l.begin();it!=l.end();it++){
            std::cout <<  *it.name << " ";
        }
        std::cout << "\n";
    }

    void to_str(){
        std::cout<<"a"<<"\n";
    }
};




int main() {

	// Klant k1("henk");
	// k1.set_korting(10);
	// Auto a1("bmw",200);

	// AutoHuur h1(a1,k1,5);

    // k1.to_str();
    // a1.to_str();
    // h1.to_str();

    Game g1("gta");
    Persoon p1("frank", 100);  
    p1.koop(g1);  
    p1.showTheContent(p1.games);
};