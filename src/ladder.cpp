#include "ladder.h"

void error(string word1, string word2, string msg){
    cerr << "Error: " << msg << word1 << " to " << word2 << endl
}

bool edit_distance_within(const string &str1, const string &str2, int d){
    int l1 = str1.size();
    int l2 = str2.size();
    if(abs(l1-l2)>d){
        return false;
    }
    int difference = 0;
    int i = 0;
    int j = 0;
    while(i<l1 && j<l2){
        if(str1[i] != str[j]){
            if(++difference > d){
                return false;
            }
            if(l1>l2){
                i++
            } else if(l1<l2){
                j++;
            } else {
                i++;
                j++;
            }
        } else {
            i++;
            j++;
        }
    }
    return true;
}

bool is_adjacent(const string &word1, const string &word2){
    return edit_distance_within(word1, word2, 1);
}

void load_words(set<string> &word_list, const string &file_name){
    ifstream file(file_name);
    if(!file){
        cerr << "Error: Could not open file " << file_name << endl;
        exit();
    }
    string word;
    while(file>>word){
        word_list.insert(word);
    }
    file.close();
}

vector<string> generate_word_ladder(const string &begin_word, const string &end_word, const set<string> &word_list){
    if(begin_word == end_word){
        error(begin_word, end_word, "Words have to be different");
    }
    queue<vector<string>> lad;
    lad.push({begin_word});
    set<string> a;
    a.insert(begin_word);
    while(!lad.empty()){
        auto l = lad.front();
        lad.pop();
        string last = l.back();

        for(const auto &w : word_list){
            if(is_adjacent(last, w) && !v.count(w)){
                v.insert(w);
                auto n = l;
                n.push_back(w);
                if(w==end_word){
                    return n;
                }
                lad.push(n);

            }
        }
    }
    return {};
}

void print_word_ladder(const vector<string> &ladder){
    if(ladder.empty()){
        cout << "Ladder not found" << endl;
        return;
    }
    for(const auto &w : ladder){
        cout << w << " -> ";
    }
    cout << "END" << endl;
}