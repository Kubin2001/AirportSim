#ifndef PRINTING_H_INCLUDED
#define PRINTING_H_INCLUDED

class Print_manager{
    private:
        std::string file_name;
        std::string type = ".txt";

    public:
        void print(Simulation *simulation);

        void single_printer(Simulation* simulation);

        void multi_printer(Simulation* simulation);

        void airspace_printer(Simulation* simulation);

        void printer_all(Simulation* simulation);

        Print_manager (std::string file_name){
            this->file_name = file_name;
        }

        ~Print_manager (){
            std::cout<<"Print manager data cleared!\n";
        }

};

#endif // PRINTING_H_INCLUDED
