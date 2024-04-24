#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include "objects.h"

void Service_Port::plane_plus_size(){
     plane.push_back(Plane());
     planes_count ++;
}

void Service_Port::plane_minus_size(){
    plane.pop_back();
    planes_count --;
}

void Service_Port::show_data(){

    std::cout<<"--------| "<<name<<"          |-------\n"
    <<"--------"<<"| "<<planes_count<<" planes              |-------\n"
    <<"--------"<<"| Maximal capacity "<<max_planes<<"  |-------\n";
    for(int i = 0;i<planes_count;i++){
        std::cout<<"    "<<i+1<<": "<<plane[i];
    }
}

void Service_Port::sort_planes(){
    switch(sort_type){
        case 1:
            std::sort(plane.begin(), plane.end(), [](Plane &plane1, Plane &plane2) {
                return plane1.get_name() < plane2.get_name();
            });
            break;

        case 2:
            std::sort(plane.begin(), plane.end(), [](Plane &plane1, Plane &plane2) {
                return plane1.get_model() < plane2.get_model();
            });
            break;

        case 3:
            std::sort(plane.begin(), plane.end(), [](Plane &plane1, Plane &plane2) {
                return plane1.get_identification_number() < plane2.get_identification_number();
            });
            break;

        case 4:
            std::sort(plane.begin(), plane.end(), [](Plane &plane1, Plane &plane2) {
                return plane1.get_age() < plane2.get_age();
            });
            break;

        case 5:
            std::sort(plane.begin(), plane.end(), [](Plane &plane1, Plane &plane2) {
                return plane1.get_location_time() < plane2.get_location_time();
            });
            break;
    }
}

///planes
std::string &Service_Port::get_name(){return name;}
int &Service_Port::get_planes_count(){return planes_count;}
int &Service_Port::get_max_planes(){return max_planes;}
int &Service_Port::get_sort_time(){return sort_type;}
///planes

std::string &Service_Port::get_plane_name(int plane_indeks){
    return plane[plane_indeks].name;
}
std::string &Service_Port::get_plane_model(int plane_indeks){
    return plane[plane_indeks].model;
}
int &Service_Port::get_plane_identification_number(int plane_indeks){
    return plane[plane_indeks].identification_number;
}
int &Service_Port::get_plane_age(int plane_indeks){
    return plane[plane_indeks].age;
}
int &Service_Port::get_plane_location_time(int plane_indeks){
    return plane[plane_indeks].location_time;
}

Plane &Service_Port::get_plane(int plane_indeks){
    return plane[plane_indeks];
}
