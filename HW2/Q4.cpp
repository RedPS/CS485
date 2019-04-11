#include <cmath>
#include <iostream>

int main(){
    float sigma = 1.0;
    int mask_size = -1;
    do{
        std::cout << "Enter the Mask size (Enter 0 to stop): ";
        std::cin >> mask_size;
        for (int i = -mask_size/2; i <= mask_size/2; i++){
            for (int j = mask_size/2; j >= -mask_size/2; j--){
                int result = (255 * ((pow(i,2)) + (pow(j,2)) - 2 * (pow(sigma,2))) * (exp(-((pow(i,2))+(pow(j,2)))/ 2.0 / sigma / sigma)) )/ (pow(sigma,4));
                printf("%10d",result);
            }
            std::cout << std::endl;
        }
    }while(mask_size != 0);
    return 0;
}