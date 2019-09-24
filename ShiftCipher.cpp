#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<string>
#include<ctype.h>
#include<algorithm>

//Encrypt function that receives a string to encrypt
std::string Encrypt(std::string pt);
//Decrypt function that receives the string to decrypt
std::string Decrypt(std::string ct);

int main()
{
    //Variables
    bool crypt;
    std::string EorD;
    std::string m;
    std::string fin;
    std::size_t en;
    std::size_t de;
    //Greeting
    std::cout << "Welcome to the Shift Cipher!" << std::endl << std::endl;
    //Asks user whether to encrypt or decrypt
    std::cout << "Would you like to encrypt or decrypt? ";
    std::cin >> EorD;
    //lowercase their answer(EorD)
    for(int i = 0; i < EorD.size(); i++){EorD[i] = tolower(EorD[i]);}
    //Check for 'en' and 'de'
    en = EorD.find("en");
    de = EorD.find("de");
    //if EorD contains 'en' then crypt is true for Encrypt
    //if EorD contains 'de' then crypt is false for Decrypt
    //else end the program
    if(en != std::string::npos){crypt = true;}
    else if(de != std::string::npos){crypt = false;}
    else
    {
        std::cout << std::endl << "INVALID ENTRY";
        getchar();
        return 0;
    }
    //Get the message
    std::cout << "What is your message? ";
    std::cin >> m;
    //remove spaces and capitalize
    remove_if(m.begin(), m.end(), isspace);
    for(int i = 0; i < m.size()-1; i++)
    {
        m[i] = toupper(m[i]);
    }
    //if crypt is true: call Encrypt, if false: call Decrypt
    if(crypt == true){fin = Encrypt(m);}
    else{fin = Decrypt(m);}

    //Deliver message
    std::cout << "Your new message is: " << fin;
    getchar();
    //if done, end
    std::cout << std::endl;
    return 0;
}
//Encrypt function that returns a string
std::string Encrypt(std::string pt)
{
    //num of chars to move
    std::string s = "";
    int shift = 0;
    //holds whether to go forward(right) or backward(left)
    std::string ForB = "";
    //true for forward, false for backward
    bool fb = NULL;
    //holds position of needed string, std::string::npos if not found
    std::size_t L = std::string::npos;
    std::size_t R = std::string::npos;
    //Ask user how far they want to shift the letters
    std::cout << "How far would you like to move the letters of your message? ";
    std::cin >> s;
    shift = std::stoi(s);
    //Ask user in what direction would they like to shift their letters
    std::cout << std::endl << "In what direction, left or right, would you like to move the letters of your message? ";
    std::cin >> ForB;
    for(int i = 0; i < ForB.size(); i++){ForB[i] = tolower(ForB[i]);}
    //Check for l or r
    L = ForB.find("l");
    R = ForB.find("r");
    //if ForB contains an r: fb is true to move forward,
    //if ForB contains an l: fb is false to move backward
    //else restart the function
    if(R != std::string::npos){fb = true;}
    else if(L != std::string::npos){fb = false;}
    else
    {
        std::cout << "INVALID ENTRY";
        Encrypt(pt);
    }
    //Loop through pt
    for(int i = 0; i < pt.size(); i++)
    {
        //Shift chars by 'shift' forward if fb is true
        if(fb == true){pt[i] += shift;}
        //Shift chars by 'shift'' backward if fb is false
        if(fb == false){pt[i] -= shift;}
    }

    //return
    return pt;
}
//Decrypt function that displays a list of possible decrypted phrases
std::string Decrypt(std::string ct)
{
    //num of chars to move
    std::string s = "";
    int shift = 0;
    //holds whether to go forward(left) or backward(left)
    std::string ForB = "";
    //true for forward, false for backward
    bool fb = NULL;
    //holds position of needed string, std::string::npos if not found
    std::size_t L = std::string::npos;
    std::size_t R = std::string::npos;
    //Ask user how far they moved the letters of their message
    std::cout << "How far did you encrypt the letters of your message? ";
    std::cin >> s;
    shift = std::stoi(s);
    //Ask user in what direction they shifted the letter of their message
    std::cout << std::endl << "In what direction, left or right, did you encrypt the letters of your message? ";
    std::cin >> ForB;
    //Check for l or r
    L = ForB.find("l");
    R = ForB.find("r");
    //if ForB contains an r: fb is false to move backward because we're decrypting
    //if ForB contains an l: fb is true to move forward because we're decrypting
    //else restart the function
    if(R != std::string::npos){fb = false;}
    else if(L != std::string::npos){fb = true;}
    else
    {
        std::cout << "INVALID ENTRY";
        Decrypt(ct);
    }
    //Loop through ct
    for(int i = 0; i < ct.size(); i++)
    {
        //Shift chars by 'shift' backward if fb is false
        if(fb == false){ct[i] -= shift;}
        //Shift chars by 'shift' forward if fb is true
        if(fb == true){ct[i] += shift;}
    }
    
    //return
    return ct;
}

/*
THINGS TO DO:
-------------
1) Make sure the encryption process sticks to letters
2) Make sure the decryption process sticks to letters
3) Check if the user is done with the program, if so: exit, if not: restart the program
*/