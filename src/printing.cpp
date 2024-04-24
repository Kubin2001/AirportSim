#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include "objects.h"
#include "printing.h"

void Print_manager::print(Simulation *simulation){
    char menu = '1';
    while(menu != '0'){
        std::cout<<"\n--------Printing--------\n";
        std::cout<<"What would you like to print?\n";
        std::cout<<"[1]:Single airport\n";
        std::cout<<"[2]:Multiple airports\n";
        std::cout<<"[3]:Airspace\n";
        std::cout<<"[4]:Full data\n";
        std::cout<<"[0]:Exit\n";
        std::cin>>menu;
        switch(menu){
            case '1':
                single_printer(simulation);
                break;

            case '2':
                multi_printer(simulation);
                break;

            case '3':
                airspace_printer(simulation);
                break;

            case '4':
                printer_all(simulation);
                break;

            case '0':
                menu = '0';
                break;

            default:
                std::cout<<"You need to write numbers between 0-4\n";

        }
    }
}

void Print_manager::single_printer(Simulation* simulation){
    std::cout<<"Enter the file name min 3 max 15: ";
    std::cin>>file_name;
    if(file_name.length() < 3 || file_name.length() > 15){
        std::cout<<"File name invalid name was set to ""name""\n";
        file_name = "name";
    }

    int airport_number = 0;
    std::cout << "Enter the airport number: ";
    std::cin >> airport_number;

    if (airport_number > simulation->GetAirports().size() || airport_number < 0) {
        std::cout << "Wrong airport number\n";
        return;
    }

    std::ofstream file;
    file.open("output/" + file_name.append(".txt"));
    if(file.is_open()){
        std::cout<<"File created!\n";
        file<<simulation->GetAirports()[airport_number-1];
        for(int i = 0;i< simulation->GetAirports()[airport_number-1].get_planes_count();i++){
            file<<"    "<<i+1<<":"<< simulation->GetAirports()[airport_number-1].get_plane(i);
        }
    }

    else{
        std::cout<<"Error file not created!";
    }
    file.close();
}

void Print_manager::multi_printer(Simulation* simulation){
    int airport_number = 1;
    std::cout<<"Enter the file name min 3 max 15: ";
    std::cin>>file_name;
    if(file_name.length() < 3 || file_name.length() > 15){
        std::cout<<"File name invalid name was set to ""name""\n";
        file_name = "name";
    }

    while(airport_number != 0){
        std::cout<<"Enter the airport number or 0 to leave: ";
        std::cin>>airport_number;
        if(airport_number > simulation->GetAirports().size() || airport_number < 0){
            std::cout<<"Wrong input try once again\n";
        }
        else if(airport_number == 0){

        }
        else{
            std::ofstream file;
            file.open("output/" + file_name + type,std::ios::app);
            if(file.is_open()){
                std::cout<<"File created!\n";
                file<<simulation->GetAirports()[airport_number-1];
                for(int i = 0;i< simulation->GetAirports()[airport_number-1].get_planes_count();i++){
                    file<<"    "<<i+1<<":"<< simulation->GetAirports()[airport_number-1].get_plane(i);
                }
                file<<"\n";
            }

            else{
                std::cout<<"Error file not created!";
            }

            file.close();
        }
    }
}

void Print_manager::airspace_printer(Simulation* simulation){
    std::cout<<"Enter the file name min 3 max 15: ";
    std::cin>>file_name;
    if(file_name.length() < 3 || file_name.length() > 15){
        std::cout<<"File name invalid name was set to ""name""\n";
        file_name = "name";
    }
    std::ofstream file;
    file.open("output/" + file_name.append(".txt"));
    if(file.is_open()){
        std::cout<<"File created!\n";
        file<<simulation->GetAirspace();
        for(int i = 0;i< simulation->GetAirspace()->get_planes_count();i++){
            file<<"    "<<i+1<<":"<< simulation->GetAirspace()->get_plane(i);
        }
    }

    else{
        std::cout<<"Error file not created!";
    }
    file.close();
}

void Print_manager::printer_all(Simulation* simulation){
    std::cout<<"Enter the file name min 3 max 15: ";
    std::cin>>file_name;
    if(file_name.length() < 3 || file_name.length() > 15){
        std::cout<<"File name invalid name was set to ""name""\n";
        file_name = "name";
    }

    std::ofstream file;
    file.open("output/" + file_name.append(".txt"));
    if(file.is_open()){
        std::cout<<"File created!\n";
        for(int i = 0;i< simulation->GetAirports().size();i++){
            file<< simulation->GetAirports()[i];
            for(int j = 0;j< simulation->GetAirports()[i].get_planes_count();j++){
                file<<"    "<<j+1<<":"<< simulation->GetAirports()[i].get_plane(j);
            }

        }

        file<<simulation->GetAirspace();
        for(int i = 0;i< simulation->GetAirspace()->get_planes_count();i++){
            file<<"    "<<i+1<<":"<< simulation->GetAirspace()->get_plane(i);
        }
    }

    else{
        std::cout<<"Error file not created!";
    }
    file.close();
}
