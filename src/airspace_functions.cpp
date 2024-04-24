#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

#include "objects.h"

void Airspace::create_data(int &fluent_planes_number){
    int temp;
    std::cout<<"How many planes would you like to add? (min 1 max 500): ";
    std::cin>>temp;
    if (temp >500){
        temp = 500;
    }
    else if(temp <1){
        temp = 1;
    }
    if(planes_count >1000){
        std::cout<<"There are over 1000 planes in airspace you can't add more";
    }

    else if(planes_count <=1000){
        planes_count += temp;
        std::cout<<"Planes number: "<<planes_count<<"\n";
    }
    fluent_planes_number = planes_count - temp;

}

void Airspace::initialize_data(int &fluent_planes_number,bool *module_flag_plane_copy){
    char choice = 0;
    srand(time(nullptr));
    int rnumber;
    int rnumber2;
    int rnumber3;
    int rnumber4;
    std::string plane_names[11];
    std::ifstream infile("input/plane_name.txt");
    for (int i =0;i<11;i++){
        getline(infile, plane_names[i]);
    }
    infile.close();

    std::string plane_model[26];
    std::ifstream infile2("input/plane_models.txt");
    for (int i =0;i<26;i++){
        getline(infile2, plane_model[i]);
    }
    infile2.close();

    if(*module_flag_plane_copy == true){
        std::cout<<"Would you like to make all planes the same?( 1 yes 0 no): ";
        std::cin>>choice;
        if(choice == '1'){
            for (int i = fluent_planes_number;i<planes_count;i++){
                Plane::get_total_planes_plus();
                plane.push_back(Plane());
                rnumber = rand()%11;
                rnumber2 = rand()%26;
                rnumber3 = rand()%2000 +1;
                rnumber4 = rand()%48 +1;
                plane[i] = Plane(plane_names[rnumber],plane_model[rnumber2],rnumber3,rnumber4,0);
                //std::cout<<rnumber<<"<<<rand1:\n";
            }

            for (int i = fluent_planes_number;i<planes_count;i++){
                Plane::get_total_planes_plus();
                plane.push_back(Plane());
                rnumber = rand()%11;
                rnumber2 = rand()%26;
                rnumber3 = rand()%2000 +1;
                rnumber4 = rand()%48 +1;
                plane[i] = Plane(plane[fluent_planes_number]);
                //std::cout<<rnumber<<"<<<rand1:\n";
            }

        }
        else{
            for (int i = fluent_planes_number;i<planes_count;i++){
                Plane::get_total_planes_plus();
                plane.push_back(Plane());
                rnumber = rand()%11;
                rnumber2 = rand()%26;
                rnumber3 = rand()%2000 +1;
                rnumber4 = rand()%48 +1;
                plane[i] = Plane(plane_names[rnumber],plane_model[rnumber2],rnumber3,rnumber4,0);
                //std::cout<<rnumber<<"<<<rand1:\n";
            }
        }
    }

    else{
        for (int i = fluent_planes_number;i<planes_count;i++){
            Plane::get_total_planes_plus();
            plane.push_back(Plane());
            rnumber = rand()%11;
            rnumber2 = rand()%26;
            rnumber3 = rand()%2000 +1;
            rnumber4 = rand()%48 +1;
            plane[i] = Plane(plane_names[rnumber],plane_model[rnumber2],rnumber3,rnumber4,0);
            //std::cout<<rnumber<<"<<<rand1:\n";
        }
    }
}

void Airspace::show_data(){
    std::cout<<"--------| Airspace |-------\n";
    std::cout<<"--------"<<"| "<<planes_count<<" planes |"<<"-------\n";
     for (int i =0;i<planes_count;i++){
        std::cout<<"    "<<i+1<<": "<<plane[i];
    }
}

void Airspace::sort_planes(){
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

void Airspace::plane_plus_size(){
    plane.push_back(Plane());
    planes_count ++;
}

void Airspace::plane_minus_size(){
    plane.pop_back();
    planes_count --;
}


////////////////////

std::string &Airspace::get_name(){
    return name;
}

int &Airspace::get_planes_count(){
    return planes_count;
}

int &Airspace::get_max_planes(){
    return max_planes;
}

int &Airspace::get_sort_time(){return sort_type;}

/////////////////

std::string &Airspace::get_plane_name(int plane_indeks){
    return plane[plane_indeks].name;
}

std::string &Airspace::get_plane_model(int plane_indeks){
    return plane[plane_indeks].model;
}

int &Airspace::get_plane_identification_number(int plane_indeks){
    return plane[plane_indeks].identification_number;
}

int &Airspace::get_plane_age(int plane_indeks){
    return plane[plane_indeks].age;
}

int &Airspace::get_plane_location_time(int plane_indeks){
    return plane[plane_indeks].location_time;
}

Plane &Airspace::get_plane(int plane_indeks){
    return plane[plane_indeks];
}
