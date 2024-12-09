#include <iostream>
#include <String>
using namespace std;
class Product{
    private:
        String name;
        double price;
        double discount;
        bool barcode = false;
        bool trust_sign = false;
    public:
        Product(double p, double d, bool bar, bool tr){
            price = p;
            discount = d;
            barcode = bar;
            trust_sign = tr;
        };
        double get_price() {
          return price;  
        }
        double get_discount() {
          return discount;  
        }
        bool get_barcode() {
          return barcode;  
        }
        bool get_trust_sign() {
          return trust_sign;  
        }
        void set_price(double p){
            price =p;
        }
        void set_discount(double d){
            discount =d;
        }
        void set_barcode(bool b){
            barcode=b;
        }
        void set_trust_sign(bool t){
            trust_sign = t; 
        }
};
class Cash{ // класс описывает количество денег наличкой
    private:
        double ammount;
    public:
        Cash( double c){
            ammount = c;
        };
        double get_ammount(){
            return ammount;
        }
        void set_ammount(double c){
            ammount = c;    
        }
};
class Debut{ // класс описывает количество денег на карте
    private:
        double ammount;
    public:
        Debut( double c){
            ammount = c;
        };
        double get_ammount(){
            return ammount;
        }
        void set_ammount(double c){
            ammount = c;    
        }
};
class BonusCard{ // бонусная карта
    private:
        int ammount;
    public:
        BonusCard( double c){
            ammount = c;
        };
        int get_ammount(){
            return ammount;
        }
        void set_ammount(int c){
            ammount = c;    
        }
};
class Client{
    private:
        Cash cash();
        Debut debut();
        BonusCard bonus();
    public:
        Client(double cash_ammount, double debut_ammount, int bonus_ammount){
            cash.set_ammount(cash_ammount);
            debut.set_ammount(debut_ammount);
            bonus.set_ammount(debut_ammount);
        }
        double get_cash(){
            return cash.get_ammount;
        }
        double get_debut(){
            return debut.get_ammount;
        }
        void set_cash(double c){
            cash.set_ammount(c);
        }
        void set_debut(double d){
            debut.set_ammount(d);
        }
};
class checkout{ // класс непосредственно кассы
    private:
        
};
int main(){
 Product p(100, 10, false, true);
 double a = p.get_price();
 cout << a;
}