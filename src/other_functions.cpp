#include <iostream>
#include <ctime>
#include <vector>

#include "objects.h"
#include "other_functions.h"


void show_simulation(Simulation* simulation){
    int *airport_inkex = new int;
    *airport_inkex = 0;
    char menu ='1';
    while(menu != '0'){
        std::cout<<"[1]Show Airports\n";
        std::cout<<"[2]Show Airspace\n";
        std::cout<<"[3]Show Serviced Planes\n";
        std::cout<<"[0]Exit\n";
        std::cout<<"Choose an option: ";
        std::cin>>menu;
        switch(menu){
            case '1':
                for (int i = 0;i<simulation->GetAirports().size();i++){
                    simulation->GetAirports()[i].show_data(simulation->GetAirports().size(), i);

                }
                ask_input(simulation->GetAirports(), simulation->GetAirports().size(), airport_inkex);
                break;

             case '2':
                simulation->GetAirspace()->show_data();
                break;

            case '3':
                simulation->GetServicePort()->show_data();
                break;

            case '0':
                menu ='0';
                break;

            default:
                std::cout<<"You need to write numbers between 0-3\n";
                break;
        }
    }
    delete airport_inkex;
}

void settings(int airport_size,Simulation *simulation, bool *module_flag_airport_dist,bool *module_flag_airspace_dist,bool *module_flag_destruction,bool *module_flag_plane_copy){
    char menu ='1';
    while(menu != '0'){
        std::cout<<"---------------Settings---------------\n";
        std::cout<<"[1]Simulation speed\n";
        std::cout<<"[2]Enable/Disable modules\n";
        std::cout<<"[3]Choose sort type\n";
        std::cout<<"[0]Exit\n";
        std::cout<<"Choose an option: ";
        std::cin>>menu;
        switch(menu){
            case '1':
                sim_time(simulation);
                break;

            case '2':
                modules(module_flag_airport_dist,module_flag_airspace_dist,module_flag_destruction,module_flag_plane_copy);
                break;

            case '3':
                sort_type(simulation,airport_size);
                break;

            case '0':
                menu = '0';
                break;

            default:
                std::cout<<"You need to write numbers between 0-3\n";
                break;
        }
    }
}

void sim_time(Simulation *simulation){
    std::cout<<"Enter the simulation delay time in milliseconds (max 2000 min 1): ";
    std::cin>>simulation->get_sim_delay();
    if(simulation->get_sim_delay() > 2000){
        simulation->get_sim_delay() = 2000;
        std::cout<<"Delay was set to 2000\n";
    }

    else if(simulation->get_sim_delay() < 1){
        simulation->get_sim_delay() = 1;
        std::cout<<"Delay was set to 1\n";
    }
    else{
        std::cout<<"Delay was set to "<<simulation->get_sim_delay()<<"\n";
    }

}

void modules(bool *module_flag_airport_dist,bool *module_flag_airspace_dist,bool *module_flag_destruction,bool *module_flag_plane_copy){
    std::string en_module = "Enabled";
    std::string dis_module = "Disabled";
    char menu ='1';
    while(menu != '0'){
        std::cout<<"---------------Enable/Disable modules---------------\n";
        std::cout<<"[1]Airport to airspace plane distribution module (core): ";
        if(*module_flag_airport_dist == true){
            std::cout<<en_module<<"\n";
        }
        else{
            std::cout<<dis_module<<"\n";
        }
        std::cout<<"[2]Airspace to airport plane distribution module (core): ";
        if(*module_flag_airspace_dist == true){
            std::cout<<en_module<<"\n";
        }
        else{
            std::cout<<dis_module<<"\n";
        }
        std::cout<<"[3]Plane destruction module (core): ";
        if(*module_flag_destruction == true){
            std::cout<<en_module<<"\n";
        }
        else{
            std::cout<<dis_module<<"\n";
        }
        std::cout<<"[4]Plane copy module: ";
        if(*module_flag_plane_copy == true){
            std::cout<<en_module<<"\n";
        }
        else{
            std::cout<<dis_module<<"\n";
        }
        std::cout<<"[0]Exit\n";
        std::cout<<"Choose an option: ";
        std::cin>>menu;
        switch(menu){
            case '1':
                if(*module_flag_airport_dist == true){
                    *module_flag_airport_dist = false;
                }
                else{
                    *module_flag_airport_dist = true;
                }
                break;

            case '2':
                if(*module_flag_airspace_dist == true){
                    *module_flag_airspace_dist = false;
                }
                else{
                    *module_flag_airspace_dist = true;
                }
                break;

            case '3':
                if(*module_flag_destruction == true){
                    *module_flag_destruction = false;
                }
                else{
                    *module_flag_destruction = true;
                }
                break;

            case '4':
                if(*module_flag_plane_copy == true){
                    *module_flag_plane_copy = false;
                }
                else{
                    *module_flag_plane_copy = true;
                }
                break;

            case '0':
                menu = '0';
                break;

            default:
                std::cout<<"You need to write numbers between 0-2\n";
                break;
        }
    }
}

void sort_type(Simulation * simulation,int airport_size){
    char menu ='1';
    while(menu != '0'){
        std::cout<<"[1]Disable sorting\n";
        std::cout<<"[2]Sort by name\n";
        std::cout<<"[3]Sort by model\n";
        std::cout<<"[4]Sort by ID\n";
        std::cout<<"[5]Sort by age\n";
        std::cout<<"[6]Sort by time in the location\n";
        std::cout<<"[0]Exit\n";
        std::cout<<"Choose an option: ";
        std::cin>>menu;
        switch(menu){
            case '1':
                std::cout<<"Sorting disabled\n";
                break;

            case '2':
                for(int i =0;i<airport_size;i++){
                    simulation->GetAirports()[i].get_sort_time() = 1;
                }
                simulation->GetAirspace()->get_sort_time() = 1;
                simulation->GetServicePort()->get_sort_time() = 1;
                std::cout<<"Sorting changed to sorting by name\n";
                break;

            case '3':
                for(int i =0;i<airport_size;i++){
                    simulation->GetAirports()[i].get_sort_time() = 2;
                }
                simulation->GetAirspace()->get_sort_time() = 2;
                simulation->GetServicePort()->get_sort_time() = 2;
                std::cout<<"Sorting changed to sorting by model\n";
                break;

            case '4':
                for(int i =0;i<airport_size;i++){
                    simulation->GetAirports()[i].get_sort_time() = 3;
                }
                simulation->GetAirspace()->get_sort_time() = 3;
                simulation->GetServicePort()->get_sort_time() = 3;
                std::cout<<"Sorting changed to sorting by ID\n";
                break;

            case '5':
                for(int i =0;i<airport_size;i++){
                    simulation->GetAirports()[i].get_sort_time() = 4;
                }
                simulation->GetAirspace()->get_sort_time() = 4;
                simulation->GetServicePort()->get_sort_time() = 4;
                std::cout<<"Sorting changed to sorting by age\n";
                break;

            case '6':
                for(int i =0;i<airport_size;i++){
                    simulation->GetAirports()[i].get_sort_time() = 5;
                }
                simulation->GetAirspace()->get_sort_time() = 5;
                simulation->GetServicePort()->get_sort_time() = 5;
                std::cout<<"Sorting changed to sorting by time in location\n";
                break;

            case '0':
                menu = '0';
                break;

            default:
                std::cout<<"You need to write numbers between 0-6\n";
                break;
        }
    }
}

void change_names(Simulation *simulation){
    char menu ='1';
    int menu1;
    int menu2;
    while(menu != '0'){
        std::cout<<"[1]Plane from airport\n";
        std::cout<<"[2]Plane from airspace\n";
        std::cout<<"[3]Plane from service\n";
        std::cout<<"[0]Exit\n";
        std::cout<<"Choose an option: ";
        std::cin>>menu;
        switch(menu){

            case '1':
                std::cout<<"Enter the airport number: ";
                std::cin>>menu1;
                if(menu1 > simulation->GetAirports().size() || menu1 < 1){
                    std::cout<<"Airport number can't be larger or smaller than amount airports\n";
                }
                else{
                    std::cout<<"Enter plane number: ";
                    std::cin>>menu2;
                    if(menu2 > simulation->GetAirports()[menu1-1].get_planes_count() || menu2 <0){
                        std::cout<<"Plane number can't be larger or smaller than amount of planes in airport\n";
                    }

                    else{
                        std::cout<<"Current name: "<< simulation->GetAirports()[menu1-1].get_plane_name(menu2-1)<<" "<< simulation->GetAirports()[menu1-1].get_plane_model(menu2-1)<<" "<< simulation->GetAirports()[menu1-1].get_plane_identification_number(menu2-1)<<"\n";
                        std::cin>> simulation->GetAirports()[menu1-1].get_plane(menu2-1);
                        std::cout<<"Changed name: "<< simulation->GetAirports()[menu1-1].get_plane_name(menu2-1)<<" "<< simulation->GetAirports()[menu1-1].get_plane_model(menu2-1)<<" "<< simulation->GetAirports()[menu1-1].get_plane_identification_number(menu2-1)<<"\n";
                    }
                }
                break;

            case '2':
                std::cout<<"Enter plane number: ";
                std::cin>>menu1;
                if(menu1 > simulation->GetAirspace()->get_planes_count() || menu1 < 1){
                    std::cout<<"Plane number can't be larger or smaller than amount of planes in airspace\n";
                }

                else{
                    std::cout<<"Current name: "<< simulation->GetAirspace()->get_plane_name(menu1-1)<<" "<< simulation->GetAirspace()->get_plane_model(menu1-1)<<" "<< simulation->GetAirspace()->get_plane_identification_number(menu1-1)<<"\n";
                    std::cin>> simulation->GetAirspace()->get_plane(menu1-1);
                    std::cout<<"Changed name: "<<simulation->GetAirspace()->get_plane_name(menu1-1)<<" "<< simulation->GetAirspace()->get_plane_model(menu1-1)<<" "<< simulation->GetAirspace()->get_plane_identification_number(menu1-1)<<"\n";
                }

                break;

            case '3':
                std::cout<<"Enter plane number: ";
                std::cin>>menu1;
                if(menu1 > simulation->GetServicePort()->get_planes_count() || menu1 < 1) {
                    std::cout<<"Plane number can't be larger or smaller than amount of planes in service\n";
                }

                else{
                    std::cout<<"Current name: "<< simulation->GetServicePort()->get_plane_name(menu1-1)<<" "<< simulation->GetServicePort()->get_plane_model(menu1-1)<<" "<< simulation->GetServicePort()->get_plane_identification_number(menu1-1)<<"\n";
                    std::cin>>simulation->GetServicePort()->get_plane(menu1 - 1);
                    std::cout<<"Changed name: "<< simulation->GetServicePort()->get_plane_name(menu1-1)<<" "<< simulation->GetServicePort()->get_plane_model(menu1-1)<<" "<< simulation->GetServicePort()->get_plane_identification_number(menu1-1)<<"\n";
                }


                break;


            case '0':
                menu ='0';
                break;

            default:
                std::cout<<"You need to write numbers between 0-3\n";
                break;
        }
    }
}

void ask_input(std::vector <Airport> &vec, int airport_size,int *airport_index){
    std::cout<<"Insert airport number for graphical information or 0 to leave: ";
    std::cin>>*airport_index;
    if(*airport_index == 0){

    }

    else if(*airport_index <=airport_size){
        vec[*airport_index-1].ground.create_array(vec,airport_index);
        vec[*airport_index-1].ground.show_array(vec,airport_index);
    }
}
