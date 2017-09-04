#include <iostream> 
using namespace std;

class pareja {
				private:
								// Datos miembro de la clase "pareja"
								int a, b; 
				public:
								// Funciones miembro de la clase "pareja"
								void imprime(int &a,int &b);
								void Lee(int &a2, int &b2){

												a2 = a;
												b2 = b;

								}
								void Guarda(int a2, int b2) {
												a = a2;
												b = b2;
								}
};
/*
	 void pareja::Lee(int &a2, int &b2) {
	 a2 = a;
	 b2 = b;
	 }
 */
void pareja::imprime(int &a,int &b){

cout << "pareja 1:"<< a << "pareja2: "<< b;

}
int main() {
				pareja par1;
				int x, y;

				par1.Guarda(12, 32);
				par1.Lee(x, y);
				par1.imprime(x,y);

				return 0;
}