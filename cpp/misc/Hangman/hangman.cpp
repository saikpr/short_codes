#include "hangman.h"



void single_Driver(std::string dict_file_name, std::string word) {
  std::ifstream infile(dict_file_name);
  std::vector<std::string> word_dict;

  std::string line;
  while (std::getline(infile, line)) {
    if (line.size() == word.size()) word_dict.push_back(line);
  }

  clock_t start_program_time = clock();
  HangManAI AI(word, word_dict);
  game_status_ct this_game = AI.play_game(std::cout);
  if (this_game == WON)
    std::cout << "WON!" << endl;
  else
    std::cout << "LOST" << endl;
  std::cout << "Time:" << double(clock() - start_program_time) / CLOCKS_PER_SEC
       << endl;

  return;
}

void full_Driver(std::string dict_file_name) {
  std::ifstream infile(dict_file_name);
  std::set<std::string> word_dict;

  std::string line;
  int max_word_size = 0;
  // getting the dictionary
  while (std::getline(infile, line)) {
    word_dict.insert(line);
    max_word_size = std::max(max_word_size, (int)line.size());
  }

  // seperating it by size
  std::vector<std::vector<std::string> > length_to_word_dict(max_word_size + 1);

  for (auto iter = word_dict.begin(); iter != word_dict.end(); iter++) {
    length_to_word_dict[(int)(*iter).size()].push_back((*iter));
  }

  // Null stream
  std::ostream null_stream(0);

  int game_count = 0, won_count = 0, lost_count = 0;

  clock_t start_program_time = clock();
  clock_t begin = start_program_time;
  for (auto it = word_dict.begin(); it != word_dict.end(); it++) {
    game_count++;

    std::string word(*it);
    HangManAI AI(word, length_to_word_dict[(int)word.size()]);

    game_status_ct this_game = AI.play_game(null_stream);

    if (this_game == WON)
      won_count++;
    else
      lost_count++;

    if (game_count % 1000 == 0) {
      std::cout << "Time to play " << game_count
           << " games :" << double(clock() - begin) / CLOCKS_PER_SEC << endl;
      begin = clock();
    }
  }
  std::cout << "Number of words tested: " << game_count << endl;
  std::cout << "Number of words guessed correctly: " << won_count << endl;
  std::cout << "Correct Guesses (%%): " << 100 * (double)won_count / game_count
       << "%%" << endl;
  std::cout << "Time to run: "
       << double(clock() - start_program_time) / CLOCKS_PER_SEC << " seconds"
       << endl;
}

void Help(char* file_name) {
  // std::cout is capable of quasi-multi-line statements, like so:
  std::cout << "Invalid Arguments!\n"
            << "Usage: " << endl
            << "For single play type: " << file_name
            << " single <Dictionary_file> <word>" << endl
            << "For Full Dictionary: " << file_name << " full <Dictionary_file>"
            << endl;
}

int main(int argc, char* argv[]) {
  // std::cout<<argc<<endl;
  if (argc != 3 && argc != 4) {
    Help(argv[0]);
    exit(1);
  }
  if (!strcmp(argv[1], "single")) {
    std::string dict_file_name(argv[2]);
    std::string word(argv[3]);
    single_Driver(dict_file_name, word);
    return 0;
  }
  if (!strcmp(argv[1], "full")) {
    std::string dict_file_name(argv[2]);
    full_Driver(dict_file_name);
    return 0;
  }

  Help(argv[0]);
  exit(1);
}