#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>

#include "objects.h"

void Airport::show_data(int temp,int airport_number){
    std::cout<<airport_number+1<<": "<<"Name: "<<name<<" Planes: "<<planes_count<<" Max planes: "<<max_planes<<"\n\n";
    for (int j =0;j<planes_count;j++){
        std::cout<<"    "<<j+1<<": "<<plane[j];
    }
    std::cout<<"\n";
}

void Airport::sort_planes(){
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


void Airport::Ground::create_array(std::vector <Airport>& airport,int *airport_index){
    for(int i = 0;i<100;i++){
        if(i < airport[*airport_index-1].max_planes && i >= airport[*airport_index-1].planes_count ){
            airport[*airport_index-1].ground.ground_array[i] = 'F';
        }

        else if(i < airport[*airport_index-1].planes_count){
            airport[*airport_index-1].ground.ground_array[i] = 'O';
        }

        else if(i >= airport[*airport_index-1].max_planes){
            airport[*airport_index-1].ground.ground_array[i] = 'X';

        }
    }
}

void Airport::Ground::show_array(std::vector <Airport>& airport,int *airport_index){
    int temp = 1;
    std::cout<<"Airport Name: "<<airport[*airport_index-1].name<<"\n";
    std::cout<<"Docked planes: "<<airport[*airport_index-1].planes_count<<"\n";
    std::cout<<"Maximum number of planes that can be docked: "<<airport[*airport_index-1].max_planes<<"\n\n";
    for(int i = 0;i<100;i++){
        std::cout<<airport[*airport_index-1].ground.ground_array[i]<<" ";
        temp++;
        if(temp == 11){
            std::cout<<"\n";
            temp = 1;
        }
    }
    std::cout<<"\n";
    temp = 1;
    std::cout<<"F = Free space\n";
    std::cout<<"O = Occupied Space\n";
    std::cout<<"X = Inaccessible space\n\n";
}

void Airport::plane_plus_size(){
     plane.push_back(Plane());
     planes_count ++;
}

void Airport::plane_minus_size(){
    plane.pop_back();
    planes_count --;
}


std::string &Airport::get_name(){
    return name;
}
int &Airport::get_planes_count(){
    return planes_count;
}
int &Airport::get_max_planes(){
    return max_planes;
}

int &Airport::get_sort_time(){return sort_type;}

///planes
std::string &Airport::get_plane_name(int plane_indeks){
    return plane[plane_indeks].name;
}
std::string &Airport::get_plane_model(int plane_indeks){
    return plane[plane_indeks].model;
}
int &Airport::get_plane_identification_number(int plane_indeks){
    return plane[plane_indeks].identification_number;
}
int &Airport::get_plane_age(int plane_indeks){
    return plane[plane_indeks].age;
}
int &Airport::get_plane_location_time(int plane_indeks){
    return plane[plane_indeks].location_time;
}

Plane &Airport::get_plane(int plane_indeks){
    return plane[plane_indeks];
}
