# Document-Analysis
This program analyzes text documents and counts the words, checks the average length of words, and calculates word frequencies. A sample .txt file is 
supplied for testing purposes. Simply compile and run the main.cpp file.

void print_word_array(string * words)
This function takes a pointer to an array of strings as an argument and prints the elements of the array to the console.

void print_int_array(int * nums, int size)
This function takes a pointer to an array of ints and the size of the array as two arguments, it then prints the elements of the array to the console.

string find_longest_word(string * words)
This function takes a pointer to an array of strings as an argument and returns the longest word in the array.

int find_word(string * words, string target)
This function takes a pointer to a string array and a 'target' string as two arguments, the function then searches the array for the target word and 
returns the index position of the word in the array if it was found.

int array_length(string *words)
This function takes a pointer to an array of strings as an argument and returns the length of the array as an integer value.

double average_word_length(string *words)
This function takes a pointer to an array of strings and returns the average length of all the elements in the array.

string * create_word_array(string filename,int filesize)
This function processes a .txt file and converts it into an array of strings, then returns that array.

void make_lower_case(string & word)
This function takes the address of a string as an argument and converts all the chars to lower case.

string * unique_words(string * words)
This function takes a pointer to an array of strings as its argument and processes it to remove all duplicate strings and then returns an array of 
strings with only unique elements.

int * word_frequencies(string * unique_words, string * words)
This function takes a pointer to an array of strings with unique elements and a pointer of an original array of strings. It then calculates the 
frequency of string elements in the orignal array.

void display_word_freqs(string * unique_words, int * counts)
This function takes a pointer to an array of unique strings and a pointer to an array of integers that contains the frequency of the elements from 
an orignal array. It prints the frequency of the elements to the console. 
