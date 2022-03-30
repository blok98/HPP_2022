// Your First C++ Program

#include <iostream>
#include <string>

class Klant {  
  public:
    std::string naam; 
	double korting_percentage;     
    // default constructor to avoid error. It makes sure AutoHuur can declare an object of type Klant  
    Klant(){             
        naam = "";
    }     
    Klant(std::string n){             
        naam = n;
    }    
	void set_korting(double percentage){
		korting_percentage = percentage;
	}
    double get_korting(){
        return korting_percentage;
    } 
    void to_str(){
        std::cout<<"klant "+naam+" heeft "+std::to_string(korting_percentage) +"% korting."<<"\n"; 
    }

};

class Auto {
  public:
    std::string type;
    double prijs_per_dag;

    // default constructor to avoid error. It makes sure AutoHuur can declare an object of type Auto
    Auto(){
        type="";
    }

    Auto(std::string t, double dag_p){
        type=t;
        prijs_per_dag=dag_p;
    }

    void set_prijs_per_dag(double percentage){
        prijs_per_dag = percentage;
    }

    double get_prijs_per_dag(){
        return prijs_per_dag;
    }

    void to_str(){
        std::cout<<"Auto van type "+type+" kost "+std::to_string(prijs_per_dag)+" per dag."<<"\n";
    }
};


class AutoHuur {       
  public:
    Auto a;        
    Klant k; 
    int d;
	AutoHuur(Auto aut,Klant kla, int dagen){             
        a = aut;
        k = kla;
        d = dagen;
    }

    void set_aantal_dagen(int dagen){
        d = dagen;
    }

    void set_gehuurde_auto(Auto aut){
        a = aut;
    }

    void set_huurder(Klant huurder){
        k = huurder;
    }

    Auto get_gehuurde_auto(){
        return a;
    }

    Klant get_huurder(){
        return k;
    }

    double totaalprijs(){
        return a.get_prijs_per_dag()*d*((100-k.get_korting())/100);
    }

    void to_str(){
        std::cout<<"Een auto is verhuurd voor "+std::to_string(d)+" dagen voor een totaalbedrag van "+std::to_string(totaalprijs())+" euro, inclusief de "+std::to_string(k.get_korting())+"% korting."<<"\n";
    }
};

int main() {
     '''
     std:: is added to cout and endl
     cout<<object is replaced with object.to_str(), because to_str() is a void function
     '''
	// Klant k1("henk");
	// k1.set_korting(10);
	// Auto a1("bmw",200);

	// AutoHuur h1(a1,k1,5);

    // k1.to_str();
    // a1.to_str();
    // h1.to_str();
    Klant k("Mijnheer de Vries");
    k.set_korting(10.0);
    Auto a1("Peugeot 207", 50);
    AutoHuur ah1(a1, k, 4);
    ah1.to_str();
    std::cout << std::endl;
    
    Auto a2("Ferrari", 3500);
    AutoHuur ah2(a1, k, 10);
    ah2.set_gehuurde_auto(a2);
    ah2.set_aantal_dagen(1);
    ah2.to_str();
    std::cout << std::endl;
    
    ah1.get_gehuurde_auto().to_str();
    ah2.get_gehuurde_auto().to_str();
    
    return 0;
};