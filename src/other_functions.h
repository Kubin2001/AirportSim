#ifndef OTHER_FUNCTIONS_H_INCLUDED
#define OTHER_FUNCTIONS_H_INCLUDED


void show_simulation(Simulation *simulation);

void settings(int airport_size,Simulation *simulation,bool *module_flag_airspace_dist,bool *module_flag_airport_dist,bool *module_flag_destruction,bool *module_flag_plane_copy);

void sim_time(Simulation *simulation);

void modules(bool *module_flag_airport_dist,bool *module_flag_airspace_dist,bool *module_flag_destruction,bool *module_flag_plane_copy);

void sort_type(Simulation* simulation, int airport_size);

void change_names(Simulation *simulation);

void ask_input(std::vector <Airport> &vec,int airport_size,int *airport_index);

#endif // OTHER_FUNCTIONS_H_INCLUDED
