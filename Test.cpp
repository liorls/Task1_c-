/*
AUTHORS: Levana Sciari,Mayanne zeevi, Lior Samuel-Levy 

*/

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of v and w"){
    string text = "xxx woow yyy";
    CHECK(find(text, "woow") == string("woow"));
    CHECK(find(text, "woov") == string("woow"));
    CHECK(find(text, "voow") == string("woow"));
    CHECK(find(text, "voov") == string("woow"));
}

TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of p and f") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
}

TEST_CASE("Test replacement of b and f") {
    string text = "xxx baby yyy";
    CHECK(find(text, "baby") == string("baby"));
    CHECK(find(text, "faby") == string("baby"));
    CHECK(find(text, "bafy") == string("baby"));
    CHECK(find(text, "fafy") == string("baby"));
}

TEST_CASE("Test replacement of f and b") {
    string text = "xxx coffee yyy";
    CHECK(find(text, "coffee") == string("coffee"));
    CHECK(find(text, "cobbee") == string("coffee"));
    CHECK(find(text, "cobfee") == string("coffee"));
    CHECK(find(text, "cofbee") == string("coffee"));
}
//c, k, q
TEST_CASE("Test replacement of c and k") {
    string text = "xxx chocolate yyy";
    CHECK(find(text, "chocolate") == string("chocolate"));
    CHECK(find(text, "khocolate") == string("chocolate"));
    CHECK(find(text, "chokolate") == string("chocolate"));
    CHECK(find(text, "khokolate") == string("chocolate"));
}

TEST_CASE("Test replacement of c and q") {
    string text = "xxx chocolate yyy";
    CHECK(find(text, "chocolate") == string("chocolate"));
    CHECK(find(text, "qhocolate") == string("chocolate"));
    CHECK(find(text, "choqolate") == string("chocolate"));
    CHECK(find(text, "qhoqolate") == string("chocolate"));
}

TEST_CASE("Test replacement of q and k") {
    string text = "xxx quiet yyy";
    CHECK(find(text, "quiet") == string("quiet"));
    CHECK(find(text, "kuiet") == string("quiet"));
}
TEST_CASE("Test replacement of k and q") {
    string text = "xxx kilo yyy";
    CHECK(find(text, "kilo") == string("kilo"));
    CHECK(find(text, "qilo") == string("kilo"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "xxx ginger yyy";
    CHECK(find(text, "ginger") == string("ginger"));
    CHECK(find(text, "jinger") == string("ginger"));
    CHECK(find(text, "ginjer") == string("ginger"));
    CHECK(find(text, "jinjer") == string("ginger"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "xxx sasson yyy";
    CHECK(find(text, "sasson") == string("sasson"));
    CHECK(find(text, "zasson") == string("sasson"));
    CHECK(find(text, "sazson") == string("sasson"));
    CHECK(find(text, "saszon") == string("sasson"));
    CHECK(find(text, "zazson") == string("sasson"));
    CHECK(find(text, "sazzon") == string("sasson"));
    CHECK(find(text, "zaszon") == string("sasson"));
    CHECK(find(text, "zazzon") == string("sasson"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "xxx dont yyy";
    CHECK(find(text, "dont") == string("dont"));
    CHECK(find(text, "dond") == string("dont"));
    CHECK(find(text, "tont") == string("dont"));
    CHECK(find(text, "tond") == string("dont")); ////////we cheak it ?
}

TEST_CASE("Test replacement of o and u") {
    string text = "xxx woow yyy";
    CHECK(find(text, "woow") == string("woow"));
    CHECK(find(text, "wouw") == string("woow"));
    CHECK(find(text, "wuow") == string("woow"));
    CHECK(find(text, "wuuw") == string("woow"));
}

TEST_CASE("Test replacement of o and u") {      ////////we cheak it ?
    string text = "xxx you yyy";
    CHECK(find(text, "you") == string("you"));
    CHECK(find(text, "yuo") == string("you"));
    CHECK(find(text, "yoo") == string("you"));
    CHECK(find(text, "yuu") == string("you"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "xxx hii zzz";
    CHECK(find(text, "hii") == string("hii"));
    CHECK(find(text, "hyi") == string("hii"));
    CHECK(find(text, "hiy") == string("hii"));
    CHECK(find(text, "hyy") == string("hii"));
}

TEST_CASE("Test replacement of y and i") {
    string text = "xxx yoyo zzz";
    // CHECK(find(text, "yoyo") == string("yoyo"));
    // CHECK(find(text, "yoyy") == string("yoyo"));
    // CHECK(find(text, "yyyo") == string("yoyo"));
    // CHECK(find(text, "yyyy") == string("yoyo"));
    CHECK(find(text, "yoyo") == string("yoyo"));
    CHECK(find(text, "yoio") == string("yoyo"));
    CHECK(find(text, "ioyo") == string("yoyo"));
    CHECK(find(text, "ioio") == string("yoyo"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy"; //lower + i/y
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "happI") == string("Happi"));
    CHECK(find(text, "hAppi") == string("Happi"));
    CHECK(find(text, "haPPi") == string("Happi"));
    CHECK(find(text, "hApPi") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "voory xxx yyy"; //lower + v/w
    CHECK(find(text, "voory") == string("voory"));
    CHECK(find(text, "VOORY") == string("voory"));
    CHECK(find(text, "Voory") == string("voory"));
    CHECK(find(text, "voorY") == string("voory"));
    CHECK(find(text, "vooRy") == string("voory"));
    CHECK(find(text, "vOOry") == string("voory"));
    CHECK(find(text, "VoOrY") == string("voory"));
    CHECK(find(text, "vOoRy") == string("voory"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "dond xxx yyy"; //lower + d/t
    CHECK(find(text, "dond") == string("dond"));
    CHECK(find(text, "DOND") == string("dond"));
    CHECK(find(text, "Dond") == string("dond"));
    CHECK(find(text, "dOnd") == string("dond"));
    CHECK(find(text, "doNd") == string("dond"));
    CHECK(find(text, "donD") == string("dond"));
    CHECK(find(text, "dOnD") == string("dond"));
    CHECK(find(text, "DoNd") == string("dond"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "chocolate xxx yyy"; //lower + c/k
    CHECK(find(text, "chocolate") == string("chocolate"));
    CHECK(find(text, "CHOCOLATE") == string("chocolate"));
    CHECK(find(text, "ChoColate") == string("chocolate"));
    CHECK(find(text, "chOcOlate") == string("chocolate"));
    CHECK(find(text, "chocolAtE") == string("chocolate"));
    CHECK(find(text, "cHocolate") == string("chocolate"));
    CHECK(find(text, "ChOcOlAtE") == string("chocolate"));
    CHECK(find(text, "cHoCoLaTe") == string("chocolate"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "coffee xxx yyy"; //lower + f/b
    CHECK(find(text, "coffee") == string("coffee"));
    CHECK(find(text, "COFFEE") == string("coffee"));
    CHECK(find(text, "Coffee") == string("coffee"));
    CHECK(find(text, "cOffee") == string("coffee"));
    CHECK(find(text, "coFFee") == string("coffee"));
    CHECK(find(text, "coffEE") == string("coffee"));
    CHECK(find(text, "cOfFeE") == string("coffee"));
    CHECK(find(text, "CoFfEe") == string("coffee"));
}


TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "TUND"; 
    CHECK(find(text, "dont") == string("TUND"));
    CHECK(find(text, "DONT") == string("TUND"));
    CHECK(find(text, "Dont") == string("TUND"));
}

TEST_CASE("THROWS") {
    string text = "sasson happ"; 
CHECK_THROWS(find(text, "happ");
CHECK_THROWS(find(text, "sasson");
}

TEST_CASE("Test replacement of v and w"){
    string text = "i wear vest white";
    
    // CHECK(find(text,"wear") == string("wear"));
    // CHECK(find(text,"veav") == string("wear"));
    // CHECK(find(text,"vear") == string("wear"));
    // CHECK(find(text,"weav") == string("wear"));
    // CHECK(find(text,"vhite") == string("white"));
    CHECK(find(text,"wear") == string("wear"));
    CHECK(find(text,"vear") == string("wear"));
    CHECK(find(text,"vear") == string("wear"));
    CHECK(find(text,"wear") == string("wear"));
    CHECK(find(text,"vhite") == string("white"));
}
//7
TEST_CASE("Test replacement of b, f and p")
{
    string text = "badp fbpf pief bad";

    CHECK(find(text, "badp") == string("badp"));
    CHECK(find(text, "fadb") == string("badp"));
    CHECK(find(text, "pad") == string("bad"));
    CHECK(find(text, "bbbb") == string("fbpf"));
    CHECK(find(text, "pief") == string("pief"));
    CHECK(find(text, "fief") == string("pief"));
    CHECK(find(text, "fad") == string("bad"));
    
}

//8
TEST_CASE("g and j")
{
    string text = "girl jumg on the glass ";
	 CHECK(find(text, "girl") == string("girl"));
     CHECK(find(text, "jirl") == string("girl"));

	//
	CHECK(find(text, "jumg") == string("jumg"));
    CHECK(find(text, "gumg") == string("jumg"));
    CHECK(find(text, "jumj") == string("jumg"));
    CHECK(find(text, "gumj") == string("jumg"));


	//
    CHECK(find(text, "jlass") == string("glass"));
    CHECK(find(text, "glass") == string("glass"));

	

}
//6

TEST_CASE("Test replacement of i and y ,also of  lower-case and upper-case") {

    string text = "I  yIsk eliorbeautifuleyes";
    
    CHECK(find(text, "i") == string("I"));
    CHECK(find(text, "Yisk") == string("yIsk"));
    CHECK(find(text, "Iisk") == string("yIsk"));
    CHECK(find(text, "elyorbeautYfuleIes") == string("eliorbeautifuleyes"));
    CHECK(find(text, "Y")== string("I"));
    CHECK(find(text, "YYSK") == string("yIsk"));
    
   
}

//4
TEST_CASE("Test replacement of d and t ,also of  lower-case and upper-case") {
    string text = "xxx dentyrit yyy";
            CHECK(find(text, "TenTyriD") == string("dentyrit"));
            CHECK(find(text, "DenDyriT") == string("dentyrit"));
            CHECK(find(text, "tenTyrid") == string("dentyrit"));
            CHECK(find(text, "DentyriT") == string("dentyrit"));
           

}
//10
TEST_CASE("Test for ALL kinds of replacement") {

    string text = "xxx vafoudik yyy";

            CHECK(find(text, "vafoudik") == string("vafoudik"));
            CHECK(find(text, "VaPUOtyK") == string("vafoudik"));
            CHECK(find(text, "VAFOUDIK") == string("vafoudik"));
            CHECK(find(text, "vabouDYC") == string("vafoudik"));
            CHECK(find(text, "wAFOUtiQ") == string("vafoudik"));
            CHECK(find(text, "vaPUODyK") == string("vafoudik"));
            CHECK(find(text, "xXX") == string("xxx"));
            CHECK(find(text, "III") == string("yyy"));
            CHECK(find(text, "iYi") == string("yyy"));
            CHECK(find(text, "vafoudiK") == string("vafoudik"));
}

TEST_CASE("Test replacement of c, k and q") {
    string text = "xx quick  yy";
    CHECK(find(text, "quick") == string("quick"));
    CHECK(find(text, "quicc") == string("quick"));
    CHECK(find(text, "quikc") == string("quick"));
    CHECK(find(text, "quikk") == string("quick"));
    CHECK(find(text, "cuick") == string("quick"));
    CHECK(find(text, "cuikk") == string("quick"));
    CHECK(find(text, "cuikc") == string("quick"));
    CHECK(find(text, "cuikq") == string("quick"));
    CHECK(find(text, "cuiqk") == string("quick"));
    CHECK(find(text, "cuiqc") == string("quick"));
    CHECK(find(text, "cuiqq") == string("quick"));
    CHECK(find(text, "kuick") == string("quick"));
    CHECK(find(text, "kuikk") == string("quick"));
    CHECK(find(text, "kuikc") == string("quick"));
    CHECK(find(text, "kuikq") == string("quick"));
    CHECK(find(text, "kuiqk") == string("quick"));
    CHECK(find(text, "kuiqc") == string("quick"));
    CHECK(find(text, "kuiqq") == string("quick"));
}
