class ParkingSystem {
public:
    
    int big, medium, small;
    
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int c) {
        if(c == 1) {
            if(big > 0 ) { 
                big--;
                return 1;
            }else return 0;
        }
        
        if(c == 2) {
            if(medium > 0 ) { 
                medium--;
                return 1;
            }else return 0;
        }
        
        if(c == 3) {
            if(small > 0 ) { 
                small--;
                return 1;
            }else return 0;
        }
        
        return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
