#include <iostream>

using namespace std;

class Student
{
private:
    string id;
    double gpa;
public:
    string name;
    Student(){};
    Student(string n, string i, double g) //implement the function
    {
        name = n;
        id = i;
        gpa = g;
    }

    void print() //implement the function
    {
        cout <<"Student Name: "<< name <<endl;
        cout <<"Student ID: "<< id <<endl;
        cout <<"Student GPA: "<< gpa <<endl;
    }
    // add function overloading <  declaration to Student class
    bool operator<(const Student &compared_to_student);

};

//Overload the operator <
bool Student::operator<(const Student &compared_to_student)
{
    if(name.compare(compared_to_student.name) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
int selectionsort(T array[], int size_of_array);

template <typename T>
int insertionsort(T array[], int size_of_array);

template <typename T>
int shellsort(T array[], int size_of_array);

template <typename T>
int mergesort(T array[], int leftmost_index, int rightmost_index);

template<typename T>
int merge( T finished_array[],int finished_array_leftmost_index,int middle_index,int finished_array_rightmost_index);

void bin_search(Student arr[], string target, int length );
int binarySearchString(string arr[], string x, int n);

int main()
{
    int num_of_comparison_selection;
    int num_of_comparison_insertion;
    int num_of_comparison_shell;
    int num_of_comparison_merge;
    string search_student;

    Student s[]={Student("Ahmed Adel"  , "1322" , 2.8) ,
                 Student("John David"   , "1340" , 3.2) ,
                 Student("Tarek Ghaly"  , "1342" , 3.2) ,
                 Student("Saleh Lotfy"  , "1348" , 3.2) ,
                 Student("Ola Nasser"    , "1351" , 3.2) ,
                 Student("Rashed Mamdouh" , "1384" , 3.2) ,
                 Student("Ashour Diaa" , "1325" , 2.5)};

    int length_of_array_s = sizeof(s)/sizeof(s[0]);

    for(int i =0; i<length_of_array_s; i++){
        cout <<"====== student number "<<i+1<<" ======\n";
        s[i].print();
    }

    cout<<"\t============\n";
    num_of_comparison_selection = selectionsort(s,length_of_array_s);
    num_of_comparison_insertion = insertionsort(s,length_of_array_s);
    num_of_comparison_shell = shellsort(s,length_of_array_s);
    num_of_comparison_merge = mergesort(s,0,length_of_array_s-1);

    cout <<"Number of comparisons of Selection Sort = "<<num_of_comparison_selection<<endl;
    cout <<"Number of comparisons of Insertion Sort = "<<num_of_comparison_insertion<<endl;
    cout <<"Number of comparisons of Shell Sort = "<<num_of_comparison_shell<<endl;
    cout <<"Number of comparisons of Merge Sort = "<<num_of_comparison_merge<<endl;
    cout<<"\t============\n";


    for(int i =0; i<length_of_array_s; i++){
        cout <<"====== student number "<<i+1<<" ======\n";
        s[i].print();
    }

    cout << "====== Search for a student ======\n";
    cout <<"let us search about Ola Nasser \n";
    bin_search(s, "Ola Nasser", length_of_array_s);


    return 0;
}
    //Selection Sort
template <typename T>
int selectionsort(T array[], int size_of_array)
{
    int number_of_compariosns = 0;
    for (int current_index = 0, comparison_index; current_index < size_of_array; current_index++) //iterate over the entire array
    {
        int index_of_minimum = current_index;
        for( comparison_index = current_index+1; comparison_index < size_of_array; comparison_index++) //iterate over an outer array of unsorted elements
        {
            number_of_compariosns++;
            if( array[comparison_index] < array[index_of_minimum]) //compare element stored at index_of_minimum with element within outer array
            {
                index_of_minimum = comparison_index ; // if element at index_of_minimum  > element at comparison index change index_of_minimum to comaprisonindex
            }
        }
        swap( array[index_of_minimum], array[current_index]);
    }
    return number_of_compariosns;
}
    //Insertion Sort
template <typename T>
int insertionsort(T array[], int size_of_array) {
    int number_of_comparisons = 0;
    for ( int current_element_index= 1,  sorted_end_index ; current_element_index < size_of_array; current_element_index ++) //iterate over unsorted array
    {
        T current_element = array[current_element_index]; // store current_element
        for ( sorted_end_index = current_element_index - 1,number_of_comparisons+=1; sorted_end_index >= 0 && current_element < array[sorted_end_index]  ;sorted_end_index --) //iterate from sorted end to begining of array based on if comparison
        {
            array[sorted_end_index + 1] = array[sorted_end_index]; // if current_element < end of sorted array shift sorted array to the right
        }
        array[sorted_end_index + 1]= current_element; // place current element after sorted array
    }
    number_of_comparisons+=1;
    return number_of_comparisons;
}
    //Shell Sort
template <typename T>
int shellsort(T array[], int size_of_array)
{
    int number_of_comparisons = 0;
    // get element through gap
    for (int gap = size_of_array / 2; gap >= 1; gap /= 2) //get gap
    {

        for ( int current_index = gap, sorted_end_index; current_index < size_of_array; current_index += 1)
        {
            number_of_comparisons++;
            T current_element = array[current_index];
            for (sorted_end_index = current_index - gap; sorted_end_index >= 0 && current_element <  array[sorted_end_index] ; sorted_end_index -= gap)
            {
                array[sorted_end_index + gap] = array[sorted_end_index];
            }
            array[sorted_end_index + gap]= current_element;
        }
    }
    number_of_comparisons+=1;
    return number_of_comparisons;
}
    //Merge Sort
template<typename T>
int merge( T finished_array[],int finished_array_leftmost_index,int middle_index,int finished_array_rightmost_index)
{
    int number_of_comparisons= 0;
    int left_array_size = middle_index + 1 - finished_array_leftmost_index;
    int right_array_size = finished_array_rightmost_index - (middle_index);
    // create left array and fill it
    T * left_array = new T [left_array_size];
    int left_array_index;
    int temp_left_index= finished_array_leftmost_index;
    for (left_array_index = 0; left_array_index < left_array_size; left_array_index++, temp_left_index++)
    {
        left_array[left_array_index] = finished_array[temp_left_index];
    }
    //create right array and fill it
    T * right_array = new T [right_array_size];
    int right_array_index;
    int temp_right_index = middle_index + 1;
    for ( right_array_index = 0; right_array_index < right_array_size;right_array_index++, temp_right_index++)
    {
        right_array[right_array_index] = finished_array[temp_right_index];
    }
    left_array_index = 0;
    right_array_index = 0;
    // compare left array and right array at index and place in finished array, and itterate if smaller
    while ( left_array_index < left_array_size && right_array_index < right_array_size)
    {
        number_of_comparisons++;
        if ( left_array[left_array_index] < right_array[right_array_index])
        {
            finished_array[finished_array_leftmost_index++] = left_array[left_array_index++];
        }
        else
        {
            finished_array[finished_array_leftmost_index++] = right_array[right_array_index++];
        }
    }
    // no more comparisons so place the remaining numbers in finished array
    while (left_array_index< left_array_size)
    {
        finished_array[finished_array_leftmost_index++] = left_array[left_array_index++];
    }
    while ( right_array_index < right_array_size)
    {
        finished_array[finished_array_leftmost_index++] = right_array[right_array_index++];
    }
    delete[] left_array;
    left_array = nullptr;
    delete[] right_array;
    right_array = nullptr;
    return number_of_comparisons;

}
 template <typename T>
int mergesort(T array[], int leftmost_index, int rightmost_index)
 {
     int number_of_comparisons = 0;
     number_of_comparisons++;
     //base case
     if( leftmost_index == rightmost_index)
     {
         return number_of_comparisons;
     }
     // recursively call for left of array and right of middle
     int middle_index = (rightmost_index + leftmost_index) / 2;
     mergesort(array, leftmost_index, middle_index);
     mergesort(array, middle_index +1 , rightmost_index);
     number_of_comparisons += merge(array,leftmost_index,middle_index,rightmost_index);
     return number_of_comparisons;
 }

 void bin_search(Student arr[], string target, int length ){
    int start=0, end=length-1, middle;
    bool student_not_here = 1;
    while (end >= start)
    {
        middle = start + (end-start)/2;
        if (arr[middle].name == target)
        {
            arr[middle].print();
            student_not_here =0;
            break;
        }
        else if (arr[middle].name > target)
        {
            end = middle-1;
        }
        else
        {
            start = middle+1;
        }
    }
    if(student_not_here)
        cout << "\n..Sorry, The student is not at the school database\n";
 }
