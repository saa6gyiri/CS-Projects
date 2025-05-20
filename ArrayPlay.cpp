#include <iostream>

const int CAPACITY = 20;

void fillArray(int array[], int &numElements);
void printArray(int array[], int numElements);
bool isSorted(int array[], int numElements);
void insertValue(int array[], int &numElements, int insertValue);
int getInsertPosition(int array[], int numElements, int insertValue);
void deleteFromArray(int array [], int &numElements, int deleteValue);
int findInArray(int array[], int numElements, int findValue);
void sortArray(int array[], int numElements);
void reverseArray(int array[], int numElements);
using std::cout, std::endl, std::cin;
int main()
{

    int numArray[CAPACITY];     // an int array with a given CAPACITY
    // numArray can be partially filled, (so use numElements below
    // to indicate the number of elements in the array)

    int numElements = 0;     // the array is initially empty,
                             // i.e., contains 0 elements
    // The numElements variable will store the actual number of elements
    // stored as the program runs. Where appropriate, your code should
    // update the value of numElements.

    // 1. TODO: Call the fillArray function to collect a number of values
    // from a user.
    fillArray(numArray, numElements);
    // 2. TODO: Call the printArray function.
    printArray(numArray, numElements);
    cout << "\n";
    // 3. TODO: Call the isSorted function. If the array is sorted, print
    // "Array is sorted\n" otherwise print "Array is not sorted\n"
    if (isSorted(numArray, numElements) == 1){
	    cout << "Array is sorted \n";
    } else {
	  cout << "Array is not sorted \n";
      }
         	    
        
    // 4. TODO: Read a value from the user. Use this prompt: "Enter a value
    // to insert: "
    int value;
    cout << "Enter a value to insert: ";
    cin >> value;
    // Call the insertValue function to insert the value obtained from the
    // user.
    insertValue(numArray, numElements, value);
    // 5. TODO: Call printArray
    printArray(numArray, numElements);
    cout << "\n";
    // 6. TODO: Read a value from a user and then call the deleteFromArray
    // 
    // function to delete the value from the array if it is there. Use this
    // prompt: "Enter a value to delete: "
    cout << "Enter a value to delete: ";
    cin >> value;
    deleteFromArray(numArray, numElements, value);
    // 7. TODO: Call printArray
    printArray(numArray, numElements);
    cout << "\n";
    // 8. TODO: Call the sortArray function. 
    sortArray(numArray, numElements);
    // 9. TODO: Call printArray
    printArray(numArray, numElements);
    cout << "\n";
    // 10. TODO: Call the reverseArray function
    reverseArray(numArray, numElements);
    // 11. TODO: Print the prompt "Reversing the Array is:\n"
    // and then call the printArray function.
    cout << "Reversing the Array is: \n";
    printArray(numArray, numElements);
    cout << "\n";
    return 0;

}

//TODO: Implement all functions as required by the instructions.
using std::cout, std::cin, std::endl;

void fillArray(int array[], int &numElements){
  int input;
  cout << "Enter non-negative integers. End with -1: ";
  cin >> input;
  while (input != -1){
       array[numElements] = input;
       numElements++;
       cin >> input;
       if((input == -1)|| (numElements == CAPACITY)){
	       break;
       }
  }

}

void printArray(int array[], int numElements){
	for (int i = 0; i < numElements; i++){
		cout << array[i] << " ";
        }
}	

bool isSorted(int array[], int numElements){
	for (int i = 0; i < numElements - 1; i++){ // iterating through the array
	  if (array[i] > array[i + 1]){ // checks if the array is sorted
		return false;
	  }
        }
	return true;
}


void insertValue(int array[], int &numElements, int insertValue){	
	if (isSorted(array, numElements) == true){ // for sorted arrays
		int i;
		for (i = numElements - 1; i >= 0; i--){ // starting from the last element in the array
			if (array[i] > insertValue){
				array[i + 1] = array[i]; // moves all elements in the array down one position and leaves a space for the insertValue
			} else {
				break;
			  }
		}
		array[i + 1] = insertValue; 
		numElements++;
	} else {
		array[numElements] = insertValue; // for unsorted arrays, places the insertValue at the end of the array
		numElements++;
	}


}

int getInsertPositon(int array[], int numElements, int insertValue){
	for (int i = 0; i < numElements; i++){ // loops through the array to find the first element greater then the insert value
		if (array[i] > insertValue){
			return i; // returns the current index as the insert position
		}
	}
	return numElements;

}

void deleteFromArray(int array[], int &numElements, int deleteValue){
	int index = findInArray(array, numElements, deleteValue); // using findInArray function to get the index of the elements to delete
	if (index == -1){
		cout << "Not found \n";
		return;
	}
	if (isSorted(array, numElements) == true){ // for sorted arrays
		for (int i = index; i < numElements - 1; i++){
			array[i] = array[i + 1]; // shifts down each element in the array one postion
		}
	} else { // for unsorted arrays
		array[index] = array[numElements - 1]; // replaces the deleted element with the last element
	}
	numElements--;


}


int findInArray(int array[], int numElements, int findValue){
	for (int i = 0; i < numElements; i++){ // looping through the array
		if (array[i] == findValue){
			return i; // returns the index if the element is found
		} 
	}
	return -1; // returns -1 if the element is not found
}
			
void sortArray(int array[], int numElements){
	for (int i = 0; i < numElements - 1; i++){
		int minIndex = i;
		for (int j = i + 1; j < numElements; j++){
			if (array[j] < array[minIndex]){
				minIndex = j;
			}
		}
		if (minIndex != i){ // swapping the elements in the array
			int temp = array[i];
			array[i] = array[minIndex];
			array [minIndex] = temp;
		}
	}
}

void reverseArray(int array[], int numElements){
	 for (int i = 0; i < numElements / 2; i++){
                int temp = array [i];
		array [i] = array[numElements - 1 - i];
		array [numElements - 1 - i] = temp;
         }
}




