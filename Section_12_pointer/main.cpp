
#include <iostream>
#include <vector>
#include <string>

//a pointer is a variable which stores in memory the location of a specific variable

void double_data(int *int_ptr){
    *int_ptr *=2; // doubling int_ptr by 2
}

//parameters like this avoid changes in value (exactly like declaration)
void display_data(const int *const int_ptr){
    std::cout << "Safe function that won't change pointer nor value which it points to prints the value : " << *int_ptr << std::endl;
}

int *create_array(size_t size, int init_value = 0){
    int *new_storage {nullptr};
    new_storage = new int[size];

    for(size_t i = 0; i<size; i++)
        *(new_storage + i) = init_value;
    
    return new_storage;
}


int main(){

    int num{10};

    std::cout<< "Value of num is : " << num << std::endl;
    std::cout<< "Size of num (in bytes) is : " << sizeof num << std::endl;
    std::cout<< "Address of num is : " << &num << std::endl;

    int *test_ptr;
    std::cout << "\nValue of test_ptr is : " << test_ptr << std::endl;
    std::cout << "Size of test_ptr is : " << sizeof test_ptr << std::endl;
    std::cout<< "Address of test_ptr is : " << &test_ptr << std::endl;

    test_ptr = nullptr;

    std::cout << "\nValue of test_ptr is : " << test_ptr << std::endl;

    test_ptr = &num;

    std::cout << "\nAfter assignment to num, value of test_ptr is : " << test_ptr << std::endl;
    std::cout<< "Address of num is still : " << &num << std::endl;

    bool equal{};
    equal = test_ptr == &num;
    std::cout << std::boolalpha;
    std::cout<< "Therefore test_ptr == &num : " << equal << std::endl;

    std::cout << "\nAccessing num through test_ptr : " << *test_ptr << std::endl;
    *test_ptr = 12;
    std::cout << "Changed the value of num through test_ptr to the value : " << num << "\n" << std::endl;

    int scores[] {100, 95, 87, 99};

    int *scores_ptr {scores};
    
    //when you use the "+" operator for a pointer, you increment the address by the amount of bytes
    //the declared type contains (ie. 4 bytes for an int)
    for(int i=0;i<(sizeof(scores)/sizeof(int));i++){
        //this confuses me
        std::cout << "The " << i << "th element = " << scores_ptr[i] << std::endl;
        //this does not
        std::cout << "The " << i << "th element = " << *(scores_ptr+i) << std::endl;
        }
    //increment
    std::cout << "\nIncrementing scores pointer gives the address " << ++scores_ptr << " which points to " << *scores_ptr << std::endl;
     std::cout << "You can increment a pointer (find value at next index) *(++scores_ptr) : " << *(++scores_ptr) <<
     " or increment the value (at position 0) " << *scores_ptr <<" using '++(*())' : " << ++(*scores_ptr) << std::endl;
    
    //creating values through a pointer
    int *int_ptr {nullptr};
    int_ptr = new int;
    std::cout << "\nThis is the garbage value of the integer that 'int_ptr' points to : " << *int_ptr << std::endl;
    *int_ptr = 100;
    std::cout << "This is the value of the integer that 'int_ptr' points to, after assignment : " << *int_ptr << std::endl;
    //deallocates the storage (deletes the integer)
    delete int_ptr;

    int *array_ptr {nullptr};
    //allocate an array of 7 ints to the pointer's address
    array_ptr = new int[7];
    //to delete an array
    delete [] array_ptr;

    int value {100};
    //the value which is pointed cannot be changed trough value_ptr
    const int *value_ptr {&value};
    //the address itself is constant
    int *const value_ptr_2 {&value};
    //both the address and the value are constant
    const int *const value_ptr_3 {&value};

    std::cout << "\nFunction double pointer takes pointed variable " << *value_ptr_2 << " and doubles it to " ;
    double_data(value_ptr_2); //value_ptr & value_ptr_3 wouldn't work here as they use "const int"
    std::cout << *value_ptr_2 << std::endl;
    std::cout << *value_ptr << "\t" << *value_ptr_3 << std::endl;
    display_data(value_ptr_3);

    //building an array of 5 values all equal to 2
    int *my_array = create_array(5, 2);
    for(int i{0}; i<5; i++)
        std::cout << my_array[i] << std::endl;


    //references in C++
    //ref is an alias of num 
    int &ref {num};

    num = 300;
    std::cout << "\nIf we change the value of num, is num & ref still equal ? " << (num == ref) << std::endl;
    ref = 200;
    std::cout << "If we change the value of ref, is num & ref still equal ? " << (num == ref) << std::endl;

    std::vector<std::string> friends{"Jack", "Moe", "Bob"};

    // you can use the keyword "const &val" to lock the values of vector friend
    for(auto &val: friends){
        std::cout << "Previous value : " << val;
        val = "Fro";
        std::cout << " to => " << val << std::endl;
    }
    std::cout << "Proof : " << friends.at(0) << std::endl;

    return 0;
}