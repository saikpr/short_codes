#include <algorithm>
#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_set>
#include <fstream>
#include <set>
#include <ctime>
#include <cstring>

using std::endl;

enum game_status_ct { LOST, WON, PLAYING };


// Constants
const int MAX_CHANCES = 6;
// const std::string DICT_FILE("words_50000.txt");

class exception_game_terminate : public std::exception {
 public:
  virtual const char *what() const throw() { return "Game Terminated\n"; }
};

class Game {
 public:
  Game(){};
  virtual ~Game(){};
};

class HangManGame : public Game {
  std::string word;
  std::unordered_set<char> char_missed;
  std::unordered_set<char> already_tried;
  std::vector<bool> guessed;
  exception_game_terminate no_chances_remain;

 public:
  HangManGame(std::string theWord) : word(theWord), guessed(theWord.size(), false) {}
  bool next_try(std::ostream &outstream, char new_char);
  std::string get_status() const;
  std::unordered_set<char> get_tried() const { return already_tried; }
};

bool HangManGame::next_try(std::ostream &outstream, char new_char) {
  /*
      returns true for game won
      false for game remaining
      throws exception_game_terminate in case game lost
  */
  assert(char_missed.size() < MAX_CHANCES);

  if (already_tried.count(new_char) == 1)  // char already tried
  {
    return false;
  }
  already_tried.insert(new_char);
  if (word.find(new_char) != std::string::npos) {
    for (size_t i = 0; i < word.size(); i++) {
      if (word[i] == new_char) {
        guessed[i] = true;
      }
    }
  } else {
    char_missed.insert(new_char);
  }
  outstream << "guess: " << new_char << endl;
  outstream << get_status() << " missed: ";

  for (auto it = char_missed.begin(); it != char_missed.end(); it++) {
    outstream << *it << ",";
  }
  outstream << endl;

  // verifying that the word is guessed completely or not
  bool flag_check_remain = true;
  for (size_t i = 0; i < guessed.size(); i++) flag_check_remain &= guessed[i];

  if (flag_check_remain) return true;  // Game Success

  // check if reached max number of possible chances
  if (char_missed.size() == MAX_CHANCES)  // Chances end
  {
    throw no_chances_remain;
  }

  return false;
}

std::string HangManGame::get_status() const {
  /*returns the status std::string*/
  std::string status_str = word;
  for (size_t i = 0; i < guessed.size(); i++) {
    if (!guessed[i]) status_str[i] = '_';
  }
  return status_str;
}

/*Class to play the Hangman Game*/
class HangManAI {
  HangManGame game_instance;
  std::vector<std::string> word_dict;
  enum char_inclusion_or_exclusion { INCLUSION, EXCLUSION };
  void reduce_dict_rule(char ch, char_inclusion_or_exclusion work_type);
  bool check_work_possibility(std::string &status_str, std::string possible_word) const {
    /*checks if possible_word(eg test or temp) can be replaced in
     * status_str(t_st)*/
    assert(status_str.size() == possible_word.size());
    for (size_t i = 0; i < possible_word.size(); i++) {
      if (status_str[i] != '_' && possible_word[i] != status_str[i])
        return false;
    }
    return true;
  }
  char get_best_char();

 public:
  HangManAI(std::string &theWord, std::vector<std::string> &theDict)
      : game_instance(theWord), word_dict(theDict) {}
  game_status_ct play_game(std::ostream &outstream);
};

void HangManAI::reduce_dict_rule(
    char ch, char_inclusion_or_exclusion work_type = INCLUSION) {
  /*Reduces the dictionary*/
  std::string status_str = game_instance.get_status();
  std::vector<std::string> new_word_dict;
  new_word_dict.reserve(word_dict.size());

  for (size_t i = 0; i < word_dict.size(); i++) {
    if (work_type == INCLUSION &&
        check_work_possibility(status_str, word_dict[i]) == false) {
      continue;
    } else if (work_type == EXCLUSION && word_dict[i].find(ch) != -1) {
      continue;
    }

    new_word_dict.push_back(word_dict[i]);
  }
  word_dict.swap(new_word_dict);
  return;
}

char HangManAI::get_best_char() {
  /*Gets the highest frequency character in the remaining dictionary*/
  std::vector<int> alphabet_occurance(26, 0);
  auto already_tried = game_instance.get_tried();

  for (size_t i = 0; i < word_dict.size(); i++) {
    for (size_t j = 0; j < word_dict[i].size(); j++) {
      if ((already_tried.count(word_dict[i][j]) == 0))
        alphabet_occurance[word_dict[i][j] - 'a']++;
    }
  }

  int max_size = 0;
  char best_char = '\0';
  for (size_t i = 0; i < alphabet_occurance.size(); i++) {
    if (max_size < alphabet_occurance[i]) {
      max_size = alphabet_occurance[i];
      best_char = 'a' + i;
    }
  }

  if (best_char == '\0') {
    exception_game_terminate no_word_remain;
    throw(no_word_remain);
  }

  return best_char;
}

game_status_ct HangManAI::play_game(std::ostream &outstream) {
  /*Play the game with output on outstream
  returns the status of the game
  */
  outstream << game_instance.get_status() << endl;

  char ch = '\0';
  try {
    do {
      if (ch != '\0') {
        std::string status_str = game_instance.get_status();

        if (status_str.find(ch) == -1)
          reduce_dict_rule(ch, EXCLUSION);
        else
          reduce_dict_rule(ch, INCLUSION);
      }
      ch = get_best_char();  // get the best character

    } while (!game_instance.next_try(outstream, ch));

    outstream << "Won!" << endl;
    return WON;
  } catch (exception_game_terminate &ep) {
    outstream << ep.what();
    return LOST;
  }
}