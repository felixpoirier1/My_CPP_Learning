#include <iostream>

void print(int arr[], int len){

    std::cout << "[ ";
    for(int i{0} ; i<len ; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;

}

int *apply_all(const int *const arr1, int len1, const int *const  arr2, int len2){

    int *ptr_arr {};

    ptr_arr = new int[len1 * len2];

    int position {};

    for(int i{0} ; i<len1 ; i++){
        for(int j{0} ; j<len2 ; j++){
            ptr_arr[position] = arr1[i]*arr2[j];
            ++position;
        }
    }
    return ptr_arr;

}

int main(){

    int array_1[] {1, 1, 1};
    int array_2[] {2, 2, 2};
    std::cout << "Array 1 : ";
    print(array_1, sizeof(array_1)/sizeof(int));
    std::cout << "Array 2 : ";
    print(array_2, sizeof(array_2)/sizeof(int));

    int *results = apply_all(array_1, sizeof(array_1)/sizeof(int), array_2, sizeof(array_2)/sizeof(int));

    std::cout << "Results : ";
    print(results, 9);


    return 0;
}