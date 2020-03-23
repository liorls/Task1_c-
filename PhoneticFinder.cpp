// /*
// AUTHORS: Levana Sciari, Lior Samuel-Levy 
// */

// #include <iostream>
// #include <string>
// #include <stdexcept>
// #include "PhoneticFinder.hpp"

// using namespace std;

// string phonetic::find(string text, string word){

//     return word;

// }



// // int main(int argc, char const *argv[])
// // {
// //     string a = "Dond vorri be haffy" , b = "happy";
// //     std::cout << phonetic::find(a,b) << std::endl;
// //     return 0;
    
// // }


 
#include "PhoneticFinder.hpp"
#include <iostream>
namespace phonetic
{
int isMixed(char t, char w)
{
    t = tolower(t);
    w = tolower(w);

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

string find(string text, string word)
{
    string str = "";
    int j = 0;
    size_t i = 0;
    for (i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            if (str.length() != word.length())
            {
                str = "";
                i++;
                j = 0;
                while (text[i] != ' ')
                {
                    i++;
                }
            }
            else
                return str;
        }
        else if ((word.length() == j) && (text.length() > i))
        {
            j = 0;
            str = "";
        }
        else if (isMixed(text[i], word[j]))
        {
            str += text[i];
            j++;
        }
        else
        {
            j = 0;
            str = "";
            while (text[i] != ' ')
            {
                i++;
            }
        }
    }
    if ((text.length() == i) && (word.length() != str.length()))
    {
        throw runtime_error("The word " + word + " is not in the text.");
    }
    return str;
}
} // namespace phonetic

// #include <string>
// #include <string.h>
// #include <exception>
// #include "PhoneticFinder.hpp"
// #include <iostream>






//     std::string toLower(std::string str){
//         std::string temp = "";
//         for(int i=0;i<str.length();i++){
//             temp+=tolower(str[i]);
//         }
//         return temp;
//     }

//     int confused_char(char c1,char c2){
//         if(c1==c2) return 1;
//         if(c1=='v' && c2=='w') return 1; 
//         if(c1=='w' && c2=='v') return 1;
//         if(c1=='g' && c2=='j') return 1;
//         if(c1=='j' && c2=='g') return 1;
//         if(c1=='s' && c2=='z') return 1;
//         if(c1=='z' && c2=='s') return 1;
//         if(c1=='d' && c2=='t') return 1;
//         if(c1=='t' && c2=='d') return 1;
//         if(c1=='o' && c2=='u') return 1;
//         if(c1=='u' && c2=='o') return 1;
//         if(c1=='i' && c2=='y') return 1;
//         if(c1=='y' && c2=='i') return 1;
//         if(c1=='b' && c2=='f') return 1;
//         if(c1=='f' && c2=='b') return 1;
//         if(c1=='b' && c2=='p') return 1;
//         if(c1=='p' && c2=='b') return 1;
//         if(c1=='f' && c2=='p') return 1;
//         if(c1=='p' && c2=='f') return 1;
//         if(c1=='c' && c2=='k') return 1;
//         if(c1=='k' && c2=='c') return 1;
//         if(c1=='c' && c2=='q') return 1;
//         if(c1=='q' && c2=='c') return 1;
//         if(c1=='k' && c2=='q') return 1;
//         if(c1=='q' && c2=='k') return 1;
//         return 0;
//     }

//     std:: string confused_word(std::string a,std::string b){
//         if(a.length()!=b.length()) return "NULL";
//         for(int i=0;i<a.length();i++){
//             if(!confused_char(a[i],b[i])) return "NULL";
//         }
//         return a;
//     }
//     struct Mexception : std::exception {
//         const char* what() const throw() {
//             const char* ex = "Did not find the word in the text";
//             return ex;
//             }
//     };
    
    
    
//     namespace phonetic {
     

//     std:: string find(std::string text,std::string word) {
        
//        std:: string lower_text = toLower(text);
//        std::string lower_word = toLower(word);
//        std:: string ans="";
        
//         int i=0;
        
//         while(i<lower_text.length()) {
            
//             if(confused_char(lower_text[i],lower_word[0])){
//                 std::string tempLower="";
//                 std::string temp="";
//                 while(text[i]!=' '){
//                     if(text[i]==text[text.length()]) break;
//                     tempLower+=lower_text[i];
//                     temp+=text[i];
//                     i++;
//                 }
                
                
//                 std:: string s = confused_word(tempLower,lower_word);
//                 if(s != "NULL") ans = temp;
                
                
                
//             }
//             i++;
//         }
//         if(ans=="") throw Mexception();
       
//         return ans;
//     }

    

// }