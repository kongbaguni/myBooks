//
//  DirectHangleMaker.cpp
//  myBooks
//
//  Created by kongbaguni on 2015. 7. 30..
//
//

#include "DirectHangleMaker.h"

static inline std::string changeWstringToDirectString(wchar_t inputWChar)
{
    const int BASE_CODE = 44032;
    const int CHOSUNG = 588;
    const int JUNGSUNG = 28;
    
    std::string CHOSUNG_LIST[] =
    {
        //ㄱ  ㄲ    ㄴ   ㄷ   ㄸ    ㄹ    ㅁ    ㅂ   ㅃ
        "k","kk", "h" ,"u","uu", "y", "i", ";", ";;",
        //ㅅ  ㅆ   ㅇ  ㅈ    ㅉ   ㅊ  ㅋ   ㅌ   ㅍ   ㅎ
        "n","nn","j","l","ll","o","0","\"","p","m"
    };
    
    std::string JUNGSUNG_LIST[] =
    {
        //ㅏ ㅐ   ㅑ   ㅒ  ㅓ ㅔ
        "f","r","6","G","t","c",
        //ㅕ ㅖ   ㅗ  ㅘ     ㅙ   ㅚ,
        "e","7","v","vf","vr","vd",
        //ㅛ ㅜ  ㅝ   ㅞ    ㅟ    ㅠ
        "4","b","bt","bc","bd", "5",
        //ㅡ  ㅢ   ㅣ
        "g","gd","d"
    };
    
    std::string JONGSUNG_LIST[] =
    {
        //' 'ㄱ  ㄲ   ㄳ  ㄴ   ㄵ  ㄶ   ㄷ,
        "","x","!","V","s","E","S","A",
        //ㄹ ㄺ  ㄻ   ㄼ   ㄽ  ㄾ   ㄿ  ㅀ,
        "w","@","F","D","T","%","$","R",
        //ㅁ ㅂ   ㅄ  ㅅ   ㅆ  ㅇ   ㅈ   ㅊ,
        "z","3","X","q","2","a","#","Z",
        //ㅋ ㅌ   ㅍ  ㅎ
        "C","W","Q","1"

    };
    
    switch (inputWChar)
    {
            //HJKL:YUIOP
        case L'\n': return "\n";
        case L' ': return " ";
        case L'0': return "H";
        case L'1': return "J";
        case L'2': return "K";
        case L'3': return "L";
        case L'4': return ":";
        case L'5': return "Y";
        case L'6': return "U";
        case L'7': return "I";
        case L'8': return "O";
        case L'9': return "P";
        case L'?': return "B";
        case L',': return "<";
        case L'.': return ">";
        case L'!': return "?";
        case L'"': return "M";
        case L'~': return ")";
        case L'\'': return "(";
        case L'/': return "}";
        case L'%': return "{";
        case L':': return "\\";
        case L'<': return "]";
        case L'>': return "=";
        case L';': return "_";
        case L'+': return "+";
        case L'*': return "`";
        case L'=': return "^";
        case L'-': return "N";

        default:
        {
            int charTemp = inputWChar;
            int cBase = charTemp -BASE_CODE;
            int c1 = cBase / CHOSUNG;
            int c2 = (cBase - (CHOSUNG * c1)) / JUNGSUNG;
            int c3 = (cBase - (CHOSUNG * c1) - (JUNGSUNG * c2));
            if (c1<0)
            {
                return " ";
            }
            auto cho = CHOSUNG_LIST[c1];
            auto jung = JUNGSUNG_LIST[c2];
            auto jong = JONGSUNG_LIST[c3];
            
            return cho+jung+jong;
        }
    }
    
    return "B";

}
std::string DirectHangleMaker::makeDirect(std::wstring inputString)
{
    std::string result;
    for (int i=0; i<inputString.length(); i++)
    {
        result+=changeWstringToDirectString(inputString[i]);
    }
    return result;
}