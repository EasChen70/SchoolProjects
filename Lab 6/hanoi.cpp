#include <iostream>
#include <fstream>
#include <sstream>

void Tower(int num_disks, int source_rod, int aux_rod, int destination_rod){
    if(num_disks == 1){
        std::cout<<"Move disk "<< num_disks <<" from tower "<< source_rod <<" to tower "<< destination_rod << std::endl;
        return;
    }
    Tower(num_disks - 1, source_rod, destination_rod, aux_rod);
	std::cout<<"Move disk "<< num_disks <<" from tower "<< source_rod <<" to tower "<< destination_rod << std::endl;
	Tower(num_disks - 1, aux_rod, source_rod, destination_rod);


}

int auxRod(int source_rod, int destination_rod){
    int aux_rod = 0;
    if(source_rod == 1 && destination_rod == 2){
        aux_rod = 3;
        //std::cout<<"hi1"<<std::endl;
    }
    else if(source_rod == 1 && destination_rod == 3){
        aux_rod = 2;
        //std::cout<<"hi2"<<std::endl;
    }
    else if(source_rod == 2 && destination_rod == 1){
        aux_rod = 3;
        //std::cout<<"hi3"<<std::endl;
    }
    else if(source_rod == 2 && destination_rod == 3){
        aux_rod = 1;
        //std::cout<<"hi4"<<std::endl;
    }
    else if(source_rod == 3 && destination_rod == 2){
        aux_rod = 1;
        //std::cout<<"hi5"<<std::endl;
    }
    else if(source_rod == 3 && destination_rod == 1){
        aux_rod = 2;
        //std::cout<<"hi6"<<std::endl;
    }
    return aux_rod;
}

int main(int argc, char* argv[]){
    int num_disks = std::stoi(argv[1]);
    int source_rod = std::stoi(argv[2]);
    int destination_rod = std::stoi(argv[3]);
    int aux_rod;
    aux_rod = auxRod(source_rod, destination_rod);
    //std::cout<<auxRod(2,3)<<std::endl;
    
    Tower(num_disks, source_rod, aux_rod, destination_rod);
}