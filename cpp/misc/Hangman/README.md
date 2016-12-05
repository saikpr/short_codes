README.md
_________


Short Version:

To play for a single word:
./hangman single dictionary_file.txt word

To play for all words in dictionary
./hangman full dictionary_file.txt

Long Version:


Assumptions :

    No Space in word
    In case of repetition of same character multiple time, it doesn't make any  difference in chance count remaining
    the length of word in the game is known at the start
    No Style Guideline given, Followed the Google C++ Style Guidelines


TradeOffs:

    Used STL, with type checking and STL for clarity. For speed use, C with char* and arrays used Set instead of bitset. Bitset or even using a 32bit int for checking would have been much faster
    Favoured extendability over speed, by using class
    Didn't mutate the word dict after, a word is found
    Used the dictionary provided as the corpus for the program


    

Algorithm is O(Count_Words_In_Dictionary*length_of_word) 
T(X) = T(X/k) +O(X) 
	X is no of elements in dictionary, k>1


classes:

HangManGame
    
    A wrapper to contain the state of the game, i.e. word, char used, char not found, etc.

    Variables and Methods:
        private:
            string word // stores the word on which the game is to be played
            unordered_set <char> char_missed // contains the char which were not found int the word
            unordered_set <char> already_tried // contains all the character tried
            vector <bool> guessed // is a boolean vector containing the positions that have been found
            exception_game_terminate no_chances_remain; //exception to be thrown in case MAX_CHANCES_REACHED
        
        public:
            bool next_try(ostream &outstream, char new_char) 

                ostream is the stream on which output will be written and new_char is the character to be tried
                returns true for the game won
                falsely for game remaining 
                throws exception_game_terminate in case game lost 


            string get_status() const
                returns the status string i.e. t__t type string

            unordered_set<char> get_tried() const{return already_tried;}
                returns the set of character tried

HangManAI

    The Class which plays the game
    
    Variables and Methods:
        private:    
            HangManGame game_instance //Game instance
            vector<string> word_dict  // vector of words in the dictionary

            enum char_inclusion_or_exclusion {INCLUSION,EXCLUSION} //enum to decide if to keep the character or exclude it from the word dict

            void reduce_dict_rule(char ch,char_inclusion_or_exclusion work_type)
                reduces the word dictionary size based on the policy 

            bool check_work_possibility(string &status_str,string possible_word)
                checks if possible_word(eg test or temp) can be replaced in status_str(t_st) 
            
        
        public:
            game_status_ct play_game(ostream &outstream);
                Play the game with output on outstream
                returns the status of the game
