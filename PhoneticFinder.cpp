/*
AUTHORS: Levana Sciari, Mayanne zeevi, Lior Samuel-Levy 
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <ctype.h>
#include "PhoneticFinder.hpp"

using namespace std;
namespace phonetic
{
int changeChar(char t, char w)
{  
    if (t == w)
        return 1;
    if ((t == 'w' && w == 'v') || (t == 'v' && w == 'w'))
        return 1;
    if ((t == 'g' && w == 'j') || (t == 'j' && w == 'g'))
        return 1;
    if ((t == 's' && w == 'z') || (t == 'z' && w == 's'))
        return 1;
    if ((t == 'd' && w == 't') || (t == 't' && w == 'd'))
        return 1;
    if ((t == 'o' && w == 'u') || (t == 'u' && w == 'o'))
        return 1;
    if ((t == 'i' && w == 'y') || (t == 'y' && w == 'i'))
        return 1;
    if ((t == 'b' && w == 'f') || (t == 'f' && w == 'b'))
        return 1;
    if ((t == 'b' && w == 'p') || (t == 'p' && w == 'b'))
        return 1;
    if ((t == 'p' && w == 'f') || (t == 'f' && w == 'p'))
        return 1;
    if ((t == 'c' && w == 'k') || (t == 'k' && w == 'c'))
        return 1;
    if ((t == 'c' && w == 'q') || (t == 'q' && w == 'c'))
        return 1;
    if ((t == 'q' && w == 'k') || (t == 'k' && w == 'q'))
        return 1;

    return 0;
}

    string changeWord(string wordText, string word){
        if(wordText.length()!=word.length()) return "NULL";
        for(int i=0;i<wordText.length();i++){
            if(!changeChar(wordText[i],word[i])) return "NULL";
        }
        return wordText;
    }

    string toLower(string str){
        string temp = "";
        for(int i=0;i<str.length();i++){
            temp+=tolower(str[i]);
        }
        return temp;
    }
 
    string find(string text,string word) {
        
       string lower_text = toLower(text);
       string lower_word = toLower(word);
       string ans="";
        
        int i=0;
        
        while(i<lower_text.length()) {
            
            if(changeChar(lower_text[i],lower_word[0])){
                string tempText="";    //lower word in text
                string orgiWord="";   //orginal word from the text
                while(text[i]!=' '){
                    if(text[i]==text[text.length()]) break;
                    tempText+=lower_text[i];
                    orgiWord+=text[i];
                    i++;
                }
                
                
                string s = changeWord(tempText,lower_word);
                if(s != "NULL") ans = orgiWord;
                  
            }
            i++;
        }
        if(ans=="") throw runtime_error("The word: " + word + " is not in the text.");
       
        return ans;
    }

    

}