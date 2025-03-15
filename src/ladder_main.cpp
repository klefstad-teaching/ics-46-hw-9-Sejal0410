#include "ladder.h"

int main(){
    string start;
    string end;
    cout << "Input start word: ";
    cin >> start;
    cout << "Input end word: ";
    cin >> end;

    if(start==end){
        cout <<"Start and end words are the same. Enter different words please." << endl;
    } else{
        set <string> w;
        load_words(w, "words.txt");
        vector <string> l = generate_word_ladder(start, end, w);
        print_word_ladder(l);
    }
}