#pragma once

class Plane{
    friend class Abstract_Container;
    friend class Airport;
    friend class Airspace;
    friend class Service_Port;

    private:
        std::string name;
        std::string model;
        int identification_number;
        int age;
        int location_time;
        static int total_planes;

    public:
        std::string &get_name(){return name;}
        std::string &get_model(){return model;}
        int &get_identification_number(){return identification_number;}
        int &get_age(){return age;}
        int &get_location_time(){return location_time;}

        static int &get_total_planes(){return total_planes;}
        static int &get_total_planes_plus(){
             total_planes +=1;
             return total_planes;}

         static int &get_total_planes_minus(){
             total_planes -=1;
             return total_planes;}

        Plane(){
        }

        Plane(std::string name,std::string model,int identification_number,int age,int location_time){
                this->name = name;
                this->model = model;
                this->identification_number = identification_number;
                this->age = age;
                this->location_time = location_time;
        }

        Plane& operator=(const Plane& other) {
            if (this != &other) {
                this->name = other.name;
                this->model = other.model;
                this->identification_number = other.identification_number;
                this->age = other.age;
                this->location_time = other.location_time;
            }
            return *this;
        }

        Plane(const Plane& other) {
            name = other.name;
            model = other.model;
            identification_number = other.identification_number;
            age = other.age;
            location_time = other.location_time;
        }

        ~Plane(){
        }

        friend std::ostream& operator <<(std::ostream& output,const Plane plane);
        friend std::istream& operator >>(std::istream& input,Plane &plane);
};


class Airspace{

    private:
        std::string name;
        int planes_count;
        int max_planes;
        int sort_type;
        std::vector<Plane> plane;

    public:
        void create_data(int &fluent_planes_number);

        void initialize_data(int &fluent_planes_number,bool *module_flag_plane_copy);

        void show_data();

        void sort_planes();

        void plane_plus_size();

        void plane_minus_size();

        //getters
        std::string &get_name();

        int &get_planes_count();

        int &get_max_planes();

        int &get_sort_time();

        /////
        std::string &get_plane_name(int plane_indeks);
        std::string &get_plane_model(int plane_indeks);
        int &get_plane_identification_number(int plane_indeks);
        int &get_plane_age(int plane_indeks);
        int &get_plane_location_time(int plane_indeks);
        Plane &get_plane(int plane_indeks);
        //getersplane

        Airspace(){
        }

        Airspace(std::string name,int planes_count,int max_planes,int sort_type){
            this->name = name;
            this->planes_count = planes_count;
            this->max_planes = max_planes;
            this->sort_type = sort_type;
        }

        ~Airspace(){
        }
        friend std::ostream& operator <<(std::ostream& output,const Airspace airspace_r);
};


class Airport{
    friend class Ground;

    private:
        std::string name;
        int planes_count;
        int max_planes;
        int sort_type;
        std::vector<Plane> plane;

    public:

        void initialize_data(int index);

        void show_data(int temp,int airport_number);

        void sort_planes();

        void plane_plus_size();

        void plane_minus_size();

        /////
        std::string &get_name();
        int &get_planes_count();
        int &get_max_planes();
        int &get_sort_time();
        ////////
        std::string &get_plane_name(int plane_indeks);
        std::string &get_plane_model(int plane_indeks);
        int &get_plane_identification_number(int plane_indeks);
        int &get_plane_age(int plane_indeks);
        int &get_plane_location_time(int plane_indeks);
        Plane &get_plane(int plane_indeks);


        Airport(std::string name, int planes_count, int max_planes, int sort_type){
            this->name = name;
            this->planes_count = planes_count;
            this->max_planes = max_planes;
            this->sort_type = sort_type;
        }

        friend std::ostream& operator <<(std::ostream& output,const Airport airport_r);

        class Ground{

            friend class Airport;

            private:
            char ground_array[100];

            public:

            void create_array(std::vector <Airport>& airport,int *airport_index);

            void show_array(std::vector <Airport>& airport,int *airport_index);


        }ground;
};

class Service_Port{
    private:
        std::string name;
        int planes_count;
        int max_planes;
        int sort_type;
        std::vector<Plane> plane;
        bool created;
        Plane *temp_plane;
    public:

        void plane_plus_size();

        void plane_minus_size();

        void show_data();

        void sort_planes();

        std::string &get_name();
        int &get_planes_count();
        int &get_max_planes();
        int &get_money();
        int &get_sort_time();
        ////////
        std::string &get_plane_name(int plane_indeks);
        std::string &get_plane_model(int plane_indeks);
        int &get_plane_identification_number(int plane_indeks);
        int &get_plane_age(int plane_indeks);
        int &get_plane_location_time(int plane_indeks);
        Plane &get_plane(int plane_indeks);

        Service_Port(std::string name,int planes_count,int max_planes,int sort_type,bool created){
            this->name = name;
            this->planes_count = planes_count;
            this->max_planes = max_planes;
            this->sort_type = sort_type;
            this->created = created;
        }

        friend std::ostream& operator <<(std::ostream& output, const Service_Port service);

};

class Simulation{
    private:
        Airspace* airspace;
        std::vector<Airport> airports;
        Service_Port* service_port;

        int simulation_delay = 100;
        int timer;
        char contin;
        std::vector <std::string> event_vector;
        std::string events[6]  ={" had been moved to airspace from "," had been moved to airport",
        " had been moved out of commission"," had been destroyed"," had been moved to service from"," had been moved to airspace from service"};

    public:

        void sim_create_vector();

        void simgettime();

        void simulate_time();

        void simulate_distribution_airspace();

        void sub_dist_airspace(std::string temp_string,int i,int rnumber5);

        void sub_dist_airport(std::string temp_string,int i,int j);

        void simulate_distribution_airport();

        void simulate_plane_destruction();

        void simulate_service();

        void simulate_repair();

        void show_events();

        void search_data();

        void simulate(bool *module_flag_airport_dist,bool *module_flag_airspace_dist, bool *module_flag_destruction);

        int &get_sim_delay(){
            return simulation_delay;
        }

        std::vector<Airport>& GetAirports();

        Airspace* GetAirspace();

        Service_Port* GetServicePort();

        Simulation();

    ~Simulation(){
        std::cout<<"Simulation data cleared\n";
        delete airspace;
        delete service_port;
    }
};

