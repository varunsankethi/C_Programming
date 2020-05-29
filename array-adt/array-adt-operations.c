// Program to demonstrate all the array operations as part of the array abstract data type. 
// An abstract data type consists of the data type/ data structure (which in this case is the array) as well as the operations on the data structure
// This program comprehensively showcases the below operations on the array:

/*
	1. Display
	2. Add/Append
	3. Insert(int index)
	4. Delete(int index)
	5. Search(int key) // Linear search algorithm
	6. BinarySearcy(int key) // The array elements must be sorted
	7. Get(int index) // Get the value at a specified index
	8. Set(int index, int num) // Set the value of a specified index with a specified value
	9. Reverse and array using auxillary array

*/


#include<stdio.h>
#include<stdlib.h>

struct array {
	int *a;
	int size;
	int length;
};

void display(struct array arr) {
	
	int i;
	for (i=0;i<arr.length; i++) {
		printf("%d ", arr.a[i]);
	}
	printf("\n");
}

void append(struct array *arr, int num) {
	if (arr->length < arr->size ) {
		arr->a[arr->length] = num;
		arr->length++;
	} else {
		printf("Array is full. Delete elements to append\n");
	}
}

void delete(struct array *arr, int index) {
	if(index >=0 && index <arr->length) {
		printf("We can delete the index: %d\n", index);
		int i ;
		for (i=index; i<arr->length; i++) {
			arr->a[i] = arr->a[i+1];
		}
		printf("The index %d has been deleted \n", index);
		arr->length--;
	} else {
		printf("Invalid index to delete. Please provide valid index to delete\n");
	}
}

void insert(struct array *arr, int num, int pos) {
	printf("The element to insert is: %d and the position is %d \n", num, pos);
	if ((arr->length < arr->size ) && pos < arr->size && pos >= 0) {
		printf("Entering the insert part of the if condition\n");
		int i ;
		for (i=arr->length; i>pos; i--) {
			printf("Iteration I val = %d\n", i);
			arr->a[i] = arr->a[i-1];
		}
		arr->a[pos] = num;
		//arr->length = arr->length + (pos - (arr->length -1));
		arr->length = arr->length + 1;
	} else {
		printf("Array is full. Delete elements before you can insert\n");
	}
		
}

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int linearSearch(struct array *arr, int key) {
	int i;
	for (i=0;i<arr->length;i++) {
		if(arr->a[i] == key)  {
			//swap(&arr->a[i], &arr->a[i-1]);
			return i;
		}
	}
	return -1;
}
// The elements of the array have to be sorted for performing binary search technique !!
int binarySearch(struct array *arr, int key, int low, int high) {
	int mid;

	while (low < high) {
		
		mid = (low + high) / 2;
		if (arr->a[mid] == key) {
			return mid;
		} else if (key < arr->a[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return -1;
	
}

//Recursive function for binary search

int recursiveBinarySearch(struct array *arr, int key, int low, int high) {
	int mid = (low + high) / 2;	
	if (low >  high) {
		return -1;
	} else if (arr->a[mid] == key) {
		return mid;
	} else if (key < arr->a[mid]) {
		return recursiveBinarySearch(arr, key, low, mid-1);
	} else {
		return recursiveBinarySearch(arr, key, mid+1, high);
	}
}

int get(struct array arr, int index) {
	if 	(index >0 && index<arr.length) {
		return arr.a[index];
	}
	return -1;
}

void set(struct array *arr, int index, int val) {
	if (index>0 && index<arr->length) {
		arr->a[index]=val;
	}
}

int max(struct array arr) {
	int max = arr.a[0];
	int i;
	for (i=1;i<arr.length;i++) {
		if(arr.a[i] > max) {
			max = arr.a[i];
		}
	}

	return max;
}

// TODO: Implement total
// TODO: Implement min
// TODO: Implement avg

// Reverse using auxillary array
void reverseUsingAuxArray(struct array *arr) {
	struct array auxArr;
	printf("The length of the original array is: %d\n", arr->length);
	int origArrayLength = arr->length;
	// Instead of creating a new array by creating a new structure, we can instead have a pointer to the below number of locations on the heap. 
	// That is equivalent to having an array of the required size
	auxArr.a = (int *) malloc(origArrayLength * sizeof(int));
	int i;
	int j;
	int finalIndex=arr->length -1;
	for (i=finalIndex,j=0; i>=0 && j<origArrayLength; i--,j++) {
		auxArr.a[j]=arr->a[i];
	}
	auxArr.length=origArrayLength;
	printf("Displaying the auxillary array\n");	
	display(auxArr);

	int m,n;
	for(m=0;m<arr->length; m++) {
		arr->a[m] = auxArr.a[m];
	}

	printf("Displaying the reversed original array\n");
	//display(arr);
}

// Reverse in place in the same array
void reverseInPlace(struct array *arr) {
	int arryLength = arr->length;
	int i,j;
	for(i=0,j=arryLength-1;i<j;i++,j--) {
		int temp = arr->a[i];
		arr->a[i] = arr->a[j];
		arr->a[j] = temp;
	}
}

// Left shift operation of the given array
void leftShift(struct array *arr) {
	int arrayLength = arr->length;
	int i;
	for(i=0;i<arrayLength-1;i++) {
		arr->a[i]=arr->a[i+1];
	}
	arr->a[arrayLength-1] = 0;
}

// Left rotation operation of the given array
void leftRotation(struct array *arr) {
	int firstPositionElement = arr->a[0];
	int length = arr->length;
	int i;
	for(i=0;i<length-1;i++) {
		arr->a[i]=arr->a[i+1];
	}
	arr->a[length-1]=firstPositionElement;
}

// check if array has been sorted 

int isSortedArray(struct array *arr) {

	for (int i = 0; i<arr->length-1; i++) {
		if(arr->a[i] > arr->a[i+1]) {
			return 0;
		} 
	}
	return 1;
}

// Add an element at a sorted position
void addElementInSortedArray(struct array *arr, int elementToAdd) {
	int posToAddTheElement = -1; 
	if(isSortedArray(arr)) {
		printf("Already sorted array. Therefore adding new element into this sorted array\n");
		int i;
		for(i=0; i<arr->length; ++i) {
			if (elementToAdd>arr->a[i]) {
				continue;
			} else {

				posToAddTheElement = i;
				break;
			}
		}
		if (posToAddTheElement == -1) {
			posToAddTheElement = arr->length;
		}
		insert(arr, elementToAdd, posToAddTheElement);
	}
	
}

// TODO: Add an element at the sorted position - Intelligent way 
// Done with the above TODO !!!
void insertInASortedArrayIntelligentrly(struct array * arr, int elementToAdd) {
	// You dont have to get	the position of the number that needs to be added in the sorted position. 
	// You can start shifting from the last element using a while loop and just place the element in the correct position instead of trying to find the position of the element
	if (arr->length < size) {
		int i = arr->length -1;
		while(arr->a[i] > elementToAdd) {
			arr->a[i+1] = arr->a[i];
			i--;
		}
		arr->a[i+1] = elementToAdd;
	} else {
		printf("The array is already full. Remove elements before inserting !!\n");
	}


}

// Main program
int main() {
	int i, n, appendElement, insertElement, insertPosition, deleteIndex, searchKey, getIndex, setIndex, setVal, elementToAddInSortedArray;
	struct array arr;
	printf("Enter the total size of the array\n");
	scanf("%d", &arr.size);
	arr.a = (int *) malloc(arr.size * sizeof(int));
	printf("Enter the number of elements in the array\n");
	scanf("%d", &n);
	printf("Enter the elements\n");
	for (i=0;i<n;i++) {
		scanf("%d", &arr.a[i]);
	}
	arr.length = n;
	display(arr);
	isSortedArray(&arr) ==  1 ?  printf("Array is sorted\n") : printf("Array is not sorted\n");
	printf("Enter the element to append in the sorted array\n");
	scanf("%d", &elementToAddInSortedArray);
	if (isSortedArray(&arr)) {
		addElementInSortedArray(&arr, elementToAddInSortedArray);
		display(arr);
	} else {
		printf("The array that is input is not sorted. Hence skipping the method to add into the sorted array. Enter sorted array to enable this functionality\n");
	}

	reverseUsingAuxArray(&arr);
	display(arr);
	reverseInPlace(&arr);
	printf("Printing reversed in place array\n");
	display(arr);
	printf("Left shifting the above array\n");
	leftShift(&arr);
	display(arr);
	printf("Left rotation of the above array\n");
	leftRotation(&arr);
	display(arr);
	return 0;
	
}

/*
      1. Display
      2. Add/Append
      3. Insert(int index)
      4. Delete(int index)
      5. Search(int key) // Linear search algorithm
      6. BinarySearcy(int key) // The array elements must be sorted
      7. Get(int index) // Get the value at a specified index
      8. Set(int index, int num) // Set the value of a specified index with a specified value
      9. Reverse and array using auxillary array
 
  */ 
// Main program for advanced functions
int main1() {
	int i, n, appendElement, insertElement, insertPosition, deleteIndex, searchKey, getIndex, setIndex, setVal, elementToAddInSortedArray;
	struct array arr;
	printf("Enter the total size of the array\n");
	scanf("%d", &arr.size);
	arr.a = (int *) malloc(arr.size * sizeof(int));
	printf("Enter the number of elements in the array\n");
	scanf("%d", &n);
	printf("Enter the elements\n");
	for (i=0;i<n;i++) {
		scanf("%d", &arr.a[i]);
	}
	arr.length = n;
	display(arr);
	
	// --------------------------Append an element to the existing array !! ------------------------
	
	printf("Enter the element to append\n");
	scanf("%d", &appendElement);
	append(&arr,appendElement);
	display(arr);

	// ------------------------- End of append ----------------------------------------------------
	printf("Enter element to insert\n");
	scanf("%d", &insertElement);
	printf("Enter the position to insert\n");
	scanf("%d", &insertPosition);
	insert(&arr, insertElement, insertPosition);
	display(arr);
	// ------------------------- Insert an element into the array at a position !! -----------------

	// ------------------------- Delete an element in the array !! ---------------------------------
	printf("Provide index to delete element\n");
	scanf("%d", &deleteIndex);	
	delete(&arr, deleteIndex);
	display(arr);

	// ------------------------- End of delete -----------------------------------------------------
	
	// ------------------------- Linear search -----------------------------------------------------
	printf("Provide key to search\n");
	scanf("%d", &searchKey);
	int searchRes = linearSearch(&arr, searchKey);
	if (searchRes != -1 ) {
		printf("The key %d is found at position %d \n", searchKey, searchRes);
		printf("The elements of the array after transposition are :\n");
		// If you want to implement "Move to head or move to front technique to improve the performance of the next search of the same key, 
		// then swap the number at index 0 with the current index of the key found.
		display(arr);
	} else {
		printf("The key %d was not found in the array\n", searchKey);
		
	}

	// ------------------------- End of Linear search ----------------------------------------------

	// ------------------------- Binary search ----------------------------------------------------
	printf("Enter the key element for binary search\n");
	scanf("%d", &searchKey);

	printf("The result of the search is pos (actual pos or -1 if not found) %d\n", binarySearch(&arr, searchKey, 0, arr.length-1));
	printf("Enter the key element for recursive binary search\n");
	scanf("%d", &searchKey);
	printf("The result of the recursive binary search is %d\n", recursiveBinarySearch(&arr, searchKey, 0, arr.length-1));


	// ------------------------- End of binary search ---------------------------------------------
	
	// ------------------------- Get the value at a specific index --------------------------------
	printf("Enter the index to get the value at the specified index\n");
	scanf("%d", &getIndex);
	printf("The value at index %d is %d\n", getIndex, get(arr, getIndex));

	// ------------------------- End of Get -------------------------------------------------------

	// ------------------------- Set the value at a specific index -------------------------------
	printf("Enter the index value and the value to set in the order\n");
	scanf("%d %d", &setIndex, &setVal);
	set(&arr, setIndex, setVal);
	printf("The value set at index %d is %d\n", setIndex, setVal);
	display(arr);

	// ------------------------ End of set -------------------------------------------------------

	// ------------------------ Max value in the array ------------------------------------------
	printf("The max values in the array is : %d\n", max(arr));
	// ----------------------- End of max value calculation -------------------------------------

	//reverseUsingAuxArray(&arr);
	//display(arr);
	//reverseInPlace(&arr);
	//printf("Printing reversed in place array\n");
	//display(arr);
	//printf("Left shifting the above array\n");
	//leftShift(&arr);
	//display(arr);
	//printf("Left rotation of the above array\n");
	//leftRotation(&arr);
	//display(arr);
	isSortedArray(&arr) ==  1 ?  printf("Array is sorted\n") : printf("Array is not sorted\n");
	printf("Enter the element to append in the sorted array\n");
	scanf("%d", &elementToAddInSortedArray);
	addElementInSortedArray(&arr, elementToAddInSortedArray);
	display(arr);
	
	/*
	*/

	return 0;
	
}
