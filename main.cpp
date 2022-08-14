#include "doc_analysis.hpp"
#include "doc_analysis.cpp"
#include <iostream>
using namespace std;

int main(){


  string filename("nilsson.txt");
  int size = 1102;
  string * all_words = create_word_array(filename, size);
  string * unique = unique_words(all_words);
  int * frequencies = word_frequencies(unique, all_words);
  display_word_freqs(unique, frequencies);


//  string array_of_strings[] = {"Hello", "Hey", "Hi", "Heya", "Bye", "See-ya", "Morning", "Night", "Mid-day", "Afternoon", "Morning", "Hello", "ByeBye", "Hey", "Heya", "See-ya", "GoodDay", "HelloThereGoodDay"};
//  string array_of_stringss[] = {};
//  int array_of_ints[] = {1, 3, 2, 4, 5, 8, 7, 3, 2, 5, 7, 4};
//  print_int_array(array_of_ints, 12);
//  print_word_array(array_of_strings);
//  cout << endl;
//  cout << find_word(array_of_strings,"HelloThereGoodDay");
//  cout << array_length(array_of_stringss);
//  cout << find_longest_word(array_of_strings);
//  cout << average_word_length(array_of_stringss);
//  cout << array_of_strings[0].length();
//  char letter;
//  cout << "Enter a letter: ";
//  cin >> letter;
//  cout << (int)letter;
//  string word = "HELlo@[]";
//  make_lower_case(word);
//  string *unique_array = unique_words(array_of_strings);
//  print_word_array(unique_array);
//  cout << endl;
//  int *word_freq = word_frequencies(unique_array, array_of_strings);
//  string filename = "lauper.txt";
//  create_word_array(filename, 1257);
//  display_word_freqs(unique_array, word_freq);

  return 0;
}
