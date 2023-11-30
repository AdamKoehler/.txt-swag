#include "mergeSort.h"
int main(){
// send files to be proccessed and specify which list they will be stored in in the function call.

    teamData list1[10];
    teamData list2[10];
    teamData list3[10];

//_____________________________________________________
ifstream file1("C:/work/C++/C++ Projects/Homework 5/file1.txt"); //1. open/send
processFile(file1, list1);
file1.close();                                                   //   close file1
//---------------------------
ifstream file2("C:/work/C++/C++ Projects/Homework 5/file2.txt"); //2. open/send
processFile(file2, list2);
file2.close();                                                   //   close file2
//---------------------------
ifstream file3("C:/work/C++/C++ Projects/Homework 5/file3.txt"); //3. open/send
processFile(file3, list3);
file3.close();                                                   //   close file3
//_____________________________________________________

printList(list1, 1);
printList(list2, 2);
printList(list3, 3);

//_____________________________________________________

// okay we have populated the lists, now we can send the lists to be sorted, merged, and compared.
sort(list1);
sort(list2);
sort(list3);
merge(list1, list2, list3); // merge will create list 4.
finalSort(list4); // final sort will sort list 4.

printFinalList(); // print list 4 to the screen.
writeFinalList(); // write list 4 to a file.
    return 0;
}