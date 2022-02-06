/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// CPP program to demonstrate working of string
// find to search a string
#include <iostream>
#include<sstream>
#include<vector>
#include <string>
  
using namespace std;
  
int main()
{
    string str = " "; // empty string to hold the input
    string word;    //string to hold substring from stringstream
    vector<int>arr; //vector to hold the enterd number -number of test cases   -each test case number of string
    int sizeMus,sizeMov,sizeImg,sizeOther,num,size, flag = 0;
    
	// get the first line numbers  -number of test cases   -each test case number of string
    getline(cin,str);
    istringstream in(str);  //use istringstream to convert entered string into a seprated numbers
    while(in>>num) arr.push_back(num); 
    
    int j = 0;
    for(int i = 0; i < arr[0]; i++)
    {
		//j for get the index for the vectors
        j++;
		//reset size of each formate after each case
        sizeImg = 0;
        sizeMov = 0;
        sizeMus = 0;
        sizeOther = 0;
		//each test case loop to get its number of string entered
        for(int x = 0; x < arr[j]; x++)
        {
            flag =0;
			//declare string stream hold each formate
            stringstream music(" mp3 aac flac");
            stringstream img(" jpg bmp gif");
            stringstream mov("mp4 avi mkv");
			//enter the string 
            getline(cin,str);
            stringstream S (str);
			//check for it a mp3 format if done it will raise the flag so it will and finish the iterration to get the new string
            while(S >> word)
            {
                if(stringstream(word) >> size)
                    break;
            }
            
            while(music>>word)
            {
                size_t found = str.rfind(word);
                if(found != string::npos)
                {
                    sizeMus += size;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
               while(img>>word)
                {
                    size_t found = str.rfind(word);
                    if(found != string::npos)
                    {
                        sizeImg += size;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                   while(mov>>word)
                    {
                        size_t found = str.rfind(word);
                        if(found != string::npos)
                        {
                            sizeMov += size;
                            flag = 1;
                            break;
                        }
                    } 
					// if the flag not raised ever this mean the format is not define so hold it size to other
                    if(flag == 0)
                        sizeOther += size;
                }
              
            }
            
        }
        cout<<"music "<<sizeMus<<"b images "<<sizeImg<<"b movies "<<sizeMov<<"b other "<<sizeOther<<"b"<<endl;
    }
  
    

    return 0;
}