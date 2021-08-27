#include <iostream>
#include <dirent.h>
#include <cstdio>
#include <string>

using namespace std;

void readDir(char* pathName, string fileNames[]){
    DIR* dir = opendir(pathName);
    dirent* entity;
    entity = readdir(dir);
    int i = 0;
    while(entity != NULL) {
        fileNames[i] = entity->d_name;
         i++;
        entity = readdir(dir);
    }

    closedir(dir);
}

void filter(string fileNames[], string filterArr[]) {
    for (int i = 0; i<9; i++){
        filterArr[i] = fileNames[i+2];
    }
}

void pathname(char* pathName, string dirName[], string filterArr[]){
    
    for (int i = 0; i<9; i++) {
        dirName[i] = pathName + filterArr[i];
    }
}

void strTochar(string str[], const char* c[]) {
    for (int i = 0; i<9; i++){
    c[i] = str[i].c_str();
    }
    
}

void newNameF(string newName[], char* pathName) {
    
     for(int i=0; i<6; i++){   
     string one = to_string(i+1);
     string jpg = ".jpg";
     newName[i] = pathName + one + jpg;
     }
}

void displayList(const char* c[]){
    for (int i = 0; i<6; i++){
        cout << c[i] << endl;
    }
}

void Rename(const char* oldname[], const char* newname[]) {

        for (int i=0; i<6; i++){
            if (rename(oldname[i], newname[i])!=0) {
        cout << "Not Found\n";
    } else {
     rename(oldname[i],newname[i]);
            }
        cout<<"Success\n";
    }
}


int main(int argc, char *argv[]){
   // The variable that holds the name of destination folder
   char* pathName = "C:\\Users\\HP\\Desktop\\test\\";
   string fileNames[50];  
   string filterArr[50];
   string dirName[50];
   const char *holder[50];
   string newName[50];
   const char *newNameC[50];
   
    //Opens the folder and read the list of files
    readDir(pathName, fileNames);
    //Filters the array of the list from unwanted variables other than the names of files
    filter(fileNames, filterArr);
    //Combines the name of the path of the folder with the name of the file
    pathname(pathName,dirName,filterArr);
    //Converts the strings to char, because the final renaming function accepts char only
    strTochar(dirName, holder);
    //Generates the new names
    newNameF(newName, pathName);
    //Converts the strings to char, because the final renaming function accepts char only
    strTochar(newName, newNameC);
    //The renaming function, which renames the files with numerically organized names
    Rename(holder,newNameC);
    //display the name of the files
    displayList(holder);  
}
