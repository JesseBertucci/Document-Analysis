#include "doc_analysis.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void print_word_array(string * words){
  int i = 0;                                      // Counter for max of 8 words per line
  while(!words[i].empty()){                       // While elment 'i' in array is not empty do this:
    cout << words[i] << " ";                      // Prints element 'i' to console
    i++;                                          // Add one to counter
    if(i % 8 == 0){                               // If remainer of counter / 8 = 0, then new line
      cout << endl;
    }
  }
}

void print_int_array(int * nums, int size){
  for(int i = 0; i < size; i ++){                 // For loop cycles through int array
    cout << nums[i] << " ";                       // Prints int's in concole seperated by a space
  }
}

string find_longest_word(string * words){
  int string_length = array_length(words);           // Finds incoming array length with array_length function
  string longest_word;                               // Stores the current longest string while checking through array
  for(int i = 0; i < string_length; i++){            // For loop runs through contents of array
    if(words[i].length() > longest_word.length()){   // If word of element 'i' is longer than the current longest word do this:
      longest_word = words[i];                       // Element 'i' becomes longest word
    }
  }
  return longest_word;
}

int find_word(string * words, string target){
  int i = 0;
  int length = array_length(words);                 // Gets length of incoming array using another function
  while(target != words[i] and i < length){         // While target word is not found at element 'i' and counter 'i' has not reached the end of the array
    i++;                                            // Add one to counter
  }
  if(i == length){                                  // If word was not found return -1
    return -1;
  } else {                                          // If word was found return index position
    return i;
  }
}

int array_length(string *words){
  int i = 0;                                       // Counter
  while(!words[i].empty()){                        // While element 'i' is not empty, add 1 to counter
    i++;
  }
  return i;                                        // Return counter
}



double average_word_length(string *words){
  int string_length = array_length(words);        // Gets the length of the incoming array
  if(string_length == 0){                         // If the array is empty return 0
    return 0;
  }
  int num_chars = 0;                              // Counter for total number of chars
  for(int i = 0; i < string_length; i++){         // Runs through array
    num_chars += words[i].length();               // Adds length of every word in array to counter
//    cout << words[i].length() << endl;
//    cout << num_chars << endl;
  }
  return num_chars / string_length;               // Returns number of chars / number of words
}

string * create_word_array(string filename,int filesize){
  int size = filesize / SMALL_WORD_LENGTH;                     // Determines approx file size
  string *finalArray = new string[size];                       // Dynamically allocates a new array
  for(int i = 0; i < size; i++){                               // Initializes array to blank spaces
    finalArray[i] = "";
  }
  ifstream reader(filename);                                  // Selecting file to open and read
  int i = 0;                                                  // Counter used to storing txt file words into array
  while(reader){                                              // While reader is still reading words, do this:
    string word;                                              // Resets a new string viable
		reader >> word;                                           // Stores txt file word into string variable
    make_lower_case(word);                                    // Converts word to lower case
//    cout << word << i << endl;
    finalArray[i] = word;                                     // Stores lower case word into array
    i++;                                                      // Add one to counter
	}
	reader.close();                                             // Close file
//  print_word_array(finalArray);
  return finalArray;                                          // Return array
}

void make_lower_case(string & word){
  int diff = 'a' - 'A';                                      // Checks the numerical difference between a lower case letter and an upper case letter
  for(int i = 0; i < word.length(); i++){                    // Runs through length of word
    if(word[i] <= 'Z' and word[i] >= 'A'){                   // If word is upper case, add the difference to it to make it lower case
      word[i] += diff;
    }
  }
//  cout << word;
}

string * unique_words(string * words){
  int string_length = array_length(words);                    // Checks length of array
  string *finalArray = new string[string_length];             // Dynamically allocates a new array
  for(int k = 0; k < string_length; k++){                     // Initializes array to blank spaces
    finalArray[k] = "";
  }
  int j = 0;                                                  // Counter for setting unique words to index positons in the unique words array
  for(int i = 0; i < string_length; i++){                     // Runs through the incoming array
//    cout << "Find words result = " << find_word(words, words[i]) << endl;
    if(find_word(finalArray, words[i]) == -1){               // Checks to see if incoming array word 'i' is already in unique word array
      finalArray[j] = words[i];                              // If it's not in the unique array than set it to index 'j' and add 1 to 'j'
      j++;
//      cout << words[i] << " " << finalArray[j] << endl;
    }
  }
  return finalArray;                                        // Return unique word array
}

int * word_frequencies(string * unique_words, string * words){
  int unique_length = array_length(unique_words);                 // Checks length of unique word array
  int words_length = array_length(words);                         // Checks length of longer array
  int *word_freq = new int[unique_length];                       // Dynamically allocates a new array and Initializes it all to 0
  for(int k = 0; k < unique_length; k++){
    word_freq[k] = 0;
  }
  for(int i = 0; i < unique_length; i++){                        // Runs through unique word array
    int counter = 0;                                             // Resets counter after each time the index of 'i' increases by 1
    for(int j = 0; j < words_length; j++){                       // Runs through longer array
      if(unique_words[i] == words[j]){                           // If unique word is found, increase counter by 1
        counter++;
      }
    word_freq[i] = counter;                                     // Set index 'i' of new int array to counter
    }
  }
//  print_int_array(word_freq, unique_length);
  return word_freq;                                            // Return int array
}

void display_word_freqs(string * unique_words, int * counts){
  int unique_length = array_length(unique_words);                  // Checks length of unique word array
  for(int i = 0; i < unique_length; i++){                          // For the length of unique word array, print to console unique word and the frequency
    cout << unique_words[i] << " : " << counts[i] << endl;
  }
}
