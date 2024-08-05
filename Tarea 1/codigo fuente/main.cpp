#include <iostream>

class Text{
private:
    std::string * txt;
public:
    Text(const char * _txt){ // const char * === "HOLA MUNDO"

        txt = new std::string(_txt); // constructor copia de std::string
    }


    friend std::ostream& operator <<(std::ostream& os, Text txt);
};

std::ostream& operator <<(std::ostream& os, Text txt){

    os << *txt.txt;

    return os;
}

int main() {

    Text text_1 = "Hola Mundo123124";
    std::cout << text_1 << std::endl;



    return 0;
}

