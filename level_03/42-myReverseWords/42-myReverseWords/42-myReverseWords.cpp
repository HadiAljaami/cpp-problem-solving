// wirte a program toreplace words in string:
/*
origial string :
Welocme to jorden, jordan is a nice country

string After Replace:
Welcome to USA, is a nice countery
*/

#include <iostream>
using namespace std;

// this function return the postion of word in string (retrun first index of the word)
int FindPositionOfWord(string S,string word)
{
    int endIndexOfTheWord = word.length() - 1;
    int endIndexOfTheString = S.length() - 1;
  
    for (int index_S = 0; index_S <= endIndexOfTheString; index_S++)
    {
        if (S[index_S] == word[0])
        {
            
            int i = index_S;
            for (int index_W=1 ;(index_W <= endIndexOfTheWord && i <=endIndexOfTheString);index_W++)
            {
                i = index_S +index_W;

                if (S[i] != word[index_W])
                    break;
                
               if (index_W == endIndexOfTheWord)  
                   return index_S;
               
            }
            
        }
       
    }
    return -1;
}

  //hadi ameen ali saif // ali - google
string Replace(string S1, string StringToReplace, string sRepalceTo)
{
    short FromPostion = FindPositionOfWord(S1, StringToReplace);
    short ToPostion = FromPostion >= 0 ? (FromPostion + StringToReplace.length() - 1) : -1;

   string first = "";
   string last = "";
   string AllStr = "";

   if (FromPostion == 0)
   {
       for (int i = ToPostion + 1; i < S1.length();i++)
       {
           last += S1[i];
       }

       AllStr = sRepalceTo + last;
   }
   if (FromPostion > 0)
   {
       for (int i =0; i < FromPostion;i++)
       {
           first += S1[i];
       }
       AllStr = first + sRepalceTo;

       for (int i = ToPostion + 1; i < S1.length();i++)
       {
           last += S1[i];
       }
       AllStr = AllStr + last;
   }
  
  

  

   


   return AllStr.empty() ? S1 : AllStr;
}


int main()
{
 

   
   cout<< Replace("Welocme to jorden, jordan is a nice country", "jorden", "USA");
    
    return 0;
}
