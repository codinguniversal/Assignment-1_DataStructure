//Name:Amr Mahmoud                  ID:20200767
//Name:Ahmed Mohamed Ahmed Wahba    ID:20200037
//Name:Bilal Ahmed Ghareb           ID:

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student
{
private:
public:
    string id;
    double gpa;
    string name;
    Student(){}; //defualt constructor
    Student(string n, string i, double g) //parameterized constructor
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
    bool operator<(const Student &compared_to_student); //overload the operator <

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

template <typename T> //template for selection sort
int selectionsort(T array[], int size_of_array); //selection sort

template <typename T>//template for insertion sort
int insertionsort(T array[], int size_of_array); //insertion sort

template <typename T>//template for shell sort
int shellsort(T array[], int size_of_array); //shell sort

template <typename T>//template for merge sort
int mergesort(T array[], int leftmost_index, int rightmost_index); //merge sort

template<typename T>//template for merge
int merge( T finished_array[],int finished_array_leftmost_index,int middle_index,int finished_array_rightmost_index);//merge

void bin_search(Student arr[], string target, int length ); //binary search

int main()
{
    int num_of_comparison_selection;
    int num_of_comparison_insertion;
    int num_of_comparison_shell;
    int num_of_comparison_merge;

    string search_student; //for binary search

    //Reading and Writing
    ifstream inputFile("students.txt"); // Open the input file
    ofstream outputFile1("Selection.txt"); // Open the output file
    ofstream outputFile2("Insertion.txt"); // Open the output file
    ofstream outputFile3("Shell.txt"); // Open the output file
    ofstream outputFile4("Merge.txt"); // Open the output file

    int numStudents;
    inputFile >> numStudents; // Read the number of students from the file
    inputFile.ignore(); // Ignore the newline character after reading the number of students

    Student* students = new Student[numStudents]; // Dynamic allocation of the student array

    // Read student data from the file
    for (int i = 0; i < numStudents; i++) {
        getline(inputFile, students[i].name);
        getline(inputFile, students[i].id);
        inputFile >> students[i].gpa;
        inputFile.ignore(); // Ignore the newline character after reading the GPA
    }
    num_of_comparison_selection = selectionsort(students,numStudents);//selection sort
    num_of_comparison_insertion = insertionsort(students,numStudents);//insertion sort
    num_of_comparison_shell = shellsort(students,numStudents);//shell sort
    num_of_comparison_merge = mergesort(students,0,numStudents-1);//merge sort

    // Write student data to the output file for selection sort
    outputFile1 << "Number of comparisons = " << num_of_comparison_selection << "\n";
    for (int i = 0; i < numStudents; i++) {
        outputFile1 << "Student " << i+1 << ":\n";
        outputFile1 << "Name: " << students[i].name << "\n";
        outputFile1 << "ID: " << students[i].id << "\n";
        outputFile1 << "GPA: " << students[i].gpa << "\n\n";
    }
    // Write student data to the output file for insertion sort
    outputFile2 << "Number of comparisons = " << num_of_comparison_insertion << "\n";
    for (int i = 0; i < numStudents; i++) {
        outputFile2 << "Student " << i+1 << ":\n";
        outputFile2 << "Name: " << students[i].name << "\n";
        outputFile2 << "ID: " << students[i].id << "\n";
        outputFile2 << "GPA: " << students[i].gpa << "\n\n";
    }
    // Write student data to the output file for shell sort
    outputFile3 << "Number of comparisons = " << num_of_comparison_shell << "\n";
    for (int i = 0; i < numStudents; i++) {
        outputFile3 << "Student " << i+1 << ":\n";
        outputFile3 << "Name: " << students[i].name << "\n";
        outputFile3 << "ID: " << students[i].id << "\n";
        outputFile3 << "GPA: " << students[i].gpa << "\n\n";
    }
    // Write student data to the output file fot merge sort
    outputFile4 << "Number of comparisons = " << num_of_comparison_merge << "\n";
    for (int i = 0; i < numStudents; i++) {
        outputFile4 << "Student " << i+1 << ":\n";
        outputFile4 << "Name: " << students[i].name << "\n";
        outputFile4 << "ID: " << students[i].id << "\n";
        outputFile4 << "GPA: " << students[i].gpa << "\n\n";
    }

    // Close the input and output files
    inputFile.close();
    outputFile1.close();
    outputFile2.close();
    outputFile3.close();
    outputFile4.close();

    int choice;
    ifstream fileToShow;
    cout << "1- Show number of comparisons and sorted array of selection sort\n";
    cout << "2- Show number of comparisons and sorted array of shell sort\n";
    cout << "3- Show number of comparisons and sorted array of merge sort\n";
    cout << "4- Search for a student by name\n";
    cout << "5- Exit\n";
    cin >>choice;
    switch(choice)
    {
        case 1:
        {
            ifstream f("selection.txt");
            if (f.is_open())
                cout << f.rdbuf();
            break;
        }
        case 2:
        {
            std::ifstream f("shell.txt");
            if (f.is_open())
                cout << f.rdbuf();
            break;
        }
      case 3:
        {
            std::ifstream f("merge.txt");
            if (f.is_open())
                cout << f.rdbuf();
            break;
        }
        case 4:
        {
            cout <<"Write the student name : ";
            cin.ignore();
            getline (cin,search_student);
            bin_search(students, search_student, numStudents);
            break;
        }
        case 5:
        {
            exit;
        }
    }

    // Deallocate the memory of the student array
    delete[] students;
    //students = nullptr;

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

    //Binary Search
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
