#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <string>

#include "objects.h"
#include "other_functions.h"
#include "printing.h"

int Plane::total_planes = 0;

std::ostream& operator << (std::ostream& output,const Plane plane){
    output<<"Name: "<<plane.name<<" "<<plane.model<<" "
    <<plane.identification_number<<" "<<"Age: "<<plane.age<<" months "
    <<"Time in this location: "<<plane.location_time<<" ticks"<<"\n";
    return output;
}

std::istream& operator >>(std::istream& input,Plane &plane){
    std::cout<<"Enter new name: ";
    input >> std::ws;
    std::getline(input, plane.name);
    std::cout<<"Enter new model sign: ";
    std::cin>>plane.model;
    std::cout<<"Enter new id: ";
    std::cin>>plane.identification_number;
    return input;
}

std::ostream& operator <<(std::ostream& output,const Airspace airspace_r){
    output<< std::setw(40) << std::right <<"--------| "<<airspace_r.name<<"  |-------\n"
    <<"--------"<<"| "<<airspace_r.planes_count<<" planes |"<<"-------\n";
    return output;
}

std::ostream& operator <<(std::ostream& output,const Airport airport_r){
    output<<"Name: "<<airport_r.name<<" Planes: "<<airport_r.planes_count<<" Max planes: "
    <<airport_r.max_planes<<"\n\n";
    return output;
}

std::ostream& operator <<(std::ostream& output, const Service_Port service){
        output<<"--------| "<<service.name<<"          |-------\n"
        <<"--------"<<"| "<<service.planes_count<<" planes              |-------\n"
        <<"--------"<<"| Maximal capacity "<<service.max_planes<<" |-------\n";
        return output;
}

int main(){
    srand(time(nullptr));
    std::cout<<"|=========================================================================|\n";
    std::cout<<"|============================| Airport Simulation |=======================|\n";
    std::cout<<"|=========================================================================|\n";
    //module flags
    bool *module_flag_airport_dist = new bool;
    *module_flag_airport_dist = true;
    bool *module_flag_airspace_dist = new bool;
    *module_flag_airspace_dist = true;
    bool *module_flag_destruction = new bool;
    *module_flag_destruction = true;
    bool *module_flag_plane_copy = new bool;
    *module_flag_plane_copy = false;
    //module flags

    Simulation *simulation = new Simulation;
    char menu = '1';
    Print_manager * print_manager = new Print_manager("file");

    int fluent_planes_number = 0;
    simulation->sim_create_vector();

    while(menu != '0'){
        std::cout<<"\n---------------Main Menu---------------\n";
        std::cout<<"Total planes in simulation: "<<Plane::get_total_planes()<<"\n";
        std::cout<<"[1]Start the simulation\n";
        std::cout<<"[2]Add planes\n";
        std::cout<<"[3]Show simulation data\n";
        std::cout<<"[4]Show all events\n";
        std::cout<<"[5]Search events\n";
        std::cout<<"[6]Change planes names\n";
        std::cout<<"[7]Print data to file\n";
        std::cout<<"[8]Settings\n";
        std::cout<<"[0]Exit\n";
        std::cout<<"Choose an option: ";
        std::cin>>menu;
        switch(menu){
            case '1':
                simulation->simgettime();
                simulation->simulate(module_flag_airport_dist,module_flag_airspace_dist,module_flag_destruction);
                for(int i =0;i<simulation->GetAirports().size();i++){
                    simulation->GetAirports()[i].sort_planes();
                }
                simulation->GetAirspace()->sort_planes();
                simulation->GetServicePort()->sort_planes();
                break;

             case '2':
                simulation->GetAirspace()->create_data(fluent_planes_number);
                simulation->GetAirspace()->initialize_data(fluent_planes_number,module_flag_plane_copy);
                break;

            case '3':
                show_simulation(simulation);
                break;

            case '4':
                simulation->show_events();
                break;

            case '5':
                simulation->search_data();
                break;

            case '6':
                change_names(simulation);
                break;

            case '7':
                print_manager->print(simulation);
                break;

             case '8':
                settings(simulation->GetAirports().size(), simulation, module_flag_airport_dist, module_flag_airspace_dist, module_flag_destruction, module_flag_plane_copy);
                for(int i =0;i< simulation->GetAirports().size();i++){
                    simulation->GetAirports()[i].sort_planes();
                }
                simulation->GetAirspace()->sort_planes();
                simulation->GetServicePort()->sort_planes();
                break;

            case '0':
                std::cout<<"Goodbye\n";
                menu ='0';
                break;

            default:
                std::cout<<"You need to write numbers between 0-7\n";
                break;
        }
    }
    delete simulation;
    delete print_manager;

    delete module_flag_airport_dist;
    delete module_flag_airspace_dist;
    delete module_flag_destruction;
    delete module_flag_plane_copy;

    simulation = nullptr;
    print_manager = nullptr;

    module_flag_airport_dist = nullptr;
    module_flag_airspace_dist = nullptr;
    module_flag_destruction = nullptr;
    module_flag_plane_copy = nullptr;
}
