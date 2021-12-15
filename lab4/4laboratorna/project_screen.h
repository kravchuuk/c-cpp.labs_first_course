#include <iostream>
#include <string>
#ifndef project_screen_h
#define project_screen_h
using namespace std;

class project_screen {

public:
    int height;
    string manufactur;


    project_screen(int widht2, string type_of_fastening2, int height2, string manufactur2)
    {
        height = height2;
        manufactur = manufactur2;
        widht = widht2;
        type_of_fastening = type_of_fastening2;
    }
    project_screen()
    {
        height = 50;
        manufactur = "ASUS";
        widht = 70;
        type_of_fastening = "wall";
    }

    void set_widht(int widht2)
    {
        widht = widht2;
    }
    void get_widht()
    {
        cout << widht << endl;
    }

    string set_type_of_fastening(string type_of_fastening2)
    {
        type_of_fastening = type_of_fastening2;
    }
    void get_type_of_fastening()
    {
        cout << type_of_fastening << endl;
    }


    void Data_output()
    {
        cout << height << endl;
        cout << manufactur << endl;
        get_widht();
        get_type_of_fastening();
        cout << "--------------------------------" << endl;
    }

private:
    int widht;

protected:
    string type_of_fastening;
};

#endif
