#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>

#include "objects.h"

Simulation::Simulation() {
    airspace = new Airspace("Airspace", 0, 2000, 0);
    service_port = new Service_Port("Service Port", 0, 200, 100, false);

    int airportSize;
    int rnumber1;

    std::cout << "Enter the amount of airports you would like to simulate: (max:10 min:1): ";
    std::cin >> airportSize;
    if (airportSize > 10) {
        airportSize = 10;
        std::cout << "Airport size has been set to max possible number: " << airportSize << "\n";
    }

    else if (airportSize < 1) {
        airportSize = 1;
        std::cout << "Airport size has been set to lowest possible number: " << airportSize << "\n";
    }

    else {
        std::cout << "Size set to: " << airportSize << "\n";
    }

    std::string* airport_names = new std::string[10];
    std::ifstream infile("input/airport_names.txt");

    for (size_t i = 0; i < airportSize; i++)
    {
        getline(infile, airport_names[i]);
        rnumber1 = rand() % 60 + 40;
        Airport airport(airport_names[i], 0, rnumber1, 100);
        airports.push_back(airport);
    }
    infile.close();

}

void Simulation::sim_create_vector(){
    event_vector.push_back("Last simulation events list:\n");
}

void Simulation::simgettime(){
    timer = 0;
    while(timer == 0){
        std::cout<<"Enter the simulation length: ";
        std::cin>>timer;
        if(timer > 6000){
            std::cout<<"Simulation time cannot be higher than 60 seconds!\n";
            std::cout<<"Write anyting to continue:";
            std::cin>>contin;
            timer = 0;
        }

        else if(timer < 1){
            std::cout<<"Simulation time cannot be lower than 1 second!\n";
            std::cout<<"Write anyting to continue:";
            std::cin>>contin;
            timer = 0;
        }
    }
    std::cout<<"Simulation time set to: "<<timer<<"\n";
    std::cout<<"Write anyting to continue:";
    std::cin>>contin;
}

void Simulation::simulate_time(){
    for(int i = 0;i<airspace->get_planes_count();i++){
        airspace->get_plane_location_time(i) +=1;
        airspace->get_plane_age(i) +=1;
    }

    for (int i = 0;i<airports.size();i++){
        for (int j =0;j<airports[i].get_planes_count();j++){
            airports[i].get_plane_location_time(j) +=1;
            airports[i].get_plane_age(j) +=1;

        }
    }

    for(int i = 0;i<service_port->get_planes_count();i++){
        service_port->get_plane_location_time(i) +=1;
    }
    //std::cout<<"1\n";

}

void Simulation::sub_dist_airspace(std::string temp_string,int i,int rnumber5){
    if(event_vector.size() >=6000){
    }
    else{
        temp_string = std::to_string(airspace->get_plane_identification_number(i));
        event_vector.push_back(airspace->get_plane_name(i) + " " + airspace->get_plane_model(i) + " " +temp_string + events[1] + " " + airports[rnumber5].get_name());
    }
    airports[rnumber5].plane_plus_size();

    airports[rnumber5].get_plane(airports[rnumber5].get_planes_count()-1) = airspace->get_plane(i);
    airports[rnumber5].get_plane_location_time(airports[rnumber5].get_planes_count()-1) = 0;

    airspace->get_plane(i) = airspace->get_plane(airspace->get_planes_count()-1);
    airspace->plane_minus_size();
}

void Simulation::simulate_distribution_airspace(){
    std::string temp_string;
    int rnumber1;
    int rnumber2;
    int rnumber3;
    int rnumber4;

    int rnumber5;
    for(int i = 0;i<airspace->get_planes_count();i++){
        rnumber1 = rand() % 100;
        rnumber2 = rand() % 50;
        rnumber3 = rand() % 10;
        rnumber4 = rand() % 4;

        rnumber5 = rand() % airports.size();
        //std::cout<<"Indeks:"<<rnumber4<<"\n";

        if(airspace->get_plane_location_time(i) == 1 && rnumber1 ==99 && airports[rnumber5].get_planes_count() < airports[rnumber5].get_max_planes()){
            sub_dist_airspace(temp_string,i,rnumber5);

        }

        else if(airspace->get_plane_location_time(i) == 2 && rnumber2 >=48 && airports[rnumber5].get_planes_count() < airports[rnumber5].get_max_planes()){
            sub_dist_airspace(temp_string,i,rnumber5);
        }

        else if(airspace->get_plane_location_time(i) == 3 && rnumber3 >=9 && airports[rnumber5].get_planes_count() < airports[rnumber5].get_max_planes()){
            sub_dist_airspace(temp_string,i,rnumber5);
        }

        else if(airspace->get_plane_location_time(i) >=4 && rnumber4 >=3 && airports[rnumber5].get_planes_count() < airports[rnumber5].get_max_planes()){
            sub_dist_airspace(temp_string,i,rnumber5);
        }
    }
    //std::cout<<"3\n";
}

void Simulation::sub_dist_airport(std::string temp_string,int i,int j){
    if(event_vector.size() >=5999){
                }
    else{
        temp_string = std::to_string(airports[i].get_plane_identification_number(j));
        event_vector.push_back(airports[i].get_plane_name(j) + " " + airports[i].get_plane_model(j) + " " +temp_string + events[0] + " " + airports[i].get_name());
    }

    airspace->plane_plus_size();
    airspace->get_plane(airspace->get_planes_count()-1) = airports[i].get_plane(j);
    airspace->get_plane_location_time(airspace->get_planes_count()-1) = 0;

    airports[i].get_plane(j) = airports[i].get_plane(airports[i].get_planes_count() -1);
    airports[i].plane_minus_size();

}

void Simulation::simulate_distribution_airport(){
    std::string temp_string;
    int rnumber1;
    int rnumber2;
    int rnumber3;
    int rnumber4;

    for (int i = 0;i<airports.size();i++){
        for (int j =0;j<airports[i].get_planes_count();j++){
            rnumber1 = rand() % 100;
            rnumber2 = rand() % 50;
            rnumber3 = rand() % 10;
            rnumber4 = rand() % 4;

            if(airports[i].get_plane_location_time(j) == 1 && rnumber1 ==99){
                sub_dist_airport(temp_string,i,j);

            }

            else if(airports[i].get_plane_location_time(j) == 2 && rnumber2 >=48){
                sub_dist_airport(temp_string,i,j);
            }

            else if(airports[i].get_plane_location_time(j) == 3 && rnumber3 >=9){
                sub_dist_airport(temp_string,i,j);
            }

            else if(airports[i].get_plane_location_time(j) >= 4 && rnumber4 >=3){
                sub_dist_airport(temp_string,i,j);
            }
        }
    }
    //std::cout<<"2\n";
}

void Simulation::simulate_plane_destruction(){
    int rnumber1;
    std::string temp_string;
    for(int i = 0;i<airspace->get_planes_count();i++){
        rnumber1 = rand() %10;
        if(airspace->get_plane_location_time(i) > 15 && rnumber1 == 5 && airspace->get_plane_location_time(i) <25){
            if(event_vector.size() >=5999){
            }
            else{
                temp_string = std::to_string(airspace->get_plane_identification_number(i));
                event_vector.push_back(airspace->get_plane_name(i) + " " + airspace->get_plane_model(i) + " " +temp_string + events[2]);

            }
            airspace->get_plane(i) = airspace->get_plane(airspace->get_planes_count()-1);
            airspace->plane_minus_size();
            Plane::get_total_planes_minus();
        }

        else if(airspace->get_plane_location_time(i) >= 25 && rnumber1 == 5){
            if(event_vector.size() >=5999){
            }
            else{
                temp_string = std::to_string(airspace->get_plane_identification_number(i));
                event_vector.push_back(airspace->get_plane_name(i) + " " + airspace->get_plane_model(i) + " " +temp_string + events[3]);

            }
            airspace->get_plane(i) = airspace->get_plane(airspace->get_planes_count()-1);
            airspace->plane_minus_size();
            Plane::get_total_planes_minus();
        }
    }
    //std::cout<<"4\n";
}


void Simulation::simulate_service(){
    for (int i = 0;i<airports.size();i++){
        for (int j =0;j<airports[i].get_planes_count();j++){
            std::string temp_string;
            int rnumber1 = rand() % 15;
            int rnumber2 = rand() % 5;

            if(airports[i].get_plane_age(j) > 30 && airports[i].get_plane_age(j) < 40 && rnumber1 == 1 && service_port->get_planes_count() < service_port->get_max_planes()){
                if(event_vector.size() >=5999){
                }
                else{
                    temp_string = std::to_string(airports[i].get_plane_identification_number(j));
                    event_vector.push_back(airports[i].get_plane_name(j) + " " + airports[i].get_plane_model(j) + " " +temp_string + events[4] + " " + airports[i].get_name());
                }
                service_port->plane_plus_size();
                service_port->get_plane(service_port->get_planes_count()-1) = airports[i].get_plane(j);
                service_port->get_plane_location_time(service_port->get_planes_count()-1) = 0;

                airports[i].get_plane(j) = airports[i].get_plane(airports[i].get_planes_count()-1);
                airports[i].get_plane_location_time(j) = airports[i].get_plane_location_time(airports[i].get_planes_count()-1);
                airports[i].plane_minus_size();
            }

            else if(airports[i].get_plane_age(j) > 40 && rnumber2 == 1 && service_port->get_planes_count() < service_port->get_max_planes()){
                if(event_vector.size() >=5999){
                }
                else{
                    temp_string = std::to_string(airports[i].get_plane_identification_number(j));
                    event_vector.push_back(airports[i].get_plane_name(j) + " " + airports[i].get_plane_model(j) + " " +temp_string + events[4] + " " + airports[i].get_name());
                }
                service_port->plane_plus_size();
                service_port->get_plane(service_port->get_planes_count()-1) = airports[i].get_plane(j);
                service_port->get_plane_location_time(service_port->get_planes_count()-1) = 0;

                airports[i].get_plane(j) = airports[i].get_plane(airports[i].get_planes_count()-1);
                airports[i].get_plane_location_time(j) = airports[i].get_plane_location_time(airports[i].get_planes_count()-1);
                airports[i].plane_minus_size();
            }
        }
    }
    //std::cout<<"5\n";
}

void Simulation::simulate_repair(){
    for(int i = 0;i<service_port->get_planes_count();i++){
        std::string temp_string;
        if(service_port->get_plane_age(i) > 0){
            service_port->get_plane_age(i) -=1;
        }
        else{
            if(event_vector.size() >=5999){
            }
            else{
                temp_string = std::to_string(service_port->get_plane_identification_number(i));
                event_vector.push_back(service_port->get_plane_name(i) + " " + service_port->get_plane_model(i) + " " +temp_string + events[5]);
            }
            airspace->plane_plus_size();
            airspace->get_plane(airspace->get_planes_count()-1) = service_port->get_plane(i);
            service_port->get_plane(i) = service_port->get_plane(service_port->get_planes_count()-1);
            service_port->plane_minus_size();
        }
    }
    //std::cout<<"6\n";
}

void Simulation::show_events(){
    for(size_t i = 0; i < event_vector.size(); ++i) {
        std::cout<<i+1<<": "<< event_vector[i]<<"\n";
    }
    if(event_vector.size() >=6000){
        std::cout<<"Warning event count can't be higher than 5999\n";
    }
}

void Simulation::search_data(){
    std::string name;
    std::cout<<"Enter the plane name you would like to search: \n";
    std::cin >> std::ws;
    std::getline(std::cin, name);
    for (size_t i = 0; i < event_vector.size(); ++i){
        if(event_vector[i].substr(0, name.length()) == name){
             std::cout<<i+1<<": "<< event_vector[i]<<"\n";
        }
    }
}

void Simulation::simulate(bool *module_flag_airport_dist,bool *module_flag_airspace_dist, bool *module_flag_destruction){
    event_vector.resize(1);
    while(timer > 0){
        simulate_time();
        if(*module_flag_airport_dist == true){
            simulate_distribution_airport();
        }
        if(*module_flag_airspace_dist == true){
            simulate_distribution_airspace();
        }
        if(*module_flag_destruction == true){
            simulate_plane_destruction();
        }

        simulate_service();
        simulate_repair();

        std::cout<<"Simulating... ";
        std::cout<<timer<<" ticks left\n";
        timer = timer -1;
        Sleep(simulation_delay);
    }
}


std::vector<Airport>& Simulation::GetAirports() {
    return airports;
}

Airspace* Simulation::GetAirspace() {
    return airspace;
}

Service_Port* Simulation::GetServicePort() {
    return service_port;
}