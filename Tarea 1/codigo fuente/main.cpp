#include <iostream>
#include <cstring> // para usar strcpy y strlen
class Text{
private:
    size_t size;
    int max_size;
    char * txt;
public:
    // constructor por defecto
    Text(){ size=0; max_size= 1024; txt= nullptr;}
    Text(const char * _txt){
        max_size= 1024;
        size = strlen(_txt); //revisar para implementarlo from scratch
        txt = new char[size];
        strcpy(txt,_txt); //revisar para implementarlo from scratch
    }

    friend std::ostream& operator <<(std::ostream& os, Text txt);
    friend std::istream& operator >>(std::istream& is, Text& txt);
};

std::ostream& operator <<(std::ostream& os, Text txt){

    os<<txt.txt;

    return os;
}

std::istream& operator >>(std::istream& is, Text& txt) {


    // guardar lo que esta adentro del is en el objeto txt
    char buffer[1000];
    is >> buffer;

    delete[] txt.txt; // liberar memoria actual si existe

    txt.txt = new char[strlen(buffer) + 1];
    strcpy(txt.txt, buffer);

    return is;
}

void test1(){
    Text text_1 = "Hola Mundo";
    std::cout << text_1 << std::endl;
}

void test2(){
    Text text_1;
    std::cin >> text_1;
    std::cout << text_1 << std::endl;
}

int main() {

    test2();
//    std::string x="hola mundo";
//    std::cout << "size: "<< x.size();
//    std::cout << "capacidad: "<< x.capacity();
//    std::cout << "max_size: "<< x.max_size();


    return 0;
}

